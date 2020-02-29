/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019,2020 Terminal-BASIC team
 *     <https://bitbucket.org/%7Bf50d6fee-8627-4ce4-848d-829168eedae5%7D/>
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

/**
 * @address
 */
typedef uint32_t HAL_nvram_address_t;

/**
 * @brief Get NVRAM size
 * @return 
 */
HAL_nvram_address_t HAL_nvram_getsize();

/**
 * @brief write byte to NVRAM
 * @param address [in]
 * @param dataByte [in]
 */
void HAL_nvram_write(HAL_nvram_address_t, uint8_t);

/**
 * @brief read byte from NVRAM
 * @param address
 * @return byte
 */
uint8_t HAL_nvram_read(HAL_nvram_address_t);

/**
 * 
 * @param address
 * @param buf
 * @param length
 */
void HAL_nvram_read_buf(HAL_nvram_address_t, void*, uint32_t);

/**
 * 
 * @param address
 * @param buf
 * @param length
 */
void HAL_nvram_write_buf(HAL_nvram_address_t, const void*, uint32_t);

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

/**
 * File handle
 */
typedef uint8_t HAL_extmem_file_t;

/**
 * Position in file/file size
 */
typedef uint32_t HAL_extmem_fileposition_t;

/**
 * @brief Open file in external memory
 * @param path
 * @return file handle > 0 or 0 on error
 */
HAL_extmem_file_t HAL_extmem_openfile(const char*);

/**
 * @brief close opened file
 * @param handle
 */
void HAL_extmem_closefile(HAL_extmem_file_t);

/**
 * @brief Read byte from file
 * @param handle
 * @return byte
 */
uint8_t HAL_extmem_readfromfile(HAL_extmem_file_t);

/**
 * @brief Write byte to file
 * @param handle
 * @param byte
 */
void HAL_extmem_writetofile(HAL_extmem_file_t, uint8_t);

/**
 * @brief 
 * @param handle
 * @return position
 */
HAL_extmem_fileposition_t HAL_extmem_getfileposition(HAL_extmem_file_t);

/**
 * @brief Set position in file
 * @param handle
 * @param position
 */
void HAL_extmem_setfileposition(HAL_extmem_file_t, HAL_extmem_fileposition_t);

/**
 * @brief handle
 * @param handle
 * @return file size
 */
HAL_extmem_fileposition_t HAL_extmem_getfilesize(HAL_extmem_file_t);

/**
 * @brief
 * @return 
 */
uint32_t HAL_extmem_getfreespace();

/**
 * @brief Get number of 
 * @return number of files
 */
uint16_t HAL_extmem_getnumfiles();

/**
 * @brief Get file name in a directory
 * @param num [in] entry number 
 * @param name [out]
 */
void HAL_extmem_getfilename(uint16_t, char[13]);

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

