#include <string.h>

#include "utft_stream.hpp"
#include "ascii.hpp"
#include "Arduino.h"
#include "bytearray.hpp"
#include "arduino_logger.hpp"

extern uint8_t SmallFont[];
extern uint8_t BigFont[];

UTFTTerminal::UTFTTerminal(UTFT &screen) :
_screen(screen)
{
}

void
UTFTTerminal::begin()
{
	_page = 1;
	_screen.InitLCD();
	_screen.setFont(BigFont);
	_screenSizePixels.data[0] = 480; _screenSizePixels.data[1] = 320;
	_screenSizeChars.data[0] =
		_screenSizePixels.get(CartesianCoordinates2D_t::X) /
		_screen.getFontXsize();
	_screenSizeChars.data[1] =
		_screenSizePixels.get(CartesianCoordinates2D_t::Y) /
		_screen.getFontYsize();
	_cursorPosition.set(0,0);
	memset(_data, 0, sizeof (_data));
	
	//_screen.setWritePage(_page);
	//_screen.setDisplayPage(_page);
	
	_screen.setColor(VGA_SILVER);
	_state = REGULAR;
	_screen.clrScr();
	drawCursor();
}

void
UTFTTerminal::end()
{
}

void
UTFTTerminal::dump()
{	
	ByteArray ba((uint8_t*)_data, sizeof (_data));
	Serial.println(ba);
}

void
UTFTTerminal::setPower(bool val)
{
	if (val)
		_screen.lcdOn();
	else
		_screen.lcdOff();
}

size_t
UTFTTerminal::write(uint8_t c)
{
	switch (_state) {
	case REGULAR:
		LOG("REGULAR");
		switch (ASCII(c)) {
		case ASCII::ESC:
			_state = ESCAPE;
			return 1;
		case ASCII::BS:
			drawCursor(false);
			insertChar(c);
			drawCursor();
			return 1;
		case ASCII::CR:
			drawCursor(false);
			insertChar(c);
			return 1;
		case ASCII::LF:
			insertChar(c);
			drawCursor();
			return 1;
		case ASCII::HT:
			for (uint8_t i=0; i<8; ++i)
				this->write(' ');
			return 1;
		default:
			insertChar(c);
			drawCursor();
			return 1;
		};
		break;
	case ESCAPE:
		LOG("ESCAPE");
		switch (c) {
		case '[':
			_state = I_BRAC; return 1;
		case char(ASCII::CAN):
		default:
			_state = REGULAR; return 1;
		}
		break;
	case I_BRAC:
		LOG("I_BRAC");
		switch (c) {
		case char(ASCII::CAN):
			_state = REGULAR; return 1;
		default:
			_state = F_ATTR1; _attr1 = c; return 1;
		};
		break;
	case F_ATTR1:
		LOG("F_ATTR1");
		switch (c) {
		case 'm':
			if (_attr1 == '1')
				addAttr(BRIGHT);
			else
				addAttr(RESET);
		default:
			_state = REGULAR; return 1;
		}
	default:
		Serial.println("Unknown state");
	}
	
	return (1);
}

void
UTFTTerminal::redraw()
{
	LOG_TRACE;
	
	_page = 3-_page;
	//_screen.setWritePage(_page);
	
	Serial.print("redraw "), Serial.println(int(_attributes));
	
	_screen.clrScr();
	_cursorPosition.set(0,0);
	Attributes_t a = _attributes;
	_attributes = RESET;
	_screen.setColor(VGA_SILVER);
	for (uint16_t i=0; i<H; ++i) {
		for (uint16_t j=0; j<W; ++j) {
			_cursorPosition.set(j,i);
			char c = _data[i][j]._symbol;
			LOG(Logger::format_t::hex, c, Logger::format_t::dec);
			if (c == '\0')
				break;
			printChar(i, j);
			if (c == '\n')
				break;
			else
			_attributes = _data[i][j]._attrs;
		}
	}
	addAttr(a);
	Serial.print(" "), Serial.println(int(_attributes));
}

void
UTFTTerminal::printChar(uint8_t y, uint8_t x)
{
	LOG_TRACE;	
	
	Attributes_t a = _data[y][x]._attrs;
	if (_attributes != a) {
		if (a == RESET)
			_screen.setColor(VGA_SILVER);
		else if (a & BRIGHT)
			_screen.setColor(VGA_WHITE);
	}
	_screen.printChar(_data[y][x]._symbol,
	    x*_screen.getFontXsize(), y*_screen.getFontYsize());
}

void
UTFTTerminal::insertChar(uint8_t c)
{
	LOG_TRACE;
	LOG(Logger::format_t::hex, c, Logger::format_t::dec);
	LOG(_insertPosition.x(), _insertPosition.y());

	switch (c) {
	case char(ASCII::BS):
		if (_cursorPosition.x > 0)
			_cursorPosition.x--;
		else if (_cursorPosition.y > 0)
			_cursorPosition.y--, _cursorPosition.x = W-1;
		return;
	case '\r' : _cursorPosition.x = 0; break;
	case '\n' : _cursorPosition.y++; break;
	default:
		_data[_cursorPosition.y][_cursorPosition.x]._attrs = _attributes;
		_data[_cursorPosition.y][_cursorPosition.x]._symbol = c;
		printChar(_cursorPosition.y, _cursorPosition.x);
		_cursorPosition.next();
		break;
	};

	if (_cursorPosition.x >= W) {
		LOG("New line");
		_cursorPosition.x = 0;
		_cursorPosition.y++;
	}
	if (_cursorPosition.y >= H) {
		LOG("Scroll");
		_cursorPosition.y--;
		memmove(_data[0], _data[1], sizeof (Cell)*W*(H-1));
		memset(_data[H-1], 0, sizeof (Cell)*W);
		redraw();
	}
}

void
UTFTTerminal::putChar(uint8_t c)
{	
	uint16_t x = _cursorPosition.x*_screen.getFontXsize(),
		y = _cursorPosition.y*_screen.getFontYsize();
	
	LOG("pos:", x, y);
	_screen.printChar(c, x, y);
	_cursorPosition.next();
	if (_cursorPosition.x >= W) {
		_cursorPosition.x = 0;
		_cursorPosition.y++;
	}
	if (_cursorPosition.y >= H) {
		_cursorPosition.y--;
	}
}

void
UTFTTerminal::addAttr(Attributes_t attrs)
{
	if (attrs == RESET) {
		LOG("RESET ATTRIBUTES");
		_attributes = RESET;
		_screen.setColor(VGA_SILVER);
		return;
	}
	
	_attributes |= attrs;
	if (_attributes & BRIGHT) {
		LOG("SET BRIGHT");
		_screen.setColor(VGA_WHITE);
	}
}

void
UTFTTerminal::drawCursor(bool v)
{
	word c = _screen.getColor(), b = _screen.getBackColor();
	if (!v) 
		_screen.setColor(b);
	_screen.fillRect(_cursorPosition.x*_screen.getFontXsize(),
			 _cursorPosition.y*_screen.getFontYsize(),
			 (_cursorPosition.x+1)*_screen.getFontXsize()-1,
			 (_cursorPosition.y+1)*_screen.getFontYsize()-1);
	if (!v)
		_screen.setColor(c);
}
