# 1 "./src/ucbasic_main.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 1
# 23 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h"
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 1 3
# 48 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stddef.h" 1 3 4
# 212 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stddef.h" 3 4
typedef unsigned int size_t;
# 49 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 2 3







extern "C" {
# 70 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
typedef struct {
 int quot;
 int rem;
} div_t;


typedef struct {
 long quot;
 long rem;
} ldiv_t;


typedef int (*__compar_fn_t)(const void *, const void *);
# 116 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern void abort(void) __attribute__((__noreturn__));




extern int abs(int __i) __attribute__((__const__));
# 130 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern long labs(long __i) __attribute__((__const__));
# 153 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb,
       size_t __size, int (*__compar)(const void *, const void *));







extern div_t div(int __num, int __denom) __asm__("__divmodhi4") __attribute__((__const__));





extern ldiv_t ldiv(long __num, long __denom) __asm__("__divmodsi4") __attribute__((__const__));
# 185 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern void qsort(void *__base, size_t __nmemb, size_t __size,
    __compar_fn_t __compar);
# 218 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern long strtol(const char *__nptr, char **__endptr, int __base);
# 252 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern unsigned long strtoul(const char *__nptr, char **__endptr, int __base);
# 264 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern long atol(const char *__s) __attribute__((__pure__));
# 276 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern int atoi(const char *__s) __attribute__((__pure__));
# 288 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern void exit(int __status) __attribute__((__noreturn__));
# 300 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern void *malloc(size_t __size) __attribute__((__malloc__));






extern void free(void *__ptr);




extern size_t __malloc_margin;




extern char *__malloc_heap_start;




extern char *__malloc_heap_end;






extern void *calloc(size_t __nele, size_t __size) __attribute__((__malloc__));
# 348 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern void *realloc(void *__ptr, size_t __size) __attribute__((__malloc__));

extern double strtod(const char *__nptr, char **__endptr);
# 361 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern double atof(const char *__nptr);
# 383 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern int rand(void);



extern void srand(unsigned int __seed);






extern int rand_r(unsigned long *__ctx);
# 428 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern __inline__ __attribute__((__gnu_inline__))
char *itoa (int __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__itoa (int, char *, int);
 return __itoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__itoa_ncheck (int, char *, unsigned char);
 return __itoa_ncheck (__val, __s, __radix);
    }
}
# 473 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern __inline__ __attribute__((__gnu_inline__))
char *ltoa (long __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__ltoa (long, char *, int);
 return __ltoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__ltoa_ncheck (long, char *, unsigned char);
 return __ltoa_ncheck (__val, __s, __radix);
    }
}
# 516 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern __inline__ __attribute__((__gnu_inline__))
char *utoa (unsigned int __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__utoa (unsigned int, char *, int);
 return __utoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__utoa_ncheck (unsigned int, char *, unsigned char);
 return __utoa_ncheck (__val, __s, __radix);
    }
}
# 558 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern __inline__ __attribute__((__gnu_inline__))
char *ultoa (unsigned long __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__ultoa (unsigned long, char *, int);
 return __ultoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__ultoa_ncheck (unsigned long, char *, unsigned char);
 return __ultoa_ncheck (__val, __s, __radix);
    }
}
# 590 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern long random(void);




extern void srandom(unsigned long __seed);







extern long random_r(unsigned long *__ctx);
# 649 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern char *dtostre(double __val, char *__s, unsigned char __prec,
       unsigned char __flags);
# 666 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern char *dtostrf(double __val, signed char __width,
                     unsigned char __prec, char *__s);
# 685 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdlib.h" 3
extern int atexit(void (*)(void));
extern int system (const char *);
extern char *getenv (const char *);



}
# 24 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stdbool.h" 1 3 4
# 25 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 1 3
# 46 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stddef.h" 1 3 4
# 47 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 2 3
# 58 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern "C" {
# 125 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern int ffs(int __val) __attribute__((__const__));





extern int ffsl(long __val) __attribute__((__const__));





__extension__ extern int ffsll(long long __val) __attribute__((__const__));
# 150 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern void *memccpy(void *, const void *, int, size_t);
# 162 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern void *memchr(const void *, int, size_t) __attribute__((__pure__));
# 180 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern int memcmp(const void *, const void *, size_t) __attribute__((__pure__));
# 191 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern void *memcpy(void *, const void *, size_t);
# 203 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern void *memmem(const void *, size_t, const void *, size_t) __attribute__((__pure__));
# 213 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern void *memmove(void *, const void *, size_t);
# 225 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern void *memrchr(const void *, int, size_t) __attribute__((__pure__));
# 235 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern void *memset(void *, int, size_t);
# 248 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strcat(char *, const char *);
# 262 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strchr(const char *, int) __attribute__((__pure__));
# 274 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strchrnul(const char *, int) __attribute__((__pure__));
# 287 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern int strcmp(const char *, const char *) __attribute__((__pure__));
# 305 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strcpy(char *, const char *);
# 320 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern int strcasecmp(const char *, const char *) __attribute__((__pure__));
# 333 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strcasestr(const char *, const char *) __attribute__((__pure__));
# 344 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern size_t strcspn(const char *__s, const char *__reject) __attribute__((__pure__));
# 364 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strdup(const char *s1);
# 377 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern size_t strlcat(char *, const char *, size_t);
# 388 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern size_t strlcpy(char *, const char *, size_t);
# 399 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern size_t strlen(const char *) __attribute__((__pure__));
# 411 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strlwr(char *);
# 422 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strncat(char *, const char *, size_t);
# 434 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern int strncmp(const char *, const char *, size_t) __attribute__((__pure__));
# 449 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strncpy(char *, const char *, size_t);
# 464 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern int strncasecmp(const char *, const char *, size_t) __attribute__((__pure__));
# 478 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern size_t strnlen(const char *, size_t) __attribute__((__pure__));
# 491 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strpbrk(const char *__s, const char *__accept) __attribute__((__pure__));
# 505 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strrchr(const char *, int) __attribute__((__pure__));
# 515 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strrev(char *);
# 533 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strsep(char **, const char *);
# 544 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern size_t strspn(const char *__s, const char *__accept) __attribute__((__pure__));
# 557 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strstr(const char *, const char *) __attribute__((__pure__));
# 576 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strtok(char *, const char *);
# 593 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strtok_r(char *, const char *, char **);
# 606 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/string.h" 3
extern char *strupr(char *);



extern int strcoll(const char *s1, const char *s2);
extern char *strerror(int errnum);
extern size_t strxfrm(char *dest, const char *src, size_t n);



}
# 26 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 1 3
# 121 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern "C" {





extern double cos(double __x) __attribute__((__const__));





extern double sin(double __x) __attribute__((__const__));





extern double tan(double __x) __attribute__((__const__));






extern double fabs(double __x) __attribute__((__const__));






extern double fmod(double __x, double __y) __attribute__((__const__));
# 168 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern double modf(double __x, double *__iptr);


extern float modff (float __x, float *__iptr);




extern double sqrt(double __x) __attribute__((__const__));


extern float sqrtf (float) __attribute__((__const__));




extern double cbrt(double __x) __attribute__((__const__));
# 195 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern double hypot (double __x, double __y) __attribute__((__const__));







extern double square(double __x) __attribute__((__const__));






extern double floor(double __x) __attribute__((__const__));






extern double ceil(double __x) __attribute__((__const__));
# 235 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern double frexp(double __x, int *__pexp);







