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

#include <unistd.h>

#include <iostream>
#include <cmath>

#include "Stream.h"
#include "Arduino.h"

char PINA, DDRA;
int ADCSRA;

unsigned long millis()
{
    return (micros() / 1000ul);
}

unsigned long micros()
{
	timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	unsigned long res = ts.tv_sec * 1E6 +
	ts.tv_nsec / 1000;
	return (res);
}

void pinMode(uint8_t number, uint8_t mode)
{
	
}

long random()
{
	rand();
}

long random(long val)
{
    return random() % val;
}

void randomSeed(unsigned long val)
{
    srand(val);
}

int analogRead(uint8_t number)
{
	static double sinPhase = 0;
	double noise = (rand() % 1024) / 50.0;
	noise += (std::sin(sinPhase += 0.5)+1.0) * 512.0;
	
	return (noise);
}

void analogWrite(uint8_t number, int value)
{
}

void digitalWrite(uint8_t, uint8_t)
{
}

int digitalRead(uint8_t number)
{
	return (rand() % 2 ? HIGH : LOW);
}

void delayMicroseconds(unsigned int us)
{
	usleep(us);
}

void delay(unsigned long delay)
{
	delayMicroseconds(delay * 1000);
}

size_t Print::write(const uint8_t *buffer, size_t size)
{
  size_t n = 0;
  while (size--) {
    if (write(*buffer++)) n++;
    else break;
  }
  return n;
}

void EmulatorSerial::begin(uint32_t baud)
{
	_tty.setBaudRate(posix::io::TTY::baudRateFromInt(baud));
}

EmulatorSerial::EmulatorSerial(posix::io::TTY	&tty) :
_period(1000000000ll),
_tty(tty), _hasFirstByte(false)
{
	_tty.setAccessMode(posix::io::AccessMode_t::READ_WRITE);
	_tty.setReadTries(2);
}

int EmulatorSerial::available()
{
	return (_tty.inputQueueSize());
}

void EmulatorSerial::flush()
{
	_tty.flush(posix::io::TTY::QueueSelector_t::INOUT);
}

int EmulatorSerial::peek()
{
	posixcpp::ByteArray	ba(1);
	
	if (_hasFirstByte)
		return _firstByte;
	else {
		_tty.read(ba);
		if (ba.size() == 1) {
			_hasFirstByte = true;
			_firstByte = ba[0];
			return (_firstByte);
		} else
			return (-1);
	}
}

int EmulatorSerial::read()
{
	if (_hasFirstByte) {
		_hasFirstByte = false;
		return (_firstByte);
	} else {
		posixcpp::ByteArray	ba(1);
		_tty.read(ba);
		if (ba.size() > 0)
			return (ba[0]);
		else
			return (-1);
	}
}

size_t EmulatorSerial::readBytes(char *buffer, size_t length)
{
	posixcpp::ByteArray	ba;
	ba.wrapExistingData((uint8_t*)buffer, length);
	try {
		_tty.read(ba, posix::io::IOMode_t::LOOPED, _period);
	} catch (std::exception &ex) {
		std::cerr << ex.what() <<std::endl;
	}
	return (ba.size());
}

size_t  EmulatorSerial::write(uint8_t character)
{
	posixcpp::ByteArray	ba(1);
	ba[0] = character;
	return (_tty.write(ba));
}

PseudoTtySerial::PseudoTtySerial() :
    EmulatorSerial(_tty)
{
	_tty.get();
	_tty.grant();
	_tty.unlock();
	std::cout << "Pseudo terminal:" << _tty.slaveName() << std::endl;
}

void PseudoTtySerial::begin(uint32_t baud)
{
	EmulatorSerial::begin(baud);
	// trick to wait for slave side open
	posix::io::TTY temp;
	temp.setFileName(_tty.slaveName());
	temp.setAccessMode(posix::io::AccessMode_t::READ_WRITE);
	temp.setCustomFlags(O_NOCTTY);
	temp.open();
	temp.close();
	posix::io::Events e(posix::io::Events_t::HANGUP), re;
	do {
		_tty.poll(e, re, 1E7);
	} while (re.testFlag(posix::io::Events_t::HANGUP));
}
