/*
 * ucBASIC is a lightweight BASIC-like language interpreter
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

#include "basic_arduinoio.hpp"
#include "Arduino.h"

namespace BASIC
{

static const char sAREAD[] PROGMEM = "AREAD";
static const char sAREAD_INT[] PROGMEM = "AREAD$";

PGM_P const ArduinoIO::funcStrings[NUM_FUNC] PROGMEM = {
	sAREAD, sAREAD_INT
};

ArduinoIO::ArduinoIO(FunctionBlock *next) :
FunctionBlock(next)
{
}

FunctionBlock::function
ArduinoIO::_getFunction(const char *name) const
{
	if (strcmp_P(name, (PGM_P)pgm_read_word(&(funcStrings[F_AREAD]))) == 0)
		return func_aread;
	else if (strcmp_P(name, (PGM_P)pgm_read_word(&(funcStrings[
	    F_AREAD_INT]))) == 0)
		return func_aread_int;
	else
		return NULL;
}

bool
ArduinoIO::func_aread(Interpreter &i)
{
	return general_func(i, aread_r);
}

bool
ArduinoIO::func_aread_int(Interpreter &i)
{
	return general_func(i, aread_i);
}

Real
ArduinoIO::aread_r(Real v)
{
	return Real(analogRead(v)) / Real(1023) * Real(5.0);
}

Integer
ArduinoIO::aread_i(Integer v)
{
	return analogRead(v);
}

}
