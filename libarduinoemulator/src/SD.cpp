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
	uint32_t result = 0;
	
	if (_file != NULL) {
		uint32_t tmp = ::ftell(_file);
		if (::fseek(_file, 0, SEEK_END) == 0) {
			result = ::ftell(_file);
			::fseek(_file, tmp, SEEK_SET);
		}
	}
	
	return (result);
}

File
SDClass::open(const char* filename, uint8_t mode)
{
	File result;

	std::string path = std::string("./SD/") + filename;
	if (std::string(filename) == "/") {
		result._directory = ::opendir("./SD");
		result._path = "./SD/";
		return (result);
	}

	std::string pathTmp(path.c_str());
	std::string base = ::basename((char*)pathTmp.c_str()); 
	
	pathTmp = path.c_str();
	char *dir = ::dirname((char*)pathTmp.c_str());
	DIR *d = ::opendir(dir);
	if (d != NULL)
		while (dirent * e = readdir(d)) {
			if (std::string(e->d_name) == base) {
				if (e->d_type == DT_REG)
					result._file = ::fopen(path.c_str(), "r+");
				else if (e->d_type == DT_DIR)
					result._directory = ::opendir(path.c_str());
				result._path = path;
				break;
			}
		}
	else
		throw;
	::closedir(d);
	if (!result)
		result._file = ::fopen(path.c_str(), "w+");
	
	return (result);
}

int
File::available()
{
	int result = 0;
	if (_file != NULL) {
		uint32_t current = ::ftell(_file);
		uint32_t end = this->size();
		result = end - current;
	}
	return (result);
}

void
File::close()
{
	if (_file != NULL) {
		::fclose(_file);
		_file = NULL;
	} else if (_directory != NULL) {
		::closedir(_directory);
		_directory = NULL;
	}
}

void
File::flush()
{
	if (_file != NULL)
		::fflush(_file);
}

File::operator bool()
{
	return ((_file != NULL) || (_directory != NULL));
}

int
File::peek()
{
	int result = -1;
	if (_file != NULL) {
		result = ::fgetc(_file);
		::ungetc(result, _file);
	}
	return (result);
}

int
File::read()
{
	if (_file)
		return (::fgetc(_file));
	else
		return (-1);
}

size_t
File::write(uint8_t c)
{
	if (_file) {
		::fputc(c, _file);
		return (1);
	} else
		return (0);
}

bool
File::isDirectory()
{
	return ((_file == NULL) || (_directory != NULL));
}

bool
SDClass::exists(const char* filepath)
{
	std::string path = std::string("./SD/")+filepath;
	FILE *temp;
	if ((temp = fopen(path.c_str(), "r")) != NULL) {
		fclose(temp);
		return (true);
	} else
		return (false);
}

bool
SDClass::remove(const char* filepath)
{
	return (::unlink((std::string("./SD/")+filepath).c_str()) == 0);
}

void
File::rewindDirectory()
{
	if (_directory != NULL)
		::rewinddir(_directory);
}

}
