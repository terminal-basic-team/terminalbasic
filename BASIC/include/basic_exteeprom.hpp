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

/**
 * @file basic_exteeprom.hpp
 * @brief I2C/SPI external eeprom functions and commands
 */

#ifndef BASIC_EXTEEPROM_HPP
#define BASIC_EXTEEPROM_HPP

#include "basic_functionblock.hpp"

#if USE_EXTEEPROM
#if EXTEEPROM_SIZE >= PROGRAMSIZE
#define EXTEEPROM_PAGES_NUMBER = (EXTEEPROM_SIZE / PROGRAMSIZE)
#define EXTEEPROM_PAGE_SIZE = PROGRAMSIZE 
#else
#define EXTEEPROM_PAGES_NUMBER = 1
#define EXTEEPROM_PAGE_SIZE = EXTEEPROM_SIZE
#endif
#endif // USE_EXTEEPROM

namespace BASIC
{

class ExtEEPROM : public FunctionBlock
{
public:
	explicit ExtEEPROM();
private:
	static bool com_echain(Interpreter&);
	static bool com_eload(Interpreter&);
	static bool com_esave(Interpreter&);
	
	static const FunctionBlock::command _commands[] PROGMEM;
// FunctionBlock interface
public:
	void _init() override;
};

}

#endif
