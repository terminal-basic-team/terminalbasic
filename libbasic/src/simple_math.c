#include "simple_math.h"
#include "math.h"

#define DEBUG 1
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#define _LOG(T, name) T name(T x) \
{ \
	PRINTF("\n%s %f", __PRETTY_FUNCTION__, x); \
\
	T m = x, y = m, yn = y, sx = x; \
	unsigned n = 2, i=65535; \
	while (1) { \
		sx = sx * (-1) * x; \
		m = sx / n++; \
		yn += m; \
		if (y == yn || (i-- == 0)) { \
			PRINTF(" : %f\n", y); \
			return y; \
		} \
		y = yn; \
	} \
}

_LOG(float, _logf)
_LOG(double, _logd)
#define _CALL_LOG(a) _log ## a

#define _S_LOG(T, name, prefix) T name(T v) \
{ \
	PRINTF("\n%s %f", __PRETTY_FUNCTION__, v); \
\
	if (v == (T)1) { \
		PRINTF(" : %f\n", (T)0); \
		return (T)0; \
	} else if (v <= (T)0) { \
		PRINTF(" : %f\n", NAN); \
		return NAN; \
	} else { \
		float sum = (T)0; \
		if (v >= 2.f) { \
			const float sh = _CALL_LOG(prefix)((T)0.5); \
			v /= (T)1.5; \
			sum += sh; \
			sum += s_logf(v); \
		} else \
			sum += _logf(v - (T)1); \
		PRINTF(" : %f\n", sum); \
		return sum; \
	} \
}
    
_S_LOG(float, s_logf, f)
_S_LOG(double, s_logd, d)