extern double ldexp(double __x, int __exp) __attribute__((__const__));





extern double exp(double __x) __attribute__((__const__));





extern double cosh(double __x) __attribute__((__const__));





extern double sinh(double __x) __attribute__((__const__));





extern double tanh(double __x) __attribute__((__const__));







extern double acos(double __x) __attribute__((__const__));







extern double asin(double __x) __attribute__((__const__));






extern double atan(double __x) __attribute__((__const__));
# 299 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern double atan2(double __y, double __x) __attribute__((__const__));





extern double log(double __x) __attribute__((__const__));





extern double log10(double __x) __attribute__((__const__));





extern double pow(double __x, double __y) __attribute__((__const__));






extern int isnan(double __x) __attribute__((__const__));
# 334 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern int isinf(double __x) __attribute__((__const__));






__attribute__((__const__)) static inline int isfinite (double __x)
{
    unsigned char __exp;
    __asm__ (
 "mov	%0, %C1		\n\t"
 "lsl	%0		\n\t"
 "mov	%0, %D1		\n\t"
 "rol	%0		"
 : "=r" (__exp)
 : "r" (__x) );
    return __exp != 0xff;
}






__attribute__((__const__)) static inline double copysign (double __x, double __y)
{
    __asm__ (
 "bst	%D2, 7	\n\t"
 "bld	%D0, 7	"
 : "=r" (__x)
 : "0" (__x), "r" (__y) );
    return __x;
}
# 377 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern int signbit (double __x) __attribute__((__const__));






extern double fdim (double __x, double __y) __attribute__((__const__));
# 393 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern double fma (double __x, double __y, double __z) __attribute__((__const__));







extern double fmax (double __x, double __y) __attribute__((__const__));







extern double fmin (double __x, double __y) __attribute__((__const__));






extern double trunc (double __x) __attribute__((__const__));
# 427 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern double round (double __x) __attribute__((__const__));
# 440 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern long lround (double __x) __attribute__((__const__));
# 454 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/math.h" 3
extern long lrint (double __x) __attribute__((__const__));



}
# 27 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2

# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 1 3
# 88 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/inttypes.h" 1 3
# 37 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/inttypes.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stdint.h" 1 3 4
# 9 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stdint.h" 3 4
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdint.h" 1 3 4
# 125 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdint.h" 3 4
typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));

typedef signed int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
# 146 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdint.h" 3 4
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 163 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdint.h" 3 4
typedef int8_t int_least8_t;




typedef uint8_t uint_least8_t;




typedef int16_t int_least16_t;




typedef uint16_t uint_least16_t;




typedef int32_t int_least32_t;




typedef uint32_t uint_least32_t;







typedef int64_t int_least64_t;






typedef uint64_t uint_least64_t;
# 217 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdint.h" 3 4
typedef int8_t int_fast8_t;




typedef uint8_t uint_fast8_t;




typedef int16_t int_fast16_t;




typedef uint16_t uint_fast16_t;




typedef int32_t int_fast32_t;




typedef uint32_t uint_fast32_t;







typedef int64_t int_fast64_t;






typedef uint64_t uint_fast64_t;
# 277 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdint.h" 3 4
typedef int64_t intmax_t;




typedef uint64_t uintmax_t;
# 10 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stdint.h" 2 3 4
# 38 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/inttypes.h" 2 3
# 77 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/inttypes.h" 3
typedef int32_t int_farptr_t;



typedef uint32_t uint_farptr_t;
# 89 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 2 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stddef.h" 1 3 4
# 90 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 2 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 1 3
# 99 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/sfr_defs.h" 1 3
# 100 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 2 3
# 272 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/iom328p.h" 1 3
# 273 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 2 3
# 627 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/portpins.h" 1 3
# 628 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 2 3

# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/common.h" 1 3
# 630 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 2 3

# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/version.h" 1 3
# 632 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 2 3






# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/fuse.h" 1 3
# 239 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/fuse.h" 3
typedef struct
{
    unsigned char low;
    unsigned char high;
    unsigned char extended;
} __fuse_t;
# 639 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 2 3


# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/lock.h" 1 3
# 642 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/io.h" 2 3
# 91 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 2 3
# 116 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern "C" {
# 1158 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern const void * memchr_P(const void *, int __val, size_t __len) __attribute__((__const__));
# 1172 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int memcmp_P(const void *, const void *, size_t) __attribute__((__pure__));






extern void *memccpy_P(void *, const void *, int __val, size_t);
# 1188 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern void *memcpy_P(void *, const void *, size_t);






extern void *memmem_P(const void *, size_t, const void *, size_t) __attribute__((__pure__));
# 1207 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern const void * memrchr_P(const void *, int __val, size_t __len) __attribute__((__const__));
# 1217 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strcat_P(char *, const char *);
# 1233 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern const char * strchr_P(const char *, int __val) __attribute__((__const__));
# 1245 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern const char * strchrnul_P(const char *, int __val) __attribute__((__const__));
# 1258 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int strcmp_P(const char *, const char *) __attribute__((__pure__));
# 1268 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strcpy_P(char *, const char *);
# 1285 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int strcasecmp_P(const char *, const char *) __attribute__((__pure__));






extern char *strcasestr_P(const char *, const char *) __attribute__((__pure__));
# 1305 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t strcspn_P(const char *__s, const char * __reject) __attribute__((__pure__));
# 1321 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t strlcat_P (char *, const char *, size_t );
# 1334 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t strlcpy_P (char *, const char *, size_t );
# 1346 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t strnlen_P(const char *, size_t) __attribute__((__const__));
# 1357 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int strncmp_P(const char *, const char *, size_t) __attribute__((__pure__));
# 1376 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int strncasecmp_P(const char *, const char *, size_t) __attribute__((__pure__));
# 1387 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strncat_P(char *, const char *, size_t);
# 1401 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strncpy_P(char *, const char *, size_t);
# 1416 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strpbrk_P(const char *__s, const char * __accept) __attribute__((__pure__));
# 1427 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern const char * strrchr_P(const char *, int __val) __attribute__((__const__));
# 1447 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strsep_P(char **__sp, const char * __delim);
# 1460 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t strspn_P(const char *__s, const char * __accept) __attribute__((__pure__));
# 1474 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strstr_P(const char *, const char *) __attribute__((__pure__));
# 1496 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strtok_P(char *__s, const char * __delim);
# 1516 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strtok_rP(char *__s, const char * __delim, char **__last);
# 1529 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t strlen_PF(uint_farptr_t src) __attribute__((__const__));
# 1545 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t strnlen_PF(uint_farptr_t src, size_t len) __attribute__((__const__));
# 1560 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern void *memcpy_PF(void *dest, uint_farptr_t src, size_t len);
# 1575 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strcpy_PF(char *dest, uint_farptr_t src);
# 1595 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strncpy_PF(char *dest, uint_farptr_t src, size_t len);
# 1611 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strcat_PF(char *dest, uint_farptr_t src);
# 1632 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t strlcat_PF(char *dst, uint_farptr_t src, size_t siz);
# 1649 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strncat_PF(char *dest, uint_farptr_t src, size_t len);
# 1665 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int strcmp_PF(const char *s1, uint_farptr_t s2) __attribute__((__pure__));
# 1682 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int strncmp_PF(const char *s1, uint_farptr_t s2, size_t n) __attribute__((__pure__));
# 1698 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int strcasecmp_PF(const char *s1, uint_farptr_t s2) __attribute__((__pure__));
# 1716 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int strncasecmp_PF(const char *s1, uint_farptr_t s2, size_t n) __attribute__((__pure__));
# 1732 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern char *strstr_PF(const char *s1, uint_farptr_t s2);
# 1744 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t strlcpy_PF(char *dst, uint_farptr_t src, size_t siz);
# 1760 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern int memcmp_PF(const void *, uint_farptr_t, size_t) __attribute__((__pure__));
# 1779 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern size_t __strlen_P(const char *) __attribute__((__const__));
__attribute__((__always_inline__)) static __inline__ size_t strlen_P(const char * s);
static __inline__ size_t strlen_P(const char *s) {
  return __builtin_constant_p(__builtin_strlen(s))
     ? __builtin_strlen(s) : __strlen_P(s);
}



}
# 29 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2

# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/interrupt.h" 1 3
# 31 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2

# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/binary.h" 1
# 33 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2


extern "C"{


void yield(void);
# 121 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h"
typedef unsigned int word;



typedef bool boolean;
typedef uint8_t byte;

void init(void);
void initVariant(void);

int atexit(void (*func)()) __attribute__((weak));

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);

unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long);
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

void setup(void);
void loop(void);
# 164 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h"
extern const uint16_t __attribute__((__progmem__)) port_to_mode_PGM[];
extern const uint16_t __attribute__((__progmem__)) port_to_input_PGM[];
extern const uint16_t __attribute__((__progmem__)) port_to_output_PGM[];

extern const uint8_t __attribute__((__progmem__)) digital_pin_to_port_PGM[];

extern const uint8_t __attribute__((__progmem__)) digital_pin_to_bit_mask_PGM[];
extern const uint8_t __attribute__((__progmem__)) digital_pin_to_timer_PGM[];
# 227 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h"
}



# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WCharacter.h" 1
# 23 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WCharacter.h"
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/ctype.h" 1 3
# 48 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/ctype.h" 3
extern "C" {
# 74 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/ctype.h" 3
extern int isalnum(int __c) __attribute__((__const__));






extern int isalpha(int __c) __attribute__((__const__));






extern int isascii(int __c) __attribute__((__const__));





extern int isblank(int __c) __attribute__((__const__));





extern int iscntrl(int __c) __attribute__((__const__));





extern int isdigit(int __c) __attribute__((__const__));





extern int isgraph(int __c) __attribute__((__const__));





extern int islower(int __c) __attribute__((__const__));





extern int isprint(int __c) __attribute__((__const__));






extern int ispunct(int __c) __attribute__((__const__));







extern int isspace(int __c) __attribute__((__const__));





extern int isupper(int __c) __attribute__((__const__));






extern int isxdigit(int __c) __attribute__((__const__));
# 173 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/ctype.h" 3
extern int toascii(int __c) __attribute__((__const__));





extern int tolower(int __c) __attribute__((__const__));





extern int toupper(int __c) __attribute__((__const__));




}
# 24 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WCharacter.h" 2


inline boolean isAlphaNumeric(int c) __attribute__((always_inline));
inline boolean isAlpha(int c) __attribute__((always_inline));
inline boolean isAscii(int c) __attribute__((always_inline));
inline boolean isWhitespace(int c) __attribute__((always_inline));
inline boolean isControl(int c) __attribute__((always_inline));
inline boolean isDigit(int c) __attribute__((always_inline));
inline boolean isGraph(int c) __attribute__((always_inline));
inline boolean isLowerCase(int c) __attribute__((always_inline));
inline boolean isPrintable(int c) __attribute__((always_inline));
inline boolean isPunct(int c) __attribute__((always_inline));
inline boolean isSpace(int c) __attribute__((always_inline));
inline boolean isUpperCase(int c) __attribute__((always_inline));
inline boolean isHexadecimalDigit(int c) __attribute__((always_inline));
inline int toAscii(int c) __attribute__((always_inline));
inline int toLowerCase(int c) __attribute__((always_inline));
inline int toUpperCase(int c)__attribute__((always_inline));




inline boolean isAlphaNumeric(int c)
{
  return ( isalnum(c) == 0 ? false : true);
}




inline boolean isAlpha(int c)
{
  return ( isalpha(c) == 0 ? false : true);
}




inline boolean isAscii(int c)
{
  return ( isascii (c) == 0 ? false : true);
}



inline boolean isWhitespace(int c)
{
  return ( isblank (c) == 0 ? false : true);
}



inline boolean isControl(int c)
{
  return ( iscntrl (c) == 0 ? false : true);
}



inline boolean isDigit(int c)
{
  return ( isdigit (c) == 0 ? false : true);
}



inline boolean isGraph(int c)
{
  return ( isgraph (c) == 0 ? false : true);
}



inline boolean isLowerCase(int c)
{
  return (islower (c) == 0 ? false : true);
}



inline boolean isPrintable(int c)
{
  return ( isprint (c) == 0 ? false : true);
}




inline boolean isPunct(int c)
{
  return ( ispunct (c) == 0 ? false : true);
}





inline boolean isSpace(int c)
{
  return ( isspace (c) == 0 ? false : true);
}



inline boolean isUpperCase(int c)
{
  return ( isupper (c) == 0 ? false : true);
}




inline boolean isHexadecimalDigit(int c)
{
  return ( isxdigit (c) == 0 ? false : true);
}




inline int toAscii(int c)
{
  return toascii (c);
}
# 156 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WCharacter.h"
inline int toLowerCase(int c)
{
  return tolower (c);
}



inline int toUpperCase(int c)
{
  return toupper (c);
}
# 232 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WString.h" 1
# 37 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/WString.h"
class __FlashStringHelper;




class StringSumHelper;


class String
{



 typedef void (String::*StringIfHelperType)() const;
 void StringIfHelper() const {}

public:





 String(const char *cstr = "");
 String(const String &str);
 String(const __FlashStringHelper *str);

 String(String &&rval);
 String(StringSumHelper &&rval);

 explicit String(char c);
 explicit String(unsigned char, unsigned char base=10);
 explicit String(int, unsigned char base=10);
 explicit String(unsigned int, unsigned char base=10);
 explicit String(long, unsigned char base=10);
 explicit String(unsigned long, unsigned char base=10);
 explicit String(float, unsigned char decimalPlaces=2);
 explicit String(double, unsigned char decimalPlaces=2);
 ~String(void);





 unsigned char reserve(unsigned int size);
 inline unsigned int length(void) const {return len;}




 String & operator = (const String &rhs);
 String & operator = (const char *cstr);
 String & operator = (const __FlashStringHelper *str);

 String & operator = (String &&rval);
 String & operator = (StringSumHelper &&rval);







 unsigned char concat(const String &str);
 unsigned char concat(const char *cstr);
 unsigned char concat(char c);
 unsigned char concat(unsigned char c);
 unsigned char concat(int num);
 unsigned char concat(unsigned int num);
 unsigned char concat(long num);
 unsigned char concat(unsigned long num);
 unsigned char concat(float num);
 unsigned char concat(double num);
 unsigned char concat(const __FlashStringHelper * str);



 String & operator += (const String &rhs) {concat(rhs); return (*this);}
 String & operator += (const char *cstr) {concat(cstr); return (*this);}
 String & operator += (char c) {concat(c); return (*this);}
 String & operator += (unsigned char num) {concat(num); return (*this);}
 String & operator += (int num) {concat(num); return (*this);}
 String & operator += (unsigned int num) {concat(num); return (*this);}
 String & operator += (long num) {concat(num); return (*this);}
 String & operator += (unsigned long num) {concat(num); return (*this);}
 String & operator += (float num) {concat(num); return (*this);}
 String & operator += (double num) {concat(num); return (*this);}
 String & operator += (const __FlashStringHelper *str){concat(str); return (*this);}

