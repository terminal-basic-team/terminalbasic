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

#ifdef HAL_SDL

#include "HAL_sdl.h"

#include <SDL.h>

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

#if HAL_NVRAM
#define NVRAM_FILE "nvram.img"
#endif

#define EXTMEM_DIR_PATH "extmem/"

//static int extmem_files[EXTMEM_NUM_FILES];
static SDL_RWops* extmemFiles[EXTMEM_NUM_FILES];
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

//static char ext_root[256];

#if HAL_GFX
static const struct {Uint8 r,g,b,a;} colors[HAL_GFX_NUMCOLORS] = {
	{0,0,0,0}, /*HAL_GFX_NOTACOLOR = 0,*/
	{255,255,255,255}, /*HAL_GFX_COLOR_WHITE,*/
	{0,0,0,255}, /*HAL_GFX_COLOR_BLACK,*/
	{255,0,0,255}, /*HAL_GFX_COLOR_RED,*/
	{0,255,0,255}, /*HAL_GFX_COLOR_GREEN,*/
	{0,0,255,255}, /*HAL_GFX_COLOR_BLUE,*/
	{0,255,255,255}, /*HAL_GFX_COLOR_CYAN,*/
	{255,0,255,255}, /*HAL_GFX_COLOR_MAGENTA,*/
	{255,255,0,255}, /*HAL_GFX_COLOR_YELLOW,*/
	{127,127,127,255} /*HAL_GFX_COLOR_GRAY,*/
};
static HAL_gfx_color_t fgColor = HAL_GFX_NOTACOLOR;
static HAL_gfx_color_t bgColor = HAL_GFX_NOTACOLOR;
#endif /* HAL_GFX */

