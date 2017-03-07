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

#include "basic_parser_value.hpp"

#include <math.h>

namespace BASIC
{

Parser::Value::Value() :
type(INTEGER)
{
	value.integer = 0;
}

#if USE_LONGINT
Parser::Value::Value(LongInteger v) :
type(LONG_INTEGER)
{
	value.longInteger = v;
}
#endif

Parser::Value::Value(Integer v) :
type(INTEGER)
{
	value.integer = v;
}

#if USE_REALS
Parser::Value::Value(Real v) :
type(REAL)
{
	value.real = v;
}
#endif

Parser::Value::Value(bool v) :
type(BOOLEAN)
{
	value.boolean = v;
}

#if USE_REALS
Parser::Value::operator Real() const
{
	switch (type) {
#if USE_LONGINT
	case LONG_INTEGER:
		return Real(value.longInteger);
#endif
	case INTEGER:
		return Real(value.integer);
	case REAL:
		return value.real;
	case BOOLEAN:
		return Real(value.boolean);
	default:
		return (Real(NAN));
	}
}
#endif

Parser::Value::operator bool() const
{
	switch (type) {
#if USE_LONGINT
	case LONG_INTEGER:
		return bool(value.longInteger);
#endif
	case INTEGER:
		return bool(value.integer);
#if USE_REALS
	case REAL:
		return bool(value.real);
#endif
	case BOOLEAN:
		return value.boolean;
	default:
		return false;
	}
}

#if USE_LONGINT
Parser::Value::operator LongInteger() const
{
	switch (type) {
	case LONG_INTEGER:
		return value.longInteger;
	case INTEGER:
		return LongInteger(value.integer);
	case REAL:
		return LongInteger(value.real);
	case BOOLEAN:
		return LongInteger(value.boolean);
	default:
		return LongInteger(0);
	}
}
#endif

Parser::Value::operator Integer() const
{
	switch (type) {
#if USE_LONGINT
	case LONG_INTEGER:
		return Integer(value.longInteger);
#endif
	case INTEGER:
		return value.integer;
#if USE_REALS
	case REAL:
		return Integer(value.real);
#endif
	case BOOLEAN:
		return Integer(value.boolean);
	default:
		return Integer(0);
	}
}

Parser::Value& 
Parser::Value::operator-()
{
	switch (type) {
#if USE_LONGINT
	case LONG_INTEGER:
		value.longInteger = -value.longInteger;
		break;
#endif
	case INTEGER:
		value.integer = -value.integer;
		break;
#if USE_REALS
	case REAL:
		value.real = -value.real;
		break;
#endif
	case BOOLEAN:
		value.boolean = !value.boolean;
		break;
	default:
		// undefined
		break;
	}
	return *this;
}

bool
Parser::Value::operator<(const Value &rhs) const
{
	switch (type) {
	case INTEGER:
		switch (rhs.type) {
		case INTEGER:
			return value.integer < rhs.value.integer;
#if USE_REALS
		case REAL:
			return Real(value.integer) < rhs.value.real;
#endif
		case BOOLEAN:
			return value.integer < Integer(rhs.value.boolean);
		}
#if USE_REALS
	case REAL:
		return value.real < Real(rhs);
#endif
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			return Integer(value.boolean) < rhs.value.integer;
#if USE_REALS
		case REAL:
			return Real(value.boolean) < rhs.value.real;
#endif
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
#if USE_REALS
		case REAL:
			return Real(value.integer) == rhs.value.real;
#endif
		case BOOLEAN:
			return value.integer == Integer(rhs.value.boolean);
		}
#if USE_REALS
	case REAL:
		return value.real == Real(rhs);
#endif
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			return Integer(value.boolean) == rhs.value.integer;
#if USE_REALS
		case REAL:
			return Real(value.boolean) == rhs.value.real;
#endif
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
			return (value.integer > rhs.value.integer);
#if USE_REALS
		case REAL:
			return (Real(value.integer) > rhs.value.real);
#endif
		case BOOLEAN:
			return (value.integer > Integer(rhs.value.boolean));
		}
#if USE_REALS
	case REAL:
		return value.real > Real(rhs);
#endif
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			return Integer(value.boolean) > rhs.value.integer;
#if USE_REALS
		case REAL:
			return Real(value.boolean) > rhs.value.real;
#endif
		case BOOLEAN:
			return value.boolean > rhs.value.boolean;
		}
	}
}

bool
operator>=(const Parser::Value &l, const Parser::Value &r)
{
	return (l.operator >(r) || l.operator ==(r));
}

bool
operator<=(const Parser::Value &l, const Parser::Value &r)
{
	return (l.operator <(r) || l.operator ==(r));
}