 friend StringSumHelper & operator + (const StringSumHelper &lhs, const String &rhs);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, const char *cstr);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, char c);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, unsigned char num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, int num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, unsigned int num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, long num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, unsigned long num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, float num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, double num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, const __FlashStringHelper *rhs);


 operator StringIfHelperType() const { return buffer ? &String::StringIfHelper : 0; }
 int compareTo(const String &s) const;
 unsigned char equals(const String &s) const;
 unsigned char equals(const char *cstr) const;
 unsigned char operator == (const String &rhs) const {return equals(rhs);}
 unsigned char operator == (const char *cstr) const {return equals(cstr);}
 unsigned char operator != (const String &rhs) const {return !equals(rhs);}
 unsigned char operator != (const char *cstr) const {return !equals(cstr);}
 unsigned char operator < (const String &rhs) const;
 unsigned char operator > (const String &rhs) const;
 unsigned char operator <= (const String &rhs) const;
 unsigned char operator >= (const String &rhs) const;
 unsigned char equalsIgnoreCase(const String &s) const;
 unsigned char startsWith( const String &prefix) const;
 unsigned char startsWith(const String &prefix, unsigned int offset) const;
 unsigned char endsWith(const String &suffix) const;


 char charAt(unsigned int index) const;
 void setCharAt(unsigned int index, char c);
 char operator [] (unsigned int index) const;
 char& operator [] (unsigned int index);
 void getBytes(unsigned char *buf, unsigned int bufsize, unsigned int index=0) const;
 void toCharArray(char *buf, unsigned int bufsize, unsigned int index=0) const
  { getBytes((unsigned char *)buf, bufsize, index); }
 const char* c_str() const { return buffer; }
 char* begin() { return buffer; }
 char* end() { return buffer + length(); }
 const char* begin() const { return c_str(); }
 const char* end() const { return c_str() + length(); }


 int indexOf( char ch ) const;
 int indexOf( char ch, unsigned int fromIndex ) const;
 int indexOf( const String &str ) const;
 int indexOf( const String &str, unsigned int fromIndex ) const;
 int lastIndexOf( char ch ) const;
 int lastIndexOf( char ch, unsigned int fromIndex ) const;
 int lastIndexOf( const String &str ) const;
 int lastIndexOf( const String &str, unsigned int fromIndex ) const;
 String substring( unsigned int beginIndex ) const { return substring(beginIndex, len); };
 String substring( unsigned int beginIndex, unsigned int endIndex ) const;


 void replace(char find, char replace);
 void replace(const String& find, const String& replace);
 void remove(unsigned int index);
 void remove(unsigned int index, unsigned int count);
 void toLowerCase(void);
 void toUpperCase(void);
 void trim(void);


 long toInt(void) const;
 float toFloat(void) const;
 double toDouble(void) const;

protected:
 char *buffer;
 unsigned int capacity;
 unsigned int len;
protected:
 void init(void);
 void invalidate(void);
 unsigned char changeBuffer(unsigned int maxStrLen);
 unsigned char concat(const char *cstr, unsigned int length);


 String & copy(const char *cstr, unsigned int length);
 String & copy(const __FlashStringHelper *pstr, unsigned int length);

 void move(String &rhs);

};

class StringSumHelper : public String
{
public:
 StringSumHelper(const String &s) : String(s) {}
 StringSumHelper(const char *p) : String(p) {}
 StringSumHelper(char c) : String(c) {}
 StringSumHelper(unsigned char num) : String(num) {}
 StringSumHelper(int num) : String(num) {}
 StringSumHelper(unsigned int num) : String(num) {}
 StringSumHelper(long num) : String(num) {}
 StringSumHelper(unsigned long num) : String(num) {}
 StringSumHelper(float num) : String(num) {}
 StringSumHelper(double num) : String(num) {}
};
# 233 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial.h" 1
# 29 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial.h"
# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Stream.h" 1
# 26 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Stream.h"
# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Print.h" 1
# 24 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Print.h"
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 1 3
# 45 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stdarg.h" 1 3 4
# 40 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 98 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 46 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 2 3




# 1 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stddef.h" 1 3 4
# 51 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 2 3
# 244 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
struct __file {
 char *buf;
 unsigned char unget;
 uint8_t flags;
# 263 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
 int size;
 int len;
 int (*put)(char, struct __file *);
 int (*get)(struct __file *);
 void *udata;
};
# 277 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
typedef struct __file FILE;
# 399 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern "C" {







extern struct __file *__iob[];
# 419 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern FILE *fdevopen(int (*__put)(char, FILE*), int (*__get)(FILE*));
# 436 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern int fclose(FILE *__stream);
# 610 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern int vfprintf(FILE *__stream, const char *__fmt, va_list __ap);





extern int vfprintf_P(FILE *__stream, const char *__fmt, va_list __ap);






extern int fputc(int __c, FILE *__stream);




extern int putc(int __c, FILE *__stream);


extern int putchar(int __c);
# 651 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern int printf(const char *__fmt, ...);





extern int printf_P(const char *__fmt, ...);







extern int vprintf(const char *__fmt, va_list __ap);





extern int sprintf(char *__s, const char *__fmt, ...);





extern int sprintf_P(char *__s, const char *__fmt, ...);
# 687 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern int snprintf(char *__s, size_t __n, const char *__fmt, ...);





extern int snprintf_P(char *__s, size_t __n, const char *__fmt, ...);





extern int vsprintf(char *__s, const char *__fmt, va_list ap);





extern int vsprintf_P(char *__s, const char *__fmt, va_list ap);
# 715 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern int vsnprintf(char *__s, size_t __n, const char *__fmt, va_list ap);





extern int vsnprintf_P(char *__s, size_t __n, const char *__fmt, va_list ap);




extern int fprintf(FILE *__stream, const char *__fmt, ...);





extern int fprintf_P(FILE *__stream, const char *__fmt, ...);






extern int fputs(const char *__str, FILE *__stream);




extern int fputs_P(const char *__str, FILE *__stream);





extern int puts(const char *__str);




extern int puts_P(const char *__str);
# 764 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern size_t fwrite(const void *__ptr, size_t __size, size_t __nmemb,
         FILE *__stream);







extern int fgetc(FILE *__stream);




extern int getc(FILE *__stream);


extern int getchar(void);
# 812 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern int ungetc(int __c, FILE *__stream);
# 824 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern char *fgets(char *__str, int __size, FILE *__stream);






extern char *gets(char *__str);
# 842 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern size_t fread(void *__ptr, size_t __size, size_t __nmemb,
        FILE *__stream);




extern void clearerr(FILE *__stream);
# 859 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern int feof(FILE *__stream);
# 870 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
extern int ferror(FILE *__stream);






extern int vfscanf(FILE *__stream, const char *__fmt, va_list __ap);




extern int vfscanf_P(FILE *__stream, const char *__fmt, va_list __ap);







extern int fscanf(FILE *__stream, const char *__fmt, ...);




extern int fscanf_P(FILE *__stream, const char *__fmt, ...);






extern int scanf(const char *__fmt, ...);




extern int scanf_P(const char *__fmt, ...);







extern int vscanf(const char *__fmt, va_list __ap);







extern int sscanf(const char *__buf, const char *__fmt, ...);




