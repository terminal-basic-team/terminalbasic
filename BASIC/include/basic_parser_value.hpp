#ifndef BASIC_PARSER_VALUE_HPP
#define BASIC_PARSER_VALUE_HPP

#include "parser.hpp"

namespace BASIC
{

class CPS_PACKED Parser::Value
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
}

#endif
