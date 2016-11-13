#include <math.h>
#include <string.h>

#include "parser.hpp"
#include "basic_interpreter.hpp"
#include "basic_interpreter_program.hpp"

/*
 * TEXT = OPERATORS | C_INTEGER OPERATORS
 * OPERATORS = OPERATOR | OPERATOR COLON OPERATORS
 * OPERATOR = KW_END |
 *	KW_RUN |
 *	KW_LIST |
 *	KW_NEW |
 *	KW_DUMP |
 *	KW_RETURN |
 *	KW_PRINT PRINT_LIST |
 *	KW_IF EXPRESSION IF_STATEMENT |
 *	KW_FOR IMPLICIT_ASSIGNMENT KW_TO EXPRESSION |
 *	KW_NEXT IDENT |
 *	ASSIGNMENT |TURN |
 *	GOTO_STATEMENT |
 *	KW_GOSUB INTEGER
 * ASSIGNMENT = KW_LET IMPLICIT_ASSIGNMENT | IMPLICIT_ASSIGNMENT
 * IMPLICIT_ASSIGNMENT = IDENTIFIER EQUALS EXPRESSION
 * EXPRESSION = SIMPLE_EXPRESSION | SIMPLE_EXPRESSION REL SIMPLE_EXPRESSION
 * REL = LT | LTE | EQUALS | GT | GTE | NE
 * SIMPLE_EXPRESSION = TERM | TERM ADD TERM
 * ADD = PLUS MINUS KW_OR
 * TERM = FACTOR | FACTOR MUL FACTOR
 * MUL = STAR | SLASH | DIV | MOD | KW_AND
 * FACTOR = FINAL | FINAL POW FINAL
 * FINAL = IDENT | INTEGER | REAL | LPAREN EXPRESSION RPAREN | MINUS FINAL
 * PRINT_LIST = EXPRESSION | EXPRESSION COMMA PRINT_LIST
 * IF_STATEMENT = GOTO_STATEMEMNT | KW_THEN OPERATOR
 * GOTO_STATEMENT = KW_GOTO C_INTEGER
 */

namespace BASIC
{

void valueFromFrame(Parser::Value &v, const Interpreter::VariableFrame &f)
{
	switch (f.type) {
	case Interpreter::VariableFrame::INTEGER:
		v.type = Parser::Value::INTEGER;
		v.value.integer = f.get<Integer>();
		break;
	case Interpreter::VariableFrame::REAL:
		v.type = Parser::Value::REAL;
		v.value.real = f.get<Real>();
	}
}

Parser::Value::Value() :
type(INTEGER)
{
	value.integer = 0;
}

Parser::Value::operator Real() const
{
	switch (type) {
	case INTEGER:
		return float(value.integer);
	case REAL:
		return value.real;
	case BOOLEAN:
		return float(value.boolean);
	default:
		return float(NAN);
	}
}

Parser::Value::operator bool() const
{
	switch (type) {
	case INTEGER:
		return bool(value.integer);
	case REAL:
		return bool(value.real);
	case BOOLEAN:
		return value.boolean;
	default:
		// undefined
		break;
	}
}

Parser::Value::operator Integer() const
{
	switch (type) {
	case INTEGER:
		return value.integer;
	case REAL:
		return Integer(value.real);
	case BOOLEAN:
		return Integer(value.boolean);
	default:
		// undefined
		break;
	}
}

bool
Parser::Value::operator<(const Value &rhs) const
{
	switch (type) {
	case INTEGER:
		switch (rhs.type) {
		case INTEGER:
			return value.integer < rhs.value.integer;
		case REAL:
			return float(value.integer) < rhs.value.real;
		case BOOLEAN:
			return value.integer < Integer(rhs.value.boolean);
		}
	case REAL:
		return value.real < float(rhs);
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			return Integer(value.boolean) < rhs.value.integer;
		case REAL:
			return float(value.boolean) < rhs.value.real;
		case BOOLEAN:
			return value.boolean < rhs.value.boolean;
		}
	}
}

