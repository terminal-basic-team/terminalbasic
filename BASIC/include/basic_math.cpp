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

Math::Math(FunctionBlock *next) :
FunctionBlock(next)
{
}

FunctionBlock::function
Math::_getFunction(const char *name) const
{
	if (strcmp(name, "ABS") == 0)
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
	volatile int a;
	return abs(a);
}

bool
Math::func_cos(Interpreter &i)
{
	volatile float a;
	return cos(a);
}

bool
Math::func_sin(Interpreter&)
{
	volatile float a;
	return sin(a);
}

bool
Math::func_sqrt(Interpreter &i)
{
	Parser::Value v(Integer(0));
	i.popValue(v);
	if (v.type == Parser::Value::INTEGER || v.type == Parser::Value::REAL) {
		v = Real(sqrt(Real(v)));
		i.pushValue(v);
		return true;
	} else
		return false;
}

bool
Math::func_pi(Interpreter &i)
{
	Parser::Value v(float(M_PI));
	i.pushValue(v);
	return (true);
}

}
