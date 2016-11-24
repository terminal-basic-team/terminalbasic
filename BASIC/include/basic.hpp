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
 * @brief SImple BASIC language interpreter package
 */
namespace BASIC
{
// Max size of the program line
const uint8_t PROGSTRINGSIZE = 64;
// Max size of the string constants/variables
const uint8_t STRINGSIZE = 32;
// Number of bytes for program text, variables and stack
const size_t PROGSIZE = 512;
// Number of characters in variable name
const uint8_t VARSIZE = 4; 
// integer type
typedef int16_t Integer;
// floating point type
typedef float Real;
}

#endif
