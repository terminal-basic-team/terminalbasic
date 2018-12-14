#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "basic_lexer.h"
#include "simple_math.h"

int
main(int argc, char** argv)
{
	float x = 1e-6;
	printf("%f\n", logf(x));
	printf("%f\n", s_logf(x));
	
	x = 4.0001;
	printf("%f\n", sqrtf(x));
	printf("%f\n", s_sqrtf(x));
	
	const char s[] = "; \"123 321 asd dsa\"\\ ^ + <<> < > <= ><,: 12 1.2 1e3 .2 1.1e-4";
	basic_lexer_context_t lexer;
	basic_lexer_init(&lexer, s);
	while (basic_lexer_getnext(&lexer)) {
		basic_token_t t = lexer.token;
		t++;
	}

	return EXIT_SUCCESS;
}

