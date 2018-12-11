#ifndef BASIC_LEXER_H
#define BASIC_LEXER_H

#include "basic.h"
#include "basic_value.h"

__BEGIN_DECLS

typedef struct _basic_lexer_context_t
{
	const char *string_to_parse;
	uint8_t string_pointer;
	basic_token_t token;
	
	/* Identifier string pointer */
	uint8_t _value_pointer;
	basic_univalue_t value;
} basic_lexer_context_t;

void basic_lexer_init(basic_lexer_context_t*, const char*);

BOOLEAN basic_lexer_getnext(basic_lexer_context_t*);

__END_DECLS

#endif /* BASIC_LEXER_H */

