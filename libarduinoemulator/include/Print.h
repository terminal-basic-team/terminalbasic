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

#ifndef _PRINT_H
#define _PRINT_H

#include <cstring>

#include <sstream>

#include "posix_io_tty.hpp"
#include "Printable.h"

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Print
{
public:
	
	size_t print(unsigned char, int = DEC);
	size_t print(char);
	size_t print(const char[]);
	size_t print(const Printable&);
	size_t print(int val, int base = DEC);
	size_t print(long n, int base = DEC);
	size_t print(double, int = 2);
	size_t print(unsigned int val, int base = DEC);
	size_t print(long unsigned int val, int base = DEC);
	uint16_t println(void);
	
	size_t println(const Printable&);
	size_t println(int, int = DEC);
	size_t println(unsigned int, int = DEC);
	size_t println(const char[]);
	virtual size_t write(uint8_t) = 0;
	
	size_t write(const uint8_t*, size_t);
	size_t write(const char *str) {
		if (str == NULL) return 0;
		return write((const uint8_t *)str, strlen(str));
	}
protected:
	size_t printNumber(unsigned long n, uint8_t base);
	size_t printFloat(double, uint8_t);
};

#endif
