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
			SUBPROGRAM_RETURN, FOR_NEXT
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
			uint16_t calleeIndex;
			ForBody forFrame;
		} body;
	};
	
	static_assert((sizeof (StackFrame::Type) + sizeof (StackFrame::ForBody))
	    == sizeof (StackFrame), "bad size");

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
	/**
	 * @brief get variable frame at a given index
	 * @param index
	 * @return pointer
	 */
	VariableFrame *variableByIndex(uint16_t);
	VariableFrame *variableByName(const char*);

	StackFrame *stackFrameByIndex(uint16_t index);

	void addString(uint16_t, const char*);
	bool insert(int, const char*);
	char _text[PROGSIZE];
private:
	uint16_t _first, _last, _current, _variablesEnd, _sp, _jump;
};

}

#endif
