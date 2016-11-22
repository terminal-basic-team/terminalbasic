/******************************************************************************
 * Разработчик: Закрытое акционерное общество "Научно исследовательский
 * институт "Центрпрограммсистем", г. Тверь (ЗАО НИИ ЦПС)
 *
 * Интеллектуальная собственность ЗАО НИИ ЦПС
 *****************************************************************************/

/**
 * @file	_Print.h
 * @author	starling13
 * @brief	________________
 * @date	1 ноября 2016 г., 11:44
 */

#ifndef _PRINT_H
#define _PRINT_H

#include <cstring>

#include <sstream>

#include "posix_io_tty.hpp"
#include "Printable.h"

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Print
{
public:
	
	size_t print(unsigned char, int = DEC);
	size_t print(char);
	size_t print(const char[]);
	size_t print(const Printable&);
	size_t print(int val, int base = DEC);
	size_t print(long n, int base);
	size_t print(double, int = 2);
	size_t print(unsigned int val, int base = DEC);
	size_t print(long unsigned int val, int base = DEC);
	uint16_t println(void);
	
	size_t println(const Printable&);
	size_t println(int, int = DEC);
	size_t println(unsigned int, int = DEC);
	size_t println(const char[]);
	virtual size_t write(uint8_t) = 0;
	
	size_t write(const uint8_t*, size_t);
	size_t write(const char *str) {
		if (str == NULL) return 0;
		return write((const uint8_t *)str, strlen(str));
	}
protected:
	size_t printNumber(unsigned long n, uint8_t base);
	size_t printFloat(double, uint8_t);
};

#endif
