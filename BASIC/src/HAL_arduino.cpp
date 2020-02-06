#ifndef ARDUINO
#error "This file requires ARDUINO to be defined"
#endif

#include "HAL.h"

#include "Arduino.h"

void HAL_time_sleep_ms(uint32_t ms)
{
	delay(ms);
}

uint32_t HAL_time_gettime_ms()
{
	return millis();
}
