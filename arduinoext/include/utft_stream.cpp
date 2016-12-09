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
	_insertPosition.data[0] = _insertPosition.data[1] = 0;
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
	Serial.print("Screen size ");
	Serial.print(_screen.getDisplayXSize());
	Serial.print('x');
	Serial.println(_screen.getDisplayYSize());
	
	Serial.print("Font size ");
	Serial.print(_screen.getFontXsize());
	Serial.print('x');
	Serial.println(_screen.getFontYsize());
	
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
			if (_insertPosition.x() > 0)
				_insertPosition.data[0]--;
			drawCursor();
			return 1;
		case ASCII::CR:
			drawCursor(false);
			_insertPosition.setX(0);
			break;
		case ASCII::LF:
			Serial.print("Write regular LF ");
			_insertPosition.data[1]++;
			insertChar(c);
			drawCursor();
			return 1;
		default:
			putChar(c);
			drawCursor();
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
			insertChar(char(ASCII::ESC));
			insertChar('['); insertChar(_attr1); insertChar('m');
		default:
			_state = REGULAR; return 1;
		}
	default:
		Serial.println("Unknown state");
	}
	insertChar(c);
	
	return (1);
}

void
UTFTTerminal::redraw()
{
	LOG_TRACE;
	
	Serial.println(__PRETTY_FUNCTION__);
	Serial.print(_insertPosition.x()); Serial.write('\t');
	Serial.println(_insertPosition.y());
	
	_page = 3-_page;
	//_screen.setWritePage(_page);
	
	_screen.clrScr();
	_insertPosition.setX(0), _insertPosition.setY(0);
	for (uint16_t i=0; i<H; ++i) {
		for (uint16_t j=0; j<W; ++j) {
			char c = _data[i][j]._symbol;
			LOG(Logger::format_t::hex, c, Logger::format_t::dec);
			if (c == '\0')
				break;
			printChar(c);
			if (c == '\n')
				break;
		}
	}
}

void
UTFTTerminal::printChar(uint8_t c)
{
	LOG_TRACE;
}

void
UTFTTerminal::insertChar(uint8_t c)
{
	LOG_TRACE;
	LOG(Logger::format_t::hex, c, Logger::format_t::dec);
	LOG(_insertPosition.x(), _insertPosition.y());

	_data[_insertPosition.y()][_insertPosition.x()]._attrs = _attributes;
	_data[_insertPosition.y()][_insertPosition.x()]._symbol = c;
	if (c == '\n') {
		_insertPosition.data[0] = 0;
		_insertPosition.data[1]++;
			
		Serial.println("\\n");
		Serial.print(_insertPosition.x()); Serial.write('\t');
		Serial.println(_insertPosition.y());
	} else
		_insertPosition.data[0]++;

	if (_insertPosition.x() >= W) {
		LOG("New line");
		_insertPosition.setX(0);
		_insertPosition.data[1]++;
		
		Serial.print("End of line "); Serial.println(int(_state));
		Serial.print(_insertPosition.x()); Serial.write('\t');
		Serial.println(_insertPosition.y());
	}
	if (_insertPosition.y() >= H) {
		LOG("Scroll");
		_insertPosition.data[1] = H-1;
		memmove(_data[0], _data[1], W*(H-1));
		memset(_data[H-1], 0, W);
		redraw();
	}
}

void
UTFTTerminal::putChar(uint8_t c)
{	
	uint16_t x = _insertPosition.x()*_screen.getFontXsize(),
		y = _insertPosition.y()*_screen.getFontYsize();
	
	LOG("pos:", x, y);
	_screen.printChar(c, x, y);
	_insertPosition.data[0]++;
	if (_insertPosition.x() >= W) {
		_insertPosition.setX(0);
		_insertPosition.data[1]++;
	}
	if (_insertPosition.y() >= H) {
		_insertPosition.data[1] = H-1;
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
	_screen.fillRect(_insertPosition.x()*_screen.getFontXsize(),
			 _insertPosition.y()*_screen.getFontYsize(),
			 (_insertPosition.x()+1)*_screen.getFontXsize()-1,
			 (_insertPosition.y()+1)*_screen.getFontYsize()-1);
	if (!v)
		_screen.setColor(c);
}
