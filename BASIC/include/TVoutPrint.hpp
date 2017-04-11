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

#ifndef TVOUT_PRINT_HPP
#define TVOUT_PRINT_HPP

#include <Print.h>
#include "TVoutEx.h"

class TVoutPrint : public Print
{
public:
	TVoutPrint();
	~TVoutPrint();
	
	void begin();
	
	size_t write(uint8_t) override;
private:
	enum State_t : uint8_t
	{
		IDLE,
		ESCAPE,
		LBRACKET
	};
	void writeIdle(uint8_t);
	void writeESC(uint8_t);
	void writeLbracket(uint8_t);
	uint8_t _buffer[192/8*192];
	TVoutEx	_boundary;
	State_t	_state;
};

#endif /* TVOUT_PRINT_HPP */
