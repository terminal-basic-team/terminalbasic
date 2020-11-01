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

#ifdef ARDUINO

#include <string.h>

#include "HAL_arduino.h"
#include "Arduino.h"

#if HAL_EXTMEM && (HAL_ARDUINO_EXTMEM == HAL_ARDUINO_EXTMEM_SDFS)
#include "sd.hpp"
#endif

#if HAL_ARDUINO_GFX == HAL_ARDUINO_GFX_SERIAL
#include "gfxterm.hpp"
#endif

#if HAL_ARDUINO_TERMINAL_OUTPUT == HAL_ARDUINO_TERMINAL_OUTPUT_ILI9341

#include "vt100.hpp"
#include "Adafruit_ILI9341.h"

class ESPI : public VT100::Print
{
public:

#define CURSOR_BLINK_PERIOD 2

	ESPI(uint8_t cs, uint8_t dc, uint8_t rs) :
	tft(cs, dc, rs)
	{
		m_row = m_column = m_scroll = 0;
		m_attr = VT100::TextAttr::NO_ATTR;
		m_lockCursor = false;
		m_cursorCounter = CURSOR_BLINK_PERIOD;
	}
	
	void begin()
	{
		tft.begin();
		tft.setTextColor(ILI9341_LIGHTGREY);
		tft.setTextSize(1);
	}
	
	void clear() override
	{
		tft.fillScreen(ILI9341_BLACK);
		m_scroll = 0;
		tft.scrollTo(m_scroll);
		setCursor(0, 0);
		drawCursor(true);
	}
	
	void onTimer()
	{
		// If cursor is locked by the non-interrupt code - return
		if (m_lockCursor)
			return;

		// Count down cursor blank interrupt counter
		if (--m_cursorCounter == 0)
			m_cursorCounter = CURSOR_BLINK_PERIOD;
		else
			return;

		m_cursorState = !m_cursorState;
		uint16_t color;
		if (m_cursorState)
			color = ILI9341_WHITE;
		else
			color = ILI9341_BLACK;
		tft.fillRect(tft.getCursorX(), tft.getCursorY(), 6, 8, color);
	}

protected:
	
	void drawCursor(bool v)
	{
		tft.fillRect(tft.getCursorX(), tft.getCursorY(), 6, 8,
		    v ? ILI9341_WHITE : ILI9341_BLACK);
	}
	
	void scrollLine()
	{
		if (m_row > 38) {
			m_scroll += 8;
			if (m_scroll >= tft.height())
				m_scroll -= tft.height();
			tft.scrollTo(m_scroll);
			tft.fillRect(0, (tft.height() - 8 + m_scroll) % tft.height(), tft.width(), 8, ILI9341_BLACK);
		} else
			++m_row;
		setCursor(m_column, m_row);
	}
	
	void writeChar(uint8_t c) override
	{
		m_lockCursor = true;
		drawCursor(false);
		switch (c) {
		case '\n':
			if (m_row < 39)
				tft.write('\n');
			scrollLine();
			break;
		case '\r':
			m_column = 0;
			break;
		case 8: //backspace
			if (m_column > 0)
				setCursor(--m_column, m_row);
			else if (m_row > 0) {
				m_column = 39;
				setCursor(m_column, --m_row);
			}
			break;
		default:
			tft.write(c);
			if (m_column > 38) {
				m_column = 0;
				scrollLine();
			} else
				++m_column;
		}
		drawCursor(true);
		m_lockCursor = false;
	}
	
	uint8_t getCursorX() override
	{
		return m_column;
	}

	void setCursorX(uint8_t x) override
	{
		setCursor(x, m_row);
	}

	void setCursor(uint8_t x, uint8_t y) override
	{
		drawCursor(false);
		m_row = y % 40;
		m_column = x % 40;
		tft.setCursor(m_column * 6, (y * 8 + m_scroll) % tft.height());
		drawCursor(true);
	}
    
