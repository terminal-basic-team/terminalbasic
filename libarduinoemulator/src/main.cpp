/*
  main.cpp - Main loop for Arduino sketches
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <iostream>
#include <random>

#include "posix_io_pseudotty.hpp"

#include "Stream.h"
#include <Arduino.h>

// Declared weak in Arduino.h to allow user redefinitions.
//int atexit(void (* /*func*/ )()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.

static posix::io::PseudoTTY	tty1;
static posix::io::PseudoTTY	tty2;
EmulatorSerial	Serial1(tty1);
EmulatorSerial	Serial2(tty2);

StdioStream Serial(std::cin, std::cout);

void initVariant() __attribute__((weak));
void initVariant() { }

void setupUSB() __attribute__((weak));
void setupUSB() { }

void setup() __attribute__((weak));
void setup() { }

void loop() __attribute__((weak));
void loop() { }

int main(void) __attribute__((weak));
int main(void)
{
	//init();
	
	tty1.get(); tty1.grant(); tty1.unlock();
	std::cout << "Serial port: " << tty1.slaveName() << std::endl;
	tty2.get(); tty2.grant(); tty2.unlock();
	std::cout << "Serial port 1: " << tty2.slaveName() << std::endl;
	
	srand(time(NULL));

	initVariant();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		//if (serialEventRun) serialEventRun();
	}
        
	return (EXIT_SUCCESS);
}

