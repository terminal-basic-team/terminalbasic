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

#ifdef HAL_LINUX

#ifndef __linux__
#error "__linux__ macro not defined"
#endif

#include "HAL.h"

#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

#include <sys/stat.h>
#include <time.h>

#define FILES_PATH "/terminal_basic_HAL/"
#define NVRAM_FILE "nvram.img"

#define EXTMEM_NUM_FILES 8
#define EXTMEM_DIR_PATH "extmem/"

static int nvram_file = -1;
static int extmem_files[EXTMEM_NUM_FILES];

static char ext_root[256];

void
HAL_initialize()
{
	/* Initialize nvram and external memory directories */
	const char *homedir = NULL;
	if ((homedir = getenv("HOME")) == NULL) {
		struct passwd* p = getpwuid(getuid());
		if (p != NULL)
			homedir = p->pw_dir;
	}
	
	char root[256], fpath[256];
	strncpy(root, homedir, 256);
	strncat(root, FILES_PATH, strlen(FILES_PATH));
	
	strncpy(fpath, root, 256);
	strncat(fpath, NVRAM_FILE, strlen(NVRAM_FILE));
	
	DIR *ucbasicHome = opendir(root);
	if (ucbasicHome == NULL)
		if (mkdir(root, 0770) == -1) {
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
	
	strncpy(ext_root, root, 256);
	strncat(ext_root, EXTMEM_DIR_PATH, strlen(EXTMEM_DIR_PATH));
	DIR *ucbasicExtmem = opendir(ext_root);
	if (ucbasicExtmem == NULL)
		if (mkdir(ext_root, 0770) == -1) {
			perror("mkdir");
			exit(EXIT_FAILURE);
		}
	
	for (size_t i=0; i<EXTMEM_NUM_FILES; ++i)
		extmem_files[i] = -1;
}

void
HAL_finalize()
{
	if (close(nvram_file) != 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
}

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

HAL_extmem_file_t
HAL_extmem_openfile(const char* str)
{
	char fpath[256];
	strncpy(fpath, ext_root, 256);
	strncat(fpath, str, 256);
	
	int fp = open(fpath, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	if (fp == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	
	for (size_t i=0; i<EXTMEM_NUM_FILES; ++i) {
		if (extmem_files[i] == -1) {
			extmem_files[i] = fp;
			return i+1;
		}
	}
	
	return 0;
}

void
HAL_extmem_deletefile(const char* str)
{
	unlink(str);
}

void
HAL_extmem_closefile(HAL_extmem_file_t file)
{
	if ((file == 0)
	 || (file > EXTMEM_NUM_FILES)
	 || (extmem_files[file-1] == -1))
		return;
	
	if (close(extmem_files[file-1]) != 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	extmem_files[file-1] = -1;
}

off_t
_seek(HAL_extmem_file_t file, off_t pos, int whence)
{
	if ((file == 0)
	 || (file > EXTMEM_NUM_FILES)
	 || (extmem_files[file-1] == -1))
		return 0;
	
	off_t res = lseek(extmem_files[file-1], pos, whence);
	if (res == -1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	
	return res;
}

HAL_extmem_fileposition_t
HAL_extmem_getfileposition(HAL_extmem_file_t file)
{
	return _seek(file, 0, SEEK_CUR);
}

void
HAL_extmem_setfileposition(HAL_extmem_file_t file,
    HAL_extmem_fileposition_t pos)
{
	_seek(file, pos, SEEK_SET);
}

HAL_extmem_fileposition_t
HAL_extmem_getfilesize(HAL_extmem_file_t file)
{
	off_t current = _seek(file, 0, SEEK_CUR);
	off_t result =  _seek(file, 0, SEEK_END);
	_seek(file, current, SEEK_SET);
	
	return result;
}

uint8_t
HAL_extmem_readfromfile(HAL_extmem_file_t file)
{
	if ((file == 0)
	 || (file > EXTMEM_NUM_FILES)
	 || (extmem_files[file-1] == -1))
		return 0;
	
	char result = '\0';
	if (read(extmem_files[file-1], &result, 1) != 1)
		fputs("HAL error \"read\": Can't read from file", stderr);
	
	return result;
}

void
HAL_extmem_writetofile(HAL_extmem_file_t file, uint8_t byte)
{
	if ((file == 0)
	 || (file > EXTMEM_NUM_FILES)
	 || (extmem_files[file-1] == -1))
		return;
	
	if (write(extmem_files[file-1], &byte, 1) != 1)
		fputs("HAL error \"write\": Can't write to file", stderr);
}

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
		if (de->d_type == DT_DIR)
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
		if (de->d_type == DT_DIR)
			continue;
		if (num == 0) {
			strncpy(name, de->d_name, 12);
			break;
		}
		num--;
	}
	if (num > 0) {
		name[0] = '\0';
		return;
	}
}

#endif /* HAL_LINUX */
