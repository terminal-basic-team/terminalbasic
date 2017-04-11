/*
Copyright (c) 2010 Myles Metzer

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
 */
/*
This library provides a simple method for outputting data to a tv
from a frame buffer stored in sram.  This implementation is done
completly by interupt and will return give as much cpu time to the
application as possible.
 */
#ifndef TVOUT_H
#define TVOUT_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "VideoGen.h"
#include "spec/HardwareSetup.h"
#include "spec/VideoProperties.h"

#include "cps.hpp"

enum Color_t : uint8_t
{
	NOT_A_COLOR = uint8_t(-1),
	BLACK = 0,
	WHITE = 1,
	INVERT = 2
};

enum Direction_t : uint8_t
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

// Macros for clearer usage
#define clearScreen()    fill(0)
#define invert(color)    fill(2)

/*
TVout.cpp contains a brief expenation of each function.
 */
class TVoutEx
{
	CPS_NOTCOPYABLE(TVoutEx)
public:
	uint8_t * screen;

	explicit TVoutEx();
	~TVoutEx();
	/**
	 * @brief overloaded version
	 * @param mode 
	 * @return Operation code
	 */
	//char begin(VideMode_t);
	
	/**
	 * @brief Init display
	 * @param mode PAL or NTSC
	 * @param x Horizontal resolution
	 * @param y Vertical resolution
	 * @param buf screen buffer pointer
	 * @param size
	 * @return code
	 */
	char begin(VideMode_t, uint8_t, uint8_t, uint8_t*, size_t);
	void end();

	//accessor functions
	unsigned char hres();
	unsigned char vres();
	char char_line();

	//flow control functions
	void delay_frame(unsigned int x);
	unsigned long millis();

	//override setup functions
	void force_vscale(char sfactor);
	void force_outstart(uint8_t time);
	void force_linestart(uint8_t line);

	//basic rendering functions
	void set_pixel(uint8_t x, uint8_t y, Color_t c);
	unsigned char get_pixel(uint8_t x, uint8_t y);
	void fill(Color_t color);
	void shift(uint8_t distance, Direction_t);
	void draw_line(uint8_t, uint8_t, uint8_t, uint8_t, Color_t c);
	void draw_row(uint8_t line, uint16_t x0, uint16_t x1, Color_t c);
	void draw_column(uint8_t row, uint16_t y0, uint16_t y1, Color_t c);
	void draw_rect(uint8_t x0, uint8_t y0, uint8_t w, uint8_t h, Color_t c, char fc = -1);
	void draw_circle(uint8_t, uint8_t, uint8_t, Color_t, Color_t = NOT_A_COLOR);
	void bitmap(uint8_t x, uint8_t y, const unsigned char * bmp, uint16_t i = 0, uint8_t width = 0, uint8_t lines = 0);

	//hook setup functions
	void set_vbi_hook(void (*func)());
	void set_hbi_hook(void (*func)());

	//tone functions
	void tone(unsigned int frequency, unsigned long duration_ms);
	void tone(unsigned int frequency);
	void noTone();

	//The following function definitions can be found in TVoutPrint.cpp
	//printing functions
	void print_char(uint8_t x, uint8_t y, unsigned char c);
	void set_cursor(uint8_t, uint8_t);
	void restore_cursor();

	void
	setCursorX(uint8_t x)
	{
		cursor_x = x;
	}

	uint8_t
	getCursorX() const
	{
		return (cursor_x);
	}

	uint8_t
	getCursorY() const
	{
		return (cursor_y);
	}
	void select_font(const unsigned char * f);

	void write(uint8_t);

	void printPGM(const char[]);
	void printPGM(uint8_t, uint8_t, const char[]);

private:
	static void vBlank();
	bool _cursorState, _lockCursor;
	uint8_t _cursorCounter;
	static TVoutEx	*_instance;
	
	uint8_t cursor_x, cursor_y;
	const unsigned char * font;

	void inc_txtline();
};

static void inline sp(unsigned char x, unsigned char y, char c);
#endif
