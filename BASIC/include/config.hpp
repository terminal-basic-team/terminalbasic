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

/**
 * Parameters
 */

/*
 * Real arithmetics
 * 
 * Support of operations with real numbers.
 * When enabled, all variables and arrays, which names are not ending with "$ ! %"
 * are treated as reals. Mathematical functions support depend on this option
 */
#define USE_REALS             1

#if USE_REALS
/*
 * Mathematical functions support
 */
#define USEMATH 	        1

#if USEMATH
/*
 * SIN COS TAN COT
 */
#define M_TRIGONOMETRIC         1
/*
 */
#define M_REVERSE_TRIGONOMETRIC	1 // ACS ASN ATN
#endif

#define USE_LONGINT           0 // Long integer support
#define USE_DUMP              1 // DUMP command support
#define CLEAR_PROGRAM_MEMORY  1 // Clear program memory on NEW
#define USE_RANDOM            1 // Clear program memory with 0xFF on NEW
#define USE_MATRIX            1 // Matrix operations
#define USE_EXTEEPROM         0 // External EEPROM functions module
#define USE_TEXTATTRIBUTES    1 // Use vt100 text attributes
#if USE_TEXTATTRIBUTES
#define USE_COLORATTRIBUTES   1 // Use vt100 color attributes
#endif
#define USE_SAVE_LOAD         1 // SAVE, LOAD and CHAIN commands support
#if USE_SAVE_LOAD
#define SAVE_LOAD_CHECKSUM    0 // Compute checksums while SAVE, LOAD and CHAIN
#endif
#define USESTOPCONT           1
#define AUTOCAPITALIZE        0 // Convert all input to upper register

#endif
