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

#ifndef CRC16_H
#define CRC16_H

#include <sys/cdefs.h>

#include <stdint.h>

__BEGIN_DECLS

inline uint16_t
crc16_update(uint16_t crc, uint8_t a)
{
	int i;
	
	crc ^= a;
	for (i=0; i<8; ++i) {
		crc = (crc >> 1);
		if (crc & 1)
			crc ^= 0xA001;
	}
	
	return (crc);
}

__END_DECLS

#endif /* CRC16_H */
