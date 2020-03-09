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

#ifdef ARDUINO

// configuration
#define USE_SD_EXTMEM 1
#define EXTMEM_FILENUM 5
// ~configuration

#include <string.h>

#include "HAL.h"
#include "Arduino.h"
#if USE_SD_EXTMEM
#include "sd.hpp"
#endif

__BEGIN_DECLS
void
HAL_initialize_concrete();
__END_DECLS

void
HAL_initialize()
{
#if USE_SD_EXTMEM
	if (!SDCard::SDFS.begin())
		abort();
#endif
	HAL_initialize_concrete();
}

void
HAL_time_sleep_ms(uint32_t ms)
{
	delay(ms);
}

uint32_t
HAL_time_gettime_ms()
{
	return millis();
}	

#if USE_SD_EXTMEM

static SDCard::File files[EXTMEM_FILENUM];

static SDCard::File
getRoorDir()
{
	SDCard::File root = SDCard::SDFS.open("/",
	    SDCard::Mode::WRITE | SDCard::Mode::READ | SDCard::Mode::CREAT);
	if (!root || !root.isDirectory())
		abort();
}

HAL_extmem_file_t
HAL_extmem_openfile(const char path[13])
{
	uint8_t i=0;
	for (; i<EXTMEM_FILENUM; ++i) {
		if (!files[i])
			break;
	}
	if (i<EXTMEM_FILENUM) {
		files[i] = SDCard::SDFS.open(path, SDCard::Mode::CREAT|SDCard::Mode::WRITE|
		    SDCard::Mode::READ);
		if (files[i])
			return i+1;
	}
	return 0;
}

HAL_extmem_fileposition_t
HAL_extmem_getfilesize(HAL_extmem_file_t f)
{
	if ((f > 0) && files[f-1])
		return files[f-1].size();
	return 0;
}

HAL_extmem_fileposition_t
HAL_extmem_getfileposition(HAL_extmem_file_t f)
{
	if ((f > 0) && files[f-1])
		return files[f-1].position();
	return 0;
}

void
HAL_extmem_setfileposition(HAL_extmem_file_t f, HAL_extmem_fileposition_t pos)
{
	if ((f > 0) && files[f-1])
		return files[f-1].seek(pos);
	return 0;
}

uint8_t
HAL_extmem_readfromfile(HAL_extmem_file_t f)
{
	if ((f > 0) && files[f-1])
		return files[f-1].read();
	return 0;
}

void
HAL_extmem_writetofile(HAL_extmem_file_t f, uint8_t b)
{
	if ((f > 0) && files[f-1])
		files[f-1].write(b);
}

void
HAL_extmem_closefile(HAL_extmem_file_t f)
{
	if ((f > 0) && files[f-1]) {
		files[f-1].close();
	}
}

uint16_t
HAL_extmem_getnumfiles()
{
	uint16_t result = 0;
	auto root = getRoorDir();
	root.rewindDirectory();
	SDCard::File f;
	while (f=root.openNextFile(SDCard::Mode::READ_ONLY)) {
		++result;
		f.close();
	}
	return result;
}

void
HAL_extmem_getfilename(uint16_t num, char path[13])
{
	auto root = getRoorDir();
	root.rewindDirectory();
	SDCard::File f;
	uint16_t n = num;
	while (f=root.openNextFile(SDCard::Mode::READ_ONLY)) {
		if (n-- == 0) {
			strncpy(path, f.name(), 13);
			f.close();
			return;
		}
		f.close();
	}
}

void
HAL_extmem_deletefile(const char* path)
{
	SDCard::SDFS.remove(path);
}
#endif // USE_SD_EXTMEM

#endif // ARDUINO
