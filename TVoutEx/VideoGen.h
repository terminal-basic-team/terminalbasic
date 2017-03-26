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

#ifndef VIDEO_GEN_H
#define VIDEO_GEN_H

enum VideMode_t : uint8_t
{
	NTSC = 0,
	PAL = 1
};

struct TVoutVid
{
	volatile int scanLine;
	volatile unsigned long frames;
	unsigned char start_render;
	int lines_frame;	  	//remove me
	uint8_t vres;
	uint8_t hres;
	uint8_t output_delay; 	//remove me
	char vscale_const;		//combine me with status switch
	char vscale;			//combine me too.
	char vsync_end;			//remove me
	uint8_t *screen;
	size_t size() const { return (hres*vres); }
};

extern TVoutVid display;
extern void (*hbi_hook)();
extern void (*vbi_hook)();

void renderSetup(VideMode_t mode, uint8_t x, uint8_t y, uint8_t *scrnptr);

void blankLine();
void activeLine();
void vsyncLine();
void emptyFunction();

//tone generation properties
extern volatile long remainingToneVsyncs;

// 6cycles functions
void renderLine6c();
void renderLine5c();
void renderLine4c();
void renderLine3c();
static void inline waitUntil(uint8_t time);
#endif
