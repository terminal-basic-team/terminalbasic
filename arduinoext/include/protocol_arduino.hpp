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
