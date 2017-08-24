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

#define USEUTFT		          0
#define USETVOUT	          0
#define USEPS2USARTKB             0

// Input select
#define S_INPUT SERIAL_I

// Output select
#define S_OUTPUT TVOUT_O
#if S_OUTPUT == TVOUT_O
#define SDL_DEBUG
#endif

#define BASIC_MULTITERMINAL       0
#if BASIC_MULTITERMINAL
#define SERIAL_PORT1 Serial1
#define SERIAL_PORT2 Serial2
#define SERIAL_PORT3 Serial3
#endif

namespace BASIC
{

// Number of bytes for program text, variables and stack
const uint16_t PROGRAMSIZE = 32768;

}

#endif
