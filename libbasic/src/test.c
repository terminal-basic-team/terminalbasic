#include <stdio.h>
#include <stdlib.h>

#include "math.h"

#include "basic_lexer.h"
#include "tools.h"

static BOOLEAN
lexer_test_keywords()
{
	const uint8_t s[] = "ANDINV(LET A = 3";
	basic_token_t tokens[] = {
		BASIC_TOKEN_OP_AND,
		BASIC_TOKEN_KW_INV,
		BASIC_TOKEN_LPAREN,
		BASIC_TOKEN_KW_LET,
		BASIC_TOKEN_REAL_IDENT,
		BASIC_TOKEN_EQUALS,
		BASIC_TOKEN_C_INTEGER
	};
	basic_lexer_context_t lexer;
	basic_lexer_init(&lexer, s, FALSE);

	uint8_t i;
	uint8_t buf[16];
	for (i = 0; i<sizeof (tokens) / sizeof (tokens[0]); ++i) {
		if (!basic_lexer_getNext(&lexer)) {
			fprintf(stderr, "basic_lexer_getnextPlain\n");
			return FALSE;
		}
		basic_lexer_tokenString(tokens[i], buf);
		fprintf(stderr, "token: %s\n", buf);
		if (lexer.token != tokens[i])
			return FALSE;
	}

	return TRUE;
}

BOOLEAN
lexer_test_tokenization()
{
	const uint8_t s[] = "LET A = 3";
	basic_token_t tokens[] = {
		BASIC_TOKEN_KW_LET,
		BASIC_TOKEN_REAL_IDENT,
		BASIC_TOKEN_EQUALS,
		BASIC_TOKEN_C_INTEGER
	};
	uint8_t tokenized[41];
	
	basic_lexer_context_t lexer;
	
	const uint8_t size = basic_lexer_tokenize(&lexer, tokenized,
	    ARRAY_SIZE(tokenized), s);
	basic_lexer_init(&lexer, tokenized, TRUE);
	while (basic_lexer_getNext(&lexer)) {
		basic_token_t tok = lexer.token;
		uint8_t buf[16];
		basic_lexer_tokenString(tok, buf);
		fprintf(stderr, "token: %s\n", buf);
	}
	
	printf("Tokenized string of size %hhu\n", size);
	return TRUE;
}

int
main(int argc, char** argv)
{
	if (lexer_test_keywords())
		printf("success\n");
	else
		fprintf(stderr, "lexer_test_keywords\n");
	
	if (lexer_test_tokenization())
		printf("success\n");
	else
		fprintf(stderr, "lexer_test_keywords\n");
	
	
	fflush(stdout);
	return EXIT_SUCCESS;
}
