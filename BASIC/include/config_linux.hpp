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

#ifndef CONFIG_LINUX_HPP
#define CONFIG_LINUX_HPP

#include <stdint.h>

/**
 * Paraeters
 */
#define USE_REALS             1 // Real arithmetics
#define USE_LONGINT           1 // Long integer support
#define USE_DUMP              1 // DUMP command support
#define CLEAR_PROGRAM_MEMORY  1 // Clear program memory on NEW
#define USE_RANDOM            1 // Clear program memory with 0xFF on NEW
#define USE_MATRIX            1 // Matrix operations
#define USE_EXTEEPROM         1

#define USE_SAVE_LOAD	      1 // SAVE and LOAD commands support
#if USE_SAVE_LOAD
#define SAVE_LOAD_CHECKSUM    1
#endif

/**
 * Used modules
 */
/*
 * Math module (requires USE_REALS)
 */
#define USEMATH 	        1
#if USEMATH
#define M_TRIGONOMETRIC         1 // SIN COS TAN COT
#define M_REVERSE_TRIGONOMETRIC	1 // ACS ASN ATN
#endif

#define USEARDUINOIO	      1 // ARduino IO
#define USESD		      1 // SD card module

#define SERIAL_PORT Serial

namespace BASIC
{

// Tokenize keywords in program text
const bool TOKENIZE = true;

// Max size of the program line
const uint8_t PROGSTRINGSIZE = 80;

// Number of bytes for program text, variables and stack
const size_t PROGRAMSIZE = 32768;

// Max size of the string constants/variables
const uint8_t STRINGSIZE = 64;

// Number of characters in variable name
const uint8_t VARSIZE = 16;

}

#define BASIC_MULTITERMINAL 0

#endif