extern int sscanf_P(const char *__buf, const char *__fmt, ...);
# 940 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/stdio.h" 3
static __inline__ int fflush(FILE *stream __attribute__((unused)))
{
 return 0;
}






__extension__ typedef long long fpos_t;
extern int fgetpos(FILE *stream, fpos_t *pos);
extern FILE *fopen(const char *path, const char *mode);
extern FILE *freopen(const char *path, const char *mode, FILE *stream);
extern FILE *fdopen(int, const char *);
extern int fseek(FILE *stream, long offset, int whence);
extern int fsetpos(FILE *stream, fpos_t *pos);
extern long ftell(FILE *stream);
extern int fileno(FILE *);
extern void perror(const char *s);
extern int remove(const char *pathname);
extern int rename(const char *oldpath, const char *newpath);
extern void rewind(FILE *stream);
extern void setbuf(FILE *stream, char *buf);
extern int setvbuf(FILE *stream, char *buf, int mode, size_t size);
extern FILE *tmpfile(void);
extern char *tmpnam (char *s);



}
# 25 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Print.h" 2


# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Printable.h" 1
# 25 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Printable.h"
class Print;







class Printable
{
  public:
    virtual size_t printTo(Print& p) const = 0;
};
# 28 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Print.h" 2






class Print
{
  private:
    int write_error;
    size_t printNumber(unsigned long, uint8_t);
    size_t printFloat(double, uint8_t);
  protected:
    void setWriteError(int err = 1) { write_error = err; }
  public:
    Print() : write_error(0) {}

    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }

    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str) {
      if (str == __null) return 0;
      return write((const uint8_t *)str, strlen(str));
    }
    virtual size_t write(const uint8_t *buffer, size_t size);
    size_t write(const char *buffer, size_t size) {
      return write((const uint8_t *)buffer, size);
    }

    size_t print(const __FlashStringHelper *);
    size_t print(const String &);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = 10);
    size_t print(int, int = 10);
    size_t print(unsigned int, int = 10);
    size_t print(long, int = 10);
    size_t print(unsigned long, int = 10);
    size_t print(double, int = 2);
    size_t print(const Printable&);

    size_t println(const __FlashStringHelper *);
    size_t println(const String &s);
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = 10);
    size_t println(int, int = 10);
    size_t println(unsigned int, int = 10);
    size_t println(long, int = 10);
    size_t println(unsigned long, int = 10);
    size_t println(double, int = 2);
    size_t println(const Printable&);
    size_t println(void);
};
# 27 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Stream.h" 2
# 41 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Stream.h"
enum LookaheadMode{
    SKIP_ALL,
    SKIP_NONE,
    SKIP_WHITESPACE
};



class Stream : public Print
{
  protected:
    unsigned long _timeout;
    unsigned long _startMillis;
    int timedRead();
    int timedPeek();
    int peekNextDigit(LookaheadMode lookahead, bool detectDecimal);

  public:
    virtual int available() = 0;
    virtual int read() = 0;
    virtual int peek() = 0;
    virtual void flush() = 0;

    Stream() {_timeout=1000;}



  void setTimeout(unsigned long timeout);
  unsigned long getTimeout(void) { return _timeout; }

  bool find(char *target);
  bool find(uint8_t *target) { return find ((char *)target); }


  bool find(char *target, size_t length);
  bool find(uint8_t *target, size_t length) { return find ((char *)target, length); }


  bool find(char target) { return find (&target, 1); }

  bool findUntil(char *target, char *terminator);
  bool findUntil(uint8_t *target, char *terminator) { return findUntil((char *)target, terminator); }

  bool findUntil(char *target, size_t targetLen, char *terminate, size_t termLen);
  bool findUntil(uint8_t *target, size_t targetLen, char *terminate, size_t termLen) {return findUntil((char *)target, targetLen, terminate, termLen); }

  long parseInt(LookaheadMode lookahead = SKIP_ALL, char ignore = '\x01');






  float parseFloat(LookaheadMode lookahead = SKIP_ALL, char ignore = '\x01');


  size_t readBytes( char *buffer, size_t length);
  size_t readBytes( uint8_t *buffer, size_t length) { return readBytes((char *)buffer, length); }



  size_t readBytesUntil( char terminator, char *buffer, size_t length);
  size_t readBytesUntil( char terminator, uint8_t *buffer, size_t length) { return readBytesUntil(terminator, (char *)buffer, length); }




  String readString();
  String readStringUntil(char terminator);

  protected:
  long parseInt(char ignore) { return parseInt(SKIP_ALL, ignore); }
  float parseFloat(char ignore) { return parseFloat(SKIP_ALL, ignore); }




  struct MultiTarget {
    const char *str;
    size_t len;
    size_t index;
  };



  int findMulti(struct MultiTarget *targets, int tCount);
};
# 30 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial.h" 2
# 59 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial.h"
typedef uint8_t tx_buffer_index_t;




typedef uint8_t rx_buffer_index_t;
# 93 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial.h"
class HardwareSerial : public Stream
{
  protected:
    volatile uint8_t * const _ubrrh;
    volatile uint8_t * const _ubrrl;
    volatile uint8_t * const _ucsra;
    volatile uint8_t * const _ucsrb;
    volatile uint8_t * const _ucsrc;
    volatile uint8_t * const _udr;

    bool _written;

    volatile rx_buffer_index_t _rx_buffer_head;
    volatile rx_buffer_index_t _rx_buffer_tail;
    volatile tx_buffer_index_t _tx_buffer_head;
    volatile tx_buffer_index_t _tx_buffer_tail;




    unsigned char _rx_buffer[64];
    unsigned char _tx_buffer[64];

  public:
    inline HardwareSerial(
      volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
      volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
      volatile uint8_t *ucsrc, volatile uint8_t *udr);
    void begin(unsigned long baud) { begin(baud, 0x06); }
    void begin(unsigned long, uint8_t);
    void end();
    virtual int available(void);
    virtual int peek(void);
    virtual int read(void);
    int availableForWrite(void);
    virtual void flush(void);
    virtual size_t write(uint8_t);
    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;
    operator bool() { return true; }


    inline void _rx_complete_irq(void);
    void _tx_udr_empty_irq(void);
};


  extern HardwareSerial Serial;
# 159 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/HardwareSerial.h"
extern void serialEventRun(void) __attribute__((weak));
# 234 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/USBAPI.h" 1
# 25 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/USBAPI.h"
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/eeprom.h" 1 3
# 50 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/eeprom.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stddef.h" 1 3 4
# 147 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 422 "/opt/arduino-1.6.12/hardware/tools/avr/lib/gcc/avr/4.9.2/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;






  typedef decltype(nullptr) nullptr_t;
# 51 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/eeprom.h" 2 3
# 92 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/eeprom.h" 3
extern "C" {
# 137 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/eeprom.h" 3
uint8_t eeprom_read_byte (const uint8_t *__p) __attribute__((__pure__));




uint16_t eeprom_read_word (const uint16_t *__p) __attribute__((__pure__));




uint32_t eeprom_read_dword (const uint32_t *__p) __attribute__((__pure__));




float eeprom_read_float (const float *__p) __attribute__((__pure__));





void eeprom_read_block (void *__dst, const void *__src, size_t __n);





void eeprom_write_byte (uint8_t *__p, uint8_t __value);




void eeprom_write_word (uint16_t *__p, uint16_t __value);




void eeprom_write_dword (uint32_t *__p, uint32_t __value);




void eeprom_write_float (float *__p, float __value);





void eeprom_write_block (const void *__src, void *__dst, size_t __n);





void eeprom_update_byte (uint8_t *__p, uint8_t __value);




void eeprom_update_word (uint16_t *__p, uint16_t __value);




void eeprom_update_dword (uint32_t *__p, uint32_t __value);




void eeprom_update_float (float *__p, float __value);





void eeprom_update_block (const void *__src, void *__dst, size_t __n);
# 241 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/avr/eeprom.h" 3
}
# 26 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/USBAPI.h" 2

# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 1 3
# 45 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 3
# 1 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay_basic.h" 1 3
# 40 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay_basic.h" 3
static __inline__ void _delay_loop_1(uint8_t __count) __attribute__((__always_inline__));
static __inline__ void _delay_loop_2(uint16_t __count) __attribute__((__always_inline__));
# 80 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay_basic.h" 3
void
_delay_loop_1(uint8_t __count)
{
 __asm__ volatile (
  "1: dec %0" "\n\t"
  "brne 1b"
  : "=r" (__count)
  : "0" (__count)
 );
}
# 102 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay_basic.h" 3
void
_delay_loop_2(uint16_t __count)
{
 __asm__ volatile (
  "1: sbiw %0,1" "\n\t"
  "brne 1b"
  : "=w" (__count)
  : "0" (__count)
 );
}
# 46 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 2 3
# 86 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 3
static __inline__ void _delay_us(double __us) __attribute__((__always_inline__));
static __inline__ void _delay_ms(double __ms) __attribute__((__always_inline__));
# 165 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 3
void
_delay_ms(double __ms)
{
 double __tmp ;



 uint32_t __ticks_dc;
 extern void __builtin_avr_delay_cycles(unsigned long);
 __tmp = ((16000000L) / 1e3) * __ms;
# 184 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 3
  __ticks_dc = (uint32_t)(ceil(fabs(__tmp)));


 __builtin_avr_delay_cycles(__ticks_dc);
# 210 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 3
}
# 254 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 3
void
_delay_us(double __us)
{
 double __tmp ;



 uint32_t __ticks_dc;
 extern void __builtin_avr_delay_cycles(unsigned long);
 __tmp = ((16000000L) / 1e6) * __us;
# 273 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 3
  __ticks_dc = (uint32_t)(ceil(fabs(__tmp)));


 __builtin_avr_delay_cycles(__ticks_dc);
# 299 "/opt/arduino-1.6.12/hardware/tools/avr/avr/include/util/delay.h" 3
}
# 28 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/USBAPI.h" 2

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 1
# 34 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/USBAPI.h" 2
# 235 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2




uint16_t makeWord(uint16_t w);
uint16_t makeWord(byte h, byte l);



unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
void noTone(uint8_t _pin);


long random(long);
long random(long, long);
void randomSeed(unsigned long);
long map(long, long, long, long, long);



# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs/pins_arduino.h" 1
# 23 "/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs/pins_arduino.h"
# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs/../standard/pins_arduino.h" 1
# 43 "/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs/../standard/pins_arduino.h"
static const uint8_t SS = (10);
static const uint8_t MOSI = (11);
static const uint8_t MISO = (12);
static const uint8_t SCK = (13);




static const uint8_t SDA = (18);
static const uint8_t SCL = (19);
# 65 "/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs/../standard/pins_arduino.h"
static const uint8_t A0 = (14);
static const uint8_t A1 = (15);
static const uint8_t A2 = (16);
static const uint8_t A3 = (17);
static const uint8_t A4 = (18);
static const uint8_t A5 = (19);
static const uint8_t A6 = (20);
static const uint8_t A7 = (21);
# 24 "/opt/arduino-1.6.12/hardware/arduino/avr/variants/eightanaloginputs/pins_arduino.h" 2
# 259 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "<command-line>" 2
# 1 "./src/ucbasic_main.cpp"
# 19 "./src/ucbasic_main.cpp"
# 1 "../arduinoext/include/arduino_logger.hpp" 1
# 22 "../arduinoext/include/arduino_logger.hpp"
# 1 "../arduinoext/include/cps.hpp" 1
# 23 "../arduinoext/include/arduino_logger.hpp" 2
# 1 "/opt/arduino-1.6.12/hardware/arduino/avr/cores/arduino/Stream.h" 1
# 24 "../arduinoext/include/arduino_logger.hpp" 2
# 117 "../arduinoext/include/arduino_logger.hpp"
class Logger final
{
 public:

 static void init(Stream&)
 {
 }

 template<typename... Args>
     static void log(const Args&... args)
 {
 }
 private:

 template<typename T>
 friend Logger &operator<<(Logger &logger, T first)
 {
  return (logger);
 }
};
# 20 "./src/ucbasic_main.cpp" 2
# 1 "include/basic_interpreter_program.hpp" 1
# 22 "include/basic_interpreter_program.hpp"
# 1 "include/basic_interpreter.hpp" 1
# 22 "include/basic_interpreter.hpp"
# 1 "include/basic.hpp" 1
# 28 "include/basic.hpp"
namespace BASIC
{

const uint8_t PROGSTRINGSIZE = 72;

const uint8_t STRINGSIZE = 32;
# 42 "include/basic.hpp"
const size_t PROGRAMSIZE = 1024;




const uint8_t VARSIZE = 8;

typedef int16_t Integer;

typedef float Real;




enum class ASCII : uint8_t
{
 NUL = 0x00,
 SOH = 0x01,

        EOT = 0x03,
 BEL = 0x07,
        BS = 0x08,
 LF = 0x0A,
 CR = 0x0D,
 ESC = 0x1B
};

}
# 23 "include/basic_interpreter.hpp" 2
# 1 "include/basic_lexer.hpp" 1
# 26 "include/basic_lexer.hpp"
# 1 "include/basic_parser.hpp" 1
# 25 "include/basic_parser.hpp"
# 1 "../arduinoext/include/cps.hpp" 1
# 26 "include/basic_parser.hpp" 2

# 1 "include/basic_functionblock.hpp" 1
# 25 "include/basic_functionblock.hpp"
namespace BASIC
{

class Interpreter;

class FunctionBlock
{
public:

 typedef bool (*function)(Interpreter&);

 function getFunction(const char*) const;

 FunctionBlock *next() { return _next; }

protected:

 typedef Real (*_funcReal)(Real);
 typedef Integer (*_funcInteger)(Integer);

 explicit FunctionBlock(FunctionBlock* =__null);






 virtual function _getFunction(const char*) const = 0;






 static bool general_func(Interpreter&, _funcReal);






 static bool general_func(Interpreter&, _funcInteger);

private:
 FunctionBlock *_next;
};

}
# 28 "include/basic_parser.hpp" 2

namespace BASIC
{

class __attribute__ ((__packed__)) Lexer;
class __attribute__ ((__packed__)) Interpreter;




class __attribute__ ((__packed__)) Parser
{
public:



 enum ErrorCodes : uint8_t
 {
  NO_ERROR = 0,
  OPERATOR_EXPECTED,
  EXPRESSION_EXPECTED,
  INTEGER_EXPRESSION_EXPECTED,
  THEN_OR_GOTO_EXPECTED,
  VARIABLES_LIST_EXPECTED
 };

 class __attribute__ ((__packed__)) Value;






 Parser(Lexer&, Interpreter&, FunctionBlock* = __null);





 bool parse(const char*);




 ErrorCodes getError() const { return _error; }
private:




