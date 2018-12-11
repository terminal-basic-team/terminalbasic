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

static void
lexer_decimal()
{
	
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
		/*case '"':
			next();
			stringConst();
			return true;*/
		case ' ':
		case '\t':
			++self->string_pointer; break;
		default:
			if (isdigit(SYM))
				lexer_decimal(self);
			goto token_found; /* ? */
		}
	}
	
	return FALSE;
token_found:
	++self->string_pointer;
	return TRUE;
}
