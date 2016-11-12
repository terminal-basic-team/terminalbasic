

#ifndef PROTOCOL_ARDUINO_HPP
#define PROTOCOL_ARDUINO_HPP

#include "protocol.hpp"
#include "cps_mosprotocol_arduino.hpp"

class Protocol::EndPoint
{
public:
	
	enum State_t { IDLE, WAIT };
	
	EndPoint(cps::MOSProtocol::EndPoint&, DeviceType, uint16_t);
	
	void step();
private:
	
	void session();
	void device();
	Header *header();
	
	DeviceType _type;
	uint16_t _id;
	cps::MOSProtocol::EndPoint	&_underlying;
	char	_buffer[256];
	State_t	_state;
};

#endif /* PROTOCOL_ARDUINO_HPP */
