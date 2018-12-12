#include <stdio.h>
#include <stdlib.h>

#include <basic_lexer.h>

int
main(int argc, char** argv)
{
	const char s[] = "; \"123 321 asd dsa\"\\ ^ + <<> < > <= ><,: 12 1.2 1e3 .2 1.1e-4";
	basic_lexer_context_t lexer;
	basic_lexer_init(&lexer, s);
	while (basic_lexer_getnext(&lexer)) {
		basic_token_t t = lexer.token;
		t++;
	}

	return EXIT_SUCCESS;
}

