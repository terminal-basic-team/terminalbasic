/*
 * Разработчик: Закрытое акционерное общество "Научно исследовательский
 * институт "Центрпрограммсистем", г. Тверь (ЗАО НИИ ЦПС)
 *
 * Интеллектуальная собственность ЗАО НИИ ЦПС
 */

/* 
 * File:   newsimpletest.cpp
 * Author: starling13
 *
 * Created on 1 ноября 2016 г., 14:01
 */

#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string.h>

#include "ringbuffer.hpp"

/*
 * Simple C++ Test Suite
 */

void test1()
{
#define S 19
	std::cout << "newsimpletest test 1" << std::endl;
	RingQueue<char, S> q;
	for (size_t i=0; i<22; ++i) {
		std::cout << q.first() << ' ' << q.last() << ' ' << q.length() << '\n';
		q.insert(i);
	}
	
	std::cout << std::endl;
	
	char a[S];
	int s = q.length() - q.first();
	std::memcpy(a, q.data()+q.first(), s);
	std::memcpy(a+s, q.data(), q.first());
	for (size_t i = 0; i<S; ++i)
		std::cout << std::hex << int(a[i]) << ' ';
	
	std::cout << std::endl;
	return;
}

void test2()
{
	std::cout << "newsimpletest test 2" << std::endl;
	//std::cout << "%TEST_FAILED% time=0 testname=test2 (newsimpletest) message=error message sample" << std::endl;
}

int main(int argc, char** argv)
{
	std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	std::cout << "%TEST_STARTED% test1 (newsimpletest)" << std::endl;
	test1();
	std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest)" << std::endl;

	std::cout << "%TEST_STARTED% test2 (newsimpletest)\n" << std::endl;
	test2();
	std::cout << "%TEST_FINISHED% time=0 test2 (newsimpletest)" << std::endl;

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	return (EXIT_SUCCESS);
}

