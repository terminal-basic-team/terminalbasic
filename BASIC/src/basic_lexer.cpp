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

#include "basic_lexer.hpp"
#include "helper.hpp"

#include <string.h>
#include <ctype.h>

/*
 * COM_DATA = "DATA"
 * COM_DUMP = "DUMP"
 * COM_LIST = "LIST"
 * COM_LOAD = "LOAD"
 * COM_NEW = "NEW"
 * COM_RUN = "RUN"
 * COM_SAVE = "SAVE"
 * 
 * KW_DIM = "DIM"
 * KW_END = "END"
 * KW_FOR = "FOR"
 * KW_GOSUB = "GOSUB"
 * KW_GOTO = "GOTO"
 * KW_IF = "IF"
 * KW_INPUT = "INPUT"
 * KW_LET = "LET"
 * KW_NEXT = "NEXT"
 * KW_PRINT = "PRINT"
 * KW_RETURN = "RETURN"
 * 
 * KW_ARRAYS = "ARRAYS"
 * KW_THEN = "THEN"
 * KW_TO = "TO"
 * KW_STEP = "STEP"
 * KW_VARS = "VARS"
 * 
 * OP_AND = "AND"
 * OP_OR = "OR"
 * OP_NOT = "NOT"
 * 
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

#if ARDUINO_LOG
const char sNOTOKENS[] PROGMEM = "NOTOKENS";

const char sDATA[] PROGMEM = "DATA";
const char sDUMP[] PROGMEM = "DUMP";
const char sLIST[] PROGMEM = "LIST";
const char sLOAD[] PROGMEM = "LOAD";
const char sNEW[] PROGMEM = "NEW";
const char sRUN[] PROGMEM = "RUN";
const char sSAVE[] PROGMEM = "SAVE";

const char sDIM[] PROGMEM = "DIM";
const char sEND[] PROGMEM = "END";
const char sFOR[] PROGMEM = "FOR";
const char sGOSUB[] PROGMEM = "GOSUB";
const char sGOTO[] PROGMEM = "GOTO";
const char sIF[] PROGMEM = "IF";
const char sINPUT[] PROGMEM = "INPUT";
const char sLET[] PROGMEM = "LET";
const char sNEXT[] PROGMEM = "NEXT";
const char sPRINT[] PROGMEM = "PRINT";
const char sREM[] PROGMEM = "REM";
const char sRETURN[] PROGMEM = "RETURN";

const char sARRAYS[] PROGMEM = "ARRAYS";
const char sTHEN[] PROGMEM = "THEN";
const char sTO[] PROGMEM = "TO";
const char sSTEP[] PROGMEM = "STEP";
const char sVARS[] PROGMEM = "VARS";

const char sREAL_IDENT[] PROGMEM = "REAL_IDENT";
const char sINTEGER_IDENT[] PROGMEM = "INTEGER_IDENT";
const char sSTRING_IDENT[] PROGMEM = "STRING_IDENT";

const char sINTEGER[] PROGMEM = "C_INTEGER";
const char sREAL[] PROGMEM = "C_REAL";
const char sSTRING[] PROGMEM = "C_STRING";

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

PGM_P const Lexer::tokenStrings[NUM_TOKENS] PROGMEM = {
	sNOTOKENS,
	
	sDATA,	sDUMP,	sLIST, sLOAD,	sNEW,	sRUN,	sSAVE,
	
	sDIM,	sEND,	sFOR,	sGOSUB,	sGOTO,	sIF,	sINPUT,	sLET,	sNEXT,
	sPRINT,	sREM,	sRETURN,
	
	sARRAYS,sTHEN,	sTO,	sSTEP,	sVARS,
	
	sREAL_IDENT,	sINTEGER_IDENT,	sSTRING_IDENT,
	
	sINTEGER,	sREAL,	sSTRING,
	
	sSTAR,	sSLASH,	sPLUS,	sMINUS,
	
	sEQUALS,
	sCOLON,
	sSEMI,
	sLT,
	sGT,
	sLTE,
	sGTE,
	sNE,
	sNEA,
	sCOLON,
	sPOW,
};

Logger&
operator<<(Logger &logger, Token tok)
{
	char buf[8];
	strcpy_P(buf, (PGM_P) pgm_read_word(&(Lexer::tokenStrings[tok])));

	logger.log(buf);
	return (logger);
}
#endif

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
		if (isdigit(SYM)) {
			_value.type = Parser::Value::INTEGER;
			_value.value.integer = SYM - '0';
			decimalNumber();
			return true;
		} else
			switch (SYM) {
			case 'A':
				_id[_valuePointer++] = SYM;
				first_A();
				return true;
			case 'D':
				_id[_valuePointer++] = SYM;
				first_D();
				return true;				
			case 'E':
				_id[_valuePointer++] = SYM;
				first_E();
				return true;
			case 'F':
				_id[_valuePointer++] = SYM;
				first_F();
				return true;
			case 'G':
				_id[_valuePointer++] = SYM;
				first_G();
				return true;
			case 'I':
				_id[_valuePointer++] = SYM;
				first_I();
				return true;
			case 'L':
				_id[_valuePointer++] = SYM;
				first_L();
				return true;
			case 'N':
				_id[_valuePointer++] = SYM;
				first_N();
				return true;
			case 'O':
				_id[_valuePointer++] = SYM;
				first_O();
				return true;
			case 'P':
				_id[_valuePointer++] = SYM;
				first_P();
				return true;
			case 'R':
				_id[_valuePointer++] = SYM;
				first_R();
				return true;
			case 'S':
				_id[_valuePointer++] = SYM;
				first_S();
				return true;
			case 'T':
				_id[_valuePointer++] = SYM;
				first_T();
				return true;
			case 'V':
				_id[_valuePointer++] = SYM;
				first_V();
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
					next();
					_token = Token(SYM & 0x7F);
				} else if (isalpha(SYM)) {
					pushSYM();
					ident();
				} else {
					next();
					_token = NOTOKENS;
				}
				return true;
			}
	}
	return false;
}

void Lexer::pushSYM()
{
	if (_valuePointer < STRINGSIZE - 1)
		_id[_valuePointer++] = SYM;
	next();
}

void Lexer::next()
{
	++_pointer;
}

void Lexer::first_A()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'N':
		pushSYM();
		switch (SYM) {
		case 'D':
			next();
			_token = OP_AND;
			return;
		}
		break;
	case 'R':
		pushSYM();
		switch (SYM) {
		case 'R':
			pushSYM();
			switch (SYM) {
			case 'A':
				pushSYM();
				switch (SYM) {
				case 'Y':
					pushSYM();
					switch (SYM) {
					case 'S':
						next();
						_token = KW_ARRAYS;
						return;
					}
					break;
				}
				break;
			}
			break;
		}
		break;
	}
	ident();
}

void Lexer::first_D()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'A':
		pushSYM();
		switch (SYM) {
		case 'T':
			pushSYM();
			switch (SYM) {
			case 'A':
				next();
				_token = COM_DATA;
				return;
			}
			break;
		}
		break;
	case 'I':
		pushSYM();
		switch (SYM) {
		case 'M':
			next();
			_token = KW_DIM;
			return;
		}
		break;
	case 'U':
		pushSYM();
		switch (SYM) {
		case 'M':
			pushSYM();
			switch (SYM) {
			case 'P':
				next();
				_token = COM_DUMP;
				return;
			}
			break;
		}
		break;
	}
	ident();
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
			next();
			_token = KW_END;
			return;
		}
		break;
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
			next();
			_token = KW_FOR;
			return;
		}
		break;
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
				next();
				_token = KW_GOTO;
				return;
			}
			break;
		case 'S':
			pushSYM();
			switch (SYM) {
			case 'U':
				pushSYM();
				switch (SYM) {
				case 'B':
					next();
					_token = KW_GOSUB;
					return;
				}
				break;
			}
			break;
		}
		break;
	}
	ident();
}

void Lexer::first_I()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'F':
		next();
		_token = KW_IF;
		return;
	case 'N':
		pushSYM();
		switch (SYM) {
		case 'P':
			pushSYM();
			switch (SYM) {
			case 'U':
				pushSYM();
				switch (SYM) {
				case 'T':
					next();
					_token = KW_INPUT;
					return;
				}
			}
		}
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
				next();
				_token = COM_LIST;
				return;
			}
			break;
		}
		break;
	case 'E':
		pushSYM();
		switch (SYM) {
		case 'T':
			next();
			_token = KW_LET;
			return;
		}
		break;
	case 'O':
		pushSYM();
		switch (SYM) {
		case 'A':
			pushSYM();
			switch (SYM) {
			case 'D':
				next();
				_token = COM_LOAD;
				return;
			}
			break;
		}
		break;
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
				next();
				_token = KW_NEXT;
				return;
			}
			break;
		case 'W':
			next();
			_token = COM_NEW;
			return;
		}
	}
	ident();
}

void Lexer::first_O()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'R':
		next();
		_token = OP_OR;
		return;
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
					next();
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
		case 'M':
			next();
			_token = KW_REM;
			return;
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
						next();
						_token = KW_RETURN;
						return;
					}
					break;
				}
				break;
			}
			break;
		}
		break;
	case 'U':
		pushSYM();
		switch (SYM) {
		case 'N':
			next();
			_token = COM_RUN;
			return;
		}
	}
	ident();
}

void Lexer::first_S()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'A':
		pushSYM();
		switch (SYM) {
		case 'V':
			pushSYM();
			switch (SYM) {
			case 'E':
				next();
				_token = COM_SAVE;
				return;
			}
			break;
		}
		break;
	case 'T':
		pushSYM();
		switch (SYM) {
		case 'E':
			pushSYM();
			switch (SYM) {
			case 'P':
				next();
				_token = KW_STEP;
				return;
			}
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
				next();
				_token = KW_THEN;
				return;
			}
			break;
		}
		break;
	case 'O':
		next();
		_token = KW_TO;
		return;
	}
	ident();
}

void Lexer::first_V()
{
	_token = NOTOKENS;

	next();
	switch (SYM) {
	case 'A':
		pushSYM();
		switch (SYM) {
		case 'R':
			pushSYM();
			switch (SYM) {
			case 'S':
				next();
				_token = KW_VARS;
				return;
			}
			break;
		}
		break;
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
	case '<':
		_token = NEA;
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

void Lexer::ident()
{
	while (isalnum(SYM)) {
		pushSYM();
	}
	if (SYM == '%') {
		pushSYM();
		_token = INTEGER_IDENT;
	} else if (SYM == '$') {
		pushSYM();
		_token = STRING_IDENT;
	} else
		_token = REAL_IDENT;
	_value.type = Parser::Value::STRING;
	_id[_valuePointer] = 0;
}

void Lexer::stringConst()
{
	_token = NOTOKENS;
	
	while (SYM != 0) {
		if (SYM == '"') {
			next();
			_token = C_STRING;
			_id[_valuePointer] = 0;
			return;
		}
		pushSYM();
	}
}


}
