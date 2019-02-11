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
		BASIC_TOKEN_COM_CLS,
		BASIC_TOKEN_KW_FOR,
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
	uint8_t buf[16];
	for (i = 0; i<sizeof (tokens) / sizeof (tokens[0]); ++i) {
		if (!basic_lexer_getnextPlain(&lexer)) {
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
	const uint8_t s[] = "40128 123456.012 .12 12. 12.32 13.1e2 13e3";
	basic_token_t tokens[] = {
		BASIC_TOKEN_OP_AND,
		BASIC_TOKEN_KW_GOSUB,
		BASIC_TOKEN_KW_GOTO,
		BASIC_TOKEN_KW_IF,
		BASIC_TOKEN_KW_LET,
		BASIC_TOKEN_KW_PRINT,
		BASIC_TOKEN_KW_RETURN
	};
	uint8_t tokenized[41];
	
	basic_lexer_context_t lexer;
	
	const uint8_t size = basic_lexer_tokenize(&lexer, tokenized,
	    ARRAY_SIZE(tokenized), s);
	basic_lexer_init(&lexer, tokenized);
	while (basic_lexer_getnextTokenized(&lexer)) {
		basic_token_t tok = lexer.token;
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
