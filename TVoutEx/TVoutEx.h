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
#include "spec/hardware_setup.h"
#include "spec/video_properties.h"

// macros for readability when selecting mode.

enum Color_t : uint8_t
{
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

#define BYTE 0

// Macros for clearer usage
#define clear_screen()				fill(BLACK)
#define invert(color)				fill(INVERT)


class Font
{
public:
	void setFont(const unsigned char *f)
	{
		_font = f;
	}
	uint8_t width() const;
	uint8_t height() const;
	uint8_t firstChar() const;
	const unsigned char *font() const;
private:
	const unsigned char *_font;
};

/*
TVout.cpp contains a brief expenation of each function.
*/
class TVoutEx
{
public:
	uint8_t * screen;
	
	char begin(VideMode_t, uint16_t=128u, uint16_t=96u);
	void end();
	
	//accessor functions
	uint16_t hres();
	uint16_t vres();
	char char_line();
	
	//flow control functions
	void delay(unsigned int x);
	void delay_frame(unsigned int x);
	unsigned long millis();
	
	//override setup functions
	void force_vscale(char sfactor);
	void force_outstart(uint8_t time);
	void force_linestart(uint8_t line);
	
	//basic rendering functions
	void set_pixel(uint8_t x, uint8_t y, char c);
	unsigned char get_pixel(uint8_t x, uint8_t y);
	void fill(Color_t color);
	void shift(uint8_t distance, Direction_t direction);
	void draw_line(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, char c);
	void draw_row(uint8_t line, uint16_t x0, uint16_t x1, uint8_t c);
	void draw_column(uint8_t row, uint16_t y0, uint16_t y1, uint8_t c);
	void draw_rect(uint8_t x0, uint8_t y0, uint8_t w, uint8_t h, char c, char fc = -1); 
	void draw_circle(uint8_t x0, uint8_t y0, uint8_t radius, char c, char fc = -1);
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
	void print_char(uint8_t x, uint8_t y, uint8_t c);
	void set_cursor(uint8_t, uint8_t);
	void select_font(const unsigned char * f);

	void write(uint8_t);
	
	void printPGM(const char[]);
	void printPGM(uint8_t, uint8_t, const char[]);
	
private:
	uint8_t cursor_x,cursor_y;
	Font	font;
	
	void inc_txtline();
};

static void inline sp(unsigned char x, unsigned char y, char c); 
#endif
