#include "lexer.hpp"

#include <string.h>
#include <ctype.h>

/*
 * KW_DUMP = "DUMP"
 * KW_END = "END"
 * KW_FOR = "FOR"
 * KW_FOR = "GOTO"
 * KW_IF = "IF"
 * KW_LET = "LET"
 * KW_LIST = "LIST"
 * KW_NEW = "NEW"
 * KW_NEXT = "NEXT"
 * KW_PRINT = "PRINT"
 * KW_RUN = "RUN"
 * KW_THEN = "THEN"
 * KW_RUN = "TO"
 * COLON = ':'
 * SEMI = ';'
 * LT = '<'
 * LTE = "<="
 * GT = '>'
 * GTE = ">="
 * EQUALS = '='
 * NE = "<>"
 * MINUS = '-'
 * PLUS = '+'
 * STAR = '*'
 * SLASH = '/'
 * POW = '^'
 * IDENT = [A-Z][A-Z0-9]*
 * C_INTEGER = [0-9]+
 * C_REAL = [0-9]+[.][0-9]*
 */

namespace BASIC
{

const char sNOTOKENS[] PROGMEM = "NOTOKENS";
const char sIDENT[] PROGMEM = "IDENT";
const char sEQUALS[] PROGMEM = "=";
const char sCOLON[] PROGMEM = ":";
const char sSEMI[] PROGMEM = ";";
const char sLT[] PROGMEM = "<";

PGM_P const Lexer::tokenStrings[NUM_TOKENS] PROGMEM = {
	sNOTOKENS,
	sIDENT,
	sEQUALS,
	sCOLON,
	sSEMI,
	sLT
};

#define SYM _string[_pointer]

void Lexer::init(const char *string)
{
	LOG_TRACE;

	_pointer = 0;
	_token = NOTOKENS;

	if (string != NULL)
		_string = string;
}

bool Lexer::getNext()
{
	LOG_TRACE;

	_valuePointer = 0;
	while (SYM > 0) {
		//LOG("Symbol:", SYM);
		if (isdigit(SYM)) {
			_value.type = Parser::Value::INTEGER;
			_value.value.integer = SYM - '0';
			decimalNumber();
			return true;
		} else
			switch (SYM) {
			case 'D':
				_value.value.string.string[_valuePointer++] = SYM;
				first_D();
				return true;
			case 'E':
				_value.value.string.string[_valuePointer++] = SYM;
				first_E();
				return true;
			case 'F':
				_value.value.string.string[_valuePointer++] = SYM;
				first_F();
				return true;
			case 'G':
				_value.value.string.string[_valuePointer++] = SYM;
				first_G();
				return true;
			case 'I':
				_value.value.string.string[_valuePointer++] = SYM;
				first_I();
				return true;
			case 'L':
				_value.value.string.string[_valuePointer++] = SYM;
				first_L();
				return true;
			case 'N':
				_value.value.string.string[_valuePointer++] = SYM;
				first_N();
				return true;
			case 'P':
				_value.value.string.string[_valuePointer++] = SYM;
				first_P();
				return true;
			case 'R':
				_value.value.string.string[_valuePointer++] = SYM;
				first_R();
				return true;
			case 'T':
				_value.value.string.string[_valuePointer++] = SYM;
				first_T();
				return true;
			case '=':
				_token = EQUALS;
				next();
				return true;
			case ';':
				_token = SEMI;
				next();
				return true;
			case ',':
				_token = COMMA;
				next();
				return true;
			case ':':
				_token = COLON;
				next();
				return true;
			case '<':
				fitst_LT();
				return true;
			case '>':
				fitst_GT();
				return true;
			case '(':
				_token = LPAREN;
				next();
				return true;
			case ')':
				_token = RPAREN;
				next();
				return true;
			case '+':
				_token = PLUS;
				next();
				return true;
			case '-':
				_token = MINUS;
				next();
				return true;
			case '*':
				_token = STAR;
				next();
				return true;
			case '/':
				_token = SLASH;
				next();
				return true;
			case '^':
				_token = POW;
				next();
				return true;
			case ' ':
			case '\t':
			case '\r':
			case '\n':
				next();
				break;
			default:
				if (isalpha(SYM)) {
					pushSYM();
					ident();
					return true;
				}
				_token = NOTOKENS;
				return true;
			}
	}
	return false;
}

void Lexer::pushSYM()
{
	if (_valuePointer < STRINGSIZE - 1)
		_value.value.string.string[_valuePointer++] = SYM;
	next();
}

void Lexer::next()
{
	++_pointer;
}

void Lexer::first_E()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'N':
		pushSYM();
		switch (SYM) {
		case 'D':
			pushSYM();
			_token = KW_END;
			return;
		}
	}
	ident();
}

