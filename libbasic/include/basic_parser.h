#ifndef BASIC_PARSER_H
#define BASIC_PARSER_H

#include "basic.h"

__BEGIN_DECLS

typedef struct {
	
} basic_parser_context_t;

/**
 * 
 * @param self context
 * @param str string to parse
 * @param success flag of successfull execution
 * @return true if there are more operators in string
 */
BOOLEAN basic_parser_parse(basic_parser_context_t*, const char*, BOOLEAN*);

__END_DECLS

#endif /* BASIC_PARSER_H */

