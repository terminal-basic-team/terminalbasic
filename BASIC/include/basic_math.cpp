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

#include "basic_math.hpp"
#include <math.h>
#include <string.h>

namespace BASIC
{

static const char sABS[] PROGMEM = "ABS";
static const char sCOS[] PROGMEM = "COS";
static const char sPI[] PROGMEM = "PI";
static const char sSIN[] PROGMEM = "SIN";
static const char sSQRT[] PROGMEM = "SQRT";

PGM_P const Math::funcStrings[NUM_FUNC] PROGMEM = {
	sABS, sCOS, sPI, sSIN, sSQRT
};

Math::Math(FunctionBlock *next) :
FunctionBlock(next)
{
}

FunctionBlock::function
Math::_getFunction(const char *name) const
{
	if (strcmp_P(name, (PGM_P)pgm_read_word(&(funcStrings[F_ABS]))) == 0)
		return func_abs;
	else if (strcmp(name, "COS") == 0)
		return func_cos;
	else if (strcmp(name, "SIN") == 0)
		return func_sin;
	else if (strcmp(name, "SQRT") == 0)
		return func_sqrt;
	else if (strcmp(name, "PI") == 0)
		return func_pi;
	else
		return NULL;
}

bool
Math::func_abs(Interpreter &i)
{
	Parser::Value v(Integer(0));
	i.popValue(v);
	if (v.type == Parser::Value::INTEGER || v.type == Parser::Value::REAL) {
		if (v < Parser::Value(Integer(0)))
			v.switchSign();
		i.pushValue(v);
		return true;
	} else
		return false;
}

bool
Math::func_cos(Interpreter &i)
{
	return general_func(i, &cos_r);
}

bool
Math::func_sin(Interpreter &i)
{
	return general_func(i, &sin_r);
}

bool
Math::func_sqrt(Interpreter &i)
{
	return general_func(i, &sqrtf);
}

bool
Math::func_pi(Interpreter &i)
{
	Parser::Value v(Real(M_PI));
	i.pushValue(v);
	return (true);
}

Real Math::sin_r(Real v)
{
	return sin(v);
}

Real Math::cos_r(Real v)
{
	return cos(v);
}

Real Math::sqrt_r(Real v)
{
	return sqrt(v);
}

bool
Math::general_func(Interpreter &i, _func f)
{
	Parser::Value v(Integer(0));
	i.popValue(v);
	if (v.type == Parser::Value::INTEGER || v.type == Parser::Value::REAL) {
		v = Real((*f)(Real(v)));
		i.pushValue(v);
		return true;
	} else
		return false;
}

}