void Lexer::first_D()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'U':
		pushSYM();
		switch (SYM) {
		case 'M':
			pushSYM();
			switch (SYM) {
			case 'P':
				_token = KW_DUMP;
				return;
			}
		}
	}
	ident();
}

void Lexer::first_F()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'O':
		pushSYM();
		switch (SYM) {
		case 'R':
			pushSYM();
			_token = KW_FOR;
			return;
		}
	}
	ident();
}

void Lexer::first_G()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'O':
		pushSYM();
		switch (SYM) {
		case 'T':
			pushSYM();
			switch (SYM) {
			case 'O':
				pushSYM();
				_token = KW_GOTO;
				return;
			}
		case 'S':
			pushSYM();
			switch (SYM) {
			case 'U':
				pushSYM();
				switch (SYM) {
				case 'B':
					pushSYM();
					_token = KW_GOSUB;
					return;
				}
			}
		}
	}
	ident();
}

void Lexer::first_I()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'F':
		pushSYM();
		_token = KW_IF;
		return;
	}
	ident();
}

void Lexer::first_L()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'I':
		pushSYM();
		switch (SYM) {
		case 'S':
			pushSYM();
			switch (SYM) {
			case 'T':
				pushSYM();
				_token = KW_LIST;
				return;
			}
		}
	case 'E':
		pushSYM();
		switch (SYM) {
		case 'T':
			pushSYM();
			_token = KW_LET;
			return;
		}
	}
	ident();
}

void Lexer::first_N()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'E':
		pushSYM();
		switch (SYM) {
		case 'X':
			pushSYM();
			switch (SYM) {
			case 'T':
				pushSYM();
				_token = KW_NEXT;
				return;
			}
		case 'W':
			pushSYM();
			_token = KW_NEW;
			return;
		}
	}
	ident();
}

void Lexer::first_P()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'R':
		pushSYM();
		switch (SYM) {
		case 'I':
			pushSYM();
			switch (SYM) {
			case 'N':
				pushSYM();
				switch (SYM) {
				case 'T':
					pushSYM();
					_token = KW_PRINT;
					return;
				}
			}
		}
	}
	ident();
}

void Lexer::first_R()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'E':
		pushSYM();
		switch (SYM) {
		case 'T':
			pushSYM();
			switch (SYM) {
			case 'U':
				pushSYM();
				switch (SYM) {
				case 'R':
					pushSYM();
					switch (SYM) {
					case 'N':
						pushSYM();
						_token = KW_RETURN;
						return;
					}
				}
			}
		}
	case 'U':
		pushSYM();
		switch (SYM) {
		case 'N':
			pushSYM();
			_token = KW_RUN;
			return;
		}
	}
	ident();
}

void Lexer::first_T()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'H':
		pushSYM();
		switch (SYM) {
		case 'E':
			pushSYM();
			switch (SYM) {
			case 'N':
				pushSYM();
				_token = KW_THEN;
				return;
			}
			break;
		}
		break;
	case 'O':
		pushSYM();
		_token = KW_TO;
		return;
	}
	ident();
}

void Lexer::fitst_LT()
{
	_token = LT;

	next();
	switch (SYM) {
	case '=':
		_token = LTE;
		break;
	case '>':
		_token = NE;
		break;
	default:
		return;
	}
	next();
}

void Lexer::fitst_GT()
{
	_token = GT;

	next();
	switch (SYM) {
	case '=':
		_token = GTE;
		break;
	default:
		return;
	}
	next();
}

void Lexer::decimalNumber()
{
	LOG_TRACE;

	_token = NOTOKENS;

	while (true) {
		next();
		if (isdigit(SYM)) {
			_value.value.integer *= Integer(10);
			_value.value.integer += SYM - '0';
			continue;
		}
		switch (SYM) {
		case '.':
		{
			_value.type = Parser::Value::REAL;
			_value.value.real = Real(_value.value.integer);
			Real d = 1;
			while (true) {
				next();
				if (isdigit(SYM)) {
					d /= 10.f;
					_value.value.real += Real(SYM-'0') *d;
					continue;
				} else
					break;
			}
		}
		default:
			if (_value.type == Parser::Value::INTEGER)
				_token = C_INTEGER;
			else
				_token = C_REAL;
			return;
		}
	}
}

void Lexer::realNumber()
{

}

void Lexer::ident()
{
	while (isalnum(SYM)) {
		pushSYM();
	}
	_value.type = Parser::Value::STRING;
	_value.value.string.string[_valuePointer] = 0;
	_token = IDENT;
}

}
