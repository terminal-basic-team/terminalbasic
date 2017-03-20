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

#ifndef BASIC_HPP
#define BASIC_HPP

#include <stdio.h>
#include <inttypes.h>

#include "helper.hpp"

#ifdef ARDUINO
#include "config_arduino.hpp"
#elif defined __linux__
#include "config_linux.hpp"
#endif

#if USEMATH
#if !USE_REALS
#error Math module requires real arithmetics support
#endif
#endif

/**
 * @brief Simple BASIC language interpreter package
 */
namespace BASIC
{

// integer type
typedef int16_t Integer;
#if USE_LONGINT
// long integer type
typedef int32_t LongInteger;
#endif
// floating point type
#if USE_REALS
typedef float Real;
#endif

/**
 * @brief lexical tokens
 */
enum class Token : uint8_t
{
	NOTOKENS = 0,
        KW_ARRAYS,     // 1
	KW_BASE,       // 2
	COM_CLS,       // 3
	KW_DATA,       // 4
	KW_DEF,        // 5
	COM_DELAY,     // 6
	KW_DIM,        // 7
	COM_DUMP,      // 8
	KW_END,        // 9
        KW_FALSE,      // 10
        KW_FOR,
	KW_GOSUB,
	KW_GOTO,
        KW_GO,
        KW_IF,
	KW_INPUT,
        KW_LET,
	COM_LIST,
	COM_LOAD,
	COM_NEW,
        KW_RANDOMIZE,
        KW_READ,
	KW_REM,
        KW_RETURN,
	COM_RUN,
	COM_SAVE,
	KW_TAB,
	KW_NEXT,
	KW_ON,
	KW_OPTION,
	KW_PRINT,
	KW_STOP,
	KW_STEP,
	KW_THEN,
	KW_TO,
	KW_TRUE,
	KW_VARS,

	OP_AND,
	OP_NOT,
	OP_OR,

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
	C_BOOLEAN,
	C_STRING,

	NUM_TOKENS
};

enum class ProgMemStrings : uint8_t
{
	S_STATIC = 0,
	S_DYNAMIC,
	S_ERROR,
	S_SEMANTIC,
	READY,
	BYTES,
	AVAILABLE,
	TERMINAL,
	S_TERMINAL_BASIC,
	S_VERSION,
	S_TEXT,
	S_OF,
	S_VARS,
	S_ARRAYS,
	S_STACK,
	S_DIR,
	S_REALLY,
	S_END,
	NUM_STRINGS
};

// Static text strings
extern PGM_P progmemString(ProgMemStrings);

/**
 * @brief Scan token table
 * @param token
 * @param table
 * @param index
 * @return find flag
 */
uint8_t *scanTable(const uint8_t*, const uint8_t[], uint8_t&);

}

#endif // BASIC_HPP
