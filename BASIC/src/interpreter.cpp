#include <string.h>
#include <assert.h>

#include "basic_interpreter.hpp"
#include "basic_interpreter_program.hpp"
#include "arduino_logger.hpp"

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
		_stream.println("READY");
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
		bool end = _lexer.getNext();
		if ((_lexer.getToken() == C_INTEGER) &&
		    (_lexer.getValue().type == Parser::Value::INTEGER)) {
			_program.addString(_lexer.getValue().value.integer,
			    buf + _lexer.getPointer());
		} else if (!_parser.parse(buf))
			staticErrorPrint();
		break;
	}
	case EXECUTE:
		Program::String *s = _program.getString();
		if (s != NULL) {
			if (!_parser.parse(s->text)) {
				staticErrorPrint();
				_state = SHELL;
			}
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
	case Parser::Value::STRING:
		_stream.print(v.value.string.string);
		break;
	default:
		dynamicErrorPrint("INVALID VALUE TYPE");
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
		_program._current = _program.stringIndex(s);
	} else {
		dynamicErrorPrint("NO STRING NUMBER");
		_stream.println(ln);
	}
}

void
Interpreter::newProgram()
{
	_program.newProg();
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
	}
}

void
Interpreter::VariableFrame::set(const Integer &i)
{
	type = INTEGER;
	union
	{
		char *b;
		Integer *i;
	} _U;
	_U.b = bytes;
	*_U.i = i;
}

Integer
Interpreter::VariableFrame::getInt() const
{
	union
	{
		const char *b;
		const Integer *i;
	} _U;
	_U.b = bytes;
	return *_U.i;
}

void
Interpreter::Program::newProg()
{
	_first = 0, _last = 0, _current = _variablesEnd = 0;
	memset(_text, 0xFF, PROGSIZE);
}

Interpreter::Program::String*
Interpreter::Program::getString()
{
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

void
Interpreter::staticErrorPrint()
{
	_stream.print(ESTRING(STATIC));
	_stream.print(' ');
	_stream.print(ESTRING(SEMANTIC));
	_stream.print(' ');
	_stream.print(ESTRING(ERROR));
	_stream.print(':');
	_stream.println(int(_parser.getError()));
}

void
Interpreter::dynamicErrorPrint(const char *text)
{
	_stream.print(ESTRING(DYNAMIC));
	_stream.print(' ');
	_stream.print(ESTRING(SEMANTIC));
	_stream.print(' ');
	_stream.print(ESTRING(ERROR));
	_stream.print(':');
	_stream.println(text);
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
			switch (v.type) {
			case Parser::Value::INTEGER:
				dist = sizeof (VariableFrame) +
				    sizeof (Integer);
			}
			memmove(_program._text + index + dist,
			    _program._text + index,
			    _program._variablesEnd - index);
			break;
		}
		index += f->size();
	}
	switch (v.type) {
	case Parser::Value::INTEGER:
		f->set(v.value.integer);
	}
	if (insertFlag)
		_program._variablesEnd += f->size();
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

void Interpreter::Program::reset()
{
	_current = _first;
}

}
