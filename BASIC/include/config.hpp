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

/**
 * @file config.hpp
 * @brief Configuration parameters, common among versions
 */

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <stdint.h>

namespace BASIC
{

/*
 * Allow '_' symbol in identifiers
 */
#define ALLOW_UNDERSCORE_ID 0
	
/*
 * DELAY command, suspends execution for N ms
 */
#define USE_DELAY    1

/*
 * Real arithmetics
 * 
 * Support of operations with real numbers.
 * When enabled, all variables and arrays, which names are not ending with "$ ! %"
 * are treated as reals. Mathematical functions support depend on this option
 */
#define USE_REALS               1

#if USE_REALS
/*
 * Mathematical functions support
 */
#define USEMATH                 1

#if USEMATH
/*
 * SIN COS TAN COT
 */
#define M_TRIGONOMETRIC         1
/*
 * ACS ASN ATN
 */
#define M_REVERSE_TRIGONOMETRIC 1
/*
 * CBR (cubic root) ...
 */
#define M_ADDITIONAL            1
#endif // USEMATH

#endif // USE_REALS

// Use string functions and operations
#define USE_STRINGOPS      1
	
#if USE_STRINGOPS
// GET$ function, returns string from last pressed key symbol
#define USE_GET            1
// CHR$ function, returns string from the parameter ASCII code
#define USE_CHR            1
// ASC function, returns code of the first symbol in a string
#define USE_ASC            1
// LEN function, returns length of the string
#define USE_LEN            1
#endif

/**
 * Allow GO TO OPERATOR in addition to GOTO
 */
#define CONF_SEPARATE_GO_TO     0
/*
 * Use >< as not-equals operator (with default <>)
 */
#define CONF_USE_ALTERNATIVE_NE 1
/*
 * Support of 4-byte integer datatype
 * Functions, variables and arrays of long integer type ends with double % mark
 */
#define USE_LONGINT          0
/**
 * DUMP command support
 * This command can be used to see BASIC memory image, variables and arrays list
 */
#define USE_DUMP             0
/*
 * Clear program memory on NEW command
 */
#define CLEAR_PROGRAM_MEMORY 1
/*
 * RANDOMIZE command and RND() function support
 */
#define USE_RANDOM           1
/*
 * Support of Darthmouth BASIX-style matrix operations
 */
#define USE_MATRIX           0
/**
 * Support of DATA/READ statements
 */
#define USE_DATA             0
/*
 * Support of DEF FN construct
 */
#define USE_DEFFN            0
/*
 * Use vt100 text attributes
 */
#define USE_TEXTATTRIBUTES   1
#if USE_TEXTATTRIBUTES
/*
 * Use ANSI color attributes
 */
#define USE_COLORATTRIBUTES  0
/*
 * Support of SPC(N) print command
 */
#define CONF_USE_SPC_PRINT_COM  1
#endif // USE_TEXTATTRIBUTES

/*
 * SAVE, LOAD and CHAIN commands support
 */
#define USE_SAVE_LOAD        1
#if USE_SAVE_LOAD
// Compute checksums while SAVE, LOAD and CHAIN
#define SAVE_LOAD_CHECKSUM   1
#endif // USE_SAVE_LOAD
/*
 * STOP and CONTINUE commands support
 */
#define USESTOPCONT       1
// Convert all input to upper register
#define AUTOCAPITALIZE    0

/*
 * C++ level code optimisation mode
 */
#define OPT_SPEED     1 // Extensive use of switch/case constructs
#define OPT_SIZE      2 // Use cascade of if/else if instead of switch/case
#define OPT           OPT_SIZE // Selected mode

/*
 * SDcard module
 */
#define USESD         0

// Arduino IO module
#define CONF_MODULE_ARDUINOIO      1
#if CONF_MODULE_ARDUINOIO
// TONE command support
#define CONF_MODULE_ARDUINOIO_TONE 1
#endif // CONF_MODULE_ARDUINOIO

// External EEPROM functions module
#define USE_EXTEEPROM    0
#if USE_EXTEEPROM
/*
 * Size in bytes
 */
#define EXTEEPROM_SIZE   32768
#endif // USE_EXTEEPROM

/*
 * Structured loop support
 */
#define USE_DOLOOP       0
/*
 * Indention of the loop bodies
 */
#define LOOP_INDENT      0
/*
 * Indention of the line numbers in LIST output
 */
#define LINE_NUM_INDENT  1
/*
 * GFX module
 */
#define USE_GFX          0

/*
 * Input and output for single terminal mode
 */

// Input variants
#define SERIAL_I    1  // Serial input
#define SERIAL1_I   2  // Serial1 input
#define SERIALL_I   3  // SerialL input (non-buffering, interrupt-free)
#define SERIALL1_I  4  // SerialL1 input (non-buffering, interrupt-free)
#define SERIALL2_I  5  // SerialL2 input (non-buffering, interrupt-free)
#define SERIALL3_I  6  // SerialL3 input (non-buffering, interrupt-free)
#define PS2UARTKB_I 7  // PS/2 keyboard through USART
#define SDL_I       8  // SDL input on PC

// Output variants
#define SERIAL_O   1 // Serial output
#define SERIAL1_O  2 // Serial1 output
#define SERIALL_O  3 // SerialL output (non-buffering, interrupt-free)
#define SERIALL1_O 4 // SerialL1 output (non-buffering, interrupt-free)
#define SERIALL2_O 5 // SerialL2 output (non-buffering, interrupt-free)
#define SERIALL3_O 6 // SerialL3 output (non-buffering, interrupt-free)
#define UTFT_O     7 // UTFT library output
#define TVOUT_O    8 // TVoutEx library output
#define LIQCR_O    9 // LiquidCrystal library output
	#define TVOUT_HORIZ 240
	#define TVOUT_VERT 192

#if USE_EXTEEPROM
#define USE_WIRE 1
#else
#define USE_WIRE 0
#endif

/*
 * Max size of the program line
 */
const uint8_t PROGSTRINGSIZE = 73;

// Max size of the string constants/variables
const uint8_t STRINGSIZE = 65;

// Number of characters in variable name
const uint8_t VARSIZE = 5;

} // namespace BASIC

#endif // CONFIG_HPP
