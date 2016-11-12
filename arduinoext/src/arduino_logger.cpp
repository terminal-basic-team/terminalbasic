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

#include <Print.h>

#include "arduino_logger.hpp"

#if ARDUINO_LOG

Logger Logger::_instance;
Logger::format_t Logger::_format = Logger::format_t::dec;

void Logger::init(Stream &stream)
{
	_instance._stream = &stream;
}
#endif

ByteArray::ByteArray(const uint8_t *data, size_t size) :
_data(data), _size(size)
{
}

size_t ByteArray::printTo(Print& p) const
{
	size_t res = 0;
	for (size_t i = 0; i < size();) {
		size_t ii = i;

		size_t addr = i + intptr_t(data());
		while (addr <= 0x0FFF) {
			p.print('0');
			addr <<= 8;
		}
		p.print(i + intptr_t(data()), HEX), p.print('(');
		if (i < 0x0F)
			p.print('0');
		p.print(i, HEX), p.print(')'), p.print(":\t");
		size_t j;
		for (j = 0; j < 8; ++j, ++ii) {
			if (ii >= size())
				break;
			uint8_t c = data()[ii];
			if (c > 0x0F) {
				res += p.print(' ');
				res += p.print(c, 16);
			} else {
				res += p.print(' ');
				res += p.print('0');
				res += p.print(c, 16);
			}
		}
		for (; j < 8; ++j)
			res += p.print("   ");
		res += p.print('\t');
		for (size_t j = 0; j < 8; ++j, ++i) {
			if (i >= size())
				break;
			const char c = ((const char*) data())[i];
			if (c < ' ')
				res += p.print('.');
			else
				res += p.print(c);
		}
		res += p.println();
	}
	return (res);
}
