#ifndef BCOPY_HPP
#define BCOPY_HPP

#include <stdlib.h>

/**
 * @brief The bcopy() function copies len bytes from buffer src to buffer dst.
 * 
 * The two buffers may overlap. If len is zero, no bytes are copied.
 * @param src source buffer
 * @param dst destination buffer
 * @param len length
 */
extern void
bcopy(const void *src, void *dst, size_t len);

#endif
