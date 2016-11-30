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

#include <EEPROM.h>

#include "helper.hpp"

#include "basic_interpreter.hpp"
#include "basic_interpreter_program.hpp"
#include "basic_parser_value.hpp"
#include "arduino_logger.hpp"
#include "version.h"

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

class Interpreter::AttrKeeper
{
public:
	explicit AttrKeeper(Interpreter &i, TextAttr a) :
	_i(i), _a(a)
	{
		if (_a == NO_ATTR)
			return;
		if ((uint8_t(a) & uint8_t(BOLD)) != uint8_t(NO_ATTR))
			_i._stream.print("\x1B[1m");
		if ((uint8_t(a) & uint8_t(UNDERLINE)) != uint8_t(NO_ATTR))
			_i._stream.print("\x1B[4m");
	}
	~AttrKeeper()
	{
		if (_a == NO_ATTR)
			return;
		_i._stream.print("\x1B[0m");
	}
private:
	Interpreter &_i; TextAttr _a;
};

enum Interpreter::ProgMemStrings : uint8_t
{
	STATIC = 0, DYNAMIC, ERROR, SEMANTIC, READY, BYTES,
	AVAILABLE, ucBASIC, S_VERSION, NUM_STRINGS
};

static const char strStatic[] PROGMEM = "STATIC";
static const char strDynamic[] PROGMEM = "DYNAMIC";
static const char strError[] PROGMEM = "ERROR";
static const char strSemantic[] PROGMEM = "SEMANTIC";
static const char strReady[] PROGMEM = "READY";
static const char strBytes[] PROGMEM = "BYTES";
static const char strAvailable[] PROGMEM = "AVAILABLE";
static const char strucBASIC[] PROGMEM = "ucBASIC";
static const char strVERSION[] PROGMEM = "VERSION";

PGM_P const Interpreter::_progmemStrings[NUM_STRINGS] PROGMEM = {
	strStatic,	// STATIC
	strDynamic,	// DYNAMAIC
	strError,	// ERROR
	strSemantic,	// SEMANTIC
	strReady,	// READY
	strBytes,	// BYTES
	strAvailable,	// AVAILABLE
	strucBASIC,	// ucBASIC
	strVERSION	// VERSION
};

#define ESTRING(en) (_progmemStrings[en])

void
Interpreter::valueFromVar(Parser::Value &v, const char *varName)
{
	const Interpreter::VariableFrame *f = getVariable(varName);
	if (f == NULL)
		return;
	
	switch (f->type) {
	case INTEGER:
		v.type = Parser::Value::INTEGER;
		v.value.integer = f->get<Integer>();
		break;
	case REAL:
		v.type = Parser::Value::REAL;
		v.value.real = f->get<Real>();
		break;
	case BOOLEAN:
		v.type = Parser::Value::BOOLEAN;
		v.value.boolean = f->get<bool>();
		break;
	case STRING:
	{
		v.type = Parser::Value::STRING;
		Program::StackFrame *fr =
		    _program.push(Program::StackFrame::STRING);
		if (fr == NULL) {
			raiseError(DYNAMIC_ERROR, STACK_FRAME_ALLOCATION);
			return;
		}
		strcpy(fr->body.string, f->bytes);
		break;
	}
	}
}

bool
Interpreter::valueFromArray(Parser::Value &v, const char *name)
{
	ArrayFrame *f = _program.arrayByName(name);
	if (f == NULL) {
		raiseError(DYNAMIC_ERROR, NO_SUCH_ARRAY);
		return false;
	}
	
	uint16_t index;
	if (!arrayElementIndex(f, index)) {
		raiseError(DYNAMIC_ERROR, INVALID_VALUE_TYPE);
		return false;
	}
	
	switch (f->type) {
	case INTEGER:
		v.type = Parser::Value::INTEGER;
		v.value.integer = f->get<Integer>(index);
		break;
	case REAL:
		v.type = Parser::Value::REAL;
		v.value.real = f->get<Real>(index);
		break;
	default:
		raiseError(DYNAMIC_ERROR, INVALID_VALUE_TYPE);
		return false;
	}
	return true;
}

