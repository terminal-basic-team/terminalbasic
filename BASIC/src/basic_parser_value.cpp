#include "basic_parser_value.hpp"

#include <math.h>

namespace BASIC
{

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

}
