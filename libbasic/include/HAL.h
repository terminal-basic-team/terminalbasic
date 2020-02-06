/* 
 * File:   HAL.h
 * Author: starling13
 *
 * Created on 6 䥢ࠫ� 2020 �., 0:23
 */

#ifndef HAL_H
#define HAL_H

#include <assert.h>
#include <inttypes.h>
#include <stdint.h>

#include "sys/cdefs.h"

__BEGIN_DECLS

/**
 * @brief Initialize hardware interface
 */
void HAL_initialize();

/**
 * @brief finalize hardware interface
 */
void HAL_finalize();

/*** Non volatile RAM interface ***/

typedef uint32_t HAL_nvram_address_t;

HAL_nvram_address_t HAL_nvram_getsize();

/**
 * @brief write byte to NVRAM
 * @param address [in]
 * @param dataByte [in]
 */
void HAL_nvram_write(HAL_nvram_address_t, uint8_t);

void HAL_nvram_write_buf(HAL_nvram_address_t, const void*, uint32_t);

/**
 * @brief read byte from NVRAM
 * @param address
 * @return byte
 */
uint8_t HAL_nvram_read(HAL_nvram_address_t);

void HAL_nvram_read_buf(HAL_nvram_address_t, void*, uint32_t);

/*** Terminal interface ***/

typedef uint8_t HAL_terminal_t;

/**
 * @param termno
 * @param byte
 */
void HAL_terminal_write(HAL_terminal_t, uint8_t);

/**
 * @param termno
 * @return byte
 */
uint8_t HAL_terminal_read(HAL_terminal_t);

/**
 * @parram termno
 * @return number of bytes, ready to read
 */
uint8_t HAL_terminal_isdataready(HAL_terminal_t);

/*** External memory interface ***/

typedef uint8_t HAL_extmem_file_t;

typedef uint32_t HAL_extmem_fileposition_t;

HAL_extmem_file_t HAL_extmem_openfile(const char*);

void HAL_extmem_closefile(HAL_extmem_file_t);

uint8_t HAL_extmem_readfromfile(HAL_extmem_file_t);

void HAL_extmem_writetofile(HAL_extmem_file_t, uint8_t);

uint32_t HAL_extmem_getfileposition(HAL_extmem_file_t);

void HAL_extmem_setfileposition(HAL_extmem_file_t, uint32_t);

HAL_extmem_fileposition_t HAL_extmem_getfilesize(HAL_extmem_file_t);

uint32_t HAL_extmem_getfreespace();

uint16_t HAL_extmem_getnumfiles();

void HAL_extmem_getfilename(uint16_t, char[11]);

/*** Time interface ***/

/**
 * @brief Delay for aa interval
 * @param ms milliseconds [in]
 */
void HAL_time_sleep_ms(uint32_t);

/**
 * @brief get current time from system start
 * @return time in milliseconds
 */
uint32_t HAL_time_gettime_ms();

__END_DECLS

#endif /* HAL_H */
