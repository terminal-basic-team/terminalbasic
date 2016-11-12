/****************************************************************************
    This file is part of scccoduino.

    Copyright (C) 2014-2016 by Andrey V. Skvortsov

    Scopduino is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    Casim is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with Casim; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 ****************************************************************************/

#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include <inttypes.h>
#include <stdlib.h>

#include "cps.hpp"
#include "cps_mosprotocol.hpp"

class Protocol
{
public:
	
	enum DeviceType
	{
		ARDUINO_NANO_168 = 0,
		ARDUINO_NANO_328,
		ARDUINO_UNO_168,
		ARDUINO_UNO_328,
		ARDUINO_MEGA_2560
	};

	enum DataSource
	{
		ANALOG, DIGITAL
	};
	
	/**
	 * Device description
	 */
    struct CPS_PACKED Device
	{
		uint8_t device_type;
		uint16_t id;
	};

	/**
	 * Channel description
	 */
    struct CPS_PACKED Channel
	{
		char name[16];
		uint64_t minPeriod;
		uint64_t maxPeriod;
		int16_t minValue;
		int16_t maxValue;
	};

	struct CPS_PACKED Channels
	{
		uint8_t channelsNumber;
		Channel channels[];
	};

	enum Type
	{
		SESSION = 1,
		DEVICE,
		CHANNELS,
		ANALOG_MEASURE,
		DIGITAL_MEASURE,
		ERROR
	};

	enum Errors
	{
		ERR_INVALID_LENGTH = 0x10,
		ERR_INVALID_TYPE,
		ERR_INVALID_PARAMETERS,
		ERR_INSUFFICIENT_DATA
	};

	enum MeasureMode
	{
		MODE_PERMANENT = 0,
		MODE_IMMEDIATE,
		MODE_RISING,
		MODE_FALLING
	};

	struct CPS_PACKED Header
	{
		uint8_t type;
	};

	struct CPS_PACKED MeasureTask
	{
		uint32_t period;
		uint16_t samplesNumber;
		uint8_t channelNumber;
		uint8_t mode;
		uint16_t threshold;
	};

	struct CPS_PACKED Measure
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

	struct CPS_PACKED MessagesData
	{
		Header header;
		union {
			MeasureTask measureTask;
			Measure measure;
			Device device;
		} messages;
	};

	struct CPS_PACKED Footer
	{
		uint8_t eot;
		uint8_t id;
		uint8_t _paddding;
		uint8_t sum;
	};

	class Message
	{
	public:
		virtual ~Message() = default;
		virtual uint16_t length() const;

		const Header &header() const
		{
			return (*_header);
		}

		Header &header()
		{
			return (*_header);
		}
		Type type() const;
	protected:
		Message(Header*, Type);
	private:
		Header *_header;
	};

	class DeviceMessage : public Message
	{
	public:
		DeviceMessage(Header*);

		uint16_t length() const override;
	};

	class SessionMessage : public Message
	{
	public:
		SessionMessage(Header*);

		uint16_t length() const override;
	};

	class ChannelsMessage : public Message
	{
	public:
		ChannelsMessage(Header*);

		uint16_t length() const override;
		uint8_t channelsNumber() const;
		Channel channel(uint8_t index);

	private:

		const Channels &channels() const;
		Channels &channels();
	};

	class MeasureTaskMessage : public Message
	{
	public:
		MeasureTaskMessage(Header*, Type);

		uint32_t period() const;
		uint16_t samplesNumber() const;
		MeasureMode mode() const;
		uint8_t channelNumber() const;

		void setPeriod(uint32_t);
		void setSamplesNumber(uint16_t);
		void setMode(MeasureMode);
		void setChannelNumber(uint8_t);

	protected:

		struct CPS_PACKED Data
		{
			Header header;
			MeasureTask task;
		};

		const Data &data() const
		{
			return (reinterpret_cast<const Data&> (*this));
		}

		Data &data()
		{
			return (reinterpret_cast<Data&> (*this));
		}
	};

	class AnalogMeasureTaskMessage : public MeasureTaskMessage
	{
	public:
		AnalogMeasureTaskMessage(Header*);

		void setThreshold(uint16_t);
	};

	class DigitalMeasureTaskMessage : public MeasureTaskMessage
	{
	public:
		DigitalMeasureTaskMessage(Header*);
	};

	class MeasureMessage : public Message
	{
	public:
		MeasureMessage(Header*, Type);

		uint16_t numberOfSamples() const;
		uint32_t period() const;
		void setPeriod(uint32_t);
	protected:

		const Measure &measure() const
		{
			return (reinterpret_cast<const Measure&> (header()));
		}

		Measure &measure()
		{
			return (reinterpret_cast<Measure&> (header()));
		}
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

	class EndPoint;
};

#endif /* PROTOCOL_HPP */


