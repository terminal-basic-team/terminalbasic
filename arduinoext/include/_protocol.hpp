/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   protocol.hpp
 * Author: starling13
 *
 * Created on 2 января 2016 г., 16:34
 */

#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include <inttypes.h>
#include <stdlib.h>

#ifndef PACKED
#define PACKED __attribute__ ((__packed__))
#endif

class Protocol
{
public:

	enum Type
	{
		SESSION = 1,
		CHANNELS,
		ANALOG_MEASURE,
		DIGITAL_MEASURE,
		ERROR_REPORT
	};

	enum Errors
	{
		ERR_INVALID_LENGTH = 0x10,
		ERR_INVALID_TYPE,
		ERR_INVALID_PARAMETERS,
		ERR_INSUFFICIENT_DATA
	};

	enum Codes
	{
		SOH = 0x1,
		EOT = 0x4
	};

	enum Flags
	{
		REQ = 0x13,
		ACK = 0x14
	};

	enum MeasureMode
	{
		MODE_PERMANENT = 0,
		MODE_IMMEDIATE,
		MODE_RISING,
		MODE_FALLING
	};

	struct PACKED Header
	{
		uint8_t soh;
		uint8_t id;
		uint8_t type;
		uint8_t flag;
		uint16_t bodylen;
		uint8_t _padding;
		uint8_t sum;
	};

	struct PACKED MeasureTask
	{
		uint32_t period;
		uint16_t samplesNumber;
		uint8_t channelNumber;
		uint8_t mode;
		uint16_t threshold;
	};

	struct PACKED Measure
	{
		uint8_t precision;
		uint32_t period;
		uint16_t samplesNumber;

		union
		{
			uint16_t doublePrec[];
			uint8_t singlePrec[];
		} data;
	};

	struct PACKED Footer
	{
		uint8_t eot;
		uint8_t id;
		uint8_t _paddding;
		uint8_t sum;
	};
	class Message
	{
	public:
		uint16_t length() const;
		uint8_t id() const;
		const char *data() const;
		Type type() const;
	protected:
		Message(Header*, Footer*, Type, uint16_t);
		Message(Header*);
	private:
		Header *_header;
		Footer *_footer;
		static uint8_t _idGenerator;
	};

	class SessionMessage : public Message
	{
	public:
		SessionMessage();
	private:

		struct
		{
			Header header;
		} _data;
	};

	class MeasureTaskMessage : public Message
	{
	public:
		MeasureTaskMessage(Type);

		uint32_t period() const;
		uint16_t samplesNumber() const;
		MeasureMode mode() const;
		uint8_t channelNumber() const;

		void setPeriod(uint32_t);
		void setSamplesNumber(uint16_t);
		void setMode(MeasureMode);
		void setChannelNumber(uint8_t);

	protected:

		struct PACKED
		{
			Header header;
			MeasureTask task;
		} _data;
	};

	class AnalogMeasureTaskMessage : public MeasureTaskMessage
	{
	public:
		AnalogMeasureTaskMessage();

		void setThreshold(uint16_t);
	};

	class DigitalMeasureTaskMessage : public MeasureTaskMessage
	{
	public:
		DigitalMeasureTaskMessage();
	};

	class MeasureMessage : public Message
	{
	public:
		MeasureMessage(Header*);

		uint16_t numberOfSamples() const;
		uint32_t period() const;
		void setPeriod(uint32_t);
	protected:
		Measure *_measure;
	};

	class AnalogMeasureMessage : public MeasureMessage
	{
	public:
		AnalogMeasureMessage(Header*);
		uint16_t doubleSample(uint16_t) const;
	};

	class DigitalMeasureMessage : public MeasureMessage
	{
	public:
		DigitalMeasureMessage(Header*);
		uint8_t sample(uint16_t) const;
	};
};

#endif /* PROTOCOL_HPP */