Interpreter::Interpreter(Stream &stream, Program &program, FunctionBlock *first) :
_program(program), _state(SHELL), _stream(stream), _parser(_lexer, *this, first)
{
	_stream.setTimeout(10000L);
}

void
Interpreter::init()
{
	print(ucBASIC, BOLD);

	print(S_VERSION), print(VERSION, BOLD), _stream.println();
	print(PROGSIZE-_program._arraysEnd, BOLD);
	print(BYTES), print(AVAILABLE), _stream.println();
}

void
Interpreter::step()
{
	LOG_TRACE;

	switch (_state) {
	// waiting for user input command or program line
	case SHELL:
	{
		print(READY, BOLD);
		_stream.println();
	}
		// fall through
	// waiting for user input next program line
	case PROGRAM_INPUT:
		_state = COLLECT_INPUT;
		_inputPosition = 0;
		memset(_inputBuffer, 0xFF, PROGSTRINGSIZE);
		break;
	// collection input buffer
	case COLLECT_INPUT:
		if (readInput())
			exec();
		break;
	case VAR_INPUT:
		if (readInput()) {
			doInput();
			_state = EXECUTE;
		}
		break;
	case EXECUTE:
		if (_program._current < _program._textEnd) {
			Program::String *s = _program.current();
			if (!_parser.parse(s->text + _program._textPosition))
				raiseError(STATIC_ERROR);
			_program.getString();
		} else
			_state = SHELL;
	}
}

void
Interpreter::exec()
{
	_lexer.init(_inputBuffer);
	if (_lexer.getNext() && (_lexer.getToken() == C_INTEGER) &&
	    (_lexer.getValue().type == Parser::Value::INTEGER)) {
		if (!_program.addLine(_lexer.getValue().value.integer,
		    _inputBuffer + _lexer.getPointer())) {
			raiseError(DYNAMIC_ERROR, OUTTA_MEMORY);
			_state = SHELL;
			return;
		} else
			_state = PROGRAM_INPUT;
	} else {
		_state = SHELL;
		if (!_parser.parse(_inputBuffer))
			raiseError(STATIC_ERROR);
	}
}

void
Interpreter::doInput()
{
	Lexer l;
	l.init(_inputBuffer);
	Parser::Value v(Integer(0));
	bool neg = false;
n:	if (l.getNext()) {
		switch (l.getToken()) {
		case MINUS:
			neg = true;
			goto n;
		case PLUS:
			neg = false;
			goto n;
		case C_INTEGER:
		case C_REAL:
			v = l.getValue();
			break;
		case C_STRING:
		{
			v = l.getValue();
			pushString(l.id());
		}
			break;
		default:
			raiseError(DYNAMIC_ERROR, INVALID_VALUE_TYPE);
		}
	}
	if (neg)
		v = -v;
	setVariable(_inputVarName, v);
}

void
Interpreter::list()
{
	_program.reset();
	for (Program::String *s = _program.getString(); s != NULL;
	    s = _program.getString()) {
		{
			AttrKeeper a(*this, BOLD);
			_stream.print(s->number);
		}
		_stream.println(s->text);
	}
}

void
Interpreter::dump(DumpMode mode)
{
	switch (mode) {
	case MEMORY:
	{
		ByteArray ba((uint8_t*) _program._text, PROGSIZE);
		_stream.println(ba);
		_stream.print("Text end:\t");
		_stream.println(unsigned(_program._textEnd),
		    HEX);
		_stream.print("Variables end:\t");
		_stream.println(unsigned(_program._variablesEnd), HEX);
		_stream.print("Arrays end:\t");
		_stream.println(unsigned(_program._arraysEnd), HEX);
		_stream.print("Stack pointer:\t");
		_stream.println(unsigned(_program._sp), HEX);
	}
		break;
	case VARS:
	{
		uint16_t index = _program._textEnd;
		for (VariableFrame *f = _program.variableByIndex(index);
		    (f != NULL) && (_program.variableIndex(f)<
		    _program._variablesEnd); f = _program.variableByIndex(
		    _program.variableIndex(f) + f->size())) {
			_stream.print(f->name);
			_stream.print(":\t");
			Parser::Value v;
			valueFromVar(v, f->name);
			print(v);
			_stream.println();
		}
	}
		break;
	case ARRAYS:
	{
		uint16_t index = _program._variablesEnd;
		for (ArrayFrame *f = _program.arrayByIndex(index);
		    _program.arrayIndex(f)<_program._arraysEnd;
		    f = _program.arrayByIndex(_program.arrayIndex(f) + f->size())) {
			_stream.print(f->name);
			_stream.print('(');
			_stream.print(f->dimension[0]);
			for (uint8_t i=1; i<f->numDimensions; ++i) {
				_stream.print(',');
				_stream.print(f->dimension[i]);
			}
			_stream.print(')');
			_stream.print(":\t");
			_stream.println();
		}
	}
	}
}

