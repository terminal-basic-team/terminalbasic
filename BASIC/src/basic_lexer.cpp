/*
 * ucBASIC is a lightweight BASIC-like language interpreter
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

#include "basic_lexer.hpp"
#include "helper.hpp"

#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

/*
 * KW_ARRAYS = "ARRAYS" // 1
 * KW_BASE = "BASE"     // 2
 * COM_CLS = "CLS"      // 3
 * KW_DATA = "DATA"     // 4
 * KW_DEF = "DEF"       // 5
 * COM_DELAY = "DELAY"  // 6
 * KW_DIM = "DIM"       // 7
 * COM_DUMP = "DUMP"    // 8
 * KW_END = "END"       // 9
 * KW_FALSE = "FALSE"   // 10
 * KW_FOR = "FOR"       // 11
 * KW_GOSUB = "GOSUB"   // 12
 * KW_GOTO = "GOTO"     // 13
 * KW_GO = "GO"         // 14
 * KW_IF = "IF"         // 15
 * KW_INPUT = "INPUT"   // 16
 * KW_LET = "LET"       // 17
 * COM_LIST = "LIST"
 * COM_LOAD = "LOAD"
 * COM_NEW = "NEW"
 * KW_NEXT = "NEXT"
 * KW_ON = "ON"
 * KW_OPTION = "OPTION"
 * KW_PRINT = "PRINT"
 * KW_RANDOMIZE = "RANDOMIZE"
 * KW_READ = "READ"
 * KW_REM = "REM"
 * KW_RETURN = "RETURN"
 * COM_RUN = "RUN"
 * COM_SAVE = "SAVE"
 * KW_STEP = "STEP"
 * KW_STOP = "STOP"
 * KW_TAB = "TAB"
 * KW_THEN = "THEN"
 * KW_TO = "TO"
 * KW_TRUE = "TRUE"
 * KW_VARS = "VARS"
 * 
 * OP_AND = "AND"
 * OP_NOT = "NOT"
 * OP_OR = "OR"
 *
 * STAR = '*'
 * SLASH = '/'
 * PLUS = '+'
 * COLON = ':'
 * SEMI = ';'
 * LT = '<'
 * LTE = "<="
 * GT = '>'
 * GTE = ">="
 * EQUALS = '='
 * NE = "<>"
 * NEA = "><"
 * MINUS = '-'
 * POW = '^'
 * IDENT = [A-Z][A-Z0-9]*
 * C_INTEGER = [0-9]+
 * C_REAL = [0-9]+[.][0-9]*
 */

