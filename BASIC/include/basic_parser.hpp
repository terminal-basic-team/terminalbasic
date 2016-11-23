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

#ifndef PARSER_HPP
#define PARSER_HPP

#include <stdlib.h>
#include <inttypes.h>

#include "cps.hpp"
#include "basic.hpp"

namespace BASIC
{

class Lexer;

class Interpreter;

class Parser
{
public:

	enum ErrorCodes : uint8_t
	{
		NO_ERROR = 0,
		OPERATOR_EXPECTED,
		EXPRESSION_EXPECTED,
		INTEGER_EXPRESSION_EXPECTED,
		THEN_OR_GOTO_EXPECTED,
		VARIABLES_LIST_EXPECTED
	};

	class CPS_PACKED Value;

	Parser(Lexer&, Interpreter&);

	bool parse(const char*);

	ErrorCodes getError() const
	{
		return _error;
	}
private:
	enum Mode : uint8_t
	{
		SCAN = 0, EXECUTE
	};
	bool fOperators();
	bool fOperator();
	bool fImplicitAssignment(char*);
	bool fPrintList();
	bool fExpression(Value&);
	bool fSimpleExpression(Value&);
	bool fTerm(Value&);
	bool fFactor(Value&);
	bool fFinal(Value&);
	bool fIfStatement();
	bool fCommand();
	bool fGotoStatement();
	bool fForConds();
	bool fVar(char*);
	bool fVarList();
	bool fArrayList();
	bool fArray();
	bool fDimensions(uint8_t&);

	ErrorCodes _error;
	Lexer &_lexer;
	Interpreter &_interpreter;
	Mode	_mode;
};

}

#endif
