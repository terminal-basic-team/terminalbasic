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

#ifdef ARDUINO_ARCH_ESP32

#include "HAL_esp32.h"

#if HAL_ESP32_ODROIDGO
#include "odroid_go.h"
#include "buffered_terminal.hpp"
#if HAL_ESP32_ODROIDGO_QWERTY
#include "utility/KeyboardStream.h"
#endif // HAL_ESP32_ODROIDGO_QWERTY
#endif // HAL_ESP32_ODROIDGO

#if HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SD
#include <SD.h>
#endif

#if HAL_NVRAM || HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SPIFFS
#include "SPIFFS.h"
#endif

#if HAL_NVRAM
static File f;
#endif

#if HAL_EXTMEM

static File extmem_files[HAL_EXTMEM_NUM_FILES];

#if HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SPIFFS
static FS& gfs = SPIFFS;
#elif HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SD
static FS& gfs = SD;
#endif

#endif // HAL_EXTMEM

#if HAL_BUZZER
#define BUZZER_CHANNEL 0
#endif

#if HAL_ESP32_ODROIDGO

#if HAL_ESP32_ODROIDGO_QWERTY
static ODROIDGO::OKeyboard* kbd = nullptr;
static ODROIDGO::OKeyboardStream* kbdStream = nullptr;
#endif // HAL_ESP32_ODROIDGO_QWERTY

class OdroidGoScreen : public BufferedTerminal
{
#define TERMINAL_ROWS 30
#define TERMINAL_COLS 53
#define FONT_WIDTH 6
#define FONT_HEIGHT 8
public:

	OdroidGoScreen()
	{
	}

	void
	clear() override
	{
		memset(m_screenBuffer[0], ' ', m_rows * m_columns);
		memset(m_screenBuffer[1], char(VT100::TextAttr::NO_ATTR), m_rows * m_columns);
		GO.lcd.fillScreen(TFT_BLACK);
		setCursor(0, 0);
		drawCursor(true);
	}

	void
	begin()
	{
		GO.lcd.setTextColor(TFT_LIGHTGREY);
		GO.lcd.setTextSize(1);
		GO.lcd.clearDisplay();

		BufferedTerminal::begin(TERMINAL_ROWS, TERMINAL_COLS);

		clear();
	}

protected:

	void drawCursor(bool v) override
	{
		GO.lcd.fillRect(GO.lcd.getCursorX(), GO.lcd.getCursorY(), FONT_WIDTH, FONT_HEIGHT,
		    v ? TFT_WHITE : TFT_BLACK);
	}

	void scrollLine()
	{
		m_lockCursor = true;
		if (m_row >= m_rows - 1) {

			memmove(m_screenBuffer[0], m_screenBuffer[0] + m_columns, uint16_t(m_columns)*(m_rows - 1));
			memmove(m_screenBuffer[1], m_screenBuffer[1] + m_columns, uint16_t(m_columns)*(m_rows - 1));

			memset(m_screenBuffer[0] + uint16_t(m_columns)*(m_rows - 1), ' ', m_columns);
			memset(m_screenBuffer[1] + uint16_t(m_columns)*(m_rows - 1), VT100::TextAttr::NO_ATTR, m_columns);

			GO.lcd.setCursor(0, 0);
			//GO.lcd.fillScreen(TFT_BLACK);

			VT100::TextAttr attr = VT100::TextAttr::NO_ATTR;
			// Save current attributes
			VT100::TextAttr oldAttr = m_attr;
			for (uint16_t row = 0; row < m_rows - 1; ++row) {
				GO.lcd.fillRect(0, row*FONT_HEIGHT, m_columns*FONT_WIDTH, FONT_HEIGHT, TFT_BLACK);
				for (uint16_t col = 0; col < m_columns; ++col) {
					if (m_screenBuffer[1][row * m_columns + col] != attr) {
						attr = m_attr = VT100::TextAttr(m_screenBuffer[1][row * m_columns + col]);
						setTextAttrs();
					}
					GO.lcd.write(m_screenBuffer[0][row * m_columns + col]);
				}
			}
			// Restore current attributes
			m_attr = oldAttr;
			GO.lcd.fillRect(0, (GO.lcd.height() - FONT_HEIGHT) %
					GO.lcd.height(), GO.lcd.width(), FONT_HEIGHT, TFT_BLACK);
		} else
			++m_row;
		setCursor(m_column, m_row);
		m_lockCursor = false;
	}

private:

