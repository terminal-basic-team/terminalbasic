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
	
	/* current identifier string */
	char _id[STRING_SIZE];
	/* Identifier string pointer */
	uint8_t _value_pointer;
	/* scanned numeric/logical value */
	basic_value_t value;
} basic_lexer_context_t;

void basic_lexer_init(basic_lexer_context_t*, const char*);

BOOLEAN basic_lexer_getnext(basic_lexer_context_t*);

void basic_lexer_tokenString(basic_token_t, uint8_t*);

__END_DECLS

#endif /* BASIC_LEXER_H */

