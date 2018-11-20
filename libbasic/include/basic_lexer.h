#ifndef BASIC_LEXER_H
#define BASIC_LEXER_H

#include "basic.h"

__BEGIN_DECLS

typedef struct _basic_lexer_context_t
{
	const char *string_to_parse;
	uint8_t string_pointer;
} basic_lexer_context_t;

__END_DECLS

#endif /* BASIC_LEXER_H */

