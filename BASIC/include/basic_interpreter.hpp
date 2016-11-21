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
#include "basic_parser.hpp"
#include "helper.hpp"

namespace BASIC
{

/**
 * @brief Interpreter context object
 */
class Interpreter
{
public:
	/**
	 * @brief BASIC program memory
	 */
	class Program;
	
	enum Type : uint8_t
	{
		INTEGER = 0,
		REAL,
		BOOLEAN,
		STRING
	};
	
	enum ErrorCodes : uint8_t
	{
		NO_ERROR = 0,
		REDIMED_ARRAY,
		STACK_FRAME_ALLOCATION,
		ARRAY_DECLARATION,
		STRING_FRAME_SEARCH,
		INVALID_NEXT,
		RETURN_WO_GOSUB,
		NO_SUCH_STRING,
		INVALID_VALUE_TYPE
	};
	
	enum ErrorType : uint8_t
	{
		STATIC_ERROR, // syntax
		DYNAMIC_ERROR // runtime
	};
	
	/**
	 * @brief variable memory object
	 */
	struct CPS_PACKED VariableFrame
	{
		/**
		 * @brief size of the initialized frame
		 * @return size in bytes
		 */
		uint8_t size() const;

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
	
	void valueFromFrame(Parser::Value &v,
	    const Interpreter::VariableFrame &f);
	
	struct ArrayFrame
	{
		uint16_t size() const;
		
		char name[VARSIZE];
		Type type;
		uint8_t numDimensions;
		uint16_t dimension[];
	};
	
	/**
	 * @brief set value to initialized object
	 * @param f frame to set to
	 * @param v value to set
	 */
	void set(VariableFrame&, const Parser::Value&);
	
	enum State : uint8_t
	{
		SHELL, EXECUTE
	};
	
	enum DumpMode : uint8_t
	{
		MEMORY, VARS
	};
	
	Interpreter(Stream&, Program&);
	// Interpreter cycle: request a string or execute one operator
	void step();
	// Output program memory
	void list();
	// Dump program memory
	void dump(DumpMode);
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
	void pushForLoop(const char*, const Parser::Value&,
	    const Parser::Value&);
	// iterate for loop
	void next(const char*);
	// Input variable value
	void input(const char*);
	
	void end();
	/**
	 * @brief set a new value and possibly create new variable
	 * @param name variable name
	 * @param v value to assign
	 */
	Interpreter::VariableFrame *setVariable(const char*,
	    const Parser::Value&);
	
	void newArray(const char*);
	const VariableFrame &getVariable(const char*);
	/**
	 * @brief push string constant on the stack
	 */
	uint16_t pushString(const char*);
	/**
	 * @brief push the next array dimesion on the stack
	 * @param 
	 * @return 
	 */
	uint16_t pushDimension(uint16_t);
	/**
	 * @brief push the number of array dimesions on the stack
	 * @param 
	 * @return 
	 */
	uint16_t pushDimensions(uint8_t);

	Program &_program;
private:
	enum TextAttr : uint8_t
	{
		NO_ATTR = 0,
		BOLD = 0x1,
		UNDERLINE = 0x2
	};
	class AttrKeeper;
	enum ErrorStrings : uint8_t;
	
	void print(const char *, TextAttr=NO_ATTR);
	void raiseError(ErrorType, uint8_t=0);
	State	 _state;
	Stream	&_stream;
	Lexer	 _lexer;
	Parser	 _parser;
	static PGM_P const _errorStrings[];
};

}

#endif