	void setTextAttrs()
	{
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
		case VT100::TextAttr::C_BLACK:
			color = VT100::Color::COLOR_BLACK;
			break;
		}

		if (m_attr & VT100::TextAttr::BRIGHT)
			GO.lcd.setTextColor(s_colors[color][1]);
		else
			GO.lcd.setTextColor(s_colors[color][0]);
	}

	static uint16_t s_colors[uint8_t(VT100::Color::NUM_COLORS)][2];

	uint8_t m_screenBuffer[2][TERMINAL_COLS*TERMINAL_ROWS];

	// VT100::Print interface
protected:

	void writeChar(uint8_t c) override
	{
		m_lockCursor = true;
		drawCursor(false);
		switch (c) {
		case '\n':
			if (m_row < m_rows - 1)
				GO.lcd.write('\n');
			scrollLine();
			break;
		case '\r':
			m_column = 0;
			break;
		case 8: //backspace
			if (m_column > 0)
				setCursor(--m_column, m_row);
			else if (m_row > 0) {
				m_column = m_columns - 1;
				setCursor(m_column, --m_row);
			}
			break;
		default:
			GO.lcd.write(c);
			m_screenBuffer[0][m_row * m_columns + m_column] = c;
			m_screenBuffer[1][m_row * m_columns + m_column] = m_attr;
			if (m_column >= m_columns - 1) {
				m_column = 0;
				scrollLine();
			} else
				++m_column;
		}
		drawCursor(true);
		m_lockCursor = false;
	}

	void setCursor(uint8_t x, uint8_t y) override
	{
		drawCursor(false);
		m_row = y % m_rows;
		m_column = x % m_columns;
		GO.lcd.setCursor(m_column * FONT_WIDTH, m_row * FONT_HEIGHT);
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
		setTextAttrs();
	}

	void resetAttributes() override
	{
		GO.lcd.setTextColor(TFT_LIGHTGREY);
		m_attr = VT100::TextAttr::NO_ATTR;
	}
};

#define TFT_DARKYELLOW 0x7BE0
#define TFT_DARKMAGENTA 0x780F

uint16_t OdroidGoScreen::s_colors[
uint8_t(VT100::Color::NUM_COLORS)][2] = {
	{ TFT_BLACK, TFT_DARKGREY}, // COLOR_BLACK
	{ TFT_RED, TFT_PINK}, // COLOR_RED
	{ TFT_DARKGREEN, TFT_GREEN}, // COLOR_GREEN
	{ TFT_DARKYELLOW, TFT_YELLOW}, // COLOR_YELLOW
	{ TFT_NAVY, TFT_BLUE}, // COLOR_BLUE
	{ TFT_DARKMAGENTA, TFT_MAGENTA}, // COLOR_MAGENTA
	{ TFT_DARKCYAN, TFT_CYAN}, // COLOR_CYAN
	{ TFT_LIGHTGREY, TFT_WHITE} // COLOR_WHITE
};

static OdroidGoScreen* GOScreen;

void
HAL_terminal_write(HAL_terminal_t t, uint8_t b)
{
	if (t == 0)
		GOScreen->write(b);
}

#if HAL_ESP32_ODROIDGO_QWERTY
uint8_t
HAL_terminal_read(HAL_terminal_t t)
{
	if (t == 0)
		return kbdStream->read();
	return 0;
}

BOOLEAN
HAL_terminal_isdataready(HAL_terminal_t t)
{
	if (t == 0)
		return kbdStream->available();
	return FALSE;
}
#endif // HAL_ESP32_ODROIDGO_QWERTY
#endif // HAL_ESP32_ODROIDGO

__BEGIN_DECLS

void
HAL_initialize_concrete()
{
#if HAL_ESP32_ODROIDGO
	GO.begin();
	delay(1000);
	GOScreen = new OdroidGoScreen();
	GOScreen->begin();

#if HAL_ESP32_ODROIDGO_QWERTY
	kbd = new ODROIDGO::OKeyboard;
	kbd->begin();
	kbdStream = new ODROIDGO::OKeyboardStream(*kbd);
#endif // HAL_ESP32_ODROIDGO_QWERTY
#endif // HAL_ESP32_ODROIDGO
  
#if HAL_NVRAM || (HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SPIFFS)
	if (!SPIFFS.begin(true)) {
		Serial.println("ERROR: SPIFFS.begin");
		exit(1);
	}
#endif

#if HAL_NVRAM

	if (SPIFFS.exists("/nvram.bin"))
		f = SPIFFS.open("/nvram.bin", "r+");
	else
		f = SPIFFS.open("/nvram.bin", "w");
	if (!f) {
		Serial.println("ERROR: SPIFFS.open");
		exit(4);
	}
	f.close();

#endif // HAL_NVRAM

#if HAL_EXTMEM && (HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SD)
	if (!SD.begin(22)) {
		Serial.println("ERROR: SD.begin");
		exit(3);
	}
#endif // HAL_ESP32_EXTMEM
}

