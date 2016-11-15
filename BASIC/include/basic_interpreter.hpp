/*
 * ucBASIC is a lightweight BASIC-like language interpreter
 * Copyright (C) 2016  Andrey V. Skvortsov <starling13@mail.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
		void set(const Real&);
		
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
		
		char name[VARSIZE];
		Type type;
		char bytes[];
	};
	
	static void valueFromFrame(Parser::Value &v,
	    const Interpreter::VariableFrame &f);
	
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
	// return from subprogram
	void returnFromSub();
	// save for loop
	void pushForLoop(const char*, const Parser::Value&);
	// iterate for loop
	void next(const char*);
	
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
	void dynamicError(const char* = NULL);
	State	 _state;
	Stream	&_stream;
	Lexer	 _lexer;
	Parser	 _parser;
	static PGM_P const _errorStrings[];
};

}

#endif
