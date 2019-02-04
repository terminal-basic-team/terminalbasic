#ifndef BASIC_VALUE_H
#define BASIC_VALUE_H

#include "basic.h"
#include "tools.h"

#include <stdlib.h>

__BEGIN_DECLS

/**
 * @brief types of the value
 */
typedef enum basic_value_type
{
	BASIC_VALUE_TYPE_INTEGER,
#if USE_LONGINT
	BASIC_VALUE_TYPE_LONG_INTEGER,
#endif
#if USE_REALS
	BASIC_VALUE_TYPE_REAL,
#endif
	BASIC_VALUE_TYPE_LOGICAL,
	BASIC_VALUE_TYPE_STRING
} basic_value_type_t;

/**
 * Universal value body
 */
typedef union basic_univalue
{
	integer_t integer;
#if USE_LONGINT
	long_integer_t long_integer;
#endif
#if USE_REALS
	real_t real;
#endif
	BOOLEAN logical;
} basic_univalue_t;

typedef struct basic_value
{
	basic_value_type_t type;
	basic_univalue_t body;
} basic_value_t;

#if USE_REALS
real_t basic_value_to_real(const basic_value_t*);

basic_value_t basic_value_from_real(real_t);

void basic_value_setFromReal(basic_value_t*, real_t);
#endif

#if USE_LONGINT
long_integer_t basic_value_toLongInt(const basic_value_t*);

basic_value_t basic_value_fromLongInteger(long_integer_t);

void basic_value_setFromLongInteger(basic_value_t*, long_integer_t);
#endif

integer_t basic_valueToInt(basic_value_t*);

void basic_value_setFromInt(basic_value_t*, integer_t);

void basic_value_multeq(basic_value_t*, const basic_value_t*);

__END_DECLS

#endif /* BASIC_VALUE_H */

