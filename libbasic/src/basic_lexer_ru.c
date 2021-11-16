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

#include "avr/pgmspace.h"
#include "basic_config.h"
#include "basic.h"

#if CONF_LEXER_LANG == LANG_RU

const uint8_t _basic_lexer_symbolsShift PROGMEM = (uint8_t)('�')-'A';

const uint8_t _basic_lexer_tokenTable[] PROGMEM = {
	ASCII_NUL,
#if USE_DUMP
	'A', 'R', 'R', 'A', 'Y', 'S',ASCII_NUL, // 2
#endif
#if USE_SAVE_LOAD
	'C', 'H', 'A', 'I', 'N', ASCII_NUL,      // 4
#endif
#if USE_TEXTATTRIBUTES
	'C', 'L', 'S', ASCII_NUL,                // 5
#endif
#if USESTOPCONT
	'C', 'O', 'N', 'T', ASCII_NUL,           // 6
#endif
#if USE_MATRIX
	'C', 'O', 'N', ASCII_NUL,                // 7
#endif
#if USE_DELAY
	'D', 'E', 'L', 'A', 'Y', ASCII_NUL,      // 10
#endif
#if USE_MATRIX
	'D', 'E', 'T', ASCII_NUL,                // 11
#endif
#if USE_DIV_KW
	'D', 'I', 'V', ASCII_NUL,                // 13
#endif
#if USE_DUMP
	'D', 'U', 'M', 'P', ASCII_NUL,           // 15
#endif
	'F', 'A', 'L', 'S', 'E', ASCII_NUL,
	'G', 'O', 'S', 'U', 'B', ASCII_NUL,      // 20
#if CONF_SEPARATE_GO_TO
	'G', 'O', ASCII_NUL,                     // 12
#endif
#if USE_MATRIX
	'I', 'D', 'N', ASCII_NUL,
	'I', 'N', 'V', ASCII_NUL,
#endif
#if USE_SAVE_LOAD
	'L', 'O', 'A', 'D', ASCII_NUL,           // 20
#endif
#if USE_TEXTATTRIBUTES
	'L', 'O', 'C', 'A', 'T', 'E', ASCII_NUL, // 21
#endif
#if USE_INTEGER_DIV
	'M', 'O', 'D', ASCII_NUL,                // 24
#endif
#if USE_PEEK_POKE
	'P', 'O', 'K', 'E', ASCII_NUL,
#endif
#if USE_RANDOM
	'R', 'A', 'N', 'D', 'O', 'M', 'I', 'Z', 'E', ASCII_NUL, //26
#endif
#if USE_SAVE_LOAD
	'S', 'A', 'V', 'E', ASCII_NUL,
#endif
#if CONF_USE_SPC_PRINT_COM
	'S', 'P', 'C', ASCII_NUL,
#endif
#if USE_TEXTATTRIBUTES
	'T', 'A', 'B', ASCII_NUL,
#endif
#if USE_MATRIX
	'T', 'R', 'N', ASCII_NUL,
#endif
	'T', 'R', 'U', 'E', ASCII_NUL,
#if USE_DUMP
	'V', 'A', 'R', 'S', ASCII_NUL,
#endif
	'X', 'O', 'R', ASCII_NUL,
#if USE_MATRIX
	'Z', 'E', 'R',ASCII_NUL,
#endif
	'�', '�', '�', '�', ASCII_NUL,
#if USE_DATA
	'�', '�', '�', '�', '�', ASCII_NUL,
#endif
	'�', '�', '�', '�', '�', '�', '�', ASCII_NUL,
	'�', '�', '�', '�', '�', ASCII_NUL,
#if USE_DATA
	'�', '�', '�', '�', '�', '�', ASCII_NUL,
#endif
	'�', '�', '�', ASCII_NUL,
	'�', '�', ASCII_NUL,
	'�', '�', '�', '�', ASCII_NUL,
	'�', '�', '�', ASCII_NUL,
        '�', ASCII_NUL,
	'�', '�', '�', ASCII_NUL,
	'�', '�', '�', '�', '�', ASCII_NUL,
	'�', '�', '�', '�', '�', '�', '�',  ASCII_NUL,
#if USE_MATRIX
	'�', '�', '�', ASCII_NUL,                // 23
#endif
	'�', '�', ASCII_NUL,
	'�', '�', ASCII_NUL,
	'�', '�', '�', '�', '�', ASCII_NUL,      // 21
#if USE_DEFFN
	'�', '�', '�', ASCII_NUL,
#endif
#if CONF_USE_ON_GOTO
	'�', '�', '�', ASCII_NUL,
#endif
	'�', '�', '�', '�', ASCII_NUL,
	'�', '�', '�', '�', '�', ASCII_NUL,
	'�', '�', '�', '�', '�', '�', ASCII_NUL,
#if USE_DATA
	'�', '�', '�', '�', '�', ASCII_NUL,
#endif
#if USESTOPCONT
	'�', '�', '�', '�', ASCII_NUL,
#endif
	'�', '�', ASCII_NUL,
#if USE_DEFFN
	'�', '�', '�', '�', ASCII_NUL,
#endif
	'�', '�', '�', '�', ASCII_NUL,
	'�', '�', '�', ASCII_NUL,
	ASCII_ETX
};

#endif  // CONF_LEXER_LANG
