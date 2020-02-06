#ifndef __linux__
#error "This file requires __linux__ to be defined"
#endif

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
