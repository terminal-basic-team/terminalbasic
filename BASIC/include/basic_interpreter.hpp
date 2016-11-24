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
	/**
	 * Variable type
	 */
	enum Type : uint8_t
	{
		INTEGER = 0,
		REAL,
		BOOLEAN,
		STRING
	};
	/**
	 * Dynamic (runtime error codes)
	 */
	enum ErrorCodes : uint8_t
	{
		NO_ERROR = 0,
		OUTTA_MEMORY,
		REDIMED_ARRAY,
		STACK_FRAME_ALLOCATION,
		ARRAY_DECLARATION,
		STRING_FRAME_SEARCH,
		INVALID_NEXT,
		RETURN_WO_GOSUB,
		NO_SUCH_STRING,
		INVALID_VALUE_TYPE,
		NO_SUCH_ARRAY,
		INTERNAL_ERROR = 255
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
	
	struct ArrayFrame
	{
		uint16_t size() const;
		
		uint8_t *data()
		{
			return (reinterpret_cast<uint8_t*>(this+1) +
			    sizeof (uint16_t)*numDimensions);
		}
		
		const uint8_t *data() const
		{
			return (reinterpret_cast<const uint8_t*>(this+1) +
			    sizeof (uint16_t)*numDimensions);
		}
		
		template <typename T>
		T get(uint16_t index) const
		{
			union
			{
				const uint8_t *b;
				const T *i;
			} _U;
			_U.b = this->data();
			return _U.i[index];
		}
		
		char name[VARSIZE];
		Type type;
		uint8_t numDimensions;
		uint16_t dimension[];
	};
	
	enum State : uint8_t
	{
		SHELL, EXECUTE
	};
	
	enum DumpMode : uint8_t
	{
		MEMORY, VARS, ARRAYS
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
	
	void save();
	
	void load();
	/**
	 * @breif Input variable
	 * @param variable name
	 */
	void input(const char*);
	
	void end();
	/**
	 * @brief set value to initialized object
	 * @param f frame to set to
	 * @param v value to set
	 */
	void set(VariableFrame&, const Parser::Value&);
	void set(ArrayFrame&, uint16_t, const Parser::Value&);
	/**
	 * @brief set a new value and possibly create new variable
	 * @param name variable name
	 * @param v value to assign
	 */
	Interpreter::VariableFrame *setVariable(const char*,
	    const Parser::Value&);
	void setArrayElement(const char*, const Parser::Value&);
	
	void newArray(const char*);
	const VariableFrame *getVariable(const char*);
	
	void valueFromVar(Parser::Value&, const char*);
	
	void valueFromArray(Parser::Value&, const char*);
	
	/**
	 * @brief push string constant on the stack
	 */
	void pushString(const char*);
	/**
	 * @brief push the next array dimesion on the stack
	 * @param 
	 * @return 
	 */
	uint16_t pushDimension(uint16_t);
	/**
	 * @brief push the number of array dimesions on the stack
	 * @param num number of dimensions
	 */
	void pushDimensions(uint8_t);

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
	/**
	 * @brief Add new array frame
	 * @param name name of the array (also defines type of the elements)
	 * @param dim number of dimensions
	 * @param num overall elements number
	 * @return 
	 */
	ArrayFrame *addArray(const char*, uint8_t, uint32_t);
	
	bool arrayElementIndex(ArrayFrame*, uint16_t&);
	
	State	 _state;
	Stream	&_stream;
	Lexer	 _lexer;
	Parser	 _parser;
	static PGM_P const _errorStrings[];
};

}

#endif
