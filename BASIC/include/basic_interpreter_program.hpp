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
	/**
	 * @brief get variable frame at a given index
	 * @param index
	 * @return pointer
	 */
	VariableFrame *variableByIndex(uint16_t);
	VariableFrame *variableByName(const char*);

	void addString(uint16_t, const char*);
	bool insert(int, const char*);
	char _text[PROGSIZE];
private:
	uint16_t _first, _last, _current, _variablesEnd;
};

}

#endif