	void addAttribute(VT100::TextAttr ta) override
	{
		switch (ta) {
		case VT100::TextAttr::BRIGHT:
			m_attr |= VT100::TextAttr::BRIGHT;
			break;
		case VT100::TextAttr::C_GREEN:
		case VT100::TextAttr::C_YELLOW:
		case VT100::TextAttr::C_BLUE:
		case VT100::TextAttr::C_CYAN:
		case VT100::TextAttr::C_MAGENTA:
		case VT100::TextAttr::C_RED:
		case VT100::TextAttr::C_WHITE:
		case VT100::TextAttr::C_BLACK:
			m_attr &= VT100::TextAttr(0x0F);
			m_attr |= ta;
			break;
		default:
			break;
		}

		VT100::Color color = VT100::Color::COLOR_BLACK;
		switch (m_attr & 0xF0) {
		case VT100::TextAttr::C_GREEN:
			color = VT100::Color::COLOR_GREEN;
			break;
		case VT100::TextAttr::C_YELLOW:
			color = VT100::Color::COLOR_YELLOW;
			break;
		case VT100::TextAttr::C_BLUE:
			color = VT100::Color::COLOR_BLUE;
			break;
		case VT100::TextAttr::C_CYAN:
			color = VT100::Color::COLOR_CYAN;
			break;
		case VT100::TextAttr::C_MAGENTA:
			color = VT100::Color::COLOR_MAGENTA;
			break;
		case VT100::TextAttr::C_RED:
			color = VT100::Color::COLOR_RED;
			break;
		case VT100::TextAttr::C_WHITE:
			color = VT100::Color::COLOR_WHITE;
			break;
		}

		if (m_attr & VT100::TextAttr::BRIGHT)
			tft.setTextColor(s_colors[color][1]);
		else
			tft.setTextColor(s_colors[color][0]);
	}

	void resetAttributes() override
	{
		tft.setTextColor(ILI9341_LIGHTGREY);
		m_attr = VT100::TextAttr::NO_ATTR;
	}

private:

	Adafruit_ILI9341 tft;

	uint8_t m_row, m_column;

	uint16_t m_scroll;

	VT100::TextAttr m_attr;

	static uint16_t s_colors[uint8_t(VT100::Color::NUM_COLORS)][2];

	bool m_lockCursor, m_cursorState;

	uint8_t m_cursorCounter;
};

#define ILI9341_DARKYELLOW 0x7BE0
#define ILI9341_DARKMAGENTA 0x780F

uint16_t ESPI::s_colors[uint8_t(VT100::Color::NUM_COLORS)][2] = {
    { ILI9341_BLACK, ILI9341_DARKGREY }, // COLOR_BLACK
  { ILI9341_RED, ILI9341_PINK }, // COLOR_RED
  { ILI9341_DARKGREEN, ILI9341_GREEN }, // COLOR_GREEN
  { ILI9341_DARKYELLOW, ILI9341_YELLOW },  // COLOR_YELLOW
  { ILI9341_NAVY, ILI9341_BLUE },  // COLOR_BLUE
  { ILI9341_DARKMAGENTA, ILI9341_MAGENTA },  // COLOR_MAGENTA
  { ILI9341_DARKCYAN, ILI9341_CYAN },  // COLOR_CYAN
  { ILI9341_LIGHTGREY, ILI9341_WHITE } // COLOR_WHITE
};

static ESPI espi(TFT_CS, TFT_DC, TFT_RS);

#endif // HAL_ARDUINO_TERMINAL_OUTPUT == HAL_ARDUINO_TERMINAL_OUTPUT_ILI9341

__BEGIN_DECLS
void
HAL_initialize_concrete();
__END_DECLS

void
HAL_initialize()
{
#if (HAL_ARDUINO_TERMINAL_OUTPUT == HAL_ARDUINO_TERMINAL_OUTPUT_SERIAL) || \
    (HAL_ARDUINO_TERMINAL_INPUT == HAL_ARDUINO_TERMINAL_INPUT_SERIAL)
	Serial.begin(HAL_ARDUINO_TERMINAL_SERIAL_0_BR);
#if defined(HAVE_HWSERIAL1) && (HAL_TERMINAL_NUM > 0)
	Serial1.begin(HAL_ARDUINO_TERMINAL_SERIAL_1_BR);
#endif
#if defined(HAVE_HWSERIAL2) && (HAL_TERMINAL_NUM > 1)
	Serial2.begin(HAL_ARDUINO_TERMINAL_SERIAL_2_BR);
#endif
#if defined(HAVE_HWSERIAL3) && (HAL_TERMINAL_NUM > 2)
	Serial3.begin(HAL_ARDUINO_TERMINAL_SERIAL_3_BR);
#endif
#endif // HAL_ARDUINO_TERMINAL

#if HAL_ARDUINO_TERMINAL_OUTPUT == HAL_ARDUINO_TERMINAL_OUTPUT_ILI9341
	espi.begin();
#endif // HAL_ARDUINO_TERMINAL

#if HAL_EXTMEM && (HAL_ARDUINO_EXTMEM == HAL_ARDUINO_EXTMEM_SDFS)
	if (!SDCard::SDFS.begin())
		abort();
#endif
	HAL_initialize_concrete();
}

