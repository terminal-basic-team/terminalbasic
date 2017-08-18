#include <stdlib.h>
#include <iostream>

#include "basic_lexer.hpp"

/*
 * Simple C++ Test Suite
 */

void test1()
{
	std::cout << "TableTest test 1" << std::endl;
	BASIC::Lexer lex;
	uint8_t buf[16];
	
	const uint8_t *c = lex.getTokenString(BASIC::Token::OP_AND, buf);
	std::cout << c << std::endl;

	c = lex.getTokenString(BASIC::Token::OP_NOT, buf);
	std::cout << c << std::endl;

	c = lex.getTokenString(BASIC::Token::OP_OR, buf);
	std::cout << c << std::endl;

	return;
}

void test2()
{
	std::cout << "TableTest test 2" << std::endl;
	//std::cout << "%TEST_FAILED% time=0 testname=test2 (TableTest) message=error message sample" << std::endl;
}

int main(int argc, char** argv)
{
	std::cout << "%SUITE_STARTING% TableTest" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	std::cout << "%TEST_STARTED% test1 (TableTest)" << std::endl;
	test1();
	std::cout << "%TEST_FINISHED% time=0 test1 (TableTest)" << std::endl;

	std::cout << "%TEST_STARTED% test2 (TableTest)\n" << std::endl;
	test2();
	std::cout << "%TEST_FINISHED% time=0 test2 (TableTest)" << std::endl;

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	return (EXIT_SUCCESS);
}

