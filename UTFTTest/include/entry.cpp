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

uint16_t x1 = 0, x2 = 479, y1 = 0, y2 = 319;
bool mode = true;
bool sleep = false;

void
loop()
{
	if (Serial.available() > 0) {
		char c = Serial.read();
		Serial.println(c, HEX);
		switch (c) {
		case 'l':
			Serial.println("Switch lcd on/off");
			if (mode = !mode) {
				utft.execCommand(MIPICommands::SET_DISPLAY_ON);
			} else {
				utft.execCommand(MIPICommands::SET_DISPLAY_OFF);
			}
			break;
		case 's':
			Serial.println("Sleep on/off");
			if (sleep = !sleep) {
				utft.execCommand(MIPICommands::ENTER_SLEEP_MODE);
			} else {
				utft.execCommand(MIPICommands::EXIT_SLEEP_MODE);
			}
			break;
		case 'd':
			terminal.dump(); break;
		case '\r':
			terminal.write(c);
			terminal.write('\n'); break;
		case 'a':
			x1--, x2--;
			utft.setXY(x1,y1,x2,y2); break;
		/*case 's':
			x1++, x2++;
			utft.setXY(x1,y1,x2,y2); break;*/
		default:
			terminal.write(c);
		};
	}
}
