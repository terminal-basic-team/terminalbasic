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

#ifndef CPS_MOSPROTOCOL_HPP
#define CPS_MOSPROTOCOL_HPP

#include <stdint.h>

#include "cps.hpp"

namespace cps
{

/**
 * @brief MOSProtocl - messages over stream protocol package
 */
Package(MOSProtocol)
{
	CPS_PACKAGE(MOSProtocol)

public:
	// Message flags
	enum class Flags_t : uint8_t
	{
		NON = 0x0,
		SYN = 0x1,	// request
		ACK = 0x2,	// reply
		FIN = 0x4,	// end
		CON = 0x8,
		CMP = 0x10
	};

	enum class ErrCodes : uint8_t
	{
		NO_ERROR = 0,
		BUFFER_SIZE_BIG,
		BUFFER_SIZE_SMALL
	};

	class EndPoint;
	
	enum class Codes : uint8_t
	{
		SOH = 0x1,
		STX = 0x2,
		ETX = 0x3,
		EOT = 0x4
	};
	
	typedef int16_t length_t;

//private:

	union CPS_PACKED header_t
	{
		struct {
			uint8_t		soh;
			uint8_t		flags;
			uint16_t	id;
			length_t	len;
			length_t	invLen;
			uint8_t		headerSum;
			uint8_t		stx;
		} _data;
		char	_bytes[sizeof (_data)];
	};

	struct CPS_PACKED footer_t
	{
		uint8_t		etx;
		uint16_t	sum;
		uint16_t	id;
		uint8_t		eot;
	};
	
	/**
	 * @brief check header for correctness
	 * @param header header to check reference
	 * @return check result
	 */
	static bool checkHeader(const header_t&);
	/**
	 * @brief prepareHeader
	 * @param header
	 * @param message length
	 * @param id
	 * @param flags
	 */
	static void prepareHeader(header_t&, length_t, uint16_t,
	    Flags_t flags=Flags_t::NON);
};

}

#endif //CPS_MOS_PROTOCOL_HPP
