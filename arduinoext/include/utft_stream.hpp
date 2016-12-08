#ifndef UTFT_STREAM_HPP
#define UTFT_STREAM_HPP

#include <memorysaver.h>
#include <UTFT.h>
#include "math.hpp"
#include "ringbuffer.hpp"

#define W 30
#define H 20

extern uint8_t SmallFont[];
extern uint8_t BigFont[];

class UTFTTerminal : public Print
{
public:
	UTFTTerminal(UTFT&);
	void begin();
	void end();
	void dump();
	void setPower(bool);
private:
	enum State_t : uint8_t
	{
		REGULAR, ESCAPE, I_BRAC, F_ATTR1
	};
	
	enum Attributes_t : uint8_t
	{
		RESET = 0x0,
		BRIGHT = 0x1,
		DIM = 0x2,
		UNDERSCORE = 0x4,
		BLINK = 5
	};
	
	void redraw();
	void insertChar(uint8_t);
	void printChar(uint8_t);
	void putChar(uint8_t);
	void addAttr(Attributes_t);
	void drawCursor(bool=true);
	void drawCurrent();
	
	UTFT &_screen;
	State_t	_state;
	CartesianCoordinates2D<uint8_t> _screenSizePixels;
	CartesianCoordinates2D<uint8_t> _screenSizeChars;
	CartesianCoordinates2D<uint8_t> _insertPosition;
	CartesianCoordinates2D<uint8_t> _cursorPosition;
	char		_data[H][W];
	char		_attr1;
	Attributes_t	_attributes;
// Print interface
public:
	size_t write(uint8_t) override;
};

#endif
