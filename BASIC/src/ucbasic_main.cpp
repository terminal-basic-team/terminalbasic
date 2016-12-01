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

#include "arduino_logger.hpp"
#include "basic_interpreter_program.hpp"
#include "basic_math.hpp"
#include "basic_arduinoio.hpp"

static BASIC::Math mathBlock;
static BASIC::ArduinoIO arduinoIo(&mathBlock);

static BASIC::Interpreter::Program program;
static BASIC::Interpreter basic(Serial, program, &arduinoIo);
/*
static BASIC::Interpreter::Program program1;
static BASIC::Interpreter basic1(Serial1, program, &arduinoIo);

static BASIC::Interpreter::Program program2;
static BASIC::Interpreter basic2(Serial2, program2, &arduinoIo);
*/
void setup()
{
	Serial.begin(57600);
	//Serial1.begin(57600);
	//Serial2.begin(57600);
	
	LOG_INIT(Serial);

	LOG_TRACE;
	
	basic.init();
	//basic1.init();
	//basic2.init();
}

void loop()
{
	LOG_TRACE;
	
	basic.step();
	//basic1.step();
	//basic2.step();
}
