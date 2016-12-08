/****************************************************************************
    This file is part of cps library.

    Copyright (C) 2014-2016 by Andrey V. Skvortsov

    Cps is free software; you can redistribute it and/or modify
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

#include "cps_mosprotocol_arduino.hpp"
#include "arduino_logger.hpp"
#include "helper.hpp"
#include "bytearray.hpp"

using namespace cps;

#define RET_ERROR(code, ret) { _lastError = ErrCodes::code; return (ret); }

uint16_t MOSProtocol::EndPoint::_idGenerator = 0;

MOSProtocol::EndPoint::EndPoint(Stream &stream) :
_stream(stream),
_lastError(ErrCodes::NO_ERROR)
{
}

bool
MOSProtocol::EndPoint::sendMsg(const uint8_t *buffer, length_t size,
			       Flags_t flags)
{
	LOG_TRACE;
	
	int16_t result;

	if (size >= 1 << 14) {
		negativeLedBlink();
		RET_ERROR(BUFFER_SIZE_BIG, -1);
	}

	header_t header;

	prepareHeader(header, size, _idGenerator++, flags);
	result = _stream.write((const uint8_t*) &header, sizeof (header_t));
	if (result != sizeof (header_t)) {
	//	negativeLedBlink();
		return (false);
	} else {
	//	positiveLedBlink(1);
	}
	result = _stream.write((const uint8_t*) buffer, size);
	if (result != size) {
	//	negativeLedBlink();
		return (false);
	} else {
		//sitiveLedBlink(2);
	}

	return (true);
}

MOSProtocol::Flags_t
MOSProtocol::MOSProtocol::EndPoint::recvMsg(char *data, length_t &len)
{
	LOG_TRACE;
	
	char buffer[2 * sizeof (header_t)];
	header_t *header;
	length_t position = 0;
	uint16_t result;

	if ((header = seekForHeader(buffer, sizeof (buffer))) != NULL) {
		while (position < header->_data.len) {
			result = _stream.readBytes(data + position,
						header->_data.len - position);
			position += result;
		}
		LOG("Message received:",
		ByteArray((const uint8_t*) data,
			header->_data.len));
		len = header->_data.len;
		return (Flags_t(header->_data.flags));
	} else {
		LOG("Unable to receive header");
		len = -1;
		return (Flags_t::NON);
	}
}

MOSProtocol::header_t*
MOSProtocol::EndPoint::seekForHeader(char *buffer, uint8_t length)
{
	LOG_TRACE;
	
	if (length <= sizeof (header_t)) {
		RET_ERROR(BUFFER_SIZE_SMALL, NULL);
	}

	uint8_t position = 0;
	uint8_t bytesToRead = sizeof (header_t);

	while (position < length - sizeof (header_t)) {
		uint8_t count = 0;
		if (bytesToRead) {
			count = _stream.readBytes(buffer + position +
			    sizeof (header_t) - bytesToRead, bytesToRead);
		}
		bytesToRead -= count;
		for (uint8_t i = 0; i<sizeof (header_t) - bytesToRead; ++i) {
			if (buffer[position] != char(Codes::SOH)) {
				++position, ++bytesToRead;
			} else
				break;
		}
		if (bytesToRead == 0) {
			LOG("Possibly header:",
			ByteArray((const uint8_t*) buffer,
				sizeof (header_t)));
			if (checkHeader(*reinterpret_cast<header_t*> (
					buffer + position))) {
				return (reinterpret_cast<header_t*> (
				    buffer + position));
			} else
				++position;
		}
	}

	return (NULL);
}