Parser::Value&
Parser::Value::operator+=(const Value &rhs)
{
	switch (type) {
#if USE_LONGINT
	case LONG_INTEGER:
		switch (rhs.type) {
		case LONG_INTEGER:
			value.longInteger += rhs.value.longInteger;
			break;
		case INTEGER:
			value.integer += rhs.value.integer;
			break;
		case REAL:
			value.real = Real(value.integer) + rhs.value.real;
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.integer += Integer(rhs.value.boolean);
			break;
		}
		break;
#endif
	case INTEGER:
		switch (rhs.type) {
#if USE_LONGINT
		case LONG_INTEGER:
			value.integer += rhs.value.longInteger;
			break;
#endif
		case INTEGER:
			value.integer += rhs.value.integer;
			break;
#if USE_REALS
		case REAL:
			value.real = Real(value.integer) + rhs.value.real;
			type = Value::REAL;
			break;
#endif
		case BOOLEAN:
			value.integer += Integer(rhs.value.boolean);
			break;
		}
		break;
#if USE_REALS
	case REAL:
		value.real += Real(rhs);
		break;
#endif
	case BOOLEAN:
		switch (rhs.type) {
#if USE_LONGINT
		case LONG_INTEGER:
			value.longInteger = Integer(value.boolean) +
			    rhs.value.longInteger;
			type = Value::LONG_INTEGER;
			break;
#endif
		case INTEGER:
			value.integer = Integer(value.boolean) +
			    rhs.value.integer;
			type = Value::INTEGER;
			break;
#if USE_REALS
		case REAL:
			value.real = Real(value.boolean) + rhs.value.real;
			type = Value::REAL;
			break;
#endif
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
#if USE_LONGINT
	case LONG_INTEGER:
		switch (rhs.type) {
		case LONG_INTEGER:
			value.longInteger -= rhs.value.longInteger;
			break;
		case INTEGER:
			value.longInteger -= rhs.value.integer;
			break;
		case REAL:
			value.real = Real(value.longInteger) - rhs.value.real;
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.longInteger -= LongInteger(rhs.value.boolean);
			break;
		}
		break;
#endif
	case INTEGER:
		switch (rhs.type) {
#if USE_LONGINT
		case LONG_INTEGER:
			value.integer -= rhs.value.longInteger;
			break;
#endif
		case INTEGER:
			value.integer -= rhs.value.integer;
			break;
#if USE_REALS
		case REAL:
			value.real = Real(value.integer) - rhs.value.real;
			type = Value::REAL;
			break;
#endif
		case BOOLEAN:
			value.integer -= Integer(rhs.value.boolean);
			break;
		}
		break;
#if USE_REALS
	case REAL:
		value.real -= Real(rhs);
		break;
#endif
	case BOOLEAN:
		switch (rhs.type) {
#if USE_LONGINT
		case LONG_INTEGER:
			value.longInteger = Integer(value.boolean) -
			    rhs.value.longInteger;
			type = Value::LONG_INTEGER;
			break;
#endif
		case INTEGER:
			value.integer = Integer(value.boolean) -
			    rhs.value.integer;
			type = Value::INTEGER;
			break;
#if USE_REALS
		case REAL:
			value.real = Real(value.boolean) - rhs.value.real;
			type = Value::REAL;
			break;
#endif
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
#if USE_LONGINT
	case LONG_INTEGER:
		switch (rhs.type) {
		case LONG_INTEGER:
			value.longInteger *= rhs.value.longInteger;
			break;	
		case INTEGER:
			value.longInteger *= LongInteger(rhs.value.integer);
			break;
		case REAL:
			value.real = Real(value.integer) * rhs.value.real;
			type = Value::REAL;
			break;
		case BOOLEAN:
			value.longInteger *= LongInteger(rhs.value.boolean);
			break;
		}
		break;
#endif
	case INTEGER:
		switch (rhs.type) {
#if USE_LONGINT
		case LONG_INTEGER:
			value.integer *= rhs.value.longInteger;
			break;	
#endif
		case INTEGER:
			value.integer *= rhs.value.integer;
			break;
#if USE_REALS
		case REAL:
			value.real = Real(value.integer) * rhs.value.real;
			type = Value::REAL;
			break;
#endif
		case BOOLEAN:
			value.integer *= Integer(rhs.value.boolean);
			break;
		}
		break;
#if USE_REALS
	case REAL:
		value.real *= Real(rhs);
		break;
#endif
	case BOOLEAN:
		switch (rhs.type) {
		case INTEGER:
			value.integer = Integer(value.boolean) *
			    rhs.value.integer;
			type = Value::INTEGER;
			break;
#if USE_REALS
		case REAL:
			value.real = Real(value.boolean) * rhs.value.real;
			type = Value::REAL;
			break;
#endif
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
#if USE_REALS
	value.real = Real(*this) / Real(rhs);
	type = Value::REAL;
#else
#if USE_LONGINT
	value.longInteger = LongInteger(*this) / LongInteger(rhs);
#else
	value.integer = Integer(*this) / Integer(rhs);
#endif // USE_LONGINT
#endif // USE_REALS
	return *this;
}

Parser::Value&
Parser::Value::operator^=(const Value &rhs)
{
	switch (type) {
	case INTEGER:
		switch (rhs.type) {
		case BOOLEAN:
			type = Value::INTEGER;
			value.integer = Integer(value.boolean);
			// fall through
		case INTEGER:
		{
			if (rhs.value.integer < 0) {
#if USE_REALS
				value.real = pow(Real(value.integer), Real(rhs));
				type = Value::REAL;
#endif
				break;
			}
			Integer r = 1;
			for (Integer i = 0; i < rhs.value.integer; ++i) {
				r *= value.integer;
			}
			value.integer = r;
		}
			break;
#if USE_REALS
		case REAL:
			value.real = pow(Real(value.integer), rhs.value.real);
			type = Value::REAL;
			break;
#endif
		}
		break;
#if USE_REALS
	case REAL:
		value.real = pow(value.real, Real(rhs));
		break;
#endif
	}
	return (*this);
}

void
Parser::Value::switchSign()
{
	switch (type) {
	case INTEGER:
		value.integer = -value.integer;
		break;
#if USE_REALS
	case REAL:
		value.real = -value.real;
		break;
#endif
	case BOOLEAN:
		value.integer = -Integer(value.boolean);
		type = INTEGER;
	}
}

}
