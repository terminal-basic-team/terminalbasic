#ifndef TOOLS_H
#define TOOLS_H

#include "sys/cdefs.h"
#include <stdint.h>

__BEGIN_DECLS

void ftoa(float, char*);

void writeU16(uint16_t, uint8_t*);

void writeU32(uint32_t, uint8_t*);
    
__END_DECLS

#endif /* TOOLS_H */