void
Interpreter::print(const Parser::Value &v, TextAttr attr)
{
	AttrKeeper keeper(*this, attr);
	
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
	case Parser::Value::STRING:
	{
		Program::StackFrame *f =
		    _program.stackFrameByIndex(_program._sp);
		if (f == NULL || f->_type != Program::StackFrame::STRING) {
			raiseError(DYNAMIC_ERROR, STRING_FRAME_SEARCH);
			return;
		}
		_stream.print(f->body.string);
		_program.pop();
		break;
	}
	default:
		raiseError(DYNAMIC_ERROR, INVALID_VALUE_TYPE);
		break;
	}
	_stream.print(' ');
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
	if (s != NULL)
		_program.jump(_program.stringIndex(s));
	else
		raiseError(DYNAMIC_ERROR, NO_SUCH_STRING);
}

void
Interpreter::newProgram()
{
	_program.newProg();
}

void
Interpreter::pushReturnAddress(uint8_t textPosition)
{
	Program::StackFrame *f = _program.push(Program::StackFrame::
	    SUBPROGRAM_RETURN);
	if (f == NULL)
		raiseError(DYNAMIC_ERROR, STACK_FRAME_ALLOCATION);
	f->body.gosubReturn.calleeIndex = _program._current;
	f->body.gosubReturn.textPosition = _program._textPosition+textPosition;
}

void
Interpreter::returnFromSub()
{
	Program::StackFrame *f = _program.stackFrameByIndex(_program._sp);
	if ((f != NULL) && (f->_type == Program::StackFrame::SUBPROGRAM_RETURN)) {
		_program.jump(f->body.gosubReturn.calleeIndex);
		_program._textPosition = f->body.gosubReturn.textPosition;
		_program.pop();
	} else
		raiseError(DYNAMIC_ERROR, RETURN_WO_GOSUB);
}

void
Interpreter::pushForLoop(const char *varName, uint8_t textPosition,
    const Parser::Value &v, const Parser::Value &vStep)
{
	Program::StackFrame *f = _program.push(Program::StackFrame::FOR_NEXT);
	if (f == NULL)
		raiseError(DYNAMIC_ERROR, STACK_FRAME_ALLOCATION);
	f->body.forFrame.calleeIndex = _program._current;
	f->body.forFrame.textPosition = _program._textPosition+textPosition;
	f->body.forFrame.finalv = v;
	f->body.forFrame.step = vStep;

	valueFromVar(f->body.forFrame.current, varName);
	strcpy(f->body.forFrame.varName, varName);
	setVariable(varName, f->body.forFrame.current);
}

void
Interpreter::pushValue(const Parser::Value &v)
{
	Program::StackFrame *f = _program.push(Program::StackFrame::
	    VALUE);
	if (f == NULL)
		raiseError(DYNAMIC_ERROR, STACK_FRAME_ALLOCATION);
	f->body.value = v;
}

bool
Interpreter::popValue(Parser::Value &v)
{
	Program::StackFrame *f = _program.stackFrameByIndex(_program._sp);
	if ((f != NULL) && (f->_type == Program::StackFrame::VALUE)) {
		v = f->body.value;
		_program.pop();
		return true;
	} else {
		raiseError(DYNAMIC_ERROR, OUTTA_MEMORY);
		return false;
	}
}

