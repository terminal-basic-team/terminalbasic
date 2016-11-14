#ifndef PARSER_HPP
#define PARSER_HPP

#include <stdlib.h>
#include <inttypes.h>

#include "cps.hpp"
#include "basic.hpp"

namespace BASIC
{

class Lexer;

class Interpreter;

class Parser
{
public:

	enum ErrorCodes
	{
		NO_ERROR = 0,
		OPERATOR_EXPECTED,
		EXPRESSION_EXPECTED,
		INTEGER_EXPRESSION_EXPECTED,
		THEN_OR_GOTO_EXPECTED
	};

	class CPS_PACKED Value;

	Parser(Lexer&, Interpreter&);

	bool parse(const char*);

	ErrorCodes getError() const
	{
		return _error;
	}
private:
	enum Mode
	{
		SCAN = 0, EXECUTE
	};
	bool fOperators();
	bool fOperator();
	bool fImplicitAssignment(char*);
	bool fPrintList();
	bool fExpression(Value&);
	bool fSimpleExpression(Value&);
	bool fTerm(Value&);
	bool fFactor(Value&);
	bool fFinal(Value&);
	bool fIfStatement();
	bool fGotoStatement();

	ErrorCodes _error;
	Lexer &_lexer;
	Interpreter &_interpreter;
	Mode	_mode;
};

}

#endif
