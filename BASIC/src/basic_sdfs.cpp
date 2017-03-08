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

#include "basic_sdfs.hpp"

#if USESD

#include "basic_program.hpp"
#include <assert.h>

namespace BASIC
{

File SDFSModule::_root;

static const uint8_t sdfsCommands[] PROGMEM = {
	'D', 'I', 'R', 'E', 'C', 'T', 'O', 'R', 'Y'+0x80,
	'D', 'L', 'O', 'A', 'D'+0x80,
	'D', 'S', 'A', 'V', 'E'+0x80,
	'H', 'E', 'A', 'D', 'E', 'R'+0x80,
	'S', 'C', 'R', 'A', 'T', 'C', 'H'+0x80,
	0
};

const FunctionBlock::function  SDFSModule::_commands[] PROGMEM = {
	SDFSModule::directory,
	SDFSModule::dload,
	SDFSModule::dsave,
	SDFSModule::header,
	SDFSModule::scratch
};

SDFSModule::SDFSModule()
{
	commands = _commands;
	commandTokens = sdfsCommands;
}

void
SDFSModule::_init()
{
	if (!SD.begin(SS)) {
		abort();
	}
	_root = SD.open("/", FILE_WRITE);
	if (!_root || !_root.isDirectory()) {
		abort();
	}
}

bool
SDFSModule::directory(Interpreter &i)
{	
	_root.rewindDirectory();
	i.print("SD CARD CONTENTS");
	i.newline();
	Integer index = 0;
	for (File ff = _root.openNextFile(); ff; ff = _root.openNextFile()) {
		i.print(index++);
		i.print('\t');
		i.print(ff.name());
		i.print('\t');
		if (ff.isDirectory())
			i.print(Interpreter::S_DIR);
		else
			i.print(Integer(ff.size()));
		i.newline();
		ff.close();
	}
	return true;
}

bool
SDFSModule::scratch(Interpreter &i)
{
	if (!i.confirm())
		return true;
	
	char ss[16];
	if (getFileName(i, ss)) {
		SD.remove(ss);
		return (true);
	} else
		return (false);
}

bool
SDFSModule::dsave(Interpreter &i)
{
	char ss[16];
	if (getFileName(i, ss))
		SD.remove(ss);
	File f = SD.open(ss, FILE_WRITE);
	if (!f)
		return (false);
	f.write(i._program._text, i._program.size());
	f.close();
	return (true);
}

bool
SDFSModule::dload(Interpreter &i)
{
	char ss[16];
	if (!getFileName(i, ss))
		return false;
	File f = SD.open(ss);
	if (!f)
		return false;
	f.readBytes(i._program._text, f.size());
	i._program.reset(f.size());
	f.close();
	return true;
}

bool
SDFSModule::header(Interpreter &i)
{
	if (!i.confirm())
		return true;

	char ss[16];
	_root.rewindDirectory();
	for (File ff = _root.openNextFile(FILE_WRITE); ff;
	    ff = _root.openNextFile(FILE_WRITE)) {
		ss[0] = '/'; strcpy(ss+1, ff.name());
		ff.close();
		if (!SD.remove(ss))
			return false;
	}
	return true;
}

bool
SDFSModule::getFileName(Interpreter &i, char ss[])
{
	const char *s;
	if (!i.popString(s))
		return false;
	ss[0] = '/';
	uint8_t len = strlen(s);
	strcpy(ss + 1, s);
	strcpy(ss + len + 1, ".BAS");

	return (SD.exists(ss));
}

}

#endif // USESD
