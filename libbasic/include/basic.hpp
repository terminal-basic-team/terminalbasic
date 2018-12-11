/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * Copyright (C) 2017-2018 Andrey V. Skvortsov <starling13@mail.ru>
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

#include "basic.h"

namespace BASIC
{

/**
 * @brief lexical tokens
 */
enum class Token : uint8_t
{
	NOTOKENS = BASIC_TOKEN_NOTOKEN,    // 0
	OP_AND = BASIC_TOKEN_OP_AND,       // 1
#if USE_DUMP
	KW_ARRAYS = BASIC_TOKEN_KW_ARRAYS, // 2
#endif
//	KW_BASE,       // 3
#if USE_SAVE_LOAD
	COM_CHAIN = BASIC_TOKEN_COM_CHAIN, // 4
#endif
#if USE_TEXTATTRIBUTES
	COM_CLS = BASIC_TOKEN_COM_CLS,     // 5
#endif
#if USESTOPCONT
	COM_CONT = BASIC_TOKEN_COM_CONT,   // 6
#endif
#if USE_MATRIX
	KW_CON = BASIC_TOKEN_KW_CON,       // 7
#endif
#if USE_DATA
	KW_DATA = BASIC_TOKEN_KW_DATA,     // 8
#endif
#if USE_DEFFN
	KW_DEF = BASIC_TOKEN_KW_DEF,       // 9
#endif
#if USE_DELAY
	COM_DELAY = BASIC_TOKEN_COM_DELAY,// 10
#endif
#if USE_MATRIX
	KW_DET = BASIC_TOKEN_KW_DET,      // 11
#endif
	KW_DIM = BASIC_TOKEN_KW_DIM,      // 12
#if USE_DIV_KW
	KW_DIV = BASIC_TOKEN_KW_DIV,      // 13
#endif
#if USE_DOLOOP
	KW_DO = BASIC_TOKEN_KW_DO,        // 14
#endif
#if USE_DUMP
	COM_DUMP = BASIC_TOKEN_COM_DUMP,  // 15
#endif
	KW_END = BASIC_TOKEN_KW_END,      // 16
	KW_FALSE = BASIC_TOKEN_KW_FALSE,  // 17
#if USE_DEFFN
	KW_FN = BASIC_TOKEN_KW_FN,        // 18
#endif
	KW_FOR = BASIC_TOKEN_KW_FOR,      // 19
	KW_GOSUB = BASIC_TOKEN_KW_GOSUB,  // 20
	KW_GOTO = BASIC_TOKEN_KW_GOTO,    // 21
#if CONF_SEPARATE_GO_TO
	KW_GO = BASIC_TOKEN_KW_GO,        // 22
#endif
#if USE_MATRIX
	KW_IDN = BASIC_TOKEN_KW_IDN,      // 23
#endif
	KW_IF = BASIC_TOKEN_KW_IF,        // 24
	KW_INPUT = BASIC_TOKEN_KW_INPUT,  // 25
#if USE_MATRIX
	KW_INV = BASIC_TOKEN_KW_INV,      // 26
#endif
	KW_LET = BASIC_TOKEN_KW_LET,      // 27
	COM_LIST = BASIC_TOKEN_COM_LIST,  // 28
#if USE_SAVE_LOAD
	COM_LOAD = BASIC_TOKEN_COM_LOAD,  // 29
#endif
#if USE_TEXTATTRIBUTES
	COM_LOCATE = BASIC_TOKEN_COM_LOCATE,// 30
#endif
#if USE_DOLOOP
	KW_LOOP = BASIC_TOKEN_KW_LOOP,      // 31
#endif
#if USE_MATRIX
	KW_MAT = BASIC_TOKEN_KW_MAT,        // 32
#endif
#if USE_INTEGER_DIV
	KW_MOD = BASIC_TOKEN_KW_MOD,        // 33
#endif
	COM_NEW = BASIC_TOKEN_COM_NEW,      // 34
	KW_NEXT = BASIC_TOKEN_KW_NEXT,      // 35
	OP_NOT = BASIC_TOKEN_OP_NOT,        // 36
	KW_ON = BASIC_TOKEN_KW_ON,          // 37
//	KW_OPTION,     // 38
	OP_OR = BASIC_TOKEN_OP_OR,          // 39
	KW_PRINT = BASIC_TOKEN_KW_PRINT,    // 40
#if USE_RANDOM
	KW_RANDOMIZE = BASIC_TOKEN_KW_RANDOMIZE,// 41
#endif
#if USE_DATA
	KW_READ = BASIC_TOKEN_KW_READ,      // 42
#endif
	KW_REM = BASIC_TOKEN_KW_REM,        // 43
#if USE_DATA
	KW_RESTORE = BASIC_TOKEN_KW_RESTORE,// 44
#endif
	KW_RETURN = BASIC_TOKEN_KW_RETURN,  // 45
	COM_RUN = BASIC_TOKEN_COM_RUN,      // 46
#if USE_SAVE_LOAD
	COM_SAVE = BASIC_TOKEN_COM_SAVE,    // 47
#endif
#if CONF_USE_SPC_PRINT_COM
	KW_SPC = BASIC_TOKEN_KW_SPC,        // 48
#endif
	KW_STEP = BASIC_TOKEN_KW_STEP,      // 49
#if USESTOPCONT
	KW_STOP = BASIC_TOKEN_KW_STOP,      // 50
#endif
#if USE_TEXTATTRIBUTES
	KW_TAB = BASIC_TOKEN_KW_TAB,        // 51
#endif
	KW_THEN = BASIC_TOKEN_KW_THEN,      // 52
	KW_TO,         // 53
#if USE_MATRIX
	KW_TRN = BASIC_TOKEN_KW_TRN,        // 54
#endif
	KW_TRUE = BASIC_TOKEN_KW_TRUE,      // 55
#if USE_DUMP
	KW_VARS = BASIC_TOKEN_KW_VARS,      // 56
#endif
	OP_XOR = BASIC_TOKEN_OP_XOR,        // 57
#if USE_MATRIX
	KW_ZER = BASIC_TOKEN_KW_ZER,        // 58
#endif
	// *
	STAR = BASIC_TOKEN_STAR,          // 59
	// /
	SLASH = BASIC_TOKEN_SLASH,         // 50
#if USE_REALS && USE_INTEGER_DIV
	BACK_SLASH = BASIC_TOKEN_BACK_SLASH,    // 61
#endif
	// +
	PLUS = BASIC_TOKEN_PLUS,          // 62
	// -
	MINUS = BASIC_TOKEN_MINUS,         // 63
	// =
	EQUALS = BASIC_TOKEN_EQUALS,        // 64
	// :
	COLON = BASIC_TOKEN_COLON,         // 65
	// ;
	SEMI = BASIC_TOKEN_SEMI,          // 66
	// <
	LT = BASIC_TOKEN_LT,            // 67
	// >
	GT = BASIC_TOKEN_GT,            // 68
	// <=
	LTE = BASIC_TOKEN_LTE,           // 69
	// >=
	GTE = BASIC_TOKEN_GTE,           // 70
	// <>
	NE = BASIC_TOKEN_NE,            // 71
#if CONF_USE_ALTERNATIVE_NE
	//  ><
	NEA = BASIC_TOKEN_NEA,           // 72
#endif
	// ,
	COMMA = BASIC_TOKEN_COMMA,         // 73
	// ^
	POW = BASIC_TOKEN_POW,           // 74
	// (
	LPAREN = BASIC_TOKEN_LPAREN,        // 75
	// )
	RPAREN = BASIC_TOKEN_RPAREN,        // 76

	INTEGER_IDENT = BASIC_TOKEN_INTEGER_IDENT, // 77
	REAL_IDENT = BASIC_TOKEN_REAL_IDENT,    // 78
#if USE_LONGINT        // 79
	LONGINT_IDENT = BASIC_TOKEN_LONGINT_IDENT, // 80
#endif
	STRING_IDENT = BASIC_TOKEN_STRING_IDENT,  // 81
	BOOL_IDENT = BASIC_TOKEN_BOOL_IDENT,    // 82

	C_INTEGER = BASIC_TOKEN_C_INTEGER,     // 83
	C_REAL = BASIC_TOKEN_C_REAL,           // 84
	C_BOOLEAN = BASIC_TOKEN_C_BOOLEAN,     // 85
	C_STRING = BASIC_TOKEN_C_STRING,       // 86

	NUM_TOKENS = BASIC_TOKEN_NUM_TOKENS    // 87
};

} // namespace BASIC

#endif /* BASIC_HPP */
