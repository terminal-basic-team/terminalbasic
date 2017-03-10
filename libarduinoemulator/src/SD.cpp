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

#include <SD.h>

namespace SDLib
{

SDClass SD;

File::File() :
_file(NULL), _directory(NULL)
{
}

bool
SDClass::begin(uint8_t csPin)
{
	root._directory = opendir("./sd");
}

File
File::openNextFile(uint8_t mode)
{
}

char*
File::name()
{
}

uint32_t
File::size()
{
}

File
SDClass::open(const char* filename, uint8_t mode)
{
}

int
File::available()
{
	return (0);
}

void
File::close()
{

}

void
File::flush()
{

}

File::operator bool()
{
}

int
File::peek()
{
}

int
File::read()
{
}

size_t
File::write(uint8_t)
{
}

bool
File::isDirectory()
{
}

bool
SDClass::exists(const char* filepath)
{
}

bool
SDClass::remove(const char* filepath)
{
}

void
File::rewindDirectory()
{
}

}
