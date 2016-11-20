/*
 * ucBASIC is a lightweight BASIC-like language interpreter
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

#include "basic_interpreter_program.hpp"

namespace BASIC
{

uint8_t
Interpreter::Program::StackFrame::size(Type t)
{
	switch (t) {
	case SUBPROGRAM_RETURN:
		return sizeof (Type) + sizeof (uint16_t);
	case FOR_NEXT:
		return sizeof (Type) + sizeof (ForBody);
	case STRING:
		return sizeof (Type) + STRINGSIZE;
	case ARRAY_DIMENSION:
		return sizeof (Type) + sizeof (uint16_t);
	case ARRAY_DIMENSIONS:
		return sizeof (Type) + sizeof (uint8_t);
	}
}

void
Interpreter::Program::newProg()
{
	_first = _last = _current = _variablesEnd = _arraysEnd = _jump = 0;
	_sp = PROGSIZE;
	memset(_text, 0xFF, PROGSIZE);
}

Interpreter::VariableFrame*
Interpreter::Program::variableByName(const char *name)
{
	uint16_t index = variablesStart();
	if (index == 0)
		index = 1;
	//if (_variablesEnd == 0)
	//	_variablesEnd = 1;

	for (VariableFrame *f = variableByIndex(index); (f != NULL) && (index <
	    _variablesEnd);
	    f = variableByIndex(index)) {
		int8_t res = strcmp(name, f->name);
		if (res == 0) {
			return f;
		} else if (res < 0)
			break;
		index += f->size();
	}
	return NULL;
}

Interpreter::Program::StackFrame*
Interpreter::Program::push(StackFrame::Type t)
{
	_sp -= StackFrame::size(t);
	StackFrame *f = stackFrameByIndex(_sp);
	if (f != NULL)
		f->_type = t;
	return f;
}

void
Interpreter::Program::pop()
{
	StackFrame *f = stackFrameByIndex(_sp);
	if (f != NULL)
		_sp += StackFrame::size(f->_type);
}

Interpreter::ArrayFrame*
Interpreter::Program::addArray(const char *name, uint8_t dim,
    uint32_t num)
{
	uint16_t index = arraysStart();
	if (index == 0)
		index = 1;
	if (_arraysEnd == 0)
		_arraysEnd = 1;

	ArrayFrame *f;
	for (f = arrayByIndex(index); (f != NULL) && (index <
	    _arraysEnd);
	    f = arrayByIndex(index)) {
		int res = strcmp(name, f->name);
		if (res == 0) {
			break;
		} else if (res < 0) {
			uint16_t dist = 0;
			if (endsWith(name, '%'))
				dist = sizeof (ArrayFrame) +
				sizeof (uint16_t)*dim + sizeof (Integer) * num;
			//else if (endsWith(name, '$'))
			//	dist = sizeof (VariableFrame) +
			//	STRINGSIZE;
			else // real
				dist = sizeof (VariableFrame) +
				sizeof (uint16_t)*dim + sizeof (Real) * num;
			memmove(_text + index + dist,
			    _text + index,
			    _arraysEnd - index);
			break;
		}
		index += f->size();
	}
}

Interpreter::Program::StackFrame*
Interpreter::Program::stackFrameByIndex(uint16_t index)
{
	if ((index > 0) && (index < PROGSIZE))
		return (reinterpret_cast<StackFrame*> (_text + index));
	else
		return (NULL);
}

uint16_t
Interpreter::Program::variablesStart() const
{
	if (_last == 0)
		return 0;
	else
		return _last + last()->size;
}

uint16_t
Interpreter::Program::arraysStart() const
{
	if (_variablesEnd == 0)
		return 0;
	else
		return _variablesEnd;
}

Interpreter::ArrayFrame*
Interpreter::Program::arrayByName(const char *name)
{

}

Interpreter::VariableFrame*
Interpreter::Program::variableByIndex(uint16_t index)
{
	if (index != 0)
		return (reinterpret_cast<VariableFrame*> (_text + index));
	else
		return (NULL);
}

Interpreter::ArrayFrame*
Interpreter::Program::arrayByIndex(uint16_t index)
{
	if (index != 0)
		return (reinterpret_cast<ArrayFrame*> (_text + index));
	else
		return (NULL);
}

}
