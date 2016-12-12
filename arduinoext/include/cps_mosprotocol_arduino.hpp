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

#ifndef CPS_MOSPROTOCOL_ARDUINO_HPP
#define CPS_MOSPROTOCOL_ARDUINO_HPP

#include "Stream.h"
#include "Arduino.h"

#include "cps_mosprotocol.hpp"

namespace cps
{

/**
 * @brief 
 */
class MOSProtocol::EndPoint
{
	CPS_NOTCOPYABLE(EndPoint)

public:
	EndPoint(Stream&);

	/**
	 * @brief send message
	 * @param data message buffer pointer
	 * @param len message length
	 * @param flags message flags
	 * @return number of bytes sent, -1 on error
	 */
	bool sendMsg(const uint8_t*, length_t, Flags_t flags = Flags_t::NON);
	
	/**
	 * @brief
	 * @param 
	 * @param length in out buffer/message size
	 * @param flags
	 * @return received message size
	 */
	Flags_t recvMsg(char*, length_t&);

private:
	
	header_t *seekForHeader(char*, uint8_t);
	
	Stream		&_stream;
	ErrCodes	 _lastError;
	
	static uint16_t _idGenerator;
};

}

#endif // CPS_MOS_PROTOCOL_ARDUINO_HPP
