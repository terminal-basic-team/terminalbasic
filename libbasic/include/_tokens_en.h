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
	BASIC_TOKEN_OP_AND,       // 1
#if USE_DUMP
	BASIC_TOKEN_KW_ARRAYS,    // 2
#endif
#if USE_SAVE_LOAD
	BASIC_TOKEN_COM_CHAIN,     // 3
#endif
#if USE_TEXTATTRIBUTES
	BASIC_TOKEN_COM_CLS,       // 4
#endif
#if USESTOPCONT
	BASIC_TOKEN_COM_CONT,      // 6
#endif
#if USE_MATRIX
	BASIC_TOKEN_KW_CON,        // 7
#endif
#if USE_DATA
	BASIC_TOKEN_KW_DATA,       // 8
#endif
#if USE_DEFFN
	BASIC_TOKEN_KW_DEF,        // 9
#endif
#if USE_DELAY
	BASIC_TOKEN_COM_DELAY,     // 10
#endif
#if USE_MATRIX
	BASIC_TOKEN_KW_DET,        // 11
#endif
	BASIC_TOKEN_KW_DIM,        // 12
#if USE_DIV_KW
	BASIC_TOKEN_KW_DIV,        // 13
#endif
#if USE_DUMP
	BASIC_TOKEN_COM_DUMP,      // 15
#endif
	BASIC_TOKEN_KW_END,        // 16
	BASIC_TOKEN_KW_FALSE,      // 17
#if USE_DEFFN
	BASIC_TOKEN_KW_FN,         // 18
#endif
	BASIC_TOKEN_KW_FOR,        // 19
	BASIC_TOKEN_KW_GOSUB,      // 20
	BASIC_TOKEN_KW_GOTO,       // 21
#if CONF_SEPARATE_GO_TO
	BASIC_TOKEN_KW_GO,         // 22
#endif
#if USE_MATRIX
	BASIC_TOKEN_KW_IDN,        // 23
#endif
	BASIC_TOKEN_KW_IF,         // 24
	BASIC_TOKEN_KW_INPUT,      // 25
#if USE_MATRIX
	BASIC_TOKEN_KW_INV,        // 26
#endif
	BASIC_TOKEN_KW_LET,        // 27
	BASIC_TOKEN_COM_LIST,      // 28
#if USE_SAVE_LOAD
	BASIC_TOKEN_COM_LOAD,      // 29
#endif
#if USE_TEXTATTRIBUTES
	BASIC_TOKEN_COM_LOCATE,    // 30
#endif
#if USE_MATRIX
	BASIC_TOKEN_KW_MAT,        // 32
#endif
#if USE_INTEGER_DIV
	BASIC_TOKEN_KW_MOD,        // 33
#endif
	BASIC_TOKEN_COM_NEW,       // 34
	BASIC_TOKEN_KW_NEXT,       // 35
	BASIC_TOKEN_OP_NOT,        // 36
#if CONF_USE_ON_GOTO
	BASIC_TOKEN_KW_ON,         // 37
#endif
//	KW_OPTION,
	BASIC_TOKEN_OP_OR,         // 38
#if USE_PEEK_POKE
	BASIC_TOKEN_KW_POKE,       // 39
#endif
	BASIC_TOKEN_KW_PRINT,      // 40
#if USE_RANDOM
	BASIC_TOKEN_KW_RANDOMIZE,  // 41
#endif
#if USE_DATA
	BASIC_TOKEN_KW_READ,       // 42
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
#if CONF_USE_SPC_PRINT_COM
	BASIC_TOKEN_KW_SPC,        // 48
#endif
	BASIC_TOKEN_KW_STEP,       // 49
#if USESTOPCONT
	BASIC_TOKEN_KW_STOP,       // 50
#endif
#if USE_TEXTATTRIBUTES
	BASIC_TOKEN_KW_TAB,        // 51
#endif
	BASIC_TOKEN_KW_THEN,       // 52
	BASIC_TOKEN_KW_TO,         // 53
#if USE_MATRIX
	BASIC_TOKEN_KW_TRN,        // 54
#endif
	BASIC_TOKEN_KW_TRUE,        // 55
#if USE_DUMP
	BASIC_TOKEN_KW_VARS,        // 56
#endif
	BASIC_TOKEN_OP_XOR,         // 57
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
	BASIC_TOKEN_LONG_REAL_IDENT,// 79
#endif
#if USE_LONGINT
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
	BASIC_TOKEN_NUM_TOKENS     // 89
} basic_token_t;
