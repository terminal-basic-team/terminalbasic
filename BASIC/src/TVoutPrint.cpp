/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * Copyright (C) 2016, 2017 Andrey V. Skvortsov <starling13@mail.ru>
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

#include "TVoutPrint.hpp"
#include "ascii.hpp"

#include "font6x8.h"

TVoutPrint::TVoutPrint() :
_state(IDLE)
{
}

TVoutPrint::~TVoutPrint()
{
}

void
TVoutPrint::begin()
{
	if (_boundary.begin(PAL, 192, 192, _buffer, sizeof (_buffer)) != 0)
		abort();
	_boundary.select_font(font6x8);
}

size_t
TVoutPrint::write(uint8_t c)
{
	switch (_state) {
	case IDLE:
		writeIdle(c);
		break;
	case ESCAPE:
		writeESC(c);
		break;
	case LBRACKET:
		writeLbracket(c);
		break;
	}
	return (1);
}

void
TVoutPrint::writeIdle(uint8_t c)
{
	switch (c) {
	case uint8_t(ASCII::ESC) :
		_state = ESCAPE;
		break;
	case uint8_t('\t') : {
		//uint8_t pZone = _boundary.getCursorX() / 13;
		//_boundary.setCursorX((pZone+1)*13);
		break;
	}
	default:
		_boundary.write(c);
	}
}

void
TVoutPrint::writeESC(uint8_t c)
{
	switch (c) {
	case uint8_t('[') :
		_state = LBRACKET;
		break;
	default:
		_state = IDLE;
	}
}

void
TVoutPrint::writeLbracket(uint8_t c)
{
	switch (c) {
	case uint8_t('m') :
		_state = IDLE;
		break;
	default:
		break;
	}
}
