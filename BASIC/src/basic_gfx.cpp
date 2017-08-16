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

#include "basic_gfx.hpp"

#if USE_GFX

#include "TVoutEx.h"

namespace BASIC
{

static const uint8_t gfxTokens[] PROGMEM = {
	'C','I','R','C','L','E'+0x80,
	'C','O','L','O','R'+0x80,
	'L','I','N','E'+0x80,
	'L','I','N','E','T','O'+0x80,
	'P','O','I','N','T'+0x80,
	'S','C','R','E','E','N'+0x80,
	0
};

const FunctionBlock::function GFXModule::comms[] PROGMEM = {
	GFXModule::command_circle,
	GFXModule::command_circle,
	nullptr, nullptr,
	
};

GFXModule::GFXModule()
{
	commands = comms;
	commandTokens = gfxTokens;
}

bool
GFXModule::command_circle(Interpreter &i)
{
	INT x,y,r;
	
	if (getIntegerFromStack(i, r)) {
		if (getIntegerFromStack(i, y)) {
			if (getIntegerFromStack(i, x)) {
				TVoutEx::instance()->drawCircle(x,y,r);
				return true;
			}
		}
	}
	return false;
}

bool
GFXModule::command_color(Interpreter &i)
{
	INT c;
	
	if (getIntegerFromStack(i, c)) {
		TVoutEx::instance()->setColor(Color_t(c));
		return true;
	}
	return false;
}

bool
GFXModule::command_point(Interpreter &i)
{
	INT x,y;
	
	if (getIntegerFromStack(i, y)) {
		if (getIntegerFromStack(i, x)) {
			TVoutEx::instance()->setPixel(x, y);
			return true;
		}
	}
	return false;
}

}

#endif // USE_GFX
