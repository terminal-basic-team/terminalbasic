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

#include <math.h>
#include <string.h>

#include "basic_parser.hpp"
#include "basic_interpreter.hpp"
#include "basic_interpreter_program.hpp"

/*
 * TEXT = OPERATORS | C_INTEGER OPERATORS
 * OPERATORS = OPERATOR | OPERATOR COLON OPERATORS
 * OPERATOR = COMMAND |
 *      KW_END |
 *	KW_RETURN |
 *	KW_REM TEXT |
 *	KW_INPUT VAR_LIST |
 *	KW_PRINT PRINT_LIST |
 *	KW_IF EXPRESSION IF_STATEMENT |
 *	KW_FOR FOR_CONDS |
 *	KW_NEXT IDENT |
 *	ASSIGNMENT |TURN |
 *	GOTO_STATEMENT |
 *	KW_GOSUB INTEGER |
 *	KW_DIM ARRAYS_LIST
 * COMMAND = COM_DUMP | COM_DUMP KW_VARS | COM_DUMP KW_ARRAYS
 *	COM_LIST | COM_NEW | COM_RUN | COM_SAVE | COM_LOAD
 * ASSIGNMENT = KW_LET IMPLICIT_ASSIGNMENT | IMPLICIT_ASSIGNMENT
 * IMPLICIT_ASSIGNMENT = VAR EQUALS EXPRESSION | VAR ARRAY EQUALS EXPRESSION
 * EXPRESSION = SIMPLE_EXPRESSION | SIMPLE_EXPRESSION REL SIMPLE_EXPRESSION
 * REL = LT | LTE | EQUALS | GT | GTE | NE | NEA
 * SIMPLE_EXPRESSION = TERM | TERM ADD TERM
 * ADD = PLUS MINUS KW_OR
 * TERM = FACTOR | FACTOR MUL FACTOR
 * MUL = STAR | SLASH | DIV | MOD | KW_AND
 * FACTOR = FINAL | FINAL POW FINAL
 * FINAL = C_INTEGER | C_REAL | C_STRING | VAR | VAR ARRAY |
 *	LPAREN EXPRESSION RPAREN | MINUS FINAL
 * VAR = REAL_IDENT | INTEGER_IDENT | STRING_IDENT
 * VAR_LIST = VAR | VAR VAR_LIST
 * PRINT_LIST = EXPRESSION | EXPRESSION COMMA PRINT_LIST
 * IF_STATEMENT = GOTO_STATEMEMNT | KW_THEN OPERATORS
 * GOTO_STATEMENT = KW_GOTO C_INTEGER
 * FOR_CONDS = IMPLICIT_ASSIGNMENT KW_TO EXPRESSION |
 *	IMPLICIT_ASSIGNMENT KW_TO EXPRESSION KW_STEP EXPRESSION
 * ARRAYS_LIST = VAR ARRAY | VAR ARRAY ARRAYS_LIST
 * ARRAY = LPAREN DIMENSIONS RPAREN
 * DIMENSIONS = C_INTEGER | C_INTEGER COMMA DIMENSIONS
 */