bool
Parser::Value::operator==(const Value &rhs) const
{
	switch (type) {
	case INTEGER:
		switch (rhs.type) {
		case INTEGER:
			return value.integer == rhs.value.integer;
		case REAL:
			return float(value.integer) == rhs.value.real;
		case BOOLEAN:
			return value.integer == Integer(rhs.value.boolean);
		}
	case REAL:
		return value.real == float(rhs);
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			return Integer(value.boolean) == rhs.value.integer;
		case REAL:
			return float(value.boolean) == rhs.value.real;
		case BOOLEAN:
			return value.boolean == rhs.value.boolean;
		}
	}
}

bool
Parser::Value::operator>(const Value &rhs) const
{
	switch (type) {
	case INTEGER:
		switch (rhs.type) {
		case INTEGER:
			return value.integer > rhs.value.integer;
		case REAL:
			return float(value.integer) > rhs.value.real;
		case BOOLEAN:
			return value.integer > Integer(rhs.value.boolean);
		}
	case REAL:
		return value.real > float(rhs);
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			return Integer(value.boolean) > rhs.value.integer;
		case REAL:
			return float(value.boolean) > rhs.value.real;
		case BOOLEAN:
			return value.boolean > rhs.value.boolean;
		}
	}
}

Parser::Value&
    Parser::Value::operator+=(const Value &rhs)
{
	switch (type) {
	case INTEGER:
		switch (rhs.type) {
		case INTEGER:
			value.integer += rhs.value.integer;
			break;
		case REAL:
			value.real = float(value.integer) + rhs.value.real;
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.integer += Integer(rhs.value.boolean);
			break;
		}
		break;
	case REAL:
		value.real += float(rhs);
		break;
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			value.integer = Integer(value.boolean) +
			    rhs.value.integer;
			type = Value::INTEGER;
			break;
		case REAL:
			value.real = float(value.boolean) + rhs.value.real;
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.boolean = value.boolean || rhs.value.boolean;
			break;
		}
	}

	return *this;
}

Parser::Value&
    Parser::Value::operator-=(const Value &rhs)
{
	switch (type) {
	case INTEGER:
		switch (rhs.type) {
		case INTEGER:
			value.integer -= rhs.value.integer;
			break;
		case REAL:
			value.real = float(value.integer) - rhs.value.real;
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.integer -= Integer(rhs.value.boolean);
			break;
		}
		break;
	case REAL:
		value.real -= float(rhs);
		break;
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			value.integer = Integer(value.boolean) -
			    rhs.value.integer;
			type = Value::INTEGER;
			break;
		case REAL:
			value.real = float(value.boolean) - rhs.value.real;
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.integer = Integer(value.boolean) -
			    Integer(rhs.value.boolean);
			type = Value::INTEGER;
			break;
		}
	}
	return *this;
}

Parser::Value&
    Parser::Value::operator*=(const Value &rhs)
{
	switch (type) {
	case INTEGER:
		switch (rhs.type) {
		case INTEGER:
			value.integer *= rhs.value.integer;
			break;
		case REAL:
			value.real = float(value.integer) * rhs.value.real;
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.integer *= Integer(rhs.value.boolean);
			break;
		}
		break;
	case REAL:
		value.real *= float(rhs);
		break;
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			value.integer = Integer(value.boolean) *
			    rhs.value.integer;
			type = Value::INTEGER;
			break;
		case REAL:
			value.real = float(value.boolean) * rhs.value.real;
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.boolean = value.boolean && rhs.value.boolean;
			break;
		}
	}
	return *this;
}

Parser::Value&
    Parser::Value::operator/=(const Value &rhs)
{
	value.real = float(*this) / float(rhs);
	type = Value::REAL;
	return *this;
}

Parser::Value&
    Parser::Value::operator^=(const Value &rhs)
{
	switch (type) {
	case INTEGER:
		switch (rhs.type) {
		case INTEGER:
		{
			if (rhs.value.integer < 0) {
				value.real = pow(float(value.integer), float(rhs));
				type = Value::REAL;
				break;
			}
			Integer r = 1;
			for (Integer i = 0; i < rhs.value.integer; ++i) {
				r *= value.integer;
			}
			value.integer = r;
		}
			break;
		case REAL:
			value.real = pow(float(value.integer), rhs.value.real);
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.integer = 1;
			for (Integer i = 0; i < Integer(rhs.value.boolean); ++i) {
				value.integer *= value.integer;
			}
			break;
		}
		break;
	case REAL:
		value.real = pow(value.real, float(rhs));
		break;
	}
	return *this;
}

