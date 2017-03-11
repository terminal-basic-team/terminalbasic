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

#ifndef SD_H
#define SD_H

#include <Stream.h>
#include "posixcpp/posix_io_file.hpp"

#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>

#define FILE_READ O_RDONLY
#define FILE_WRITE (O_RDWR | O_CREAT)

namespace SDLib
{

class File : public Stream
{
public:

	File();

	int available() override;
	void flush() override;
	int peek() override;
	int read() override;
	size_t write(uint8_t) override;

	char * name();
	uint32_t size();
	void close();

	operator bool();
	bool isDirectory(void);
	void rewindDirectory(void);
	File openNextFile(uint8_t mode = O_RDONLY);
private:
	friend class SDClass;
	DIR *_directory;
	FILE *_file;
	std::string _path;
};

class SDClass
{
public:
	bool begin(uint8_t csPin);
	File open(const char *filename, uint8_t mode = FILE_READ);
	bool remove(const char *filepath);
	bool exists(const char *filepath);
private:
	File root;
};

extern SDClass SD;

}

// This ensure compatibility with sketches that uses only SD library
using namespace SDLib;

// This allows sketches to use SDLib::File with other libraries (in the
// sketch you must use SDFile instead of File to disambiguate)
typedef SDLib::File SDFile;
typedef SDLib::SDClass SDFileSystemClass;
#define SDFileSystem   SDLib::SD

#endif /* SD_H */

