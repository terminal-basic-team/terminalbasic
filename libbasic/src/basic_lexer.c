#include "basic_lexer.h"

#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

void
basic_lexer_init(basic_lexer_context_t *self, const char *str)
{
	assert(str != NULL);
	
	self->string_pointer = 0;
	self->string_to_parse = str;
}

#define SYM ((uint8_t)(self->string_to_parse[self->string_pointer]))

static void
lexer_first_lt(basic_lexer_context_t *self)
{
	if (SYM == '=')
		self->token = BASIC_TOKEN_LTE;
	else if (SYM == '>')
		self->token = BASIC_TOKEN_NE;
	else {
		self->token = BASIC_TOKEN_LT;
		return;
	}
	++self->string_pointer;
}

static void
lexer_first_gt(basic_lexer_context_t *self)
{
	if (SYM == '=')
		self->token = BASIC_TOKEN_GTE;
#if CONF_USE_ALTERNATIVE_NE
	else if (SYM == '<')
		self->token = BASIC_TOKEN_NEA;
#endif // CONF_USE_ALTERNATIVE_NE
	else {
		self->token = BASIC_TOKEN_GT;
		return;
	}
	++self->string_pointer;
}

#if USE_REALS
static BOOLEAN
lexer_number_scale(basic_lexer_context_t *self)
{
	integer_t scale = 0;
	BOOLEAN sign = TRUE;

	++self->string_pointer;
	if (SYM == '-') {
		sign = FALSE;
		++self->string_pointer;
	} else if (SYM == '+')
		++self->string_pointer;

	if (isdigit(SYM)) {
		scale += SYM - '0';
		++self->string_pointer;
	} else
		return FALSE;

	while (TRUE) {
		if (isdigit(SYM)) {
			scale *= (integer_t)(10);
			scale += SYM - '0';
			++self->string_pointer;
			continue;
		} else {
			if (!sign)
				scale = -scale;
			real_t pw = mf_pow((real_t)(10), (real_t)scale);
			basic_value_t pwv = basic_value_from_real(pw);
			basic_value_multeq(&self->value, &pwv);
			return TRUE;
		}
	}
}
#endif // USE_REALS

static void
lexer_decimal(basic_lexer_context_t *self)
{
#if USE_LONGINT
	self->value.type = BASIC_VALUE_TYPE_LONG_INTEGER;
	long_integer_t *val = &self->value.body.long_integer;
#else
	self->value.type = basic_value_type_t;
	integer_t *val = &self->value.body.integer;
#endif // USE_LONGINT
#if USE_REALS
	if (SYM == '.')
		*val = 0;
	else
#endif
		*val = SYM - '0';
	while (SYM > 0) {
#if USE_REALS
		if (self->value.type == BASIC_VALUE_TYPE_REAL) {
			++self->string_pointer;
			if (isdigit(SYM)) {
				self->value.body.real *= (real_t)(10);
				self->value.body.real += (real_t)(SYM - '0');
				continue;
			}
		} else if (SYM != '.') {

#endif // USE_REALS
			++self->string_pointer;
			if (isdigit(SYM)) {
#if USE_REALS
				if (*val > MAXINT/(INT)(10)) {
					self->value.type = BASIC_VALUE_TYPE_REAL;
					self->value.body.real = (real_t)(*val);
					self->value.body.real *= (real_t)(10);
					self->value.body.real += SYM - '0';
				} else {
#endif
					*val *= (INT)(10);
					*val += SYM - '0';
#if USE_REALS
				}
#endif
				continue;
			}
#if USE_REALS
		}
#endif
		
			
		switch (SYM) {
#if USE_REALS
		case '.':
		{
			if (self->value.type != BASIC_VALUE_TYPE_REAL) {
				self->value.type = BASIC_VALUE_TYPE_REAL;
				self->value.body.real = (real_t)(*val);
			}
			real_t d = 1;
			while (TRUE) {
				++self->string_pointer;
				if (isdigit(SYM)) {
					d /= 10.f;
					self->value.body.real +=
					    (real_t)(SYM - '0') * d;
					continue;
				} else if (SYM == 0) {
					self->token = BASIC_TOKEN_C_REAL;
					return;
				} else if (SYM == 'E' || SYM == 'e') {
					if (!lexer_number_scale(self))
						self->token = BASIC_TOKEN_NOTOKEN;
					else
						self->token = BASIC_TOKEN_C_REAL;
					return;
				} else {
					self->token = BASIC_TOKEN_C_REAL;
					return;
				}
			}
		}
			break;
		case 'E':
		case 'e':
		{
			if (self->value.type == BASIC_VALUE_TYPE_INTEGER
#if USE_LONGINT
			    || self->value.type == BASIC_VALUE_TYPE_LONG_INTEGER
#endif
			    )
				self->value.body.real = basic_value_to_real(
				    &self->value);
			if (!lexer_number_scale(self)) {
				self->token = BASIC_TOKEN_NOTOKEN;
				return;
			}
		}
#endif
		default:
			if (self->value.type == BASIC_VALUE_TYPE_INTEGER
#if USE_LONGINT
			    || self->value.type == BASIC_VALUE_TYPE_LONG_INTEGER
#endif
			    )
				self->token = BASIC_TOKEN_C_INTEGER;
#if USE_REALS
			else
				self->token = BASIC_TOKEN_C_REAL;
#endif
			return;
		}
	}
}