 enum Mode : uint8_t
 {
  SCAN = 0, EXECUTE
 };
 bool fOperators();
 bool fOperator();
 bool fImplicitAssignment(char*);
 bool fPrintList();
 bool fExpression(Value&);
 bool fSimpleExpression(Value&);
 bool fTerm(Value&);
 bool fFactor(Value&);
 bool fFinal(Value&);
 bool fIfStatement();
 bool fCommand();
 bool fGotoStatement();
 bool fForConds();
 bool fVar(char*);
 bool fVarList();
 bool fArrayList();
 bool fArray(uint8_t&);
 bool fDimensions(uint8_t&);
 bool fIdentifierExpr(const char*, Value&);

 ErrorCodes _error;

 Lexer &_lexer;

 Interpreter &_interpreter;

 Mode _mode;

 bool _stopParse;

 FunctionBlock *_firstFB;
};

}
# 27 "include/basic_lexer.hpp" 2
# 1 "include/basic_parser_value.hpp" 1
# 24 "include/basic_parser_value.hpp"
namespace BASIC
{

class __attribute__ ((__packed__)) Parser::Value
{
public:

 enum Type : uint8_t
 {
  INTEGER, REAL, BOOLEAN, STRING
 };

 struct __attribute__ ((__packed__)) String
 {
  uint8_t size;

 };

 union __attribute__ ((__packed__)) Body
 {
  Integer integer;
  float real;
  bool boolean;
 };

 Value();
 Value(Integer);
 Value(float);
 Value(bool);

 explicit operator Real() const;
 explicit operator bool() const;
 explicit operator Integer() const;

 Value &operator-();

 bool operator<(const Value&) const;
 bool operator==(const Value&) const;
 bool operator>(const Value&) const;
 friend bool operator >=(const Value&, const Value&);
 friend bool operator <=(const Value&, const Value&);
 Value &operator+=(const Value&);
 Value &operator-=(const Value&);
 Value &operator*=(const Value&);
 Value &operator/=(const Value&);
 Value &operator^=(const Value&);
 void switchSign();

 Type type;
 Body value;
};
}
# 28 "include/basic_lexer.hpp" 2
# 1 "../arduinoext/include/helper.hpp" 1
# 10 "../arduinoext/include/helper.hpp"
inline void
positiveLedBlink(size_t num = 1)
{
 for (size_t i = 0; i<num; ++i) {
  digitalWrite(13, 0x1);
  delay(100);
  digitalWrite(13, 0x0);
  delay(100);
 }
}

inline void
negativeLedBlink(size_t num = 1)
{
 for (size_t i = 0; i < num; ++i) {
  digitalWrite(13, 0x1);
  delay(500);
  digitalWrite(13, 0x0);
  delay(300);
 }
}
# 46 "../arduinoext/include/helper.hpp"
inline bool
endsWith(const char *str, const char end)
{
 if (str == __null || strlen(str)==0)
  return false;
 if (end == 0)
  return true;
 if (str[strlen(str)-1] == end)
  return true;
 else
  return false;
}
# 29 "include/basic_lexer.hpp" 2

namespace BASIC
{




enum Token : uint8_t
{
 NOTOKENS = 0,


 COM_CLS,
 COM_DATA,
 COM_DUMP,
 COM_LIST,
 COM_LOAD,
 COM_NEW,
 COM_RUN,
 COM_SAVE,


 KW_DIM,
 KW_END,
 KW_FOR,
 KW_GOSUB,
 KW_GOTO,
 KW_IF,
 KW_INPUT,
 KW_LET,
 KW_NEXT,
 KW_PRINT,
 KW_REM,
 KW_RETURN,

 KW_ARRAYS,
 KW_THEN,
 KW_TO,
 KW_STEP,
 KW_VARS,

 REAL_IDENT,
 INTEGER_IDENT,
 STRING_IDENT,

 C_INTEGER,
 C_REAL,
 C_STRING,


 STAR,

 SLASH,

 PLUS,

 MINUS,

 EQUALS,

 COLON,

 SEMI,

 LT,

 GT,

 LTE,

 GTE,

 NE,

 NEA,

 COMMA,

 POW,

 LPAREN,

 RPAREN,

 OP_AND,
 OP_OR,
 OP_NOT,

 NUM_TOKENS
};
# 129 "include/basic_lexer.hpp"
class __attribute__ ((__packed__)) Lexer
{
public:




 void init(const char*);




 bool getNext();




 Token getToken() const
 {
  return _token;
 }




 const Parser::Value &getValue() const { return _value; }




 const char *id() const { return _id; }




 size_t getPointer() const { return _pointer; }






private:

 void pushSYM();
 void next();

 void first_A();
 void first_C();
 void first_D();
 void first_E();
 void first_F();
 void first_G();
 void first_I();
 void first_L();
 void first_N();
 void first_O();
 void first_P();
 void first_R();
 void first_S();
 void first_T();
 void first_V();

 void fitst_LT();
 void fitst_GT();

 void decimalNumber();
 bool numberScale();
 void ident();
 void stringConst();


 const char *_string;

 uint8_t _pointer;

 Parser::Value _value;

 char _id[STRINGSIZE];

 uint8_t _valuePointer;
 Token _token;
};

}
# 24 "include/basic_interpreter.hpp" 2



namespace BASIC
{




class __attribute__ ((__packed__)) Interpreter
{
public:



 class __attribute__ ((__packed__)) Program;




 enum Type : uint8_t
 {
  INTEGER = 0,
  REAL,
  BOOLEAN,
  STRING
 };




 enum ErrorCodes : uint8_t
 {
  NO_ERROR = 0,
  OUTTA_MEMORY,
  REDIMED_ARRAY,
  STACK_FRAME_ALLOCATION,
  ARRAY_DECLARATION,
  STRING_FRAME_SEARCH,
  INVALID_NEXT,
  RETURN_WO_GOSUB,
  NO_SUCH_STRING,
  INVALID_VALUE_TYPE,
  NO_SUCH_ARRAY,
  INTERNAL_ERROR = 255
 };




 enum ErrorType : uint8_t
 {
  STATIC_ERROR,
  DYNAMIC_ERROR
 };




 struct __attribute__ ((__packed__)) VariableFrame
 {




  uint8_t size() const;






  template <typename T>
  T get() const
  {
   union
   {
    const char *b;
    const T *i;
   } _U;
   _U.b = bytes;
   return *_U.i;
  }


  char name[VARSIZE];

  Type type;

  char bytes[];
 };




 struct ArrayFrame
 {




  uint16_t size() const;





  uint8_t *data()
  {
   return (reinterpret_cast<uint8_t*>(this+1) +
       sizeof (uint16_t)*numDimensions);
  }




  const uint8_t *data() const
  {
   return (reinterpret_cast<const uint8_t*>(this+1) +
       sizeof (uint16_t)*numDimensions);
  }






  template <typename T>
  T get(uint16_t index) const
  {
   union
   {
    const uint8_t *b;
    const T *i;
   } _U;
   _U.b = this->data();
   return _U.i[index];
  }


  char name[VARSIZE];

  Type type;

  uint8_t numDimensions;

  uint16_t dimension[];
 };

 enum State : uint8_t
 {
  SHELL, PROGRAM_INPUT, COLLECT_INPUT, EXECUTE, VAR_INPUT
 };

 enum DumpMode : uint8_t
 {
  MEMORY, VARS, ARRAYS
 };

 enum TextAttr : uint8_t
 {
  NO_ATTR = 0,
  BOLD = 0x1,
  UNDERLINE = 0x2,
  DIM = 0x4
 };
 enum ProgMemStrings : uint8_t;







