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

#include <string.h>
#include <assert.h>
#include "helper.hpp"

#include "basic_interpreter.hpp"
#include "basic_interpreter_program.hpp"
#include "basic_parser_value.hpp"
#include "arduino_logger.hpp"

#ifdef ARDUINO
static int freeRam()
{
	extern int __heap_start, *__brkval;
	int v;
	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
#endif

namespace BASIC
{

enum Interpreter::ErrorStrings : uint8_t
{
	STATIC = 0, DYNAMIC, ERROR, SEMANTIC, NUM_STRINGS
};

static const char strStatic[] PROGMEM = "STATIC";
static const char strDynamic[] PROGMEM = "DYNAMIC";
static const char strError[] PROGMEM = "ERROR";
static const char strSemantic[] PROGMEM = "SEMANTIC";

PGM_P const Interpreter::_errorStrings[NUM_STRINGS] PROGMEM = {
	strStatic, // STATIC
	strDynamic, // DYNAMAIC
	strError, // ERROR
	strSemantic, // SEMANTIC
};

#define ESTRING(en) (_errorStrings[en])

void
Interpreter::valueFromFrame(Parser::Value &v, const Interpreter::VariableFrame &f)
{
	switch (f.type) {
	case Interpreter::VariableFrame::INTEGER:
		v.type = Parser::Value::INTEGER;
		v.value.integer = f.get<Integer>();
		break;
	case Interpreter::VariableFrame::REAL:
		v.type = Parser::Value::REAL;
		v.value.real = f.get<Real>();
		break;
	case Interpreter::VariableFrame::BOOLEAN:
		v.type = Parser::Value::BOOLEAN;
		v.value.boolean = f.get<bool>();
		break;
	}
}

Interpreter::Interpreter(Stream &stream, Program &program) :
_program(program), _state(SHELL), _stream(stream), _parser(_lexer, *this)
{
}

void Interpreter::step()
{
	LOG_TRACE;

	switch (_state) {
	case SHELL:
	{
#ifdef ARDUINO
		_stream.print("FREE RAM ");
		_stream.println(freeRam());
#endif
		_stream.print("\x1B[1m");
		_stream.print("READY");
		_stream.println("\x1B[0m");
nextinput:
		char buf[STRINGSIZE];
		memset(buf, 0xFF, sizeof (buf));
		size_t read;
		do {
			read = _stream.readBytesUntil('\n', buf, 128);
		} while (read <= 0);
		if (read >= STRINGSIZE)
			read = STRINGSIZE - 1;
		buf[read] = 0;
		LOG(buf);
		_lexer.init(buf);
		if (_lexer.getNext() && (_lexer.getToken() == C_INTEGER) &&
		    (_lexer.getValue().type == Parser::Value::INTEGER)) {
			_program.addString(_lexer.getValue().value.integer,
			    buf + _lexer.getPointer());
			goto nextinput;
		} else if (!_parser.parse(buf))
			dynamicError();
		break;
	}
	case EXECUTE:
		Program::String *s = _program.current();
		if (s != NULL) {
			if (!_parser.parse(s->text))
				dynamicError();
			_program.getString();
		} else
			_state = SHELL;
	}
}

void Interpreter::list()
{
	LOG_TRACE;
	_program.reset();

	for (Program::String *s = _program.getString(); s != NULL;
	    s = _program.getString()) {
		_stream.print(s->number), _stream.println(s->text);
	}
}

void
Interpreter::dump()
{
	ByteArray ba((uint8_t*) _program._text, PROGSIZE);
	_stream.println(ba);
}

void
Interpreter::print(const Parser::Value &v)
{
	switch (v.type) {
	case Parser::Value::BOOLEAN:
		_stream.print(v.value.boolean);
		break;
	case Parser::Value::REAL:
		_stream.print(v.value.real, 8);
		break;
	case Parser::Value::INTEGER:
		_stream.print(v.value.integer);
		break;
		//case Parser::Value::STRING:
		//	_stream.print(v.value.string.string);
		//	break;
	default:
		dynamicError("INVALID VALUE TYPE");
		break;
	}
}

void
Interpreter::print(char v)
{
	_stream.print(v);
}

void
Interpreter::run()
{
	_program.reset();
	_state = EXECUTE;
}

void
Interpreter::gotoLine(Integer ln)
{
	Program::String *s = _program.stringByNumber(ln);
	if (s != NULL) {
		_program.jump(_program.stringIndex(s));
	} else {
		dynamicError("NO STRING NUMBER");
		_stream.println(ln);
	}
}

void
Interpreter::newProgram()
{
	_program.newProg();
}

void
Interpreter::pushReturnAddress()
{
	_program._sp -= Program::StackFrame::size(
	    Program::StackFrame::SUBPROGRAM_RETURN);
	Program::StackFrame *f = _program.stackFrameByIndex(_program._sp);
	f->_type = Program::StackFrame::SUBPROGRAM_RETURN;
	f->body.calleeIndex = _program._current;
}

void
Interpreter::returnFromSub()
{
	Program::StackFrame *f = _program.stackFrameByIndex(_program._sp);
	if ((f != NULL) && (f->_type == Program::StackFrame::SUBPROGRAM_RETURN)) {
		_program._current = f->body.calleeIndex;
		_program._sp += Program::StackFrame::size(
		    Program::StackFrame::SUBPROGRAM_RETURN);
	} else
		dynamicError("RETURN NEEDS GOSUB");
}

void
Interpreter::pushForLoop(const char *varName, const Parser::Value &v,
    const Parser::Value &vStep)
{
	Program::StackFrame *f = _program.stackFrameByIndex(_program._sp);
	if ((f != NULL) && (f->_type == Program::StackFrame::FOR_NEXT) &&
	    (strcmp(varName, f->body.forFrame.varName) == 0)) { // for iteration
		setVariable(varName, f->body.forFrame.current);
	} else {
		_program._sp -= Program::StackFrame::size(
		    Program::StackFrame::FOR_NEXT);
		f = _program.stackFrameByIndex(_program._sp);
		if (f == NULL)
			dynamicError(varName);
		f->_type = Program::StackFrame::FOR_NEXT;
		f->body.forFrame.calleeIndex = _program._current;
		f->body.forFrame.finalv = v;
		f->body.forFrame.step = vStep;
		Parser::Value cur;
		VariableFrame *vf = _program.variableByName(varName);
		valueFromFrame(f->body.forFrame.current, *vf);
		strcpy(f->body.forFrame.varName, varName);
		setVariable(varName, f->body.forFrame.current);
	}
}

void
Interpreter::next(const char *varName)
{
	Program::StackFrame *f = _program.stackFrameByIndex(_program._sp);
	if ((f != NULL) && (f->_type == Program::StackFrame::FOR_NEXT) &&
	    (strcmp(f->body.forFrame.varName, varName) == 0)) {
		f->body.forFrame.current += f->body.forFrame.step;
		if (f->body.forFrame.step > Parser::Value(Integer(0))) {
			if (f->body.forFrame.current > f->body.forFrame.finalv) {
				_program._sp += Program::StackFrame::size(
				    Program::StackFrame::FOR_NEXT);
				return;
			}
		} else if (f->body.forFrame.current < f->body.forFrame.finalv) {
			_program._sp += Program::StackFrame::size(
			    Program::StackFrame::FOR_NEXT);
			return;
		}
		_program.jump(f->body.forFrame.calleeIndex);
	} else
		dynamicError("INVALID NEXT");
}

Interpreter::Program::Program()
{
	newProg();
}

uint8_t
Interpreter::VariableFrame::size() const
{
	switch (type) {
	case Parser::Value::INTEGER:
		return sizeof (VariableFrame) + sizeof (Integer);
	case Parser::Value::REAL:
		return sizeof (VariableFrame) + sizeof (float);
	case Parser::Value::BOOLEAN:
		return sizeof (VariableFrame) + sizeof (bool);
	case Parser::Value::STRING:
		return sizeof (VariableFrame) + strlen(bytes) + 1;
	default:
		return sizeof (VariableFrame);
	}
}

void
Interpreter::VariableFrame::set(const Parser::Value &v)
{
	switch (type) {
	case INTEGER:
	{
		union
		{
			char *b;
			Integer *i;
		} _U;
		_U.b = bytes;
		*_U.i = Integer(v);
	}
	break;
	case REAL:
	{
		union
		{
			char *b;
			Real *r;
		} _U;
		_U.b = bytes;
		*_U.r = Real(v);
	}
	}
}

void
Interpreter::Program::newProg()
{
	_first = 0, _last = 0, _current = _variablesEnd = _jump = 0;
	_sp = PROGSIZE;
	memset(_text, 0xFF, PROGSIZE);
}

Interpreter::Program::String*
Interpreter::Program::getString()
{
	if (_jump != 0) {
		_current = _jump;
		_jump = 0;
		return current();
	}
	Program::String *result = current();
	if (result != NULL) {
		_current += result->size;
		if (_current > _last)
			_current = 0;
	}
	return result;
}

Interpreter::Program::String*
Interpreter::Program::current() const
{
	return (stringByIndex(_current));
}

Interpreter::Program::String*
Interpreter::Program::first() const
{
	return (stringByIndex(_first));
}

Interpreter::Program::String*
Interpreter::Program::last() const
{
	return (stringByIndex(_last));
}

Interpreter::Program::String*
Interpreter::Program::stringByIndex(uint16_t index) const
{
	if (index != 0)
		return (const_cast<String*> (reinterpret_cast<const String*> (
	    _text + index)));
	else
		return (NULL);
}

Interpreter::Program::String*
Interpreter::Program::stringByNumber(uint16_t number, size_t index)
{
	Program::String *result = NULL;

	if (index <= _last) {
		_current = index;
		for (String *cur = getString(); cur != NULL;
		    cur = getString()) {
			if (cur->number == number) {
				result = cur;
				break;
			}
		}
	}
	return (result);
}

uint16_t
Interpreter::Program::stringIndex(const String *s) const
{
	return (((char*) s) - _text);
}

uint16_t
Interpreter::Program::variablesStart() const
{
	if (_last == 0)
		return 0;
	else
		return _last + last()->size;
}

Interpreter::VariableFrame*
Interpreter::Program::variableByIndex(uint16_t index)
{
	if (index != 0)
		return (reinterpret_cast<VariableFrame*> (_text + index));
	else
		return (NULL);
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
Interpreter::Program::stackFrameByIndex(uint16_t index)
{
	if ((index > 0) && (index < PROGSIZE))
		return (reinterpret_cast<StackFrame*> (_text + index));
	else
		return (NULL);
}

void
Interpreter::dynamicError(const char *text)
{
	char buf[16];
	if (text != NULL)
		strcpy_P(buf, (PGM_P) pgm_read_word(&(ESTRING(DYNAMIC))));
	else
		strcpy_P(buf, (PGM_P) pgm_read_word(&(ESTRING(STATIC))));
	_stream.print(buf);
	_stream.print(' ');
	strcpy_P(buf, (PGM_P) pgm_read_word(&(ESTRING(SEMANTIC))));
	_stream.print(buf);
	_stream.print(' ');
	strcpy_P(buf, (PGM_P) pgm_read_word(&(ESTRING(ERROR))));
	_stream.print(buf);
	_stream.print(':');
	if (text != NULL) {
		_stream.println(text);
	} else
		_stream.println(int(_parser.getError()));
	_state = SHELL;
}

void
Interpreter::setVariable(const char *name, const Parser::Value &v)
{
	uint16_t index = _program.variablesStart();
	if (index == 0)
		index = 1;
	if (_program._variablesEnd == 0)
		_program._variablesEnd = 1;

	VariableFrame *f;
	bool insertFlag = true;
	for (f = _program.variableByIndex(index); (f != NULL) && (index <
	    _program._variablesEnd);
	    f = _program.variableByIndex(index)) {
		int8_t res = strcmp(name, f->name);
		if (res == 0) {
			insertFlag = false;
			break;
		} else if (res < 0) {
			uint16_t dist = 0;
			if (endsWith(name, '%'))
				dist = sizeof (VariableFrame) +
				    sizeof (Integer);
			else
				dist = sizeof (VariableFrame) +
				    sizeof (Real);
			memmove(_program._text + index + dist,
			    _program._text + index,
			    _program._variablesEnd - index);
			break;
		}
		index += f->size();
	}

	if (insertFlag) {
		if (endsWith(name, '%'))
			f->type = VariableFrame::INTEGER;
		else
			f->type = VariableFrame::REAL;
		_program._variablesEnd += f->size();
	}
	
	f->set(v);
	strcpy(f->name, name);
}

const Interpreter::VariableFrame&
Interpreter::getVariable(const char *name)
{
	const VariableFrame *f = _program.variableByName(name);
	if (f == NULL) {
		Parser::Value v;
		setVariable(name, v);
		f = _program.variableByName(name);
		assert(f != 0);
	}
	return *f;
}

void
Interpreter::Program::addString(uint16_t num, const char *text)
{
	reset();

	String *cur;
	if (_last == 0) { // First string insertion
		_first = 1;
		_last = 1;
		_current = 1;
		uint16_t dist = sizeof (String) +
		    strlen(text) + 1;
		if (_variablesEnd != 0)
			memmove(_text + dist + 1, _text + 1, _variablesEnd - 1);
		insert(num, text);
		_last = _current;
		_variablesEnd = variablesStart() + _variablesEnd;
		return;
	}
	// Iterate over
	for (cur = current(); cur != NULL; getString(), cur = current()) {
		if ((_current == _last) && ((cur->number < num))) { // Last string
			// add new string
			uint16_t dist = sizeof (String) +
			    strlen(text) + 1;
			memmove(_text + variablesStart() + dist,
			    _text + variablesStart(), dist);
			_current = _last + cur->size;
			insert(num, text);
			_last = _current;
			_variablesEnd += dist;
			return;
		} else { // Not last string
			if (cur->number == num) { // Replace string
				uint16_t newSize = sizeof (String) +
				    strlen(text) + 1;
				uint16_t curSize = cur->size;
				int16_t dist = int16_t(newSize) - curSize;
				uint16_t bytes2copy = _variablesEnd -
				    (_current + curSize);
				memmove(_text + _current + newSize,
				    _text + _current + curSize,
				    bytes2copy);
				if (_current != _last) {
					_last += dist;
					_variablesEnd += dist;
				}
				insert(num, text);
				return;
			} else if (cur->number > num) { // Insert before
				_current = stringIndex(cur);
				uint16_t dist = sizeof (String) +
				    strlen(text) + 1;
				uint16_t bytes2copy = _variablesEnd -
				    (_current);
				memmove(_text + _current + dist,
				    _text + _current, bytes2copy);
				_last += dist, _variablesEnd += dist;
				insert(num, text);
				return;
			} else {

			}
		}
	}
}

bool
Interpreter::Program::insert(int num, const char *text)
{
	if (_last < (PROGSIZE)) {
		String *cur = current();
		cur->number = num;
		cur->size = sizeof (String) + strlen(text) + 1;
		strcpy(cur->text, text);
		return true;
	} else
		return false;
}

void
Interpreter::end()
{
	_state = SHELL;
}

void Interpreter::Program::reset()
{
	_current = _first;
}

}
