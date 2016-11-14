#ifndef LEXER_HPP
#define LEXER_HPP

#include <inttypes.h>
#include <stdlib.h>

#include "arduino_logger.hpp"
#include "parser.hpp"
#include "basic_parser_value.hpp"
#include "helper.hpp"

namespace BASIC
{

enum Token : uint8_t
{
	NOTOKENS = 0,
	IDENT,

	// =
	EQUALS,
	// :
	COLON,
	// ;
	SEMI,
	// <
	LT,
	// >
	GT,
	// <>
	NE,
	// <=
	LTE,
	// >=
	GTE,
	// ,
	COMMA,
	// ^
	POW,
	// (
	LPAREN,
	// )
	RPAREN,
	// +
	PLUS,
	// -
	MINUS,
	// *
	STAR,
	// /
	SLASH,

	C_INTEGER,
	C_REAL,
	C_STRING,

	KW_DUMP,
	KW_END,
	KW_FOR,
	KW_GOTO,
	KW_GOSUB,
	KW_IF,
	KW_LET,
	KW_LIST,
	KW_NEW,
	KW_NEXT,
	KW_PRINT,
	KW_RETURN,
	KW_RUN,
	KW_THEN,
	KW_TO,
	    
	NUM_TOKENS
};

#if ARDUINO_LOG

inline Logger&
operator<<(Logger &logger, Token tok)
{
	switch (tok) {
	case NOTOKENS:
		logger.log("NOTOKENS");
		break;
	case KW_END:
		logger.log("KW_END");
		break;
	case IDENT:
		logger.log("IDENT");
		break;
	case EQUALS:
		logger.log("EQUALS");
		break;
	case COLON:
		logger.log("COLON");
		break;
	case SLASH:
		logger.log("SLASH");
		break;
	case SEMI:
		logger.log("SEMI");
		break;
	case LT:
		logger.log("LT");
		break;
	case LTE:
		logger.log("LTE");
		break;
	case NE:
		logger.log("NE");
		break;
	case GT:
		logger.log("GT");
		break;
	case GTE:
		logger.log("GTE");
		break;
	case C_INTEGER:
		logger.log("C_INTEGER");
		break;
	case C_REAL:
		logger.log("C_REAL");
		break;
	case C_STRING:
		logger.log("C_STRING");
		break;
	case KW_RUN:
		logger.log("KW_RUN");
		break;
	case KW_GOTO:
		logger.log("KW_GOTO");
		break;
	case KW_DUMP:
		logger.log("KW_DUMP");
		break;
	case KW_LIST:
		logger.log("KW_LIST");
		break;
	case KW_LET:
		logger.log("KW_LIST");
		break;
	case KW_PRINT:
		logger.log("KW_PRINT");
		break;
	case KW_GOSUB:
		logger.log("KW_GOSUB");
		break;
	case KW_RETURN:
		logger.log("KW_RETURN");
		break;
	case KW_FOR:
		logger.log("KW_FOR");
		break;
	case KW_TO:
		logger.log("KW_TO");
		break;
	case KW_IF:
		logger.log("KW_IF");
		break;
	case KW_NEXT:
		logger.log("KW_NEXT");
		break;
	case KW_NEW:
		logger.log("KW_NEXT");
		break;
	case KW_THEN:
		logger.log("KW_THEN");
		break;
	case COMMA:
		logger.log("COMMA");
		break;
	case POW:
		logger.log("POW");
		break;
	case LPAREN:
		logger.log("LPAREN");
		break;
	case RPAREN:
		logger.log("RPAREN");
		break;
	case PLUS:
		logger.log("PLUS");
		break;
	case MINUS:
		logger.log("MINUS");
		break;
	case STAR:
		logger.log("STAR");
		break;
	}
	return (logger);
}
#endif

class Lexer
{
public:
	void init(const char*);
	bool getNext();

	Token getToken() const
	{
		return _token;
	}

	const Parser::Value &getValue() const
	{
		return _value;
	}

	size_t getPointer() const
	{
		return _pointer;
	}
	
	static PGM_P const tokenStrings[NUM_TOKENS];

private:

	void pushSYM();
	void next();

	void first_D();
	void first_E();
	void first_F();
	void first_G();
	void first_I();
	void first_L();
	void first_N();
	void first_P();
	void first_R();
	void first_T();

	void fitst_LT();
	void fitst_GT();
	void decimalNumber();
	void realNumber();
	void ident();

	const char *_string;
	uint16_t _pointer;

	Parser::Value _value;
	size_t _valuePointer;

	Token _token;
};

}

#endif
