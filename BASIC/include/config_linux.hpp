/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
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

#ifndef CONFIG_LINUX_HPP
#define CONFIG_LINUX_HPP

#include <cstdint>

// Tokenize keywords in program text
const bool TOKENIZE = true;

// Max size of the program line
const uint8_t PROGSTRINGSIZE = 80;

// Number of bytes for program text, variables and stack
const size_t PROGRAMSIZE = 4096;

// Max size of the string constants/variables
const uint8_t STRINGSIZE = 128;

// Number of characters in variable name
const uint8_t VARSIZE = 16;

// USe long integer
#define USE_LONGINT 1

#endif
