/******************************************************************************
 * Разработчик: Закрытое акционерное общество "Научно исследовательский
 * институт "Центрпрограммсистем", г. Тверь (ЗАО НИИ ЦПС)
 *
 * Интеллектуальная собственность ЗАО НИИ ЦПС
 *****************************************************************************/

/**
 * @file	math.cpp
 * @author	starling13
 * @brief	________________
 * @date	6 декабря 2016 г., 17:06
 */

#include "math.hpp"
#include <stdlib.h>
#include <float.h>

#include <stdio.h>

uint8_t digits10(unsigned num)
{
	uint8_t i = 0;
	
	do {
		num /= 10;
		++i;
	} while (num != 0);
	
	return i;
}

void itoa(int num, char *buffer)
{
	uint8_t pos;
	unsigned a;
	bool neg;
	
	if (num < 0) {
		a = -num;
		neg = true;
	} else {
		a = num;
		neg = false;
	}
	
	pos = digits10(a) + 1; // 1 byte for '+' or ' '
	
	buffer[pos] = '\0';
	pos--;
	do {
		buffer[pos] = (a % 10) + '0';
		pos--;
		a /= 10;
	} while (a != 0);
	buffer[pos] = neg ? '-' : ' ';
}
/*
void ftoa(float Value, char* Buffer)
{
	union
	{
		float f;

		struct
		{
			unsigned int mantissa_lo : 16;
			unsigned int mantissa_hi : 7;
			unsigned int exponent : 8;
			unsigned int sign : 1;
		};
	} helper;

	unsigned long mantissa;
	signed char exponent;
	unsigned int int_part;
	char frac_part[5];
	int i, count = 0;

	helper.f = Value;
	//mantissa is LS 23 bits
	mantissa = helper.mantissa_lo;
	mantissa += ((unsigned long) helper.mantissa_hi << 16);
	//add the 24th bit to get 1.mmmm^eeee format
	mantissa += 0x00800000;
	//exponent is biased by 127
	exponent = (signed char) helper.exponent - 127;

	//too big to shove into 8 chars
	if (exponent > 18) {
		Buffer[0] = 'I';
		Buffer[1] = 'n';
		Buffer[2] = 'f';
		Buffer[3] = '\0';
		return;
	}

	//too small to resolve (resolution of 1/16)
	if (exponent < -4) {
		Buffer[0] = '0';
		Buffer[1] = '\0';
		return;
	}

	count = 0;

	//add negative sign (if applicable)
	if (helper.sign) {
		Buffer[0] = '-';
		count++;
	}

	//get the integer part
	int_part = mantissa >> (23 - exponent);
	//convert to string
	itoa(int_part, Buffer + count);

	//find the end of the integer
	for (i = 0; i < 8; i++)
		if (Buffer[i] == '\0') {
			count = i;
			break;
		}

	//not enough room in the buffer for the frac part    
	if (count > 5)
		return;

	//add the decimal point    
	Buffer[count++] = '.';

	//use switch to resolve the fractional part
	switch (0xF & (mantissa >> (19 - exponent))) {
	case 0:
		frac_part[0] = '0';
		frac_part[1] = '0';
		frac_part[2] = '0';
		frac_part[3] = '0';
		break;
	case 1:
		frac_part[0] = '0';
		frac_part[1] = '6';
		frac_part[2] = '2';
		frac_part[3] = '5';
		break;
	case 2:
		frac_part[0] = '1';
		frac_part[1] = '2';
		frac_part[2] = '5';
		frac_part[3] = '0';
		break;
	case 3:
		frac_part[0] = '1';
		frac_part[1] = '8';
		frac_part[2] = '7';
		frac_part[3] = '5';
		break;
	case 4:
		frac_part[0] = '2';
		frac_part[1] = '5';
		frac_part[2] = '0';
		frac_part[3] = '0';
		break;
	case 5:
		frac_part[0] = '3';
		frac_part[1] = '1';
		frac_part[2] = '2';
		frac_part[3] = '5';
		break;
	case 6:
		frac_part[0] = '3';
		frac_part[1] = '7';
		frac_part[2] = '5';
		frac_part[3] = '0';
		break;
	case 7:
		frac_part[0] = '4';
		frac_part[1] = '3';
		frac_part[2] = '7';
		frac_part[3] = '5';
		break;
	case 8:
		frac_part[0] = '5';
		frac_part[1] = '0';
		frac_part[2] = '0';
		frac_part[3] = '0';
		break;
	case 9:
		frac_part[0] = '5';
		frac_part[1] = '6';
		frac_part[2] = '2';
		frac_part[3] = '5';
		break;
	case 10:
		frac_part[0] = '6';
		frac_part[1] = '2';
		frac_part[2] = '5';
		frac_part[3] = '0';
		break;
	case 11:
		frac_part[0] = '6';
		frac_part[1] = '8';
		frac_part[2] = '7';
		frac_part[3] = '5';
		break;
	case 12:
		frac_part[0] = '7';
		frac_part[1] = '5';
		frac_part[2] = '0';
		frac_part[3] = '0';
		break;
	case 13:
		frac_part[0] = '8';
		frac_part[1] = '1';
		frac_part[2] = '2';
		frac_part[3] = '5';
		break;
	case 14:
		frac_part[0] = '8';
		frac_part[1] = '7';
		frac_part[2] = '5';
		frac_part[3] = '0';
		break;
	case 15	:
		frac_part[0] = '9';
		frac_part[1] = '3';
		frac_part[2] = '7';
		frac_part[3] = '5';
		break;
	case 16:
		frac_part[0] = '0';
		frac_part[1] = '0';
		frac_part[2] = '0';
		frac_part[3] = '0';
		break;
	}

	//add the fractional part to the output string
	for (i = 0; i < 4; i++)
		if (count < 7)
			Buffer[count++] = frac_part[i];

	//make sure the output is terminated
	Buffer[count] = '\0';
}
 */

union Float_t
{
    Float_t(float num = 0.0f) : f(num) {}
    // Portable extraction of components.
    bool Negative() const { return (i >> 31) != 0; }
    int32_t RawMantissa() const { return i & ((1 << 23) - 1); }
    int32_t RawExponent() const { return (i >> 23) & 0xFF; }
 
    int32_t i;
    float f;

    struct
    {   // Bitfields for exploration. Do not use in production code.
        uint32_t mantissa : 23;
        uint32_t exponent : 8;
        uint32_t sign : 1;
    } parts;

};

void ftoa(float Value, char* Buffer)
{
	//sprintf(Buffer, "%f", Value);
}
