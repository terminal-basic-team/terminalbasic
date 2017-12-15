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

#include "Arduino.h"
#include "config.hpp"

// Use multiterminal mode
#define BASIC_MULTITERMINAL       0
#if BASIC_MULTITERMINAL
#define NUM_TERMINALS 1
#ifdef HAVE_HWSERIAL1
#define SERIAL_PORT1 Serial1
#undef NUM_TERMINALS
#define NUM_TERMINALS 2
#endif
#ifdef HAVE_HWSERIAL2
#define SERIAL_PORT2 Serial2
#undef NUM_TERMINALS
#define NUM_TERMINALS 3
#endif
#ifdef HAVE_HWSERIAL3
#define SERIAL_PORT3 Serial3
#undef NUM_TERMINALS
#define NUM_TERMINALS 4
#endif
#endif // BASIC_MULTITERMINAL

namespace BASIC
{

// Number of bytes for program text, variables and stack
const uint16_t PROGRAMSIZE = 32768;

#if BASIC_MULTITERMINAL
const uint16_t SINGLE_PROGSIZE = PROGRAMSIZE / NUM_TERMINALS;
#else
const uint16_t SINGLE_PROGSIZE = PROGRAMSIZE;
#endif

}

// BEGIN PRIVATE

#define USEUTFT	           0
#define USETVOUT           0
#define USEPS2USARTKB      0

// END PRIVATE

#endif