void
HAL_time_sleep_ms(uint32_t ms)
{
	delay(ms);
}

uint32_t
HAL_time_gettime_ms()
{
	return millis();
}

#if HAL_ARDUINO_TERMINAL_OUTPUT != HAL_ARDUINO_TERMINAL_OUTPUT_NONE

void
HAL_terminal_write(HAL_terminal_t t, uint8_t b)
{
#if HAL_ARDUINO_TERMINAL_OUTPUT == HAL_ARDUINO_TERMINAL_OUTPUT_SERIAL
	if (t == 0)
		Serial.write(b);
#if defined(HAVE_HWSERIAL1) && (HAL_TERMINAL_NUM > 0)
	else if (t == 1)
		Serial1.write(b);
#endif
#elif HAL_ARDUINO_TERMINAL_OUTPUT == HAL_ARDUINO_TERMINAL_OUTPUT_ILI9341
	if (t == 0)
		espi.write(b);
#endif
}

#endif // #if HAL_ARDUINO_TERMINAL_OUTPUT

#if HAL_ARDUINO_TERMINAL_INPUT != HAL_ARDUINO_TERMINAL_INPUT_NONE

uint8_t
HAL_terminal_read(HAL_terminal_t t)
{
#if HAL_ARDUINO_TERMINAL_INPUT == HAL_ARDUINO_TERMINAL_INPUT_SERIAL
	if (t == 0)
		return Serial.read();
#if defined(HAVE_HWSERIAL1) && (HAL_TERMINAL_NUM > 0)
	else if (t == 1)
		return Serial1.read();
#endif
#endif
	return 0;
}

BOOLEAN
HAL_terminal_isdataready(HAL_terminal_t t)
{
#if HAL_ARDUINO_TERMINAL_INPUT == HAL_ARDUINO_TERMINAL_INPUT_SERIAL
	if (t == 0)
		return Serial.available();
#if defined(HAVE_HWSERIAL1) && (HAL_TERMINAL_NUM > 0)
	else if (t == 1)
		return Serial1.available();
#endif
#endif
	return FALSE;
}

#endif // HAL_ARDUINO_TERMINAL

#if HAL_EXTMEM && (HAL_ARDUINO_EXTMEM == HAL_ARDUINO_EXTMEM_SDFS)

static SDCard::File files[EXTMEM_NUM_FILES];

static SDCard::File
getRootDir()
{
	SDCard::File root = SDCard::SDFS.open("/",
	    SDCard::Mode::WRITE | SDCard::Mode::READ | SDCard::Mode::CREAT);
	if (!root || !root.isDirectory())
		abort();
}

HAL_extmem_file_t
HAL_extmem_openfile(const char path[13])
{
	uint8_t i=0;
	for (; i<EXTMEM_NUM_FILES; ++i) {
		if (!files[i]) {
			files[i] = SDCard::SDFS.open(path, SDCard::Mode::CREAT|SDCard::Mode::WRITE|
			    SDCard::Mode::READ);
			if (files[i])
				return i+1;
		}
	}
	return 0;
}

HAL_extmem_fileposition_t
HAL_extmem_getfilesize(HAL_extmem_file_t f)
{
	if ((f > 0) && files[f-1])
		return files[f-1].size();
	return 0;
}

HAL_extmem_fileposition_t
HAL_extmem_getfileposition(HAL_extmem_file_t f)
{
	if ((f > 0) && files[f-1])
		return files[f-1].position();
	return 0;
}

void
HAL_extmem_setfileposition(HAL_extmem_file_t f, HAL_extmem_fileposition_t pos)
{
	if ((f > 0) && files[f-1])
		files[f-1].seek(pos);
}

uint8_t
HAL_extmem_readfromfile(HAL_extmem_file_t f)
{
	if ((f > 0) && files[f-1])
		return files[f-1].read();
	return 0;
}

void
HAL_extmem_writetofile(HAL_extmem_file_t f, uint8_t b)
{
	if ((f > 0) && files[f-1])
		files[f-1].write(b);
}