void
HAL_initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_Init: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
#if HAL_NVRAM
	/* Initialize nvram and external memory directories */
	SDL_RWops* nvram_file = SDL_RWFromFile(NVRAM_FILE, "r+");
	if (nvram_file == NULL) {
		nvram_file = SDL_RWFromFile(NVRAM_FILE, "w+");
		if (nvram_file == NULL) {
			SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWFromFile: %s",
			    SDL_GetError());
			exit(EXIT_FAILURE);
		}
	}
	
	if (SDL_RWclose(nvram_file) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWclose: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
#endif

	if (atexit(&HAL_finalize) != 0) {
		perror("atexit");
		exit(EXIT_FAILURE);
	}
	
	for (size_t i=0; i<EXTMEM_NUM_FILES; ++i)
		extmemFiles[i] = NULL;
	
	window = SDL_CreateWindow("Terminal-BASIC", 0,0, HAL_SDL_WIDTH,
	    HAL_SDL_HEIGHT, 0);
	if (window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_CreateWindow: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_CreateRenderer: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	if (SDL_RenderClear(renderer) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RenderClear: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_RenderPresent(renderer);
}

void
HAL_finalize()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
}

uint32_t
HAL_time_gettime_ms()
{
	return 	SDL_GetTicks();
}

#if HAL_NVRAM
uint8_t
HAL_nvram_read(HAL_nvram_address_t address)
{
	SDL_RWops* nvram_file = SDL_RWFromFile(NVRAM_FILE, "r");
	if (nvram_file == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWFromFile: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if (SDL_RWseek(nvram_file, (uint32_t)(address), RW_SEEK_SET) == -1) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWseek: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	uint8_t r;
	if (SDL_RWread(nvram_file, &r, 1, 1) == 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWread: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if (SDL_RWclose(nvram_file) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWclose: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	return r;
}

void
HAL_nvram_write(HAL_nvram_address_t address, uint8_t b)
{
	SDL_RWops* nvram_file = SDL_RWFromFile(NVRAM_FILE, "r+");
	if (nvram_file == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWFromFile: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Sint64 size = SDL_RWseek(nvram_file, 0, RW_SEEK_END);
	if (size == -1) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWseek: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	if (size > (Sint64)(address)) {
		if (SDL_RWseek(nvram_file, (Sint64)(address), RW_SEEK_SET) == -1) {
			SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWseek: %s",
			    SDL_GetError());
			exit(EXIT_FAILURE);
		}
	} else {
		Sint64 diff = (Sint64)(address) - size;
		char* buf = (char*)malloc(diff);
		if (SDL_RWwrite(nvram_file, buf, diff, 1) != diff) {
			SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWwrite: %s",
			    SDL_GetError());
			free(buf);
			exit(EXIT_FAILURE);
		}
		free(buf);
	}
	if (SDL_RWwrite(nvram_file, &b, 1, 1) == 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWwrite: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	if (SDL_RWclose(nvram_file) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWclose: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
}
#endif /* HAL_NVRAM */

#if HAL_EXTMEM
	
HAL_extmem_file_t
HAL_extmem_openfile(const char str[13])
{
	SDL_RWops* fp = SDL_RWFromFile(str, "r+");
	if (fp == NULL) {
		fp = SDL_RWFromFile(str, "w+");
		if (fp == NULL) {
			SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWFromFile: %s",
			    SDL_GetError());
			exit(EXIT_FAILURE);
		}
	}
	
	for (size_t i=0; i<EXTMEM_NUM_FILES; ++i) {
		if (extmemFiles[i] == NULL) {
			extmemFiles[i] = fp;
			return i+1;
		}
	}
	
	return 0;
}

void
HAL_extmem_deletefile(const char fname[13])
{
	unlink(fname);
}

void
HAL_extmem_closefile(HAL_extmem_file_t file)
{
	if ((file == 0)
	 || (file > EXTMEM_NUM_FILES)
	 || (extmemFiles[file-1] == NULL))
		return;
	
	if (SDL_RWclose(extmemFiles[file-1]) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWclose: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	extmemFiles[file-1] = NULL;
}

off_t
_seek(HAL_extmem_file_t file, Sint64 pos, int whence)
{
	if ((file == 0)
	 || (file > EXTMEM_NUM_FILES)
	 || (extmemFiles[file-1] == NULL))
		return 0;
	
	Sint64 res = SDL_RWseek(extmemFiles[file-1], pos, whence);
	if (res == -1) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWseek: %s",
		    SDL_GetError());
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
	 || (extmemFiles[file-1] == NULL))
		return 0;
	
	uint8_t r;
	if (SDL_RWread(extmemFiles[file-1], &r, 1, 1) == 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWread: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
	return r;
}

void
HAL_extmem_writetofile(HAL_extmem_file_t file, uint8_t byte)
{
	if ((file == 0)
	 || (file > EXTMEM_NUM_FILES)
	 || (extmemFiles[file-1] == NULL))
		return;
	
	if (SDL_RWwrite(extmemFiles[file-1], &byte, 1, 1) == 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_RWwrite: %s",
		    SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

uint16_t
HAL_extmem_getnumfiles()
{
	DIR *extRootDir = opendir("./");
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
	DIR *extRootDir = opendir("./");
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

BOOLEAN
HAL_extmem_fileExists(const char fname[13])
{
	SDL_RWops* tfile = SDL_RWFromFile(fname, "r");
	return tfile != NULL;
}

#endif /* HAL_EXTMEM */

#if HAL_GFX

void
_setColor(HAL_gfx_color_t color)
{
	SDL_SetRenderDrawColor(renderer, colors[color].r, colors[color].g,
	    colors[color].b, colors[color].a);
}

void
HAL_gfx_setColor(HAL_gfx_color_t color)
{
	fgColor = color;
	_setColor(color);
}

void
HAL_gfx_setBgColor(HAL_gfx_color_t color)
{
	bgColor = color;
}

void
HAL_gfx_point(uint16_t x, uint16_t y)
{
	SDL_RenderDrawPoint(renderer, x, y);
	SDL_RenderPresent(renderer);
}

void
HAL_gfx_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	SDL_RenderPresent(renderer);
}

void
HAL_gfx_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	SDL_Rect rect = { .x = x, .y = y, .w = w, .h = h };
	if (bgColor != HAL_GFX_NOTACOLOR) {
		_setColor(bgColor);
		SDL_RenderFillRect(renderer, &rect);
	}
	_setColor(fgColor);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

void
HAL_gfx_circle(uint16_t x0, uint16_t y0, uint16_t radius)
{
	int f = 1 - radius;
	int ddF_x = 1;
	int ddF_y = -2 * radius;
	int x = 0;
	int y = radius;
	uint8_t pyy = y, pyx = x;

	//there is a fill color
	if (bgColor != HAL_GFX_NOTACOLOR) {
		_setColor(bgColor);
		SDL_RenderDrawLine(renderer, x0 - radius, y0, x0 + radius, y0);
	}

	_setColor(fgColor);
	SDL_RenderDrawPoint(renderer, x0, y0 + radius);
	SDL_RenderDrawPoint(renderer, x0, y0 - radius);
	SDL_RenderDrawPoint(renderer, x0 + radius, y0);
	SDL_RenderDrawPoint(renderer, x0 - radius, y0);

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		//there is a fill color
		if (bgColor != HAL_GFX_NOTACOLOR) {
			//prevent double draws on the same rows
			_setColor(bgColor);
			if (pyy != y) {
				SDL_RenderDrawLine(renderer, x0 - x, y0 + y, x0 + x, y0 + y);
				SDL_RenderDrawLine(renderer, x0 - x, y0 - y, x0 + x, y0 - y);
			}
			if (pyx != x && x != y) {
				SDL_RenderDrawLine(renderer, x0 - y, y0 + x, x0 + y, y0 + x);
				SDL_RenderDrawLine(renderer, x0 - y, y0 - x, x0 + y, y0 - x);
			}
			pyy = y;
			pyx = x;
		}
		_setColor(fgColor);
		SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
		SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
		SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);
		SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);
	}
	SDL_RenderPresent(renderer);
}
#endif /* HAL_GFX */

#endif /* HAL_SDL */
