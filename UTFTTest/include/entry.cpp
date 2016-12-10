#include "utft_stream.hpp"
#include <memorysaver.h>
#include <UTFT.h>

#include "arduino_logger.hpp"

static UTFT utft(CTE32HR, 38, 39, 40, 41);
static UTFTTerminal terminal(utft);

void
setup()
{
	terminal.begin();
	Serial.begin(57600);
	LOG_INIT(Serial);
}

void
loop()
{
	if (Serial.available() > 0) {
		char c = Serial.read();
		if (c == '\r') {
			terminal.println();
		} else if (c == 'd') {
			terminal.dump();
		} else
			terminal.write(c);
	}
}
