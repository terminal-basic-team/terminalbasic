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

#ifndef BASIC_H
#define BASIC_H

#include "sys/cdefs.h"
#include <stdint.h>

#include "basic_config.h"

#if USE_REALS
#include <math.h>
#endif

__BEGIN_DECLS

typedef uint8_t BOOLEAN;

#ifndef TRUE
#define TRUE ((BOOLEAN)1)
#endif

#ifndef FALSE
#define FALSE ((BOOLEAN)0)
#endif

/**
 * @brief ASCII characters
 */
typedef enum ascii_codes
{
	NUL = 0x00, /* Null */
	SOH = 0x01, /* Start of heading */
	STX = 0x02, /* Start of text */
	ETX = 0x03, /* End of text */
	EOT = 0x04, /* End of transmission */
	ENQ = 0x05, /* Enquire */
	ACK = 0x06, /* Acknowledgement */
	BEL = 0x07, /* Bell */
	BS = 0x08,  /* Backspace */
	HT = 0x09,  /* Horizontal tab */
	LF = 0x0A,  /* Line feed */
	VT = 0x0B,  /* Vertical tab */
	FF = 0x0C,  /* Form feed */
	CR = 0x0D,  /* Carriage return */
	SO = 0x0E,  /* Shift out */
	SI = 0x0F,  /* Shift in */
	DLE = 0x10, /* Data link escape */
	DC1 = 0x11, /* Device control 1 */
	DC2 = 0x12, /* Device control 2 */
	DC3 = 0x13, /* Device control 3 */
	DC4 = 0x14, /* Device control 4 */
	NAK = 0x15, /* Negative acknowledgement */
	SYN = 0x16, /* Synchronous idle */
	ETB = 0x17, /* End of transmission block */
	CAN = 0x18, /* Cancel */
	ESC = 0x1B, /* Escape */
	FS = 0x1C,  /* File separator */
	GS = 0x1D,  /* Group separator */
	RS = 0x1E,  /* Record separator */
	US = 0x1F,  /* Unit separator */
	SPACE = ' ',
	QMARK = '?',
	DOT = '.',
	COLON = ':',
	SEMICOLON = ';',
	QUMARK = '\"',
	LPAREN = '(',
	RPAREN = ')',
	COMMA = ',',
	GT = '>',
	LT = '<',
	TILDE = 0x7E,
	DEL = 0x7F
} ascii_codes_t;

typedef uint16_t pointer_t;
// integer type
typedef int16_t integer_t;
#define MAX_INTEGER (integer_t)(INT16_MAX)
#if USE_LONGINT
// long integer type
typedef int32_t long_integer_t;
#define MAX_LONG_INTEGER (long_integer_t)(INT32_MAX)
typedef long_integer_t INT;
#define MAXINT MAX_LONG_INTEGER
#else
typedef integer_t INT;
#define MAXINT MAX_INTEGER
#endif // USE_LONGINT
// floating point type
#if USE_REALS == REAL_SINGLE
typedef float real_t;
#define mf_pow powf
#elif USE_REALS == REAL_DOUBLE
typedef double real_t;
#define mf_pow pow
#endif

/* Size of the string identifiers */
#define STRING_SIZE 72

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
#if USE_DOLOOP
	BASIC_TOKEN_KW_DO,         // 14
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
#if USE_DOLOOP
	BASIC_TOKEN_KW_LOOP,       // 31
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
	BASIC_TOKEN_KW_ON,         // 37
//	KW_OPTION,     // 38
	BASIC_TOKEN_OP_OR,         // 39
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
#if USE_LONGINT        // 79
	BASIC_TOKEN_LONGINT_IDENT, // 80
#endif
	BASIC_TOKEN_STRING_IDENT,  // 81
	BASIC_TOKEN_BOOL_IDENT,    // 82

	BASIC_TOKEN_C_INTEGER,     // 83
	BASIC_TOKEN_C_REAL,        // 84
	BASIC_TOKEN_C_BOOLEAN,     // 85
	BASIC_TOKEN_C_STRING,      // 86

	BASIC_TOKEN_NUM_TOKENS     // 87
} basic_token_t;

/**
 * @brief Scan token table
 * @param token
 * @param table
 * @param index
 * @return find flag
 */
uint8_t *scanTable(const uint8_t*, const uint8_t[], uint8_t*);

__END_DECLS

#endif /* BASIC_H */