namespace BASIC
{

Parser::Parser(Lexer &l, Interpreter &i, FunctionBlock *first) :
_lexer(l), _interpreter(i), _mode(EXECUTE), _firstFB(first)
{
}

bool
Parser::parse(const char *s)
{
	LOG_TRACE;

	_lexer.init(s);
	_stopParse = false;
	_error = NO_ERROR;
	
	return fOperators();
}

bool
Parser::fOperators()
{
	Token t;
	do {
		if (_lexer.getNext()) {
			if (!fOperator()) {
				if (_error == NO_ERROR)
					_error = OPERATOR_EXPECTED;
				return false;
			}
		} else
			return true;
		t = _lexer.getToken();
	} while (t == COLON && !_stopParse);
	return true;
}

bool
Parser::fOperator()
{
	LOG_TRACE;

	Token t = _lexer.getToken();
	LOG(t);
	switch (t) {
	case KW_DIM:
		if (!fArrayList())
			return false;
		else
			return true;
	case KW_END:
		if (_mode == EXECUTE)
			_interpreter.end();
		return true;
	case KW_FOR:
		return fForConds();
	case KW_GOSUB:
	{
		Value v;
		if (!_lexer.getNext() || !fExpression(v) || (v.type !=
		    Value::INTEGER)) {
			_error = INTEGER_EXPRESSION_EXPECTED;
			return false;
		}
		if (_mode == EXECUTE) {
			_interpreter.pushReturnAddress(_lexer.getPointer());
			_interpreter.gotoLine(v.value.integer);
		}
		_stopParse = true;
		return true;
	}
	case KW_IF:
	{
		Value v;
		if (!_lexer.getNext() || !fExpression(v)) {
			_error = EXPRESSION_EXPECTED;
			return false;
		}
		bool res;
		if (!bool(v))
			_mode = SCAN;
		if (fIfStatement())
			res = true;
		else {
			_error = THEN_OR_GOTO_EXPECTED;
			res = false;
		}
		_mode = EXECUTE;
		return res;
	}
	case KW_INPUT:
	{
		if (!fVarList()) {
			_error = VARIABLES_LIST_EXPECTED;
			return false;
		} else
			return true;
	}
	case KW_LET:
	{
		char vName[VARSIZE];
		if (!_lexer.getNext() || !fImplicitAssignment(vName)) {
			return false;
		} else
			return true;
	}
	case KW_NEXT:
		if (!_lexer.getNext() || (_lexer.getToken() != REAL_IDENT &&
		    _lexer.getToken() != INTEGER_IDENT))
			return false;
		if (_mode == EXECUTE)
			_stopParse = !_interpreter.next(_lexer.id());
		if (!_stopParse)
			_lexer.getNext();
		return true;
	case KW_PRINT:
		if (_lexer.getNext())
			if (!fPrintList())
				return false;
		if (_mode == EXECUTE)
			_interpreter.print('\n');
		return true;
	case KW_REM:
		while (_lexer.getNext());
		return true;
	case KW_RETURN:
		if (_mode == EXECUTE)
			_interpreter.returnFromSub();
		return true;
	default:
		if (fCommand())
			return true;
		if (fGotoStatement())
			return true;
		{
			char vName[VARSIZE];
			if (fImplicitAssignment(vName))
				return true;
		}
		_error = OPERATOR_EXPECTED;
		return false;
	}
}

bool
Parser::fImplicitAssignment(char *varName)
{
	LOG_TRACE;

	if (fVar(varName) && _lexer.getNext()) {
		uint8_t dimensions;
		Value v;
		bool array;
		if (_lexer.getToken() == LPAREN) {
			if (fArray(dimensions))
				array = true;
			else
				return false;
		} else
			array = false;
		if ((_lexer.getToken() == EQUALS) && _lexer.getNext() &&
			fExpression(v)) {
			if (_mode == EXECUTE) {
				if (array)
					_interpreter.setArrayElement(varName, v);
				else
					_interpreter.setVariable(varName, v);
			}
			return true;
		} else {
			_error = EXPRESSION_EXPECTED;
		}
	}
	return false;
}

bool
Parser::fPrintList()
{
	LOG_TRACE;

	Value v;
	if (!fExpression(v)) {
		_error = EXPRESSION_EXPECTED;
		return false;
	}

	if (_mode == EXECUTE)
		_interpreter.print(v);
	while (true) {
		Token t = _lexer.getToken();
		switch (t) {
		case COMMA:
			if (!_lexer.getNext() || !fExpression(v)) {
				_error = EXPRESSION_EXPECTED;
				return false;
			}
			if (_mode == EXECUTE) {
				_interpreter.print('\t');
				_interpreter.print(v);
			}
			break;
		default:
			return true;
		}
	}
}

bool
Parser::fExpression(Value &v)
{
	LOG_TRACE;

	if (!fSimpleExpression(v))
		return false;

	while (true) {
		Token t = _lexer.getToken();
		Value v2;
		switch (t) {
		case LT:
			if (_lexer.getNext() && fSimpleExpression(v2)) {
				v.value.boolean = v < v2;
				v.type = Value::BOOLEAN;
				continue;
			} else
				return false;
		case LTE:
			if (_lexer.getNext() && fSimpleExpression(v2)) {
				v.value.boolean = (v < v2) || (v == v2);
				v.type = Value::BOOLEAN;
				continue;
			} else
				return false;
		case GT:
			if (_lexer.getNext() && fSimpleExpression(v2)) {
				v.value.boolean = v > v2;
				v.type = Value::BOOLEAN;
				continue;
			} else
				return false;
		case GTE:
			if (_lexer.getNext() && fSimpleExpression(v2)) {
				v.value.boolean = (v > v2) || (v == v2);
				v.type = Value::BOOLEAN;
				continue;
			} else
				return false;
		case EQUALS:
			if (_lexer.getNext() && fSimpleExpression(v2)) {
				v.value.boolean = v == v2;
				v.type = Value::BOOLEAN;
				continue;
			} else
				return false;
		case NE:
			if (_lexer.getNext() && fSimpleExpression(v2)) {
				v.value.boolean = !(v == v2);
				v.type = Value::BOOLEAN;
				continue;
			} else
				return false;
		default:
			return true;
		}
		v.type = Value::BOOLEAN;
	}
}

bool
Parser::fSimpleExpression(Value &v)
{
	LOG_TRACE;

	if (!fTerm(v))
		return false;

	while (true) {
		Token t = _lexer.getToken();
		LOG(t);
		Value v2;
		switch (t) {
		case PLUS:
			if (_lexer.getNext() && fTerm(v2)) {
				if (v.type == Value::STRING &&
				    v2.type == Value::STRING)
					_interpreter.strConcat(v,v2);
				v += v2;
				continue;
			} else
				return false;
		case MINUS:
			if (_lexer.getNext() && fTerm(v2)) {
				v -= v2;
				continue;
			} else
				return false;
		default:
			return true;
		}
	}
}

bool
Parser::fTerm(Value &v)
{
	LOG_TRACE;

	if (!fFactor(v))
		return false;

	while (true) {
		Token t = _lexer.getToken();
		LOG(t);
		Value v2;
		switch (t) {
		case STAR:
			if (_lexer.getNext() && fTerm(v2)) {
				v *= v2;
				continue;
			} else
				return false;
		case SLASH:
			if (_lexer.getNext() && fTerm(v2)) {
				v /= v2;
				continue;
			} else
				return false;
		default:
			return true;
		}
	}
}

bool
Parser::fFactor(Value &v)
{
	LOG_TRACE;

	if (!fFinal(v))
		return false;

	while (true) {
		Token t = _lexer.getToken();
		LOG(t);
		Value v2;
		switch (t) {
		case POW:
			if (_lexer.getNext() && fFactor(v2)) {
				v ^= v2;
				continue;
			} else
				return false;
		default:
			return true;
		}
	}
}

bool
Parser::fFinal(Value &v)
{
	LOG_TRACE;

	Token t = _lexer.getToken();
	LOG(t);
	while (true) {
		switch (t) {
		case MINUS:
			if (!_lexer.getNext() || !fFinal(v))
				return false;
			if (_mode == EXECUTE)
				v.switchSign();
			return true;
		case C_INTEGER:
		case C_REAL:
			if (_mode == EXECUTE)
				v = _lexer.getValue();
			_lexer.getNext();
			return true;
		case C_STRING:
			if (_mode == EXECUTE) {
				_interpreter.pushString(_lexer.id());
				v.type = Value::Type::STRING;
			}
			_lexer.getNext();
			return true;
		case LPAREN:
			if (!_lexer.getNext() || !fExpression(v))
				return false;
			if (_lexer.getToken() != RPAREN)
				return false;
			else {
				_lexer.getNext();
				return true;
			}
		default:
		{
			char varName[VARSIZE];
			if (fVar(varName))
				return fIdentifierExpr(varName, v);
		}
			return false;
		}
	}
}

bool
Parser::fIfStatement()
{
	Token t = _lexer.getToken();
	LOG(t);
	switch (t) {
	case KW_THEN:
		if (_lexer.getNext()) {
			if (_lexer.getToken() == C_INTEGER) {
				if (_mode == EXECUTE)
					_interpreter.gotoLine(Integer(_lexer.getValue()));
				_lexer.getNext();
				return true;
			} else if (fOperator())
				return true;
		}
		break;
	default:
		if (fGotoStatement())
			return true;
		break;
	}
	return false;
}

bool
Parser::fGotoStatement()
{
	Token t = _lexer.getToken();
	LOG(t);
	if (t == KW_GOTO) {
		Value v;
		if (!_lexer.getNext() || !fExpression(v) || (v.type != Value::INTEGER)) {
			_error = INTEGER_EXPRESSION_EXPECTED;
			return false;
		}
		if (_mode == EXECUTE) {
			_interpreter.gotoLine(v.value.integer);
			_stopParse = true;
		}
		return true;
	} else
		return false;
}

bool
Parser::fCommand()
{
	Token t = _lexer.getToken();
	LOG(t);
	switch (t) {
	case COM_DUMP:
	{
		Interpreter::DumpMode mode = Interpreter::MEMORY;
		if (_lexer.getNext()) {
			if (_lexer.getToken() == KW_VARS) {
				mode = Interpreter::VARS;
				_lexer.getNext();
			} else if (_lexer.getToken() == KW_ARRAYS) {
				mode = Interpreter::ARRAYS;
				_lexer.getNext();
			}
		}
		if (_mode == EXECUTE)
			_interpreter.dump(mode);
		return true;
	}
	case COM_LIST:
		if (_mode == EXECUTE)
			_interpreter.list();
		_lexer.getNext();
		return true;
	case COM_LOAD:
		if (_mode == EXECUTE)
			_interpreter.load();
		_lexer.getNext();
		return true;
	case COM_NEW:
		if (_mode == EXECUTE)
			_interpreter.newProgram();
		_lexer.getNext();
		return true;
	case COM_RUN:
		if (_mode == EXECUTE)
			_interpreter.run();
		_lexer.getNext();
		return true;
	case COM_SAVE:
		if (_mode == EXECUTE)
			_interpreter.save();
		_lexer.getNext();
		return true;
	default:
		return false;
	}
}

bool
Parser::fForConds()
{
	Value v;
	char vName[VARSIZE];
	if (!_lexer.getNext() || !fImplicitAssignment(vName) ||
	    _lexer.getToken()!=KW_TO || !_lexer.getNext() ||
	    !fExpression(v)) {
		return false;
	}
	Value vStep(Integer(1));
	if (_lexer.getToken() == KW_STEP && (!_lexer.getNext() ||
	    !fExpression(vStep)))
		return false;
	
	if (_mode == EXECUTE)
		_interpreter.pushForLoop(vName, _lexer.getPointer(), v, vStep);
	
	return true;
}

bool
Parser::fVarList()
{
	Token t;
	char varName[VARSIZE];
	do {
		if (!_lexer.getNext() || !fVar(varName))
			return false;
		if (_mode == EXECUTE)
			_interpreter.input(varName);
		if (!_lexer.getNext())
			return true;
		t = _lexer.getToken();
	} while (t == COMMA);
	return true;
}

bool
Parser::fVar(char *varName)
{
	if ((_lexer.getToken() != REAL_IDENT) &&
	    (_lexer.getToken() != INTEGER_IDENT) &&
	    (_lexer.getToken() != STRING_IDENT))
		return false;

	strcpy(varName, _lexer.id());
	return true;
}

bool
Parser::fArrayList()
{
	Token t;
	char arrName[VARSIZE];
	uint8_t dimensions;
	do {
		if (!_lexer.getNext() || !fVar(arrName) ||
		    !_lexer.getNext() || !fArray(dimensions))
			return false;
		_interpreter.pushDimensions(dimensions);
		_interpreter.newArray(arrName);
		t = _lexer.getToken();
	} while (t == COMMA);
	return true;
}

bool
Parser::fArray(uint8_t &dimensions)
{
	if (_lexer.getToken() != LPAREN ||
	    !fDimensions(dimensions) || _lexer.getToken() != RPAREN)
		return false;

	_lexer.getNext();
	return true;
}

bool
Parser::fDimensions(uint8_t &dimensions)
{
	Parser::Value v;
	dimensions = 0;
	do {
		if (!_lexer.getNext() || !fExpression(v))
			return false;
		_interpreter.pushDimension(Integer(v));
		++dimensions;
	} while (_lexer.getToken() == COMMA);
	return true;
}

bool
Parser::fIdentifierExpr(const char *varName, Value &v)
{
	 // Identifier, var or func or array ?
	if (_lexer.getNext() && _lexer.getToken()==
	    LPAREN) { // (, array or function
		FunctionBlock::function f;
		if (_firstFB != NULL && (f=_firstFB->getFunction(varName))) { // function
			Value arg;
			do {
				if (!_lexer.getNext())
					return false;
				else if (_lexer.getToken() == RPAREN) {
					break;
				} else {
					if (!fExpression(arg))
						return false;
					_interpreter.pushValue(arg);
				}
			} while (_lexer.getToken() == COMMA);
			_lexer.getNext();
			bool result = true;
			if (_mode == EXECUTE) {
				result = ((*f)(_interpreter));
				if (!_interpreter.popValue(v) || !result)
					return false;
			}
		} else { // No such function, array variable
			uint8_t dim;
			if (fArray(dim)) {
				if (_mode == EXECUTE &&
				    _interpreter.valueFromArray(v, varName))
					return true;
			} else
				return false;
		}
	} else
		if (_mode == EXECUTE)
			_interpreter.valueFromVar(v, varName);
	return true;
}

}
