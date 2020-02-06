#ifndef ARDUINO_ARCH_AVR
#error "This file requires ARDUINO_ARCH_AVR to be defined"
#endif

#include <avr/io.h>
#include <avr/eeprom.h>

#include "HAL.h"

HAL_nvram_address_t HAL_nvram_getsize()
{
	return HAL_nvram_address_t(E2END+1);
}

uint8_t HAL_nvram_read(HAL_nvram_address_t addr)
{
	return eeprom_read_byte((uint8_t*)addr);
}

void HAL_nvram_write(HAL_nvram_address_t addr, uint8_t byte)
{
	return eeprom_update_byte((uint8_t*)addr, byte);
}
