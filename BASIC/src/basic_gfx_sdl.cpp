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


#include "basic_gfx.hpp"

#if USE_GFX
#if !USETVOUT

#include <SDL2/SDL.h>
#include <stdexcept>

namespace BASIC
{
	
#define SDL_ASSERT(a) { if (!(a)) throw std::runtime_error(SDL_GetError()); }

static SDL_Window *window = nullptr;
static const uint8_t scale = 2;
static SDL_Renderer *renderer = nullptr;
	
static void
drawPoint(uint16_t x, uint16_t y)
{
	const uint16_t xs = x*scale+scale;
	const uint16_t ys = y*scale+scale;
	for (uint16_t _x = x*scale; _x<xs; ++_x)
		for (uint16_t _y=y*scale; _y<ys; ++_y)
			SDL_ASSERT(SDL_RenderDrawPoint(renderer, _x, _y) == 0);
}

void
GFXModule::_init()
{
	SDL_ASSERT(SDL_Init(SDL_INIT_VIDEO) == 0);
	
	SDL_ASSERT((window = SDL_CreateWindow("TERMINAL BASIC", 100,100,
	    scale*240, scale*192, 0)) != nullptr);
	
	SDL_ASSERT((renderer = SDL_CreateRenderer(window, -1, 0)) != nullptr);
	
	SDL_ASSERT(SDL_RenderClear(renderer) == 0);
	SDL_RenderPresent(renderer);
}

static void
circlePoints(uint8_t xc, uint8_t yc, int16_t x, int16_t y)
{
	drawPoint(xc+x, yc+y);
	drawPoint(xc+y, yc+x);
	drawPoint(xc+y, yc-x);
	drawPoint(xc+x, yc-y);
	drawPoint(xc-x, yc-y);
	drawPoint(xc-y, yc-x);
	drawPoint(xc-y, yc+x);
	drawPoint(xc-x, yc+y);
}

static void
circle(uint8_t xc, uint8_t yc, uint16_t r)
{
	int16_t x = 0;
	int16_t y = r;
	int16_t d = 1-r;
	int16_t d1 = 3;
	int16_t d2 = -2*r+5;
	
	circlePoints(xc, yc, x, y);
	
	while (y>x) {
		if (d<0) {
			d += d1;
			d1 += 2;
			d2 += 2;
			++x;
		} else {
			d += d2;
			d1 += 2;
			d2 += 4;
			++x;
			--y;
		}
		circlePoints(xc, yc, x, y);
	}
}

bool
GFXModule::command_circle(Interpreter &i)
{
	INT x,y,r;
	
	if (getIntegerFromStack(i, r)) {
		if (getIntegerFromStack(i, y)) {
			if (getIntegerFromStack(i, x)) {
				circle(x,y,r);
				SDL_RenderPresent(renderer);
				return true;
			}
		}
	}
	return false;
}

bool
GFXModule::command_color(Interpreter &i)
{
	INT c;
	
	if (getIntegerFromStack(i, c)) {
		return true;
	}
	return false;
}

bool
GFXModule::command_line(Interpreter &i)
{
	INT x1,y1,x2,y2;
	
	if (getIntegerFromStack(i, y2)) {
		if (getIntegerFromStack(i, x2)) {
			if (getIntegerFromStack(i, y1)) {
				if (getIntegerFromStack(i, x1)) {
					SDL_ASSERT(SDL_RenderDrawLine(renderer,
					    scale*x1, scale*y1, scale*x2, scale*y2) == 0);
					SDL_RenderPresent(renderer);
					return true;
				}
			}
		}
	}
	return false;
}

bool
GFXModule::command_lineto(Interpreter &i)
{
	INT x1,y1;
	
	if (getIntegerFromStack(i, y1)) {
		if (getIntegerFromStack(i, x1)) {
			return true;
		}
	}
	
	return false;
}

bool
GFXModule::command_point(Interpreter &i)
{
	INT x,y;
	
	if (getIntegerFromStack(i, y)) {
		if (getIntegerFromStack(i, x)) {
			drawPoint(x, y);
			SDL_RenderPresent(renderer);
			return true;
		}
	}
	return false;
}

bool
GFXModule::command_screen(Interpreter &i)
{
	INT x;
	
	if (getIntegerFromStack(i, x)) {
		if (x == 1) {

		} else if (x == 0) {

		} else
			return false;
		return true;
	}
	return false;
}

} // namespace BASIC

#endif // USETVOUT
#endif // USE_GFX