bool
Interpreter::next(const char *varName)
{
	Program::StackFrame *f = _program.stackFrameByIndex(_program._sp);
	if ((f != NULL) && (f->_type == Program::StackFrame::FOR_NEXT) &&
	    (strcmp(f->body.forFrame.varName, varName) == 0)) {
		f->body.forFrame.current += f->body.forFrame.step;
		if (f->body.forFrame.step > Parser::Value(Integer(0))) {
			if (f->body.forFrame.current >
			    f->body.forFrame.finalv) {
				_program.pop();
				return true;
			}
		} else if (f->body.forFrame.current < f->body.forFrame.finalv) {
			_program.pop();
			return true;
		}
		_program.jump(f->body.forFrame.calleeIndex);
		_program._textPosition = f->body.forFrame.textPosition;
		setVariable(f->body.forFrame.varName, f->body.forFrame.current);
	} else
		raiseError(DYNAMIC_ERROR, INVALID_NEXT);
	
	return false;
}

void
Interpreter::save()
{
	uint16_t len = _program._textEnd;
	EEPROMClass e;
	e.update(0, (len<<8)>>8);
	e.update(1, len>>8);
	for (uint16_t p=0; p<_program._textEnd; ++p) {
		e.update(p+2, _program._text[p]);
		_stream.print('.');
	}
	_stream.println();
}

void Interpreter::load()
{
	_program.newProg();
	EEPROMClass e;
	uint16_t len = uint16_t(e.read(0));
	len |= uint16_t(e.read(1)) << 8;
	for (uint16_t p=0; p<len; ++p) {
		_program._text[p] = e.read(p+2);
		_stream.print('.');
	}
	_stream.println();
	_program._textEnd = _program._variablesEnd = _program._arraysEnd = len;
}

void
Interpreter::input(const char *varName)
{
	_stream.print('?');
	
	strcpy(_inputVarName, varName);

	_state = VAR_INPUT;
	_program._textPosition += _lexer.getPointer();
	
	_inputPosition = 0;
	memset(_inputBuffer, 0xFF, PROGSTRINGSIZE);
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
		return sizeof (VariableFrame) + STRINGSIZE;
	default:
		return sizeof (VariableFrame);
	}
}

void
Interpreter::set(VariableFrame &f, const Parser::Value &v)
{
	switch (f.type) {
	case INTEGER:
	{
		union
		{
			char *b;
			Integer *i;
		} _U;
		_U.b = f.bytes;
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
		_U.b = f.bytes;
		*_U.r = Real(v);
	}
		break;
	case STRING:
	{
		Program::StackFrame *fr =
		    _program.stackFrameByIndex(_program._sp);
		if (fr == NULL || fr->_type != Program::StackFrame::STRING) {
			raiseError(DYNAMIC_ERROR, STRING_FRAME_SEARCH);
			return;
		}
		strcpy(f.bytes, fr->body.string);
		_program.pop();
	}
		break;
	default:
		raiseError(DYNAMIC_ERROR, INVALID_VALUE_TYPE);
	}
}

void
Interpreter::set(ArrayFrame &f, uint16_t index, const Parser::Value &v)
{
	switch (f.type) {
	case INTEGER:
	{
		union
		{
			uint8_t *b;
			Integer *i;
		} _U;
		_U.b = f.data();
		_U.i[index] = Integer(v);
	}
		break;
	case REAL:
	{
		union
		{
			uint8_t *b;
			Real *r;
		} _U;
		_U.b = f.data();
		_U.r[index] = Real(v);
	}
		break;
	default:
		raiseError(DYNAMIC_ERROR, INVALID_VALUE_TYPE);
	};
}

bool
Interpreter::readInput()
{
	int a = _stream.available();
	if (a <= 0)
		return false;

	const uint8_t availableSize = PROGSTRINGSIZE-1-_inputPosition;
	a = min(a, availableSize);
	
	size_t read = _stream.readBytes(_inputBuffer+_inputPosition, a);
	assert(read <= availableSize);
	uint8_t end = _inputPosition+read;
	for (uint8_t i=_inputPosition; i<end; ++i) {
		char c = _inputBuffer[i];
		switch (c) {
		case '\r':
			_inputBuffer[i] = 0;
			return true;
		default:
			++_inputPosition;
			continue;
		}
	}
	return false;
}

void
Interpreter::print(const char *text, TextAttr attr)
{
	AttrKeeper _a(*this, attr);

	_stream.print(text), _stream.print(' ');
}

