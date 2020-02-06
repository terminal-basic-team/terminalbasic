#include <stdint.h>

#include "HAL.h"

void HAL_nvram_write_buf(HAL_nvram_address_t address, const void* buf, uint32_t size)
{
	const uint8_t* bp = (const uint8_t*)buf;
	for (HAL_nvram_address_t a=address; a<address+size; ++a)
		HAL_nvram_write(a, *(bp++));
}

void HAL_nvram_read_buf(HAL_nvram_address_t address, void* buf, uint32_t size)
{
	uint8_t* bp = (uint8_t*)buf;
	for (HAL_nvram_address_t a=address; a<address+size; ++a)
		*(bp++) = HAL_nvram_read(a);
}
