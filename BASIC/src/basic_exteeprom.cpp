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

#include "basic.hpp"
#include "basic_exteeprom.hpp"
#include "basic_interpreter.hpp"
#include "basic_program.hpp"

#if USE_EXTEEPROM

#include <i2ceeprom.hpp>
#include <seriallight.hpp>

namespace BASIC
{

static AT28C256 i2c_eeprom(0x50);

static const uint8_t extEEPROMCommandTokens[] PROGMEM = {
	'E', 'C', 'H', 'A', 'I', 'N' + 0x80,
	'E', 'L', 'O', 'A', 'D' + 0x80,
	'E', 'S', 'A', 'V', 'E' + 0x80,
	0
};

const FunctionBlock::function ExtEEPROM::_commands[] PROGMEM = {
	ExtEEPROM::com_echain,
	ExtEEPROM::com_eload,
	ExtEEPROM::com_esave
};

ExtEEPROM::ExtEEPROM()
{
	commands = _commands;
	commandTokens = extEEPROMCommandTokens;
}

void
ExtEEPROM::_init() {
 }

bool
ExtEEPROM::com_echain(Interpreter &i)
{
	return true;
}

bool
ExtEEPROM::com_eload(Interpreter &i)
{
	return true;
}

bool
ExtEEPROM::com_esave(Interpreter &i)
{
	SerialL.println(__PRETTY_FUNCTION__);
	INT zoneNumber;
	if (!getIntegerFromStack(i, zoneNumber)) return false;

	SerialL.println("Correct zone");
	return true;
	const uint16_t zoneAddr = zoneNumber*PROGRAMSIZE;
	if (zoneAddr+PROGRAMSIZE > AT28C256::size)
		return false;
	SerialL.print("Correct zone address ");
	SerialL.println(zoneAddr, DEC);
	// Write program to EEPROM
	for (uint16_t p = 0; p < PROGRAMSIZE; ++p) {
		if (!i2c_eeprom.writeByte(zoneAddr+p, i._program._text[p]))
			return false;
		else
			i.print('.');
	}
}

}

#endif // USE_EXTEEPROM
