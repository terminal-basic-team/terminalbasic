/*
 * This file is part of Terminal-BASIC: a lightweight BASIC-like language
 * interpreter.
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019-2021 Terminal-BASIC team
 *     <https://github.com/terminal-basic-team>
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

#include "basic.h"

/**
 * @brief lexical tokens
 */
typedef enum basic_token
{
	BASIC_TOKEN_NOTOKEN = 0,  // 0
	BASIC_TOKEN_KW_GOTO,      // 1
	BASIC_TOKEN_KW_GOSUB,     // 2
	BASIC_TOKEN_KW_THEN,      // 3
	BASIC_TOKEN_OP_AND,       // 4
#if USE_DUMP
	BASIC_TOKEN_KW_ARRAYS,    // 5
#endif
#if USE_SAVE_LOAD
	BASIC_TOKEN_COM_CHAIN,    // 6
#endif
#if USE_TEXTATTRIBUTES
	BASIC_TOKEN_COM_CLS,      // 7
#endif
#if USESTOPCONT
	BASIC_TOKEN_COM_CONT,     // 8
#endif
#if USE_MATRIX
	BASIC_TOKEN_KW_CON,       // 9
#endif
#if USE_DATA
	BASIC_TOKEN_KW_DATA,      // 10
#endif
#if USE_DEFFN
	BASIC_TOKEN_KW_DEF,       // 11
#endif
#if USE_DELAY
	BASIC_TOKEN_COM_DELAY,    // 12
#endif
#if USE_MATRIX
	BASIC_TOKEN_KW_DET,       // 13
#endif
	BASIC_TOKEN_KW_DIM,       // 14
#if USE_DIV_KW
	BASIC_TOKEN_KW_DIV,       // 15
#endif
#if USE_DUMP
	BASIC_TOKEN_COM_DUMP,     // 16
#endif
#if CONF_USE_ON_GOTO
	BASIC_TOKEN_KW_ON,        // 17
#endif
	BASIC_TOKEN_KW_FALSE,     // 18
	BASIC_TOKEN_KW_END,       // 19
#if USE_DEFFN
	BASIC_TOKEN_KW_FN,        // 20
#endif
#if CONF_SEPARATE_GO_TO
	BASIC_TOKEN_KW_GO,        // 21
#endif
#if USE_MATRIX
	BASIC_TOKEN_KW_IDN,       // 22
#endif
	BASIC_TOKEN_KW_INPUT,     // 23
#if USE_MATRIX
	BASIC_TOKEN_KW_INV,       // 24
#endif
	BASIC_TOKEN_KW_TO,        // 25
	BASIC_TOKEN_KW_LET,       // 26
	BASIC_TOKEN_COM_LIST,     // 27
#if USE_SAVE_LOAD
	BASIC_TOKEN_COM_LOAD,     // 28
#endif
#if USE_TEXTATTRIBUTES
	BASIC_TOKEN_COM_LOCATE,   // 29
#endif
#if USE_MATRIX
	BASIC_TOKEN_KW_MAT,       // 30
#endif
#if USE_INTEGER_DIV
	BASIC_TOKEN_KW_MOD,       // 31
#endif
	BASIC_TOKEN_COM_NEW,      // 32
	BASIC_TOKEN_OP_NOT,       // 34
//	KW_OPTION,
	BASIC_TOKEN_OP_OR,
#if USE_PEEK_POKE
	BASIC_TOKEN_KW_POKE,
#endif
	BASIC_TOKEN_KW_FOR,        // 36
	BASIC_TOKEN_KW_PRINT,      // 37
#if USE_RANDOM
	BASIC_TOKEN_KW_RANDOMIZE,  // 38
#endif
#if USE_DATA
	BASIC_TOKEN_KW_READ,       // 39
#endif
	BASIC_TOKEN_KW_REM,        // 43
#if USE_DATA
	BASIC_TOKEN_KW_RESTORE,    // 44
#endif
	BASIC_TOKEN_KW_RETURN,     // 45
	BASIC_TOKEN_COM_RUN,       // 46
#if USE_SAVE_LOAD
	BASIC_TOKEN_COM_SAVE,      // 47
#endif
	BASIC_TOKEN_KW_IF,         // 22
#if CONF_USE_SPC_PRINT_COM
	BASIC_TOKEN_KW_SPC,        // 48
#endif
	BASIC_TOKEN_KW_STEP,       // 49
#if USESTOPCONT
	BASIC_TOKEN_KW_STOP,       // 50
#endif
	BASIC_TOKEN_KW_NEXT,       // 33
#if USE_TEXTATTRIBUTES
	BASIC_TOKEN_KW_TAB,        // 51
#endif
#if USE_MATRIX
	BASIC_TOKEN_KW_TRN,        // 54
#endif
	BASIC_TOKEN_KW_TRUE,       // 55
#if USE_DUMP
	BASIC_TOKEN_KW_VARS,       // 56
#endif
	BASIC_TOKEN_OP_XOR,        // 57
#if USE_MATRIX
	BASIC_TOKEN_KW_ZER,        // 58
#endif
	// *
	BASIC_TOKEN_STAR,          // 59
	// /
	BASIC_TOKEN_SLASH,         // 50
#if USE_REALS && USE_INTEGER_DIV
	BASIC_TOKEN_BACK_SLASH,    // 61
#endif
	// +
	BASIC_TOKEN_PLUS,          // 62
	// -
	BASIC_TOKEN_MINUS,         // 63
	// =
	BASIC_TOKEN_EQUALS,        // 64
	// :
	BASIC_TOKEN_COLON,         // 65
	// ;
	BASIC_TOKEN_SEMI,          // 66
	// <
	BASIC_TOKEN_LT,            // 67
	// >
	BASIC_TOKEN_GT,            // 68
	// <=
	BASIC_TOKEN_LTE,           // 69
	// >=
	BASIC_TOKEN_GTE,           // 70
	// <>
	BASIC_TOKEN_NE,            // 71
#if CONF_USE_ALTERNATIVE_NE
	//  ><
	BASIC_TOKEN_NEA,           // 72
#endif
	// ,
	BASIC_TOKEN_COMMA,         // 73
	// ^
	BASIC_TOKEN_POW,           // 74
	// (
	BASIC_TOKEN_LPAREN,        // 75
	// )
	BASIC_TOKEN_RPAREN,        // 76

	BASIC_TOKEN_INTEGER_IDENT, // 77
	BASIC_TOKEN_REAL_IDENT,    // 78
#if USE_LONG_REALS
	BASIC_TOKEN_LONG_REAL_IDENT,// 85
#endif
#if USE_LONGINT        // 79
	BASIC_TOKEN_LONGINT_IDENT, // 80
#endif
	BASIC_TOKEN_STRING_IDENT,  // 81
	BASIC_TOKEN_BOOL_IDENT,    // 82

	BASIC_TOKEN_C_INTEGER,     // 83
#if USE_LONGINT
	BASIC_TOKEN_C_LONG_INTEGER,// 83
#endif
	BASIC_TOKEN_C_REAL,        // 84
#if USE_LONG_REALS
	BASIC_TOKEN_C_LONG_REAL,   // 85
#endif
	BASIC_TOKEN_C_BOOLEAN,     // 86
	BASIC_TOKEN_C_STRING,      // 87
#if FAST_MODULE_CALL
	BASIC_TOKEN_COMMAND,       // 88
#endif
	BASIC_TOKEN_NUM_TOKENS     // 88
} basic_token_t;
