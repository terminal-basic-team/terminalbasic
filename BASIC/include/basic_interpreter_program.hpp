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

#ifndef BASIC_INTERPRETER_PROGRAM_HPP
#define BASIC_INTERPRETER_PROGRAM_HPP

#include "basic_interpreter.hpp"

namespace BASIC
{

class Interpreter::Program
{
	friend class Interpreter;
public:

	/**
	 * BASIC string
	 * @return 
	 */
	struct CPS_PACKED String
	{
		uint16_t number;
		uint8_t size;
		char text[];
	};

	struct CPS_PACKED StackFrame
	{

		enum Type : uint8_t
		{
			SUBPROGRAM_RETURN, FOR_NEXT, STRING, ARRAY_DIMENSION,
			ARRAY_DIMENSIONS
		};

		struct CPS_PACKED ForBody
		{
			uint16_t calleeIndex;
			char varName[VARSIZE];
			Parser::Value current;
			Parser::Value step;
			Parser::Value finalv;
		};

		static uint8_t size(Type);

		Type _type;

		union CPS_PACKED
		{
			uint16_t	calleeIndex;
			uint8_t		arrayDimensions;
			uint16_t	arrayDimension;
			ForBody		forFrame;
			char		string[STRINGSIZE];
		} body;
	};

	Program();
	/**
	 * Clear program memory
	 */
	void newProg();

	void reset();

	String *getString();

	String *current() const;
	String *first() const;
	String *last() const;
	
	void jump(uint16_t newVal) { _jump = newVal; }

	/**
	 * @brief program string at given index
	 * @param index
	 * @return string pointer or NULL if not exists
	 */
	String *stringByIndex(uint16_t) const;
	/**
	 * @brief program string of given number
	 * @param number
	 * @param index
	 * @return string pointer or NULL if not found
	 */
	String *stringByNumber(uint16_t, size_t = 1);
	/**
	 * @brief 
	 * @param string pointer
	 * @return index
	 */
	uint16_t stringIndex(const String*) const;

	uint16_t variablesStart() const;
	uint16_t arraysStart() const;
	/**
	 * @brief get variable frame at a given index
	 * @param index
	 * @return pointer
	 */
	VariableFrame *variableByIndex(uint16_t);
	VariableFrame *variableByName(const char*);
	uint16_t variableIndex(VariableFrame*) const;
	
	ArrayFrame *arrayByIndex(uint16_t);
	ArrayFrame *arrayByName(const char*);
	uint16_t arrayIndex(ArrayFrame*) const;
	/**
	 * @brief Add new array frame
	 * @param name name of the array (also defines type of the elements)
	 * @param dim number of dimensions
	 * @param num overall elements number
	 * @return 
	 */
	ArrayFrame *addArray(const char*, uint8_t, uint32_t);

	StackFrame *stackFrameByIndex(uint16_t index);
	/**
	 * @brief create new stack frame of given type and get its pointer
	 * @param type
	 */
	StackFrame *push(StackFrame::Type);
	void pop();
	/**
	 * @brief Add new Program string
	 * @param number
	 * @param text
	 */
	void addString(uint16_t, const char*);
	bool insert(int, const char*);
	char _text[PROGSIZE];
private:
	uint16_t _first, _last, _current, _variablesEnd, _arraysEnd, _sp, _jump;
};

}

#endif
