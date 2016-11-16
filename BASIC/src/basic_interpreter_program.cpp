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
	}
}

Interpreter::VariableFrame*
Interpreter::Program::variableByName(const char *name)
{
	uint16_t index = variablesStart();
	if (index == 0)
		index = 1;
	if (_variablesEnd == 0)
		_variablesEnd = 1;

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
	if (f!=NULL)
		f->_type = t;
	return f;
}

void
Interpreter::Interpreter::Program::insertVariable()
{
	uint16_t dist;
}

}
