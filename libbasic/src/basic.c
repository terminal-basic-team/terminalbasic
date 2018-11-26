/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * Copyright (C) 2017-2018 Andrey V. Skvortsov <starling13@mail.ru>
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

#include "basic.h"

#include <stdlib.h>

#include "avr/pgmspace.h"

uint8_t*
scanTable(const uint8_t *token, const uint8_t table[], uint8_t *index)
{
	uint8_t tokPos = 0, tabPos = 0;
	while (1) {
		uint8_t c = pgm_read_byte(table);
		uint8_t ct = token[tokPos];
		if (c == 0)
			return NULL;
		
		if (ct == c) {
			++tokPos, ++table;
			continue;
		} else if (ct+(uint8_t)(0x80) == c) {
			*index = tabPos;
			++tokPos;
			return (uint8_t*)token+tokPos;
		} else {
			if (c & (uint8_t)(0x80))
				c &= ~(uint8_t)(0x80);
			if (c > ct && ct != 0)
				return NULL;
			else {
				while ((pgm_read_byte(table++) & (uint8_t)(0x80)) ==
				    0);
				++tabPos, tokPos=0;
			}
			continue;
		}
		
		if (ct == 0) {
			while ((pgm_read_byte(table++) & (uint8_t)(0x80)) ==
				    0);
			++tabPos, tokPos=0;
		}
	}
	return NULL;
}
