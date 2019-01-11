#include <stdint.h>
#include <string.h>

#include "tools.h"

#define FLOAT_DIGITS10 7

void
ftoa(float f, char *buf)
{
	if (f != f) {
		strcpy(buf, "NAN");
		return;
	} else if (f + f == f) {
		if (1.f / f < 0.f)
			strcpy(buf, "-0.0");
		else if (f == 0.0f)
			strcpy(buf, "0.0");
		else if (f > 0.0f)
			strcpy(buf, "INF");
		else
			strcpy(buf, "-INF");
		return;
	}

	const unsigned char mns = (f < 0.f);
	if (mns) {
		f = -f;
		*(buf++) = '-';
	}

	int32_t n = 0;

	if (f < 1e6f)
		do {
			f *= 10.f;
			--n;
		} while (f < (1e6f - 0.5f));
	else if (f >= 1e7f)
		do {
			f /= 10.f;
			++n;
		} while (f >= 1e7f);
	n += FLOAT_DIGITS10 - 1;
	uint32_t fi = f + 0.5f;

	uint8_t i;
	for (i = FLOAT_DIGITS10; (i--) > 1;) {
		buf[i + 1] = fi % 10 + '0';
		fi /= 10;
	}
	buf[1] = '.';
	buf[0] = fi % 10 + '0';
	buf += FLOAT_DIGITS10 + 1;
	if (n != 0) {
		*(buf++) = 'e';
		if (n < 0) {
			*(buf++) = '-';
			n = -n;
		}
		if (n >= 10)
			*(buf++) = n / 10 + '0';
		*(buf++) = n % 10 + '0';
	}

	*buf = '\0';
}

union U16 {
	uint16_t num;
	char bytes[sizeof(uint16_t)];
};

union U32 {
	uint32_t num;
	char bytes[sizeof(uint32_t)];
};

void
writeU16(uint16_t num, uint8_t *buf)
{
	union U16 s;
	
	s.num = num;
	
	*(buf++) = s.bytes[1];
	*buf = s.bytes[0];
}

void
writeU32(uint32_t num, uint8_t *buf)
{
	union U32 s;
	
	s.num = num;
	
	*(buf++) = s.bytes[3];
	*(buf++) = s.bytes[2];
	*(buf++) = s.bytes[1];
	*buf = s.bytes[0];
}
