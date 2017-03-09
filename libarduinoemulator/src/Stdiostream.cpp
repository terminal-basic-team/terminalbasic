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

#include "Stdiostream.hpp"

StdioStream::StdioStream(std::istream &istream, std::ostream &ostream) :
_istream(istream), _ostream(ostream)
{
	::termios TermConf;

	::tcgetattr(STDIN_FILENO, &TermConf);
	TermConf.c_lflag &= ~(ICANON | ECHO);
	::tcsetattr(STDIN_FILENO, TCSANOW, &TermConf);
}

StdioStream::~StdioStream()
{
	::termios TermConf;

	::tcgetattr(STDIN_FILENO, &TermConf);
	TermConf.c_lflag |= (ICANON | ECHO);
	::tcsetattr(STDIN_FILENO, TCSANOW, &TermConf);
}

void StdioStream::begin(uint32_t)
{
}

void StdioStream::end()
{
}

size_t
StdioStream::write(uint8_t byte)
{
	_ostream << byte << std::flush;
}

int
StdioStream::available()
{
	if (_istream.peek() != std::istream::traits_type::eof())
		return 1;
	else
		return 0;
}

void StdioStream::flush()
{
	_ostream.flush();
}

int StdioStream::peek()
{
	return (_istream.peek());
}

int StdioStream::read()
{
	int byte = _istream.get();
	if (byte == '\n')
		byte = '\r';
	return byte;
}