void
Interpreter::print(ProgMemStrings index, TextAttr attr)
{
	char buf[16];
	strcpy_P(buf, (PGM_P) pgm_read_word(&(ESTRING(index))));

	AttrKeeper _a(*this, attr);

	_stream.print(buf),  _stream.print(' ');
}

void
Interpreter::print(Integer i, TextAttr attr)
{
	AttrKeeper _a(*this, attr);

	_stream.print(i), _stream.print(' ');
}

void
Interpreter::raiseError(ErrorType type, uint8_t errorCode)
{
	char buf[8];
	if (type == DYNAMIC_ERROR)
		strcpy_P(buf, (PGM_P) pgm_read_word(&(ESTRING(DYNAMIC))));
	else // STATIC_ERROR
		strcpy_P(buf, (PGM_P) pgm_read_word(&(ESTRING(STATIC))));
	_stream.print(buf);
	_stream.print(' ');
	strcpy_P(buf, (PGM_P) pgm_read_word(&(ESTRING(SEMANTIC))));
	_stream.print(buf);
	_stream.print(' ');
	strcpy_P(buf, (PGM_P) pgm_read_word(&(ESTRING(ERROR))));
	_stream.print(buf);
	_stream.print(':');
	if (type == DYNAMIC_ERROR) {
		_stream.println(errorCode);
	} else { // STATIC_ERROR
		_stream.println(int(_parser.getError()));
	}
	_state = SHELL;
}

bool
Interpreter::arrayElementIndex(ArrayFrame *f, uint16_t &index)
{
	index = 0;
	uint16_t dim = f->numDimensions, mul = 1;
	while (dim-- > 0) {
		Program::StackFrame *sf = _program.currentStackFrame();
		if (sf == NULL ||
		    sf->_type != Program::StackFrame::ARRAY_DIMENSION ||
		    sf->body.arrayDimension > f->dimension[dim]) {
			return false;
		}
		index += mul*sf->body.arrayDimension;
		mul *= f->dimension[dim]+1;
		_program.pop();
	};
	return true;
}

Interpreter::VariableFrame*
Interpreter::setVariable(const char *name, const Parser::Value &v)
{
	uint16_t index = _program._textEnd;

	VariableFrame *f;
	for (f = _program.variableByIndex(index); f != NULL; index += f->size(),
	    f = _program.variableByIndex(index)) {
		int res = strcmp(name, f->name);
		if (res == 0) {
			set(*f, v);
			return f;
		} else if (res < 0) {
			break;
		}
	}

	if (f == NULL)
		f = reinterpret_cast<VariableFrame*>(_program._text+index);
	
	uint16_t dist = sizeof (VariableFrame);
	Type t;
	if (endsWith(name, '%')) {
		t = INTEGER;
		dist += sizeof (Integer);
	} else if (endsWith(name, '$')) {
		t = STRING;
		dist += STRINGSIZE;
	} else {
		t = REAL;
		dist += sizeof (Real);
	}
	if (_program._arraysEnd >= _program._sp) {
		raiseError(DYNAMIC_ERROR, OUTTA_MEMORY);
		return NULL;
	}
	memmove(_program._text + index + dist, _program._text + index,
	    _program._arraysEnd - index);
	f->type = t;
	strcpy(f->name, name);
	_program._variablesEnd += f->size();
	_program._arraysEnd += f->size();
	set(*f, v);

	return f;
}

void
Interpreter::setArrayElement(const char *name, const Parser::Value &v)
{
	ArrayFrame *f = _program.arrayByName(name);
	if (f == NULL) {
		raiseError(DYNAMIC_ERROR, NO_SUCH_ARRAY);
		return;
	}
	
	uint16_t index;
	if (!arrayElementIndex(f, index)) {
		raiseError(DYNAMIC_ERROR, INVALID_VALUE_TYPE);
		return;
	}
	
	set(*f, index, v);
}

