#include <stdio.h>
#include <stdlib.h>

#include "math.h"

#include "basic_lexer.h"
#include "tools.h"

static BOOLEAN
lexer_test_keywords()
{
	const uint8_t s[] = "AND GOSUB GOTO IF LET PRINT RETURN";
	basic_token_t tokens[] = {
		BASIC_TOKEN_OP_AND,
		BASIC_TOKEN_KW_GOSUB,
		BASIC_TOKEN_KW_GOTO,
		BASIC_TOKEN_KW_IF,
		BASIC_TOKEN_KW_LET,
		BASIC_TOKEN_KW_PRINT,
		BASIC_TOKEN_KW_RETURN
	};
	basic_lexer_context_t lexer;
	basic_lexer_init(&lexer, s);
	
	uint8_t i;
	for (i=0; i<sizeof(tokens)/sizeof(tokens[0]); ++i) {
		if (!basic_lexer_getnextPlain(&lexer)) {
			fprintf(stderr, "basic_lexer_getnextPlain\n");
			return FALSE;
		}
		if (lexer.token != tokens[i]) {
			uint8_t buf[16];
			basic_lexer_tokenString(tokens[i], buf);
			fprintf(stderr, "token: %s\n", buf);
			return FALSE;
		}
	}
	
	return TRUE;
}

int
main(int argc, char** argv)
{
	if (lexer_test_keywords())
		printf(stdout, "success\n");
	else
		fprintf(stderr, "lexer_test_keywords\n");
	
	return EXIT_SUCCESS;
}