__END_DECLS

void
HAL_finalize()
{
#if HAL_NVRAM || (HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SPIFFS)
	SPIFFS.end();
#endif
#if HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SD
	SD.end();
#endif // HAL_ESP32_EXTMEM
#if HAL_ESP32_ODROIDGO
	delete GOScreen;
#endif // HAL_ESP32_ODROIDGO
}

#if HAL_NVRAM

HAL_nvram_address_t
HAL_nvram_getsize()
{
	return NVRAMSIZE;
}

uint8_t
HAL_nvram_read(HAL_nvram_address_t addr)
{
	f = SPIFFS.open("/nvram.bin", "r");
	if (!f) {
		Serial.println("ERROR: SPIFFS.open");
		exit(2);
	}
	if (!f.seek(uint32_t(addr))) {
		Serial.println("ERROR: SPIFFS.open");
		exit(3);
	}
	uint8_t r = f.read();
	f.close();
	return r;
}

void
HAL_nvram_write(HAL_nvram_address_t addr, uint8_t b)
{
	f = SPIFFS.open("/nvram.bin", "r+");
	if (!f) {
		Serial.println("ERROR: SPIFFS.open");
		exit(5);
	}

	if (f.size() > uint32_t(addr)) {
		if (!f.seek(uint32_t(addr))) {
			Serial.println("ERROR: f.seek(addr)");
			exit(6);
		}
	} else {
		if (!f.seek(f.size())) {
			Serial.println("ERROR: f.seek(f.size())");
		}
		while (f.size() < uint32_t(addr)) {
			f.write(0xFF);
			f.flush();
		}
	}

	f.write(b);
	f.close();
}

#endif // HAL_NVRAM

#if HAL_EXTMEM

HAL_extmem_file_t
HAL_extmem_openfile(const char fname[13])
{
	size_t i = 0;
	for (; i < HAL_EXTMEM_NUM_FILES; ++i) {
		if (!extmem_files[i])
			break;
	}

	if (i == HAL_EXTMEM_NUM_FILES) {
		Serial.println("ERROR: Maximum opened files reached");
		return 0;
	}

	char fname_[14];
	fname_[0] = '/';
	strncpy(fname_ + 1, fname, 12);
	fname_[13] = '\0';

#if HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SPIFFS

	if (SPIFFS.exists(fname_))
		extmem_files[i] = SPIFFS.open(fname_, "r+");
	else
		extmem_files[i] = SPIFFS.open(fname_, "w");
	if (!extmem_files[i]) {
		Serial.println("ERROR: SPIFFS.open");
		return 0;
	}
#elif HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SD

	extmem_files[i] = SD.open(fname_, "r+");
	if (!extmem_files[i]) {
		extmem_files[i] = SD.open(fname_, "w");
		if (!extmem_files[i]) {
			Serial.println("ERROR: SD.open");
			return 0;
		}
	}
#endif // HAL_ESP32_EXTMEM

	return i + 1;
}

void
HAL_extmem_closefile(HAL_extmem_file_t file)
{
	if ((file == 0)
	|| (file > HAL_EXTMEM_NUM_FILES)
	|| (!extmem_files[file - 1])) {
		Serial.println("ERROR: HAL_extmem_closefile");
		return;
	}

	extmem_files[file - 1].close();
}

uint32_t
_seek(HAL_extmem_file_t file, uint32_t pos, SeekMode whence)
{
	if ((file == 0)
	|| (file > HAL_EXTMEM_NUM_FILES)
	|| (!extmem_files[file - 1]))
		return 0;

	extmem_files[file - 1].seek(pos, whence);
	return pos;
}

void
HAL_extmem_setfileposition(
   HAL_extmem_file_t file,
   HAL_extmem_fileposition_t pos)
{
	_seek(file, pos, SeekSet);
}

