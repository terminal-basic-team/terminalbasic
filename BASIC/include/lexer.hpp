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

#ifndef LEXER_HPP
#define LEXER_HPP

#include <inttypes.h>
#include <stdlib.h>

#include "arduino_logger.hpp"
#include "parser.hpp"
#include "basic_parser_value.hpp"
#include "helper.hpp"

namespace BASIC
{

enum class ASCII : uint8_t
{
	NUL = 0x00,
	SOH = 0x01,
	BEL = 0x07,
	LF  = 0x0A,
	CR  = 0x0D,
	ESC = 0x1B
};

enum Token : uint8_t
{
	NOTOKENS = 0,
	
	// Commands
	COM_DUMP,
	COM_LIST,
	COM_NEW,
	COM_RUN,
	
	// Statements
	KW_END,
	KW_FOR,
	KW_GOSUB,
	KW_GOTO,
	KW_IF,
	KW_LET,
	KW_NEXT,
	KW_PRINT,
	KW_RETURN,
	// other keywords
	KW_THEN,
	KW_TO,
	KW_STEP,
	
	REAL_IDENT,
	INTEGER_IDENT,
	STRING_IDENT,
	
	C_INTEGER,
	C_REAL,
	C_STRING,

	// =
	EQUALS,
	// :
	COLON,
	// ;
	SEMI,
	// <
	LT,
	// >
	GT,
	// <=
	LTE,
	// >=
	GTE,
	// <>
	NE,
	//  ><
	NEA,
	// ,
	COMMA,
	// ^
	POW,
	// (
	LPAREN,
	// )
	RPAREN,
	// +
	PLUS,
	// -
	MINUS,
	// *
	STAR,
	// /
	SLASH,
	
	OP_AND,
	OP_OR,
	OP_NOT,
	    
	NUM_TOKENS
};

#if ARDUINO_LOG
Logger&
operator<<(Logger &logger, Token tok);
#endif

class Lexer
{
public:
	
	void init(const char*);
	bool getNext();

	Token getToken() const
	{
		return _token;
	}

	const Parser::Value &getValue() const
	{
		return _value;
	}
	
	const char *id() const { return _id; }

	size_t getPointer() const
	{
		return _pointer;
	}
	
	static PGM_P const tokenStrings[NUM_TOKENS];

private:

	void pushSYM();
	void next();

	void first_A();
	void first_D();
	void first_E();
	void first_F();
	void first_G();
	void first_I();
	void first_L();
	void first_N();
	void first_O();
	void first_P();
	void first_R();
	void first_S();
	void first_T();

	void fitst_LT();
	void fitst_GT();
	void decimalNumber();
	void ident();
	void stringConst();

	const char *_string;
	uint16_t _pointer;

	Parser::Value _value;
	char _id[STRINGSIZE];
	size_t _valuePointer;

	Token _token;
};

}

#endif
