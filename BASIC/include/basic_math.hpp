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

#ifndef BASIC_MATH_HPP
#define BASIC_MATH_HPP

#include "basic_functionblock.hpp"
#include "basic_interpreter.hpp"

namespace BASIC
{

class Math : public FunctionBlock
{
public:
	explicit Math(FunctionBlock* =NULL);
// FunctionBlock interface
protected:
	FunctionBlock::function _getFunction(const char*) const override;
	
	static bool func_abs(Interpreter&);
	static bool func_cos(Interpreter&);
	static bool func_sin(Interpreter&);
	static bool func_sqrt(Interpreter&);
	static bool func_pi(Interpreter&);
};

}

#endif
