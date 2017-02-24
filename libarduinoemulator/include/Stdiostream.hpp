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

#ifndef STDIOSTREAM_HPP
#define STDIOSTREAM_HPP

#include <iostream>
#include "Emuserial.hpp"

class StdioStream : public Emuserial
{
public:
	StdioStream(std::istream&, std::ostream&);
	~StdioStream();
	
	void begin(uint32_t baud);
	void end();

	bool operator!() const
	{
		return (false);
	}

private:
	std::istream &_istream;
	std::ostream &_ostream;
	// Stream interface
public:
	size_t write(uint8_t) override;
	int available() override;
	int read() override;
	void flush() override;
	int peek() override;
};

#endif
