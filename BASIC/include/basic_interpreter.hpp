#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "basic.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "helper.hpp"

namespace BASIC
{

class Interpreter
{
public:
	/**
	 * Basic program memory
	 */
	class Program;
	
	struct CPS_PACKED VariableFrame
	{
		enum Type : uint8_t
		{
			INTEGER = 0, REAL, BOOLEAN, STRING, INTEGER_ARRAY,
			REAL_ARRAY
		};
		uint8_t size() const;
		void set(const Integer&);
		
		template <typename T>
		T get() const
		{
			union
			{
				const char *b;
				const T *i;
			} _U;
			_U.b = bytes;
			return *_U.i;
		}
		
		char name[4];
		Type type;
		char bytes[];
	};
	
	enum State
	{
		SHELL, EXECUTE
	};
	
	Interpreter(Stream&, Program&);
	// Interpreter cycle: request a string or execute one operator
	void step();
	// Output program memory
	void list();
	// Dump program memory
	void dump();
	// print value
	void print(const Parser::Value&);
	void print(char);
	// run program
	void run();
	// goto new line
	void gotoLine(Integer);
	// CLear program memory
	void newProgram();
	// save current line on stack
	void pushReturnAddress();
	
	void returnFromSub();
	
	void end();
	/**
	 * @brief set a new value and possibly create new variable
	 * @param name variable name
	 * @param v value to assign
	 */
	void setVariable(const char*, const Parser::Value&);
	const VariableFrame &getVariable(const char*);
	
	Program &_program;
private:
	enum ErrorStrings : uint8_t;
	void staticErrorPrint();
	void dynamicError(const char*);
	State	 _state;
	Stream	&_stream;
	Lexer	 _lexer;
	Parser	 _parser;
	static PGM_P const _errorStrings[];
};

}

#endif