static void
lexer_string_const(basic_lexer_context_t *self)
{
	while (SYM != 0) {
		if (SYM == '"') {
			self->token = BASIC_TOKEN_STRING_IDENT;
			self->_id[self->_value_pointer] = 0;
			return;
		}
		if (self->_value_pointer < (STRING_SIZE - 1))
			self->_id[self->_value_pointer++] = SYM;
		//else
			//_error = STRING_OVERFLOW;
		++self->string_pointer;
	}
}

BOOLEAN
basic_lexer_getnext(basic_lexer_context_t *self)
{
	self->token = BASIC_TOKEN_NOTOKEN;
	/*_error = NO_ERROR;*/
	self->_value_pointer = 0;
	/* Iterate until end of input string */
	while (SYM > 0) {
		switch (SYM) {
		case '=':
			self->token = BASIC_TOKEN_EQUALS;
			goto token_found;
		case ';':
			self->token = BASIC_TOKEN_SEMI;
			goto token_found;
#if USE_REALS
		case '.':
			lexer_decimal(self);
			return TRUE;
#endif // USE_REALS
		case ',':
			self->token = BASIC_TOKEN_COMMA;
			goto token_found;
		case ':':
			self->token = BASIC_TOKEN_COLON;
			goto token_found;
		case '<':
			++self->string_pointer;
			lexer_first_lt(self);
			return TRUE;
		case '>':
			++self->string_pointer;
			lexer_first_gt(self);
			return TRUE;
		case '(':
			self->token = BASIC_TOKEN_LPAREN;
			goto token_found;
		case ')':
			self->token = BASIC_TOKEN_RPAREN;
			goto token_found;
		case '+':
			self->token = BASIC_TOKEN_PLUS;
			goto token_found;
		case '-':
			self->token = BASIC_TOKEN_MINUS;
			goto token_found;
		case '*':
			self->token = BASIC_TOKEN_STAR;
			goto token_found;
		case '/':
			self->token = BASIC_TOKEN_SLASH;
			goto token_found;
		
#if USE_REALS && USE_INTEGER_DIV
		case '\\':
			self->token = BASIC_TOKEN_BACK_SLASH;
			goto token_found;
#endif
		case '^':
			self->token = BASIC_TOKEN_POW;
			goto token_found;
		case '"':
			++self->string_pointer;
			lexer_string_const(self);
			goto token_found;
		case ' ':
		case '\t':
			++self->string_pointer; break;
		default:
			if (isdigit(SYM)) {
				lexer_decimal(self);
				return TRUE;
			}
			goto token_found; /* ? */
		}
	}
	
	return FALSE;
token_found:
	++self->string_pointer;
	return TRUE;
}
