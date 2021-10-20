/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019,2021 Terminal-BASIC team
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

#ifdef ARDUINO_ARCH_SAM

#include "HAL.h"

void
HAL_initialize()
{
}

void
HAL_finalize()
{
}

HAL_nvram_address_t HAL_nvram_getsize()
{
	return 0;
}

uint8_t HAL_nvram_read(HAL_nvram_address_t)
{
	return 0;
}

void HAL_nvram_write(HAL_nvram_address_t, uint8_t)
{
}

#endif // ARDUINO_ARCH_SAM
