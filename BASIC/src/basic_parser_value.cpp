/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
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

#include "math.hpp"
#include "basic_lexer.hpp"
#include "ascii.hpp"

namespace BASIC
{

Parser::Value::Value()
{
	basic_value_setFromInteger(&m_value, 0);
}

#if USE_LONGINT

Parser::Value::Value(LongInteger v)
{
	basic_value_setFromLongInteger(&m_value, v);
}
#endif // USE_LONGINT

Parser::Value::Value(Integer v)
{
	basic_value_setFromInteger(&m_value, v);
}

#if USE_REALS
Parser::Value::Value(Real v)
{
	basic_value_setFromReal(&m_value, v);
}
#endif // USE_REALS

Parser::Value::Value(bool v)
{
	basic_value_setFromLogical(&m_value, v);
}

#if USE_REALS
Parser::Value::operator Real() const
{
	return basic_value_toReal(&m_value);
}
#endif // USE_REALS

Parser::Value::operator bool() const
{
	return basic_value_toLogical(&m_value);
}

#if USE_LONGINT

Parser::Value::operator LongInteger() const
{
	return basic_value_toLongInteger(&m_value);
}
#endif // USE_LONGINT

Parser::Value::operator Integer() const
{
	return basic_value_toInteger(&m_value);
}

Parser::Value&
Parser::Value::operator-()
{
	basic_value_switchSign(&m_value);
	
	return *this;
}

bool
Parser::Value::operator<(const Value &rhs) const
{
	return !((*this > rhs) || (*this == rhs));
}

bool
Parser::Value::operator==(const Value &rhs) const
{
	return basic_value_equals(&m_value, &rhs.m_value);
}

bool
Parser::Value::operator>(const Value &rhs) const
{
#if USE_REALS
	if (rhs.type == REAL)
		return Real(*this) > Real(rhs);
	else
#endif
	switch (this->type) {
#if USE_REALS
	case REAL:
		return this->value.real > Real(rhs);
#endif
#if USE_LONGINT
	case LONG_INTEGER:
		return this->value.longInteger > LongInteger(rhs);
#endif
	case INTEGER:
		return this->value.integer > Integer(rhs);
	default:
        	return false;
	}
}

bool
operator>=(const Parser::Value &l, const Parser::Value &r)
{
	return l.operator>(r) || l.operator==(r);
}

bool
operator<=(const Parser::Value &l, const Parser::Value &r)
{
	return l.operator<(r) || l.operator==(r);
}

Parser::Value&
Parser::Value::operator+=(const Value &rhs)
{
#if USE_REALS
	if (rhs.type == REAL)
		*this = Real(*this) + Real(rhs);
	else
#endif
	switch (this->type) {
#if USE_REALS
	case REAL: this->value.real += Real(rhs);
		break;
#endif
#if USE_LONGINT
	case LONG_INTEGER: this->value.longInteger += LongInteger(rhs);
		break;
#endif
	case INTEGER: this->value.integer += Integer(rhs);
		break;
	default:
		break;
	}

	return *this;
}

Parser::Value&
Parser::Value::operator-=(const Value &rhs)
{
	basic_value_minuseq(&m_value, &rhs.m_value);
	return *this;
}

Parser::Value&
Parser::Value::operator*=(const Value &rhs)
{
	basic_value_multeq(&m_value, &rhs.m_value);
	return *this;
}

// '/' operation always return REAL if real numbers support used
Parser::Value&
Parser::Value::operator/=(const Value &rhs)
{
	basic_value_diveq(&m_value, &rhs.m_value);
	return *this;
}

Parser::Value&
Parser::Value::divEquals(const Value &rhs)
{
#if USE_LONGINT
	if (type == Value::INTEGER || type == Value::BOOLEAN)
		*this = Integer(Integer(*this) / Integer(rhs));
	else
#endif
		*this = INT(INT(*this) / INT(rhs));
	
	return *this;
}

Parser::Value&
Parser::Value::modEquals(const Value &rhs)
{
#if USE_LONGINT
	if (type == Value::INTEGER || type == Value::BOOLEAN)
		*this = Integer(Integer(*this) % Integer(rhs));
	else
#endif
		*this = INT(INT(*this) % INT(rhs));
	
	return *this;
}

void
Parser::Value::powerMatchValue(const Value &rhs)
{
#if USE_LONGINT
	if (rhs.type == LONG_INTEGER
#if USE_REALS
	    && type != REAL
#endif
	    )
		*this = LongInteger(*this);
#endif
#if USE_REALS
	if (rhs.type == REAL || rhs < Integer(0))
		*this = Real(*this);
#endif
}

Parser::Value&
Parser::Value::operator^=(const Value &rhs)
{
	powerMatchValue(rhs);
	switch (type) {
	case INTEGER:
	{
		Integer r = 1;
		for (Integer i = Integer(rhs); i > 0; --i)
			r *= value.integer;
		value.integer = r;
	}
		break;
#if USE_LONGINT
	case LONG_INTEGER:
	{
		LongInteger r = 1;
		for (LongInteger i = LongInteger(rhs); i > 0 ; --i)
			r *= value.longInteger;
		value.longInteger = r;
	}
		break;
#endif
#if USE_REALS
	case REAL:
		value.real = pow(value.real, Real(rhs));
		break;
#endif
	default:
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
#if USE_LONGINT
	case LONG_INTEGER:
		value.longInteger = -value.longInteger;
		break;
#endif
#if USE_REALS
	case REAL:
		value.real = -value.real;
		break;
#endif
	case BOOLEAN:
		value.integer = -Integer(value.boolean);
		type = INTEGER;
		break;
	default:
		break;
	}
}

void
Parser::Value::notOp()
{
	switch (type) {
	case INTEGER:
		this->value.integer = ~this->value.integer;
		break;
	case BOOLEAN:
		this->value.boolean = !this->value.boolean;
		break;
	default:
		break;
	}
}

size_t
Parser::Value::size(Type t)
{
	switch (t) {
	case INTEGER:
		return sizeof(Integer);
#if USE_LONGINT
	case LONG_INTEGER:
		return sizeof(LongInteger);	
#endif
#if USE_REALS
	case REAL:
		return sizeof(Real);	
#endif
	case BOOLEAN:
		return sizeof(bool);
	default:
		return 0;
	}
}

Parser::Value&
Parser::Value::operator|=(const Value &v)
{
	switch (type) {
	case INTEGER:
		this->value.integer |= Integer(v);
		break;
	case BOOLEAN:
		this->value.boolean |= bool(v);
		break;
#if USE_LONGINT
	case LONG_INTEGER:
		this->value.longInteger |= LongInteger(v);
		break;
#endif
	default:
		break;
	}

	return *this;
}

Parser::Value&
Parser::Value::operator&=(const Value &v)
{
	switch (type) {
	case INTEGER:
		this->value.integer &= Integer(v);
		break;
	case BOOLEAN:
		this->value.boolean &= bool(v);
		break;
#if USE_LONGINT
	case LONG_INTEGER:
		this->value.longInteger &= LongInteger(v);
		break;
#endif
	default:
		break;
	}
	return *this;
}

size_t
Parser::Value::printTo(Print& p) const
{
	switch (type) {
	case BOOLEAN:
	{
		char buf[6]; // Size, sufficient to store both 'TRUE' and 'FALSE
		const uint8_t *res;
		if (value.boolean)
			res = Lexer::getTokenString(Token::KW_TRUE, (uint8_t*)buf);
		else
			res = Lexer::getTokenString(Token::KW_FALSE, (uint8_t*)buf);
		if (res != nullptr)
			return p.print(buf);
		else
			return 0;
	}
		break;
#if USE_REALS
	case REAL:
	{
		char buf[15];
#ifdef __AVR_ARCH__
		int8_t decWhole = 1;
		Real n = math<Real>::abs(value.real);
                
		if (n >= Real(1)) {
			while (n >= Real(10)) {
				n /= Real(10);
				++decWhole;
			}
		} else {
			while (n < Real(1)) {
				n *= Real(10);
				--decWhole;
				if (decWhole <= -3)
					break;
			}
		}
		if (decWhole >= -3 && decWhole <= 8)
			::dtostrf(value.real, 14, 8 - decWhole, buf);
		else
			::dtostre(value.real, buf, 7, DTOSTR_ALWAYS_SIGN);
#else
		::sprintf(buf, "%- 12.9G", value.real);
#endif // ARDUINO
		if (buf[1] == '0' && buf[2] == '.')
			memmove(buf+1, buf+2, 15-2);
		return p.print(buf);
	}
		break;
#endif
#if USE_LONGINT
	case Parser::Value::LONG_INTEGER:
		if (value.longInteger >= LongInteger(0))
			p.print(char(ASCII::SPACE));
		return p.print(value.longInteger) + 1;
#endif // USE_LONGINT
	case Parser::Value::INTEGER:
		if (value.integer >= Integer(0))
			p.print(char(ASCII::SPACE));
		return p.print(value.integer) + 1;
	default:
		return p.print(char(ASCII::QMARK));
	}
}

} // namespace BASIC
