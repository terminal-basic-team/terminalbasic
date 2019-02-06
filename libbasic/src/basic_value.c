#include "basic_value.h"

#include <math.h>

#if USE_REALS
real_t
basic_value_to_real(const basic_value_t *self)
{
	switch (self->type) {
#if USE_LONGINT
	case BASIC_VALUE_TYPE_LONG_INTEGER:
		return (real_t)(self->body.long_integer);
#endif // USE_LONGINT
	case BASIC_VALUE_TYPE_INTEGER:
		return (real_t)(self->body.integer);
	case BASIC_VALUE_TYPE_REAL:
		return self->body.real;
	case BASIC_VALUE_TYPE_LOGICAL:
		return (real_t)(self->body.logical);
	default:
		return (real_t)(NAN);
	}
}

basic_value_t
basic_value_from_real(real_t other)
{
	basic_value_t result;
	
	basic_value_setFromReal(&result, other);
	
	return result;
}

void
basic_value_setFromReal(basic_value_t* self, real_t val)
{
	self->type = BASIC_VALUE_TYPE_REAL;
	self->body.real = val;
}
#endif // USE_REALS

#if USE_LONGINT
long_integer_t
basic_value_toLongInt(const basic_value_t* self)
{
	switch (self->type) {
	case BASIC_VALUE_TYPE_LONG_INTEGER:
		return self->body.long_integer;
	case BASIC_VALUE_TYPE_INTEGER:
		return (long_integer_t)self->body.integer;
#if USE_REALS
	case BASIC_VALUE_TYPE_REAL:
		return (long_integer_t)self->body.real;
#endif // USE_REALS
	case BASIC_VALUE_TYPE_LOGICAL:
		return (BOOLEAN)self->body.logical;
	default:
		return (long_integer_t)0;
	}
}

basic_value_t
basic_value_fromLongInteger(long_integer_t other)
{
	basic_value_t result;
	
	result.type = BASIC_VALUE_TYPE_LONG_INTEGER;
	result.body.long_integer = other;
	
	return result;
}

void
basic_value_setFromLongInteger(basic_value_t* self, long_integer_t other)
{
	self->type = BASIC_VALUE_TYPE_LONG_INTEGER;
	self->body.long_integer = other;
}
#endif // USE_LONGINT

void
basic_value_setFromInt(basic_value_t* self, integer_t val)
{
	self->type = BASIC_VALUE_TYPE_INTEGER;
	self->body.integer = val;
}

void
basic_value_multeq(basic_value_t *self, const basic_value_t *rhs)
{
#if USE_REALS
	if (rhs->type == BASIC_VALUE_TYPE_REAL) {
		self->type = BASIC_VALUE_TYPE_REAL;
		self->body.real = basic_value_to_real(self) * rhs->body.real;
	} else
#endif
	switch (self->type) {
#if USE_REALS
	case BASIC_VALUE_TYPE_REAL :
		self->body.real *= rhs->body.real;
		break;
#endif
#if USE_LONGINT
	case BASIC_VALUE_TYPE_LONG_INTEGER :
		self->body.long_integer *= rhs->body.long_integer;
		break;
#endif
	case BASIC_VALUE_TYPE_INTEGER :
		self->body.integer *= rhs->body.integer;
		break;
	default:
		break;
	}
}
