#include "test_module.hpp"
#include "basic_interpreter.hpp"
/*
static const uint8_t testModuleFuncs[] PROGMEM = {
	'H','Y','P','O','T',ASCII_NUL,
	ASCII_ETX
};

static const BASIC::FunctionBlock::function funcs[] PROGMEM = {
	TestModule::func_hypot
};

static const uint8_t testModuleCommands[] PROGMEM = {
	'M','U','L','T','P','R','I','N','T','2',ASCII_NUL,
	'M','U','L','T','P','R','I','N','T',ASCII_NUL,
	ASCII_ETX
};

static const BASIC::FunctionBlock::command commands[] PROGMEM = {
	TestModule::comm_multprint2,
	TestModule::comm_multprint
};*/

TestModule::TestModule()
{
	/*commands = commands;
	commandTokens = testModuleCommands;
	functions = funcs;
	functionTokens = testModuleFuncs;*/
}

bool
TestModule::comm_multprint(BASIC::Interpreter& i)
{
	const char *str;
	if (i.popString(str)) { // Получение строки со стека
		BASIC::Parser::Value v;
		if (i.popValue(v)) { // Получение числового/логического значения со стека
			//if (v.type() == BASIC::Parser::Value::INTEGER) {
				BASIC::Integer num = BASIC::Integer(v);
				while (num-- > 0) {
					i.print(str);
					i.print('\n');
				}
				return true;
			//}
		}
	}
	return false;
}
/*
bool
TestModule::comm_multprint2(BASIC::Interpreter& i)
{
	const char *str;
	if (i.popString(str)) { // Получение строки со стека
		BASIC::Parser::Value v;
		if (i.popValue(v)) { // Получение числового/логического значения со стека
			//if (v.type() == BASIC::Parser::Value::INTEGER) {
				BASIC::Integer num = BASIC::Integer(v);
				while (num-- > 0) {
					i.print(str);
				}
				i.print('\n');
				return true;
			//}
		}
	}
	return false;
}

bool
TestModule::func_hypot(BASIC::Interpreter& i)
{
	BASIC::Parser::Value v1, v2;
	if (i.popValue(v2)) {
		if (i.popValue(v1)) {
			const BASIC::Real rv1 = BASIC::Real(v1);
			const BASIC::Real rv2 = BASIC::Real(v2);
			v1 = sqrt(rv1*rv1 + rv2*rv2);
			if (i.pushValue(v1))
				return true;
		}
	}
	return false;
}
*/
