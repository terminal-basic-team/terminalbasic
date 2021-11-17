/*
 * This file is part of Terminal-BASIC: a lightweight BASIC-like language
 * interpreter.
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019-2021 Terminal-BASIC team
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

#ifdef __MINGW32__

#ifdef HAL_PC_TERMINAL

#include "HAL.h"

#include <string.h>
#include <conio.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <windows.h>

#include <stdlib.h>
#include <stdio.h>

#include <sys/stat.h>
#include <time.h>

#include "_HAL_pc.h"
#include "HAL_pc.h"

HANDLE hStdin;

void
HAL_initialize()
{
#if HAL_NVRAM
	/* Initialize nvram and external memory directories */
	const char homedir[]="./";
	
	char root[256],  // root HAL directory
	     fpath[256]; // NVRAM file full path
	strncpy(root, homedir, 255);
	strncat(root, HAL_PC_FILES_PATH, strlen(HAL_PC_FILES_PATH));
	
	strncpy(fpath, root, 255);
	strcat(fpath, "/nvram.bin");
	
	// Open or create root HAL directory
	DIR *ucbasicHome = opendir(root);
	if (ucbasicHome == NULL)
		if (mkdir(root) == -1) {
			perror("mkdir");
			exit(EXIT_FAILURE);
		}
	
	nvram_file = open(fpath, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	if (nvram_file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	
	if (atexit(&HAL_finalize) != 0) {
		perror("atexit");
		exit(EXIT_FAILURE);
	}
#endif /* HAL_NVRAM */

#if HAL_EXTMEM
	strncpy(ext_root, root, 255);
	strncat(ext_root, HAL_PC_EXTMEM_DIR_PATH, strlen(HAL_PC_EXTMEM_DIR_PATH)+1);
	// Open or create extmem files directory
	DIR *ucbasicExtmem = opendir(ext_root);
	if (ucbasicExtmem == NULL)
		if (mkdir(ext_root) == -1) {
			perror("mkdir");
			exit(EXIT_FAILURE);
		}
	
	for (size_t i=0; i<HAL_EXTMEM_NUM_FILES; ++i)
		extmem_files[i] = -1;
#endif /* HAL_EXTMEM */
	
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
}

void
HAL_finalize()
{
#if HAL_NVRAM
	if (close(nvram_file) != 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
#endif /* HAL_NVRAM */
}

#if HAL_NVRAM
uint8_t
HAL_nvram_read(HAL_nvram_address_t address)
{
	if (lseek(nvram_file, (off_t)address, SEEK_SET) == (off_t)-1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	char buf;
	if (read(nvram_file, &buf, 1) == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	return buf;
}

void
HAL_nvram_write(HAL_nvram_address_t address, uint8_t b)
{
	if (lseek(nvram_file, (off_t)address, SEEK_SET) == (off_t)-1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	if (write(nvram_file, &b, 1) != 1) {
		perror("write");
		exit(EXIT_FAILURE);
	}
}
#endif // HAL_NVRAM

uint32_t
HAL_time_gettime_ms()
{
	struct timespec ts;
	if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
		perror("clock_gettime");
		exit(EXIT_FAILURE);
	}
	
	return ts.tv_sec * 1000l + ts.tv_nsec / 1000000l;
}

#if HAL_EXTMEM

uint16_t
HAL_extmem_getnumfiles()
{
	DIR *extRootDir = opendir(ext_root);
	if (extRootDir == NULL) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	
	uint16_t result = 0;
	
	struct dirent* de;
	while ((de = readdir(extRootDir)) != NULL) {
		struct stat lst;
		char path[256];
		strcpy(path, ext_root);
		strcat(path, "\\");
		strcat(path, de->d_name);
		if (stat(path, &lst) < 0)
			perror("stat");
		if (S_ISDIR(lst.st_mode))
			continue;
		result++;
	}
	
	return result;
}

void
HAL_extmem_getfilename(uint16_t num, char name[13])
{
	DIR *extRootDir = opendir(ext_root);
	if (extRootDir == NULL) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	
	struct dirent* de;
	while ((de = readdir(extRootDir)) != NULL) {
		struct stat lst;
		char path[256];
		strcpy(path, ext_root);
		strcat(path, "\\");
		strcat(path, de->d_name);
		if (stat(path, &lst) < 0)
			perror("stat");
		if (S_ISDIR(lst.st_mode))
			continue;
		if (num == 0) {
			strncpy(name, de->d_name, 12);
			break;
		}
		num--;
	}
	if (num > 0)
		name[0] = '\0';
	name[12] = '\0';
}

#endif /* HAL_EXTMEM */

void
HAL_terminal_write(HAL_terminal_t t, uint8_t b)
{
	if (t == 0) {
		putchar(b);
		fflush(stdout);
	}
}

static int storedchar = EOF;

uint8_t
HAL_terminal_read(HAL_terminal_t t)
{
	if (t == 0) {
		if (HAL_terminal_isdataready(t)) {
			uint8_t c = storedchar;
			//printf("x%x", c);
			storedchar = EOF;
			if (c == '\n')
				c = '\r';
			return c;
		}
	}
	return -1;
}

BOOLEAN
HAL_terminal_isdataready(HAL_terminal_t t)
{
	if (t == 0) {
		if (storedchar == EOF) {
			if (_kbhit()) {
				INPUT_RECORD rec;
				DWORD num;
				if (ReadConsoleInput(hStdin, &rec, 1, &num) && (num > 0)) {
					if (rec.EventType == KEY_EVENT) {
						const KEY_EVENT_RECORD* krec = &rec.Event.KeyEvent;
						if (krec->bKeyDown && (krec->uChar.AsciiChar > 0))
							storedchar = krec->uChar.AsciiChar;
					}
    				} else
					perror("ReadConsoleInput");
			}
		}
		return storedchar != EOF;
	}
	return FALSE;
}

void
HAL_random_seed(uint32_t seed)
{
	srand(seed);
}

uint32_t
HAL_random_generate(uint32_t max)
{
	return rand() * (INT32_MAX / RAND_MAX) % max;
}

void
HAL_time_sleep_ms(uint32_t ms)
{
	Sleep(ms);
}

#endif /* HAL_PC_TERMINAL */

#endif /* __MINGW32__ */
