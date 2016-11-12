#ifndef HELPER_HPP
#define HELPER_HPP

#include "cps.hpp"

#ifdef ARDUINO
#include <Arduino.h>

inline void
positiveLedBlink(size_t num = 1)
{
	for (size_t i = 0; i<num; ++i) {
		digitalWrite(13, HIGH);
		delay(100);
		digitalWrite(13, LOW);
		delay(100);
	}
}

inline void
negativeLedBlink(size_t num = 1)
{
	for (size_t i = 0; i < num; ++i) {
		digitalWrite(13, HIGH);
		delay(500);
		digitalWrite(13, LOW);
		delay(300);
	}
}

#else

#ifndef ARDUINO
#define positiveLedBlink(a...)
#define negativeLedBlink(a...)
#define PGM_P const char*
#define PROGMEM
#endif

#endif

#endif /* HELPER_HPP */
