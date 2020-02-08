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

#ifdef __linux__

#include "HAL.h"

#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

#include <sys/stat.h>

#define FILES_PATH "/terminal_basic_HAL/"
#define NVRAM_FILE "nvram.img"

static int nvram_file = -1;

void HAL_initialize()
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
}

void HAL_finalize()
{
	if (close(nvram_file) != 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
}

uint8_t HAL_nvram_read(HAL_nvram_address_t address)
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

void HAL_nvram_write(HAL_nvram_address_t address, uint8_t b)
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

uint32_t HAL_time_gettime_ms()
{
	return 0;
}

#endif // __linux__
