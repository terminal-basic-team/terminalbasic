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

#include <iostream>
#include <random>
#include <csignal>

#include "posix_io_pseudotty.hpp"

#include "Stream.h"
#include <Arduino.h>
#include <signal.h>

// Declared weak in Arduino.h to allow user redefinitions.
//int atexit(void (* /*func*/ )()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.

#include "Stdiostream.hpp"

StdioStream Serial(std::cin, std::cout);
//PseudoTtySerial	Serial;
//PseudoTtySerial	Serial1;
//PseudoTtySerial	Serial2;
//PseudoTtySerial	Serial3;

//StdioStream Serial(std::cin, std::cout);

void initVariant() __attribute__((weak));
void initVariant() { }

void setupUSB() __attribute__((weak));
void setupUSB() { }

void setup() __attribute__((weak));
void setup() { }

void loop() __attribute__((weak));
void loop() { }

static posix::io::File eepromFile;

uint8_t eeprom_read_byte(const uint8_t *__p)
{
	eepromFile.lseek(off_t(__p));
	posixcpp::ByteArray ba(1);
	eepromFile.read(ba);
	return ba[0];
}

void eeprom_write_byte (uint8_t *__p, uint8_t __value)
{
	eepromFile.lseek(off_t(__p));
	posixcpp::ByteArray ba(1);
	ba[0] = __value;
	eepromFile.write(ba);
}

static bool exitFlag = false;

void sighandler(int signum)
{
	exitFlag = true;
}

int main(void) __attribute__((weak));
int main(void)
{
	//init();
	
	std::signal(SIGINT, &sighandler);
	
	eepromFile.setFileName("./eeprom.img");
	eepromFile.setAccessMode(posix::io::AccessMode_t::READ_WRITE);
	eepromFile.setCretaeFlags(posix::io::CreateMode_t::CREAT);
	eepromFile.open();
	
	srand(time(NULL));

	initVariant();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	while (!exitFlag) {
		loop();
		//if (serialEventRun) serialEventRun();
	}
	
	eepromFile.close();
        
	return (EXIT_SUCCESS);
}

