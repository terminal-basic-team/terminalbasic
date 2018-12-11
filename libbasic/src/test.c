#include <stdio.h>
#include <stdlib.h>

#include <basic_lexer.h>

int
main(int argc, char** argv)
{
	const char s[] = ";	\\  ^ + <<> < > <= ><,:";
	basic_lexer_context_t lexer;
	basic_lexer_init(&lexer, s);
	while (basic_lexer_getnext(&lexer)) {
		basic_token_t t = lexer.token;
		t++;
	}

	return EXIT_SUCCESS;
}

