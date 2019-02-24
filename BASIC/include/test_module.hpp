#ifndef TEST_MODULE_HPP
#define TEST_MODULE_HPP

#include "basic_functionblock.hpp"

class TestModule : public BASIC::FunctionBlock
{
public:
	TestModule();

//	static bool func_hypot(BASIC::Interpreter&);
//	static bool comm_multprint2(BASIC::Interpreter&);
	static bool comm_multprint(BASIC::Interpreter&);
};

#endif /* TEST_MODULE_HPP */
