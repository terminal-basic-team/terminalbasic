#include <stdio.h>
#include <stdlib.h>

#include "math.h"

#include "basic_lexer.h"
#include "tools.h"

int
main(int argc, char** argv)
{
	char buf[32];
	const char s[] = "LET; \"123 321 asd dsa\"\\PRINT ^ + <<> < > <= ><,: 12 1.2 1e3 .2 1.1e-4";
	basic_lexer_context_t lexer;
	basic_lexer_init(&lexer, s);
	while (basic_lexer_getnext(&lexer)) {
		basic_token_t t = lexer.token;
		basic_lexer_tokenString(t, buf);
		puts(buf);
	}
	
	const char s2[] = "REM   1 0 2";
	uint8_t d2[12];
	uint8_t len = basic_lexer_tokenize(&lexer, d2, 12, s2);

	return EXIT_SUCCESS;
}
