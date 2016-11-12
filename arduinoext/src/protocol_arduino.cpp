#include "protocol_arduino.hpp"
#include "_protocol.hpp"
#include "arduino_logger.hpp"
#include "helper.hpp"

using cps::MOSProtocol;

Protocol::EndPoint::EndPoint(cps::MOSProtocol::EndPoint &mos, DeviceType type,
    uint16_t id) :
_type(type), _id(id), _underlying(mos), _state(IDLE)
{
}

void
Protocol::EndPoint::step()
{
	LOG_TRACE;
	
        MOSProtocol::length_t   length = sizeof (_buffer);
        MOSProtocol::Flags_t    flags;
        
        flags = _underlying.recvMsg(_buffer, length);
	
        if ((length > 0) && (int(flags) & int(MOSProtocol::Flags_t::SYN))) {
		switch (header()->type) {
		case SESSION:
			this->session();
			break;
		case DEVICE:
			this->device();
			break;
		case ANALOG_MEASURE:
		default:
			break;    
		}
        } else {
                return;
	}
}

void
Protocol::EndPoint::session()
{
	LOG_TRACE;

	_underlying.sendMsg((uint8_t*)_buffer, sizeof (Header),
	    MOSProtocol::Flags_t::ACK);
}

void
Protocol::EndPoint::device()
{
	LOG_TRACE;
	
	MessagesData *data = reinterpret_cast<MessagesData*>(_buffer);
	data->messages.device.device_type = _type;
	data->messages.device.id = _id;
	_underlying.sendMsg((uint8_t*)_buffer, sizeof (Header) + sizeof (Device),
	    MOSProtocol::Flags_t::ACK);
}

Protocol::Header*
Protocol::EndPoint::header()
{
	return reinterpret_cast<Header*>(&_buffer);
}
