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

#ifndef BASIC_HPP
#define BASIC_HPP

#include <stdio.h>
#include <inttypes.h>

/**
 * @brief Simple BASIC language interpreter package
 */
namespace BASIC
{
// Max size of the program line
const uint8_t PROGSTRINGSIZE = 72;
// Max size of the string constants/variables
const uint8_t STRINGSIZE = 32;
// Number of bytes for program text, variables and stack
#if defined (__AVR_ATmega1284__) || defined (__AVR_ATmega1284P__)
const size_t PROGRAMSIZE = 14848;
#elif defined (__AVR_ATmega2560__)
const size_t PROGRAMSIZE = 6144;
#elif defined (__AVR_ATmega128__) || defined (__AVR_ATmega128A__)
const size_t PROGRAMSIZE = 3072;
#elif defined (__AVR_ATmega328__) || defined (__AVR_ATmega328P__)
const size_t PROGRAMSIZE = 1024;
#else
const size_t PROGRAMSIZE = 8192;
#endif
// Number of characters in variable name
const uint8_t VARSIZE = 8; 
// integer type
typedef int16_t Integer;
// long integer type
typedef int32_t LongInteger;
// floating point type
typedef float Real;
/**
 * @brief lexical tokens
 */
enum class Token : uint8_t
{
	NOTOKENS = 0,
	
	// Commands
	COM_CLS,
	COM_DATA,
	COM_DUMP,
	COM_LIST,
	COM_LOAD,
	COM_NEW,
	COM_RUN,
	COM_SAVE,
	
	// Statements
	KW_DIM,
	KW_END,
	KW_FOR,
	KW_GO,
	KW_GOSUB,
	KW_GOTO,
	KW_IF,
	KW_INPUT,
	KW_LET,
	KW_NEXT,
	KW_PRINT,
	KW_REM,
	KW_RETURN,
	// other keywords
	KW_ARRAYS,
	KW_FALSE,
	KW_THEN,
	KW_TO,
	KW_TRUE,
	KW_STEP,
	KW_VARS,
	
	OP_AND,
	OP_OR,
	OP_NOT,

	// *
	STAR,
	// /
	SLASH,
	// +
	PLUS,
	// -
	MINUS,
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
	
	REAL_IDENT,
	INTEGER_IDENT,
	LONGINT_IDENT,
	STRING_IDENT,
	BOOL_IDENT,
	
	C_INTEGER,
	C_REAL,
	C_STRING,
	C_BOOLEAN,
	    
	NUM_TOKENS
};

}

#endif