HAL_extmem_fileposition_t
HAL_extmem_getfilesize(HAL_extmem_file_t file)
{
	if ((file == 0)
	|| (file > HAL_EXTMEM_NUM_FILES)
	|| (!extmem_files[file - 1]))
		return 0;

	return extmem_files[file - 1].size();
}

uint16_t
HAL_extmem_getnumfiles()
{
	uint16_t result = 0;
	File d = gfs.open("/");
	if (!d || !d.isDirectory())
		return 0;
#if HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SPIFFS

	d.rewindDirectory();
	File f = d.openNextFile();
	while (f) {
		++result;
		f = d.openNextFile();
	}
#elif HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SD

	while (true) {
		File f = d.openNextFile();
		if (!f)
			break;
		++result;
		f.close();
	}
	d.close();
#endif // HAL_ESP32_EXTMEM

	return result;
}

void
HAL_extmem_getfilename(uint16_t num, char fname[13])
{
	fname[0] = '\0';
	File d = gfs.open("/");
	if (!d || !d.isDirectory())
		return;

#if HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SPIFFS

	d.rewindDirectory();
	File f = d.openNextFile();
	while (f) {
		if (num == 0) {
			strncpy(fname, f.name() + 1, 12);
			break;
		}
		f = d.openNextFile();
		num--;
	}

#elif HAL_ESP32_EXTMEM == HAL_ESP32_EXTEM_SD

	while (true) {
		File f = d.openNextFile();
		if (!f)
			break;
		if (num == 0) {
			strncpy(fname, f.name() + 1, 12);
			f.close();
			break;
		}
		num--;
		f.close();
	}

#endif // HAL_ESP32_EXTMEM
	d.close();
	fname[12] = '\0';
}

void
HAL_extmem_deletefile(const char fname[13])
{
	char fname_[14];
	fname_[0] = '/';
	strncpy(fname_ + 1, fname, 12);
	fname_[13] = '\0';

	if (!gfs.remove(fname_))
		Serial.println("ERROR: FS.remove");
}

uint8_t
HAL_extmem_readfromfile(HAL_extmem_file_t file)
{
	if ((file == 0)
	|| (file > HAL_EXTMEM_NUM_FILES)
	|| !extmem_files[file - 1])
		return 0;

	return extmem_files[file - 1].read();
}

void
HAL_extmem_writetofile(HAL_extmem_file_t file, uint8_t b)
{
	if ((file == 0)
	|| (file > HAL_EXTMEM_NUM_FILES)
	|| !extmem_files[file - 1])
		return;

	extmem_files[file - 1].write(b);
}

HAL_extmem_fileposition_t
HAL_extmem_getfileposition(HAL_extmem_file_t file)
{
	if ((file == 0)
	|| (file > HAL_EXTMEM_NUM_FILES)
	|| !extmem_files[file - 1])
		return 0;

	return extmem_files[file - 1].position();
}

BOOLEAN
HAL_extmem_fileExists(const char fname[13])
{
	char fname_[14];
	fname_[0] = '/';
	strncpy(fname_ + 1, fname, 12);
	fname_[13] = '\0';

	return gfs.exists(fname_);
}

#endif // HAL_EXTMEM

#if HAL_BUZZER

#if HAL_BUZZER_ESP32 == HAL_BUZZER_ESP32_PWM

void
HAL_buzzer_tone(uint8_t channel, uint16_t freq, uint16_t dur)
{
	ledcAttachPin(channel, BUZZER_CHANNEL);
	ledcWriteTone(BUZZER_CHANNEL, freq);
	if (dur > 0) {
		delay(dur);
		HAL_buzzer_notone(channel);
  }
}

void
HAL_buzzer_notone(uint8_t channel)
{
	ledcWrite(BUZZER_CHANNEL, 0);
	ledcDetachPin(channel);
	pinMode(channel, OUTPUT);
	digitalWrite(channel, HIGH);
}

#endif // HAL_BUZZER_ESP32

#endif // HAL_BUZZER

__BEGIN_DECLS

void
HAL_update_concrete()
{
#if HAL_ESP32_ODROIDGO
	GO.update();
	GOScreen->update();
#endif // HAL_ESP32_ODROIDGO
}

__END_DECLS

void analogWrite(uint8_t, uint8_t) {}

#endif // ARDUINO_ARCH_ESP32
