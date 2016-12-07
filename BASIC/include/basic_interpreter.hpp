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
#include "basic_lexer.hpp"
#include "basic_parser.hpp"
#include "helper.hpp"

namespace BASIC
{

/**
 * @brief Interpreter context object
 */
class CPS_PACKED Interpreter
{
public:
	/**
	 * @brief BASIC program memory
	 */
	class CPS_PACKED Program;
	
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
		NO_ERROR = 0,		// Ok
		OUTTA_MEMORY,		// Out of memory
		REDIMED_ARRAY,		// Attempt to define existing array
		STACK_FRAME_ALLOCATION,	// Unable to allocate stack frame
		ARRAY_DECLARATION,	
		STRING_FRAME_SEARCH,	// Missing string frame
		INVALID_NEXT,		// 
		RETURN_WO_GOSUB,
		NO_SUCH_STRING,
		INVALID_VALUE_TYPE,
		NO_SUCH_ARRAY,
		INTERNAL_ERROR = 255
	};
	
	/**
	 * Type of the occurederror
	 */
	enum ErrorType : uint8_t
	{
		STATIC_ERROR, // syntax
		DYNAMIC_ERROR // runtime
	};
	
	/**
	 * @brief variable memory frame
	 */
	struct CPS_PACKED VariableFrame
	{
		/**
		 * @brief size of the initialized frame
		 * @return size in bytes
		 */
		uint8_t size() const;

		/**
		 * @brief getValue from Variable frame
		 * @param T value type
		 * @return value
		 */		
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
		
		// Variable name
		char name[VARSIZE];
		// Variable type
		Type type;
		// Frame body
		char bytes[];
	};
	
	/**
	 * Array memory frame
	 */
	struct ArrayFrame
	{
		/**
		 * @brief get frame size in bytes
		 * @return size
		 */
		uint16_t size() const;
		
		/**
		 * @brief get array raw data pointer
		 * @return pointer
		 */
		uint8_t *data()
		{
			return (reinterpret_cast<uint8_t*>(this+1) +
			    sizeof (uint16_t)*numDimensions);
		}
		
		/**
		 * @brief Overloaded version
		 */
		const uint8_t *data() const
		{
			return (reinterpret_cast<const uint8_t*>(this+1) +
			    sizeof (uint16_t)*numDimensions);
		}
		
		/**
		 * @brief get array value by raw index
		 * @param index shift in array data
		 * @return value
		 */
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
		
		// Array data
		char name[VARSIZE];
		// Array type
		Type type;
		// Number of dimensions
		uint8_t numDimensions;
		// dimensions values
		uint16_t dimension[];
	};
	// Interpreter FSM state
	enum State : uint8_t
	{
		SHELL, PROGRAM_INPUT, COLLECT_INPUT, EXECUTE, VAR_INPUT
	};
	// Memory dump modes
	enum DumpMode : uint8_t
	{
		MEMORY, VARS, ARRAYS
	};
	// Terminal text attributes to use when printing
	enum TextAttr : uint8_t
	{
		NO_ATTR = 0,
		BOLD = 0x1,
		UNDERLINE = 0x2,
		DIM = 0x4
	};
	enum ProgMemStrings : uint8_t;
	
	/**
	 * @brief constructor
	 * @param stream Boundary object for I/O
	 * @param program Program object
	 * @param firstModule First module in chain
	 */
	explicit Interpreter(Stream&, Program&, FunctionBlock* = NULL);
	
	/**
	 * [re]initialize interpreter object
	 */
	void init();
	// Interpreter cycle: request a string or execute one operator
	void step();
	// Execute entered command (command or inputed program line)
	void exec();
	void cls();
	void doInput();
	// Output program memory
	void list(uint16_t=1, uint16_t=0);
	// Dump program memory
	void dump(DumpMode);
	// print value
	void print(const Parser::Value&, TextAttr=NO_ATTR);
	void print(char);
	void print(Real);
	// run program
	void run();
	// goto new line
	void gotoLine(Integer);
	// CLear program memory
	void newProgram();
	/**
	 * save current line on stack
	 * @param text position
	 */
	void pushReturnAddress(uint8_t);
	// return from subprogram
	void returnFromSub();
	// save for loop
	void pushForLoop(const char*, uint8_t, const Parser::Value&,
	    const Parser::Value&);
	void pushValue(const Parser::Value&);
	bool popValue(Parser::Value&);
	/**
	 * @brief iterate over loop
	 * @param varName loop variable name
	 * @return loop end flag
	 */
	bool next(const char*);
	
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
	/**
	 * @brief setarray element a given value with indexes on the stack
	 * @param name array name
	 * @param value value to set
	 */
	void setArrayElement(const char*, const Parser::Value&);
	/**
	 * @brief create array
	 * @param name array name
	 */
	void newArray(const char*);
	/**
	 * @brief get variable frame pointer (or create new one)
	 * @param name variable name
	 * @return frame pointer
	 */
	const VariableFrame *getVariable(const char*);
	
	void valueFromVar(Parser::Value&, const char*);
	
	bool valueFromArray(Parser::Value&, const char*);
	
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
	
	void strConcat(Parser::Value&, Parser::Value&);

	Program &_program;
private:
	class AttrKeeper;
	
	void print(const char *, TextAttr=NO_ATTR);
	void print(ProgMemStrings, TextAttr=NO_ATTR);
	void print(Integer, TextAttr=NO_ATTR);

	
	void raiseError(ErrorType, uint8_t=0);
	/**
	 * @brief read and buffer one symbol
	 * @return input finished flag
	 */
	bool readInput();
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
	static PGM_P const _progmemStrings[];
	char _inputBuffer[PROGSTRINGSIZE];
	uint8_t _inputPosition;
	char _inputVarName[VARSIZE];
};

}

#endif
