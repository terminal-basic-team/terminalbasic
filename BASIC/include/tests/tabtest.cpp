/*
 * Разработчик: Закрытое акционерное общество "Научно исследовательский
 * институт "Центрпрограммсистем", г. Тверь (ЗАО НИИ ЦПС)
 *
 * Интеллектуальная собственность ЗАО НИИ ЦПС
 */

/* 
 * File:   tabtest.cpp
 * Author: starling13
 *
 * Created on 17 марта 2017 г., 19:07
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

#include "basic.hpp"

static const uint8_t tab1[] = {
	'P', 'A', 'R', 'S', 'E'+0x80,	// 0
	'T', 'E', 'S', 'T', '2'+0x80,	// 1
	'T', 'E', 'S', 'T'+0x80,	// 2
	0
};

void test1()
{
	std::cout << "tabtest test 1" << std::endl;
	const char str[] = "TESTTEST2PARSE SYM";
	
	uint8_t index;
	uint8_t *st = (uint8_t*)str;
	while (st = BASIC::scanTable(st, tab1, index)) {
		std::cout << "Token " << int(index) << std::endl;
	}
}

void test2()
{
	std::cout << "tabtest test 2" << std::endl;
	//std::cout << "%TEST_FAILED% time=0 testname=test2 (tabtest) message=error message sample" << std::endl;
}

int main(int argc, char** argv)
{
	std::cout << "%SUITE_STARTING% tabtest" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	std::cout << "%TEST_STARTED% test1 (tabtest)" << std::endl;
	test1();
	std::cout << "%TEST_FINISHED% time=0 test1 (tabtest)" << std::endl;

	std::cout << "%TEST_STARTED% test2 (tabtest)\n" << std::endl;
	test2();
	std::cout << "%TEST_FINISHED% time=0 test2 (tabtest)" << std::endl;

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	return (EXIT_SUCCESS);
}