void
HAL_extmem_closefile(HAL_extmem_file_t f)
{
	if ((f > 0) && files[f-1]) {
		files[f-1].close();
	}
}

uint16_t
HAL_extmem_getnumfiles()
{
	uint16_t result = 0;
	auto root = getRootDir();
	root.rewindDirectory();
	SDCard::File f;
	while (f=root.openNextFile(SDCard::Mode::READ_ONLY)) {
		++result;
		f.close();
	}
	return result;
}

void
HAL_extmem_getfilename(uint16_t num, char path[13])
{
	auto root = getRootDir();
	root.rewindDirectory();
	SDCard::File f;
	uint16_t n = num;
	while (f=root.openNextFile(SDCard::Mode::READ_ONLY)) {
		if (n-- == 0) {
			strncpy(path, f.name(), 13);
			f.close();
			return;
		}
		f.close();
	}
}

void
HAL_extmem_deletefile(const char path[13])
{
	SDCard::SDFS.remove(path);
}

BOOLEAN
HAL_extmem_fileExists(const char path[13])
{
	SDCard::SDFS.exists(path);
}

#endif // HAL_ARDUINO_EXTMEM

#if HAL_GFX && (HAL_ARDUINO_GFX == HAL_ARDUINO_GFX_SERIAL)

static void
_write16(int16_t v)
{
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(v>>8));
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(v&0xFFu));
}

static HAL_gfx_color_t _colors[2] = {HAL_GFX_NOTACOLOR, HAL_GFX_NOTACOLOR};

void
_writeCommand(GFXTERM::Command c)
{
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(ASCII::DLE));
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(c));
}

void
_setColors()
{
	_writeCommand(GFXTERM::Command::COLOR);
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(_colors[0]));
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(_colors[1]));
}

void
HAL_gfx_setColor(HAL_gfx_color_t color)
{
	_colors[0] = color;
	
	_setColors();
}

void
HAL_gfx_setBgColor(HAL_gfx_color_t color)
{
	_colors[1] = color;
	
	_setColors();
}

void
HAL_gfx_point(uint16_t x, uint16_t y)
{
	_writeCommand(GFXTERM::Command::POINT);
	_write16(x); _write16(y);
}

void
HAL_gfx_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	_writeCommand(GFXTERM::Command::LINE);
	_write16(x1); _write16(y1); _write16(x2); _write16(y2);
}

void
HAL_gfx_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	_writeCommand(GFXTERM::Command::BOX);
	_write16(x); _write16(y); _write16(w); _write16(h);
}

void
HAL_gfx_lineto(uint16_t x, uint16_t y)
{
	
}

void
HAL_gfx_circle(uint16_t x, uint16_t y, uint16_t r)
{
	_writeCommand(GFXTERM::Command::CIRCLEC);
	_write16(x); _write16(y); _write16(r);
}

#if !HAL_GFX_EXPCOLOR_SIMPL
void
HAL_gfx_pointc(uint16_t x, uint16_t y, HAL_gfx_color_t color)
{
	_writeCommand(GFXTERM::Command::POINTC);
	_write16(x); _write16(y);
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(color));
}

void
HAL_gfx_linec(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, HAL_gfx_color_t color)
{
	_writeCommand(GFXTERM::Command::LINEC);
	_write16(x1); _write16(y1); _write16(x2); _write16(y2);
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(color));
}

void
HAL_gfx_rectc(uint16_t x, uint16_t y, uint16_t w, uint16_t h, HAL_gfx_color_t color)
{
	_writeCommand(GFXTERM::Command::BOXC);
	_write16(x); _write16(y); _write16(w); _write16(h);
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(color));
}

void
HAL_gfx_circlec(uint16_t x, uint16_t y, uint16_t r, HAL_gfx_color_t color)
{
	_writeCommand(GFXTERM::Command::CIRCLEC);
	_write16(x); _write16(y); _write16(r);
	HAL_terminal_write(HAL_ARDUINO_GFX_SERIAL_TERMNO, uint8_t(color));
}
#endif /* HAL_GFX_EXPCOLOR_SIMPL */

#endif // HAL_ARDUINO_GFX

void
HAL_random_seed(uint32_t seed)
{
	randomSeed(seed);
}

uint32_t
HAL_random_generate(uint32_t max)
{
	return random(max);
}

#endif // ARDUINO
