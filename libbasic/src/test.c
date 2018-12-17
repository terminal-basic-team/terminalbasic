#include <stdio.h>
#include <stdlib.h>

#include "math.h"

#include "basic_lexer.h"
#include "tools.h"

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
	
	char b[14];
	ftoa(0, b);
	puts(b);
	ftoa(1e27, b);
	puts(b);
	ftoa(1e-27, b);
	puts(b);
	ftoa(9.9999999, b);
	puts(b);
	ftoa(66.3, b);
	puts(b);
	ftoa(-0.1e-22, b);
	puts(b);

	return EXIT_SUCCESS;
}
