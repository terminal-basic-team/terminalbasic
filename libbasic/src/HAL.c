/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019,2020 Terminal-BASIC team
 *     <https://bitbucket.org/%7Bf50d6fee-8627-4ce4-848d-829168eedae5%7D/>
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

#include "HAL.h"

void
HAL_nvram_write_buf(HAL_nvram_address_t address, const void* buf, uint32_t size)
{
	const uint8_t* bp = (const uint8_t*)buf;
    HAL_nvram_address_t a;
    for (a=address; a<address+size; ++a)
		HAL_nvram_write(a, *(bp++));
}

void
HAL_nvram_read_buf(HAL_nvram_address_t address, void* buf, uint32_t size)
{
	uint8_t* bp = (uint8_t*)buf;
    HAL_nvram_address_t a;
    for (a=address; a<address+size; ++a)
		*(bp++) = HAL_nvram_read(a);
}