namespace BASIC
{

const char sNOTOKENS[] PROGMEM = "NOTOKENS";  // 0
#if USE_DUMP
const char sARRAYS[] PROGMEM = "ARRAYS";      // 1
#endif
const char sBASE[] PROGMEM = "BASE";          // 2
const char sCLS[] PROGMEM = "CLS";            // 3
const char sDATA[] PROGMEM = "DATA";          // 4
const char sDEF[] PROGMEM = "DEF";            // 5
const char sDELAY[] PROGMEM = "DELAY";        // 6
const char sDIM[] PROGMEM = "DIM";            // 7
#if USE_DUMP
const char sDUMP[] PROGMEM = "DUMP";          // 8
#endif
const char sEND[] PROGMEM = "END";            // 9
const char sFALSE[] PROGMEM = "FALSE";        // 10
const char sFOR[] PROGMEM = "FOR";            // 11
const char sGOSUB[] PROGMEM = "GOSUB";        // 12
const char sGOTO[] PROGMEM = "GOTO";          // 13
const char sGO[] PROGMEM = "GO";              // 14
const char sIF[] PROGMEM = "IF";              // 15
const char sINPUT[] PROGMEM = "INPUT";        // 16
const char sLET[] PROGMEM = "LET";            // 17
const char sLIST[] PROGMEM = "LIST";
const char sLOAD[] PROGMEM = "LOAD";
const char sNEW[] PROGMEM = "NEW";
const char sNEXT[] PROGMEM = "NEXT";
const char sON[] PROGMEM = "ON";
const char sOPTION[] PROGMEM = "OPTION";
const char sPRINT[] PROGMEM = "PRINT";
const char sRANDOMIZE[] PROGMEM = "RANDOMIZE";
const char sREAD[] PROGMEM = "READ";
const char sREM[] PROGMEM = "REM";
const char sRETURN[] PROGMEM = "RETURN";
const char sRUN[] PROGMEM = "RUN";
const char sSAVE[] PROGMEM = "SAVE";
const char sSTEP[] PROGMEM = "STEP";
const char sSTOP[] PROGMEM = "STOP";
const char sTAB[] PROGMEM = "TAB";
const char sTHEN[] PROGMEM = "THEN";
const char sTO[] PROGMEM = "TO";
const char sTRUE[] PROGMEM = "TRUE";
#if USE_DUMP
const char sVARS[] PROGMEM = "VARS";
#endif

const char sOP_AND[] PROGMEM = "AND";
const char sOP_NOT[] PROGMEM = "NOT";
const char sOP_OR[] PROGMEM = "OR";

const char sSTAR[] PROGMEM = "*";
const char sSLASH[] PROGMEM = "/";
const char sPLUS[] PROGMEM = "+";
const char sMINUS[] PROGMEM = "-";
const char sEQUALS[] PROGMEM = "=";
const char sCOLON[] PROGMEM = ":";
const char sSEMI[] PROGMEM = ";";
const char sLT[] PROGMEM = "<";
const char sGT[] PROGMEM = ">";
const char sLTE[] PROGMEM = "<=";
const char sGTE[] PROGMEM = ">=";
const char sNE[] PROGMEM = "<>";
const char sNEA[] PROGMEM = "><";
const char sCOMMA[] PROGMEM = ",";
const char sPOW[] PROGMEM = "^";
const char sLPAREN[] PROGMEM = "(";
const char sRPAREN[] PROGMEM = ")";

const char sREAL_IDENT[] PROGMEM = "REAL_IDENT";
const char sINTEGER_IDENT[] PROGMEM = "INTEGER_IDENT";
const char sLONGINT_IDENT[] PROGMEM = "LONGINT_IDENT";
const char sSTRING_IDENT[] PROGMEM = "STRING_IDENT";
const char sBOOL_IDENT[] PROGMEM = "BOOL_IDENT";

const char sINTEGER[] PROGMEM = "C_INTEGER";
const char sREAL[] PROGMEM = "C_REAL";
const char sBOOLEAN[] PROGMEM = "C_BOOLEAN";
const char sSTRING[] PROGMEM = "C_STRING";

PGM_P const Lexer::tokenStrings[uint8_t(Token::NUM_TOKENS)] PROGMEM = {
	sNOTOKENS,  // 0
#if USE_DUMP
	sARRAYS,    // 1
#endif
	sBASE,      // 2
	sCLS,       // 3
	sDATA,      // 4
	sDEF,       // 5
	sDELAY,     // 6
	sDIM,       // 7
#if USE_DUMP
	sDUMP,      // 8
#endif
	sEND,       // 9
	sFALSE,     // 10
	sFOR,       // 11
	sGOSUB,     // 12
	sGOTO,      // 13
	sGO,        // 14
	sIF,        // 15
	sINPUT,     // 16
	sLET,       // 17
	sLIST,
	sLOAD,
	sNEW,
	sNEXT,
	sON,
	sOPTION,
	sPRINT,
	sRANDOMIZE,
	sREAD,
	sREM,
	sRETURN,
	sRUN,
	sSAVE,
	sSTEP,
	sSTOP,
	sTAB,
	sTHEN,
	sTO,
	sTRUE,
#if USE_DUMP
	sVARS,
#endif

	sOP_AND, sOP_NOT, sOP_OR,

	sSTAR, sSLASH, sPLUS, sMINUS,

	sEQUALS,
	sCOLON, sSEMI,
	sLT, sGT,
	sLTE, sGTE,
	sNE, sNEA,
	sCOMMA,
	sPOW,
	sLPAREN, sRPAREN,

	sREAL_IDENT, sINTEGER_IDENT, sLONGINT_IDENT, sSTRING_IDENT,
	sBOOL_IDENT,

	sINTEGER, sREAL, sBOOLEAN, sSTRING
};

static const uint8_t tokenTable[] PROGMEM = {
	0x80,
#if USE_DUMP
	'A', 'R', 'R', 'A', 'Y', 'S'+0x80, // 1
#endif
	'B', 'A', 'S', 'E'+0x80,           // 2
	'C', 'L', 'S'+0x80,                // 3
	'D', 'A', 'T', 'A'+0x80,           // 4
	'D', 'E', 'F'+0x80,                // 5
	'D', 'E', 'L', 'A', 'Y'+0x80,      // 6
	'D', 'I', 'M'+0x80,                // 7
#if USE_DUMP
	'D', 'U', 'M', 'P'+0x80,           // 8
#endif
	'E', 'N', 'D'+0x80,                // 9
	'F', 'A', 'L', 'S', 'E'+0x80,      // 10
	'F', 'O', 'R'+0x80,                // 11
	'G', 'O', 'S', 'U', 'B'+0x80,      // 12
	'G', 'O', 'T', 'O'+0x80,           // 13
	'G', 'O'+0x80,                     // 14
	'I', 'F'+0x80,                     // 15
	'I', 'N', 'P', 'U', 'T'+0x80,      // 16
	'L', 'E', 'T'+0x80,                // 17
	'L', 'I', 'S', 'T'+0x80,           // 18
	'L', 'O', 'A', 'D'+0x80,           // 19
	'N', 'E', 'W'+0x80,                // 20
	'N', 'E', 'X', 'T'+0x80,           // 21
	'O', 'N'+0x80,                     // 22
	'O', 'P', 'T', 'I', 'O', 'N'+0x80, // 23
	'P', 'R', 'I', 'N', 'T'+0x80,      // 24
	'R', 'A', 'N', 'D', 'O', 'M', 'I', 'Z', 'E'+0x80, //25
	'R', 'E', 'A', 'D'+0x80,           // 26
	'R', 'E', 'M'+0x80,
	'R', 'E', 'T', 'U', 'R', 'N'+0x80,
	'R', 'U', 'N'+0x80,
	'S', 'A', 'V', 'E'+0x80,
	'S', 'T', 'E', 'P'+0x80,
	'S', 'T', 'O', 'P'+0x80,
	'T', 'A', 'B'+0x80,
	'T', 'H', 'E', 'N'+0x80,
	'T', 'O'+0x80,
	'T', 'R', 'U', 'E'+0x80,
#if USE_DUMP
	'V', 'A', 'R', 'S'+0x80,
#endif
	0
};

#if ARDUINO_LOG

Logger&
operator<<(Logger &logger, Token tok)
{
	char buf[12];
	strcpy_P(buf, (PGM_P) pgm_read_word(&(Lexer::tokenStrings[tok])));

	logger.log(buf);
	return (logger);
}
#endif

#define SYM (uint8_t(_string[_pointer]))

const uint8_t*
Lexer::getTokenString(Token t) const
{
	const uint8_t *result = tokenTable;
	
	uint8_t c; uint8_t index = 0;
	while ((c = pgm_read_byte(result)) != 0) {
		if (index == uint8_t(t))
			return (result);
		if (c&0x80)
			++index;
		c=pgm_read_byte(++result);
	}
	return NULL;
}

void
Lexer::init(const char *string)
{
	LOG_TRACE;
	assert(string != NULL);

	_pointer = 0, _string = string;
}

bool
Lexer::getNext()
{
	LOG_TRACE;

	_token = Token::NOTOKENS;
	_valuePointer = 0;
	while (SYM > 0) {
		if (isdigit(SYM)) {
			decimalNumber();
			return (true);
		} else if (isalpha(SYM)) {
			uint8_t index;
			uint8_t *pos = (uint8_t*)_string+_pointer;
			if ((pos = scanTable(pos, tokenTable, index)) != NULL) {
				_token = Token(index);
				_pointer += uint8_t(pos - ((uint8_t*)_string+
				    _pointer));
				return (true);
			}
		}
		switch (SYM) {
		case 'A':
			_id[_valuePointer++] = SYM;
			first_A();
			return (true);
		case 'N':
			_id[_valuePointer++] = SYM;
			first_N();
			return true;
		case 'O':
			_id[_valuePointer++] = SYM;
			first_O();
			return true;
		case '=':
			_token = Token::EQUALS;
			next();
			return true;
		case ';':
			_token = Token::SEMI;
			next();
			return true;
		case ',':
			_token = Token::COMMA;
			next();
			return true;
		case ':':
			_token = Token::COLON;
			next();
			return true;
		case '<':
			fitst_LT();
			return true;
		case '>':
			fitst_GT();
			return true;
		case '(':
			_token = Token::LPAREN;
			next();
			return true;
		case ')':
			_token = Token::RPAREN;
			next();
			return true;
		case '+':
			_token = Token::PLUS;
			next();
			return true;
		case '-':
			_token = Token::MINUS;
			next();
			return true;
		case '*':
			_token = Token::STAR;
			next();
			return true;
		case '/':
			_token = Token::SLASH;
			next();
			return true;
		case '^':
			_token = Token::POW;
			next();
			return true;
		case '"':
			next();
			stringConst();
			return true;
		case ' ':
		case '\t':
		case '\r':
		case '\n':
			next();
			break;
		default:
			if (SYM >= 0x80) {
				_token = Token(SYM & 0x7F);
				next();
				if (_token == Token::C_INTEGER)
					binaryInteger();
			} else if (isalpha(SYM)) {
				pushSYM();
				ident();
			} else
				next();
			return true;
		}
	}
	return (false);
}

void
Lexer::pushSYM()
{
	if (_valuePointer < STRINGSIZE - 1)
		_id[_valuePointer++] = SYM;
	next();
}

void
Lexer::next()
{
	++_pointer;
}

void
Lexer::first_A()
{
	next();
	switch (SYM) {
	case 'N':
		pushSYM();
		switch (SYM) {
		case 'D':
			next();
			_token = Token::OP_AND;
			return;
		}
		break;
	}
	ident();
}

void
Lexer::first_N()
{
	next();
	switch (SYM) {
	case 'O':
		pushSYM();
		switch (SYM) {
		case 'T':
			next();
			_token = Token::OP_NOT;
			return;
		}
		break;
	}
	ident();
}

void
Lexer::first_O()
{
	next();
	switch (SYM) {
	case 'R':
		next();
		_token = Token::OP_OR;
		return;
	}
	ident();
}

void
Lexer::fitst_LT()
{
	next();
	switch (SYM) {
	case '=':
		_token = Token::LTE;
		break;
	case '>':
		_token = Token::NE;
		break;
	default:
		_token = Token::LT;
		return;
	}
	next();
}

void
Lexer::fitst_GT()
{
	next();
	switch (SYM) {
	case '=':
		_token = Token::GTE;
		break;
	case '<':
		_token = Token::NEA;
		break;
	default:
		_token = Token::GT;
		return;
	}
	next();
}

void
Lexer::decimalNumber()
{
	LOG_TRACE;

#if USE_LONGINT
	_value.type = Parser::Value::LONG_INTEGER;
	LongInteger *val = &_value.value.longInteger;
#else
	_value.type = Parser::Value::INTEGER;
	Integer *val = &_value.value.integer;
#endif
	*val = SYM - '0';
	while (SYM > 0) {
		next();
		if (isdigit(SYM)) {
			*val *= Integer(10);
			*val += SYM - '0';
			continue;
		}
		switch (SYM) {
#if USE_REALS
		case '.':
		{
			_value.type = Parser::Value::REAL;
			_value.value.real = Real(*val);
			Real d = 1;
			while (true) {
				next();
				if (isdigit(SYM)) {
					d /= 10.f;
					_value.value.real += Real(SYM - '0') * d;
					continue;
				} else if (SYM == 0) {
					_token = Token::C_REAL;
					return;
				} else if (SYM == 'E') {
					if (!numberScale())
						_token = Token::NOTOKENS;
					else
						_token = Token::C_REAL;
					return;
				} else {
					_token = Token::C_REAL;
					return;
				}
			}
		}
			break;
		case 'E':
		{
			if (_value.type == Parser::Value::INTEGER
#if USE_LONGINT
			    || _value.type == Parser::Value::LONG_INTEGER
#endif   
			    )
				_value = Real(_value);
			if (!numberScale()) {
				_token = Token::NOTOKENS;
				return;
			}
		}
#endif
		default:
			if (_value.type == Parser::Value::INTEGER
#if USE_LONGINT
			    || _value.type == Parser::Value::LONG_INTEGER
#endif
			    )
				_token = Token::C_INTEGER;
#if USE_REALS
			else
				_token = Token::C_REAL;
#endif
			return;
		}
	}
}

void
Lexer::binaryInteger()
{
#if USE_LONGINT
	_value.type = Parser::Value::LONG_INTEGER;
	LongInteger *val = &_value.value.longInteger;
	*val = LongInteger(SYM) << 24;
	next();
	*val |= LongInteger(SYM) << 16;
	next();
	*val |= LongInteger(SYM) << 8;
	next();
	*val |= LongInteger(SYM);
	next();
#else
	_value.type = Parser::Value::INTEGER;
	Integer *val = &_value.value.integer;
	*val = Integer(SYM) << uint8_t(8);
	next();
	*val |= Integer(SYM);
	next();
#endif
}

#if USE_REALS

bool
Lexer::numberScale()
{
	Integer scale(0);
	bool sign = true;

	next();
	if (SYM == '-') {
		sign = false;
		next();
	}
	if (isdigit(SYM)) {
		scale += SYM - '0';
		next();
	} else
		return false;

	while (true) {
		if (isdigit(SYM)) {
			scale *= Integer(10);
			scale += SYM - '0';
			next();
			continue;
		} else {
			if (!sign)
				scale = -scale;
			Real pw = pow(Real(10), scale);
			_value *= pw;
			return true;
		}
	}
}
#endif

void
Lexer::ident()
{
	while (isalnum(SYM)) {
		pushSYM();
	}
	if (SYM == '%') {
		pushSYM();
#if USE_LONGINT
		if (SYM == '%') {
			pushSYM();
			_token = Token::LONGINT_IDENT;
		} else
#endif
			_token = Token::INTEGER_IDENT;
	} else if (SYM == '$') {
		pushSYM();
		_token = Token::STRING_IDENT;
	} else if (SYM == '!') {
		pushSYM();
		_token = Token::BOOL_IDENT;
	} else
		_token = Token::REAL_IDENT;
	_value.type = Parser::Value::STRING;
	_id[_valuePointer] = 0;
}

void
Lexer::stringConst()
{
	while (SYM != 0) {
		if (SYM == '"') {
			next();
			_token = Token::C_STRING;
			_id[_valuePointer] = 0;
			return;
		}
		pushSYM();
	}
}

}
