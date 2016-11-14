#include "basic_interpreter_program.hpp"

namespace BASIC
{

uint8_t
Interpreter::Program::StackFrame::size(Type t)
{
	switch (t) {
	case SUBPROGRAM_RETURN:
		return sizeof (Type) + sizeof (uint16_t);
	case FOR_NEXT:
		return sizeof (Type) + sizeof (ForBody);
	}
}

}
