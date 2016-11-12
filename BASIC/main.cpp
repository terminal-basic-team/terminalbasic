#include "arduino_logger.hpp"
#include "basic_interpreter_program.hpp"

static BASIC::Interpreter::Program program;
static BASIC::Interpreter basic(Serial, program);

void setup()
{
	Serial.begin(19200);
	LOG_INIT(Serial);

	LOG_TRACE;
}

void loop()
{
	LOG_TRACE;

	basic.step();
}
