/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * Copyright (C) 2016  Andrey V. Skvortsov <starling13@mail.ru>
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

#ifndef STREAM_H
#define STREAM_H

#include "Print.h"

#include "posix_io_pseudotty.hpp"

class Stream : public Print
{
public:
	Stream() {_timeout=1000;}
	
	size_t readBytesUntil( char terminator, char *buffer, size_t length); // as readBytes with terminator character
	size_t readBytesUntil( char terminator, uint8_t *buffer, size_t length) { return readBytesUntil(terminator, (char *)buffer, length); }
	
	void setTimeout(unsigned long timeout) { _timeout = timeout; }  // sets maximum milliseconds to wait for stream data, default is 1 second
	unsigned long getTimeout(void) { return _timeout; }
	
	int timedRead();    // private method to read stream with timeout
	virtual int available() = 0;
	virtual int read() = 0;
	virtual int peek() = 0;
	virtual void flush() = 0;
	virtual size_t readBytes( char *buffer, size_t length); // read chars from stream into buffer
	size_t readBytes( uint8_t *buffer, size_t length) { return readBytes((char *)buffer, length); }
	
	bool findUntil(char *target, char *terminator);   // as find but search ends if the terminator string is found
private:
	unsigned long _timeout;
	unsigned long _startMillis;  // used for timeout measurement
};

class EmulatorSerial : public Stream
{
public:
	EmulatorSerial(posix::io::TTY&);

	virtual void begin(uint32_t baud);
	size_t readBytes(char*, size_t) override;

	size_t write(uint8_t) override;

	posix::io::TTY &tty()
	{
		return (_tty);
	}
	
	bool operator!() const
	{
		return false;
	}
	
private:
	posix::io::TTY &_tty;
	uint64_t _period;
	uint8_t	_firstByte;
	bool _hasFirstByte;
	
	// Stream interface
public:
	int available() override;
	int read() override;
	void flush() override;;
	int peek() override;;
};

class PseudoTtySerial : public EmulatorSerial
{
public:
	PseudoTtySerial();
	void begin(uint32_t) override;
private:
	posix::io::PseudoTTY _tty;
};

class StdioStream : public Stream
{
public:
	StdioStream(std::istream&, std::ostream&);
	void begin(uint32_t baud);
	void end();
	bool operator !() const
	{
		return false;
	}
private:
	std::istream &_istream;
	std::ostream &_ostream;
	// Stream interface
public:
	size_t write(uint8_t) override;
	int available() override;
	int read() override;
	void flush() override;;
	int peek() override;;
};

extern StdioStream Serial;
extern PseudoTtySerial Serial1;
extern PseudoTtySerial Serial2;
extern PseudoTtySerial Serial3;

#endif
