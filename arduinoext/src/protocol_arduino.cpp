/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * Copyright (C) 2016  Andrey V. Skvortsov <starling13@mail.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
