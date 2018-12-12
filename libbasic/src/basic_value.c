#include "basic_value.h"

#include <math.h>

#if USE_REALS
real_t
basic_value_to_real(basic_value_t *self)
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
	
	result.type = BASIC_VALUE_TYPE_REAL;
	result.body.real = other;
	
	return result;
}
#endif // USE_REALS

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
