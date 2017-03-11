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
#include <libgen.h>
#include <iostream>

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
	return (true);
}

File
File::openNextFile(uint8_t mode)
{
	File result;
	if (this->_directory == NULL)
		return (result);
	
	dirent * e = readdir(_directory);
	if (e != NULL) {
		std::string path = _path + '/' + e->d_name;
		if (e->d_type == DT_REG)
			result._file = ::fopen(path.c_str(), "r+");
		else if (e->d_type == DT_DIR)
			result._directory = ::opendir(path.c_str());
		result._path = path;
	}
	
	return (result);
}

char*
File::name()
{
	return (::basename((char*)_path.c_str()));
}

uint32_t
File::size()
{
	return (0);
}

File
SDClass::open(const char* filename, uint8_t mode)
{
	File result;

	std::string path = std::string("./SD/") + filename;
	if (std::string(filename) == "/") {
		result._directory = ::opendir("./SD");
		result._path = "./SD";
		return (result);
	}

	char *dir = ::dirname((char*) path.c_str());
	std::string base = ::basename((char*) filename);
	DIR *d = opendir(dir);
	if (d != NULL)
		while (dirent * e = readdir(d)) {
			if (std::string(e->d_name) == base) {
				if (e->d_type == DT_REG)
					result._file = ::fopen(path.c_str(), "r+");
				else if (e->d_type == DT_DIR)
					result._directory = ::opendir(path.c_str());
				result._path = path;
			}
		}
	else
		throw;

	return (result);
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
	return ((_file != NULL) || (_directory != NULL));
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
	return ((_file == NULL) || (_directory != NULL));
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