 explicit Interpreter(Stream&, Program&, FunctionBlock* = __null);




 void init();

 void step();

 void exec();
 void cls();
 void doInput();

 void list();

 void dump(DumpMode);

 void print(const Parser::Value&, TextAttr=NO_ATTR);
 void print(char);
 void print(Real);

 void run();

 void gotoLine(Integer);

 void newProgram();




 void pushReturnAddress(uint8_t);

 void returnFromSub();

 void pushForLoop(const char*, uint8_t, const Parser::Value&,
     const Parser::Value&);
 void pushValue(const Parser::Value&);
 bool popValue(Parser::Value&);





 bool next(const char*);

 void save();

 void load();




 void input(const char*);

 void end();





 void set(VariableFrame&, const Parser::Value&);
 void set(ArrayFrame&, uint16_t, const Parser::Value&);





 Interpreter::VariableFrame *setVariable(const char*,
     const Parser::Value&);





 void setArrayElement(const char*, const Parser::Value&);




 void newArray(const char*);





 const VariableFrame *getVariable(const char*);

 void valueFromVar(Parser::Value&, const char*);

 bool valueFromArray(Parser::Value&, const char*);




 void pushString(const char*);





 uint16_t pushDimension(uint16_t);




 void pushDimensions(uint8_t);

 void strConcat(Parser::Value&, Parser::Value&);

 Program &_program;
private:
 class AttrKeeper;

 void print(const char *, TextAttr=NO_ATTR);
 void print(ProgMemStrings, TextAttr=NO_ATTR);
 void print(Integer, TextAttr=NO_ATTR);


 void raiseError(ErrorType, uint8_t=0);




 bool readInput();







 ArrayFrame *addArray(const char*, uint8_t, uint32_t);

 bool arrayElementIndex(ArrayFrame*, uint16_t&);

 State _state;
 Stream &_stream;
 Lexer _lexer;
 Parser _parser;
 static const char * const _progmemStrings[];
 char _inputBuffer[PROGSTRINGSIZE];
 uint8_t _inputPosition;
 char _inputVarName[VARSIZE];
};

}
# 23 "include/basic_interpreter_program.hpp" 2

namespace BASIC
{

class __attribute__ ((__packed__)) Interpreter::Program
{
 friend class Interpreter;
public:





 struct __attribute__ ((__packed__)) String
 {
  uint16_t number;
  uint8_t size;
  char text[];
 };

 struct __attribute__ ((__packed__)) StackFrame
 {

  enum Type : uint8_t
  {
   SUBPROGRAM_RETURN, FOR_NEXT, STRING, ARRAY_DIMENSION,
   ARRAY_DIMENSIONS, VALUE
  };

  struct __attribute__ ((__packed__)) ForBody
  {
   uint16_t calleeIndex;
   uint8_t textPosition;
   char varName[VARSIZE];
   Parser::Value current;
   Parser::Value step;
   Parser::Value finalv;
  };
  static_assert (sizeof (ForBody) <= (0x7f * 2 + 1), "bad size");

  struct __attribute__ ((__packed__)) GosubReturn
  {
   uint16_t calleeIndex;
   uint8_t textPosition;
  };

  static uint8_t size(Type);

  Type _type;

  union __attribute__ ((__packed__))
  {
   GosubReturn gosubReturn;
   uint8_t arrayDimensions;
   uint16_t arrayDimension;
   ForBody forFrame;
   char string[STRINGSIZE];
   Parser::Value value;
  } body;
 };

 Program(uint16_t=PROGRAMSIZE);



 void newProg();

 void reset();

 String *getString();

 String *current() const;
 String *first() const;
 String *last() const;

 void jump(uint16_t newVal) { _jump = newVal; _jumpFlag = true; }





 String *stringByIndex(uint16_t) const;






 String *stringByNumber(uint16_t, size_t = 0);





 uint16_t stringIndex(const String*) const;





 VariableFrame *variableByIndex(uint16_t);
 VariableFrame *variableByName(const char*);
 uint16_t variableIndex(VariableFrame*) const;

 ArrayFrame *arrayByIndex(uint16_t);
 ArrayFrame *arrayByName(const char*);
 uint16_t arrayIndex(ArrayFrame*) const;

 StackFrame *stackFrameByIndex(uint16_t index);
 StackFrame *currentStackFrame();





 StackFrame *push(StackFrame::Type);
 void pop();





 bool addLine(uint16_t, const char*);





 bool insert(uint16_t, const char*);
 char *_text;
 const uint16_t programSize;
private:
 uint16_t _textEnd, _current, _variablesEnd, _arraysEnd, _sp, _jump;
 bool _jumpFlag;
 uint8_t _textPosition;
};

}
# 21 "./src/ucbasic_main.cpp" 2
# 1 "include/basic_math.hpp" 1
# 30 "include/basic_math.hpp"
namespace BASIC
{

class Math : public FunctionBlock
{
public:
 explicit Math(FunctionBlock* =__null);

protected:
 FunctionBlock::function _getFunction(const char*) const override;
private:
 static bool func_abs(Interpreter&);
 static bool func_acs(Interpreter&);
 static bool func_atn(Interpreter&);
 static bool func_cos(Interpreter&);
 static bool func_cot(Interpreter&);
 static bool func_exp(Interpreter&);
 static bool func_log(Interpreter&);
 static bool func_sin(Interpreter&);
 static bool func_sqr(Interpreter&);
 static bool func_pi(Interpreter&);
 static bool func_tan(Interpreter&);

 enum FuncNames : uint8_t
 {
  F_ABS = 0, F_ACS, F_ATN, F_COS, F_COT, F_EXP, F_LOG, F_PI, F_SIN,
  F_SQR, F_TAN, NUM_FUNC
 };

 static Real acs_r(Real);
 static Real atn_r(Real);
 static Real sin_r(Real);
 static Real cos_r(Real);
 static Real cot_r(Real);
 static Real exp_r(Real);
 static Real log_r(Real);
 static Real sqr_r(Real);
 static Real tan_r(Real);

 static const char * const funcStrings[NUM_FUNC];
};

}
# 22 "./src/ucbasic_main.cpp" 2
# 1 "include/basic_arduinoio.hpp" 1
# 30 "include/basic_arduinoio.hpp"
namespace BASIC
{

class ArduinoIO : public FunctionBlock
{
public:
 explicit ArduinoIO(FunctionBlock* =__null);

protected:
 FunctionBlock::function _getFunction(const char*) const override;

private:
 static bool func_aread(Interpreter&);
 static bool func_aread_int(Interpreter&);
 static bool func_dread(Interpreter&);

 enum FuncNames : uint8_t
 {
  F_AREAD = 0, F_AREAD_INT, F_DREAD, NUM_FUNC
 };

 static Real aread_r(Real);
 static Integer aread_i(Integer);

 static const char * const funcStrings[NUM_FUNC];
};

}
# 23 "./src/ucbasic_main.cpp" 2

static BASIC::Math mathBlock;
static BASIC::ArduinoIO arduinoIo(&mathBlock);
# 43 "./src/ucbasic_main.cpp"
static BASIC::Interpreter::Program program(BASIC::PROGRAMSIZE);
static BASIC::Interpreter basic(Serial, program, &arduinoIo);


void setup()
{
 Serial.begin(57600);
# 62 "./src/ucbasic_main.cpp"
 ;

 ;

 basic.init();
# 78 "./src/ucbasic_main.cpp"
}

void loop()
{
 ;

 basic.step();
# 96 "./src/ucbasic_main.cpp"
}