void
Parser::Value::switchSign()
{
	switch (type) {
	case INTEGER:
		value.integer = -value.integer;
		break;
	case REAL:
		value.real = -value.real;
		break;
	case BOOLEAN:
		value.integer = -Integer(value.boolean);
		type = INTEGER;
	}
}

Parser::Parser(Lexer &l, Interpreter &i) :
_lexer(l), _interpreter(i), _mode(EXECUTE)
{
}

bool
Parser::parse(const char *s)
{
	LOG_TRACE;

	_lexer.init(s);
	_error = NO_ERROR;

	Token t;
	do {
		if (!_lexer.getNext() || !fOperator()) {
			if (_error == NO_ERROR)
				_error = OPERATOR_EXPECTED;
			return false;
		}
		t = _lexer.getToken();
	} while (t == COLON);
	return true;
}

bool
Parser::fOperator()
{
	LOG_TRACE;

	Token t = _lexer.getToken();
	LOG(t);
	switch (t) {
	case KW_DUMP:
		if (_mode == EXECUTE)
			_interpreter.dump();
		return true;
	case KW_END:
		if (_mode == EXECUTE)
			_interpreter.end();
		return true;
	case KW_FOR:
	{
		if (!_lexer.getNext() || !fImplicitAssignment()) {
			return false;
		}
		if (_lexer.getToken()!=KW_TO) {
			return false;
		}
		return true;
	}
	case KW_GOSUB:
	{
		Value v;
		if (!_lexer.getNext() || !fExpression(v) || (v.type !=
		    Value::INTEGER)) {
			_error = INTEGER_EXPRESSION_EXPECTED;
			return false;
		}
		if (_mode == EXECUTE) {
			_interpreter.pushReturnAddress();
			_interpreter.gotoLine(v.value.integer);
		}
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
	case KW_LET:
		if (!_lexer.getNext() || !fImplicitAssignment()) {
			return false;
		} else
			return true;
	case KW_LIST:
		if (_mode == EXECUTE)
			_interpreter.list();
		return true;
	case KW_NEW:
		if (_mode == EXECUTE)
			_interpreter.newProgram();
		return true;
	case KW_PRINT:
		if (_lexer.getNext())
			if (!fPrintList())
				return false;
		if (_mode == EXECUTE)
			_interpreter.print('\n');
		return true;
	case KW_RETURN:
		if (_mode == EXECUTE)
			_interpreter.returnFromSub();
		return true;
	case KW_RUN:
		if (_mode == EXECUTE)
			_interpreter.run();
		return true;
	default:
		if (fGotoStatement())
			return true;
		_error = OPERATOR_EXPECTED;
		return false;
	}
}

bool
Parser::fImplicitAssignment()
{
	LOG_TRACE;

	if (_lexer.getToken() != IDENT)
		return false;

	char buf[16];
	strcpy(buf, _lexer.getValue().value.string.string);
	Value v;
	if (_lexer.getNext() && (_lexer.getToken() == EQUALS) &&
	    _lexer.getNext() && fExpression(v)) {
		if (_mode == EXECUTE)
			_interpreter.setVariable(buf, v);
		return true;
	} else {
		_error = EXPRESSION_EXPECTED;
		return false;
	}
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
		LOG(t);
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
			_lexer.getNext();
			return true;
		case C_INTEGER:
		case C_REAL:
			if (_mode == EXECUTE)
				v = _lexer.getValue();
			_lexer.getNext();
			return true;
		case IDENT:
			if (_mode == EXECUTE) {
				valueFromFrame(v, _interpreter.getVariable(_lexer.getValue().
				    value.string.string));
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
		if (_lexer.getNext() && fOperator())
			return true;
		break;
	default:
		if (_lexer.getNext() && fGotoStatement())
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
		if (_mode == EXECUTE)
			_interpreter.gotoLine(v.value.integer);
		return true;
	} else
		return false;
}

}
