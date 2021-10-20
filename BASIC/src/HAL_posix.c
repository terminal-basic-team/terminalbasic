/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019,2021 Terminal-BASIC team
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

#ifdef __unix__

#ifdef HAL_PC_TERMINAL

#include "HAL.h"

#include <pwd.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <termios.h>

#include <stdlib.h>
#include <stdio.h>

#include <sys/stat.h>
#include <sys/cdefs.h>
#include <time.h>

#include "HAL_pc.h"
#include "_HAL_pc.h"

void
HAL_initialize()
{
#if HAL_NVRAM || HAL_EXTMEM
	/* Initialize nvram and external memory directories */
	const char *homedir = NULL;
	if ((homedir = getenv("HOME")) == NULL) {
		struct passwd* p = getpwuid(getuid());
		if (p != NULL)
			homedir = p->pw_dir;
	}
	
	char root[256], fpath[256];
	strncpy(root, homedir, 255);
	strncat(root, HAL_PC_FILES_PATH, strlen(HAL_PC_FILES_PATH)+1);
	
	strncpy(fpath, root, 255);
	
	DIR *ucbasicHome = opendir(root);
	if (ucbasicHome == NULL)
		if (mkdir(root, 0770) == -1) {
			perror("mkdir");
			exit(EXIT_FAILURE);
		}
	
#endif /* HAL_NVRAM || HAL_EXTMEM */
#if HAL_NVRAM
	strcat(fpath, "/nvram.bin");
	
	nvram_file = open(fpath, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	if (nvram_file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
#endif /* HAL_NVRAM */
#if HAL_EXTMEM
	strncpy(ext_root, root, 255);
	strncat(ext_root, HAL_PC_EXTMEM_DIR_PATH, strlen(HAL_PC_EXTMEM_DIR_PATH)+1);
	DIR *ucbasicExtmem = opendir(ext_root);
	if (ucbasicExtmem == NULL)
		if (mkdir(ext_root, 0770) == -1) {
			perror("mkdir");
			exit(EXIT_FAILURE);
		}
	
	for (size_t i=0; i<HAL_EXTMEM_NUM_FILES; ++i)
		extmem_files[i] = -1;
#endif /* HAL_EXTMEM */
	
	struct termios TermConf;

	tcgetattr(STDIN_FILENO, &TermConf);
	TermConf.c_lflag &= ~(ICANON | ECHO);
	TermConf.c_cc[VMIN] = 1;
        TermConf.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &TermConf);
	
	if (atexit(&HAL_finalize) != 0) {
		perror("atexit");
		exit(EXIT_FAILURE);
	}
}

void
HAL_finalize()
{
#if HAL_NVRAM
	if (close(nvram_file) != 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
#endif // HAL_NVRAM
	
	struct termios TermConf;
	
	tcgetattr(STDIN_FILENO, &TermConf);
	TermConf.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &TermConf);
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

void
HAL_time_sleep_ms(uint32_t ms)
{
	struct timespec ts, rem;
	ts.tv_sec = ms / 1000;
	ts.tv_nsec = ms % 1000;
	if (clock_nanosleep(CLOCK_MONOTONIC, 0, &ts, &rem) != 0)
		perror("clock_nanosleep");
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

#endif /* HAL_EXTMEM */

void
HAL_terminal_write(HAL_terminal_t t, uint8_t b)
{
	if (t == 0) {
		putchar(b);
		fflush(stdout);
	}
}

uint8_t
HAL_terminal_read(HAL_terminal_t t)
{
	if (t == 0) {
		if (HAL_terminal_isdataready(t)) {
			uint8_t c = getchar();
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
		struct timeval tv;
		fd_set fds;
		tv.tv_sec = 0;
		tv.tv_usec = 0;
		FD_ZERO(&fds);
		FD_SET(STDIN_FILENO, &fds);
		select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
		return FD_ISSET(0, &fds);
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
	return rand() % max;
}

#endif /* HAL_LINUX */
#endif /* __unix__ */
