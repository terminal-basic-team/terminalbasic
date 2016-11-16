#ifndef HELPER_HPP
#define HELPER_HPP

#include "cps.hpp"
#include <string.h>

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
#define pgm_read_word(a) (*a)
#define strcpy_P(a,b) strcpy(a,b)
#endif

#endif

inline bool
endsWith(const char *str, const char end)
{
	if (str == NULL || strlen(str)==0)
		return false;
	if (end == 0)
		return true;
	if (str[strlen(str)-1] == end)
		return true;
	else
		return false;
}

#endif /* HELPER_HPP */
