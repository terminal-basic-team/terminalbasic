#ifndef STACK_CPU_H
#define STACK_CPU_H

#include <sys/cdefs.h>

__BEGIN_DECLS

typedef struct
{
	uint8_t *i_memory;
	uint8_t *d_memory;
	uint8_t pc;
	uint8_t sp;
} stack_cpu_t;

typedef enum
{
	OP_NOP = 0,
	OP_LOAD = 1,
	OP_STORE = 2,
	OP_ADD = 3,
	NUM_OPCODES
} opcode_t;

typedef enum
{
	DT_NONE = 0 << 5,
	DT_INT1 = 1 << 5,
	DT_INT2 = 2 << 5,
	DT_INT4 = 3 << 5,
	DT_INT8 = 4 << 5,
	DT_REAL4 = 5 << 5,
	DT_REAL8 = 6 << 5,
	    
	NUM_DATATYPES
} datatype_t;

const char* opcode_strings[(uint8_t)NUM_OPCODES] = {
	"NOP",
	"LOAD",
	"STORE",
	"ADD"
};

#define OPCODE(a) (opcode_t)(a & 0b00011111)

const char* datatype_strings[(uint8_t)NUM_DATATYPES] = {
	"NONE",
	"I1",
	"I2",
	"I4",
	"I8",
	"R4",
	"R8"
};

#define DATATYPE(a) (datatype_t)(a & 0b11100000)

__END_DECLS

#endif /* STACK_CPU_H */

