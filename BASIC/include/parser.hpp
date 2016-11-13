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

	class CPS_PACKED Value
	{
	public:
		enum Type : uint8_t
		{
			INTEGER, REAL, BOOLEAN, STRING
		};
		
		struct CPS_PACKED String
		{
			uint8_t size;
			char string[STRINGSIZE];
		};
		
		union CPS_PACKED Body
		{
			Integer integer;
			float real;
			bool boolean;
			String string;
		};

		Value();
		
		operator Real() const;
		operator bool() const;
		operator Integer() const;

		bool operator<(const Value&) const;
		bool operator==(const Value&) const;
		bool operator>(const Value&) const;
		Value &operator+=(const Value&);
		Value &operator-=(const Value&);
		Value &operator*=(const Value&);
		Value &operator/=(const Value&);
		Value &operator^=(const Value&);
		void switchSign();
		
		Type type;
		Body value;
	};

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
	bool fOperator();
	bool fImplicitAssignment();
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