void
Interpreter::newArray(const char *name)
{
	Program::StackFrame *f = _program.stackFrameByIndex(_program._sp);
	if (f != NULL && f->_type == Program::StackFrame::ARRAY_DIMENSIONS) {
		uint8_t dimensions = f->body.arrayDimensions;
		_program.pop();
		uint16_t size = 1;
		uint16_t sp = _program._sp; // go on stack frames, containong dimesions
		for (uint8_t dim = 0; dim<dimensions; ++dim) {
			f = _program.stackFrameByIndex(sp);
			if (f != NULL && f->_type ==
			    Program::StackFrame::ARRAY_DIMENSION) {
				size *= f->body.arrayDimension+1;
				sp += f->size(Program::StackFrame::ARRAY_DIMENSION);
			} else {
				raiseError(DYNAMIC_ERROR, INTERNAL_ERROR);
				return;
			}
		}
		ArrayFrame *array = addArray(name, dimensions, size);
		if (array != NULL) { // go on stack frames, containong dimesions once more
				     // now popping
			for (uint8_t dim = dimensions; dim-->0;) {
				f = _program.stackFrameByIndex(_program._sp);
				array->dimension[dim] = f->body.arrayDimension;
				_program.pop();
			}
		} else
			return;
	};
	return;
}

const Interpreter::VariableFrame*
Interpreter::getVariable(const char *name)
{
	const VariableFrame *f = _program.variableByName(name);
	if (f == NULL) {
		Parser::Value v(Integer(0));
		f = setVariable(name, v);
	}
	return f;
}

void
Interpreter::pushString(const char *str)
{
	Program::StackFrame *f = _program.push(Program::StackFrame::STRING);
	if (f == NULL) {
		raiseError(DYNAMIC_ERROR, STACK_FRAME_ALLOCATION);
		return;
	}
	strcpy(f->body.string, str);
}

uint16_t
Interpreter::pushDimension(uint16_t dim)
{
	Program::StackFrame *f =
	    _program.push(Program::StackFrame::ARRAY_DIMENSION);
	if (f == NULL) {
		raiseError(DYNAMIC_ERROR, STACK_FRAME_ALLOCATION);
		return 0;
	}
	f->body.arrayDimension = dim;
	return (_program._sp);
}

void
Interpreter::pushDimensions(uint8_t dim)
{
	Program::StackFrame *f =
	    _program.push(Program::StackFrame::ARRAY_DIMENSIONS);
	if (f == NULL) {
		raiseError(DYNAMIC_ERROR, STACK_FRAME_ALLOCATION);
		return;
	}
	f->body.arrayDimensions = dim;
}

void
Interpreter::end()
{
	_state = SHELL;
}

uint16_t
Interpreter::ArrayFrame::size() const
{
	uint16_t result = sizeof (Interpreter::ArrayFrame) +
	    numDimensions * sizeof (uint16_t);
	
	uint16_t mul = 1;
	
	for (uint8_t i=0; i<numDimensions; ++i)
		mul *= dimension[i]+1;
	
	switch (type) {
	case INTEGER:
		mul *= sizeof (Integer); break;
	case REAL:
		mul *= sizeof (Real); break;
	default:
		mul = 1;
	}
	result += mul;
	
	return result;
}

Interpreter::ArrayFrame*
Interpreter::addArray(const char *name, uint8_t dim,
    uint32_t num)
{
	uint16_t index = _program._variablesEnd;
	ArrayFrame *f;
	for (f = _program.arrayByIndex(index); f != NULL; index += f->size(),
	    f = _program.arrayByIndex(index)) {
		int res = strcmp(name, f->name);
		if (res == 0) {
			raiseError(DYNAMIC_ERROR, REDIMED_ARRAY);
			return NULL;
		} else if (res < 0)
			break;
	}

	if (f == NULL)
		f = reinterpret_cast<ArrayFrame*>(_program._text+index);
	
	Type t;
	if (endsWith(name, '%')) {
		t = INTEGER;
		num *= sizeof (Integer);
	} else { // real
		t = REAL;
		num *= sizeof (Real);
	}
	uint16_t dist = sizeof (ArrayFrame) + sizeof (uint16_t)*dim + num;
	if (_program._arraysEnd + dist >= _program._sp) {
		raiseError(DYNAMIC_ERROR, OUTTA_MEMORY);
		return NULL;
	}
	memmove(_program._text + index + dist, _program._text + index,
	    _program._arraysEnd - index);
	f->type = t;
	f->numDimensions = dim;
	strcpy(f->name, name);
	memset(f->data(), 0, num);
	_program._arraysEnd += dist;

	return (f);
}

}
