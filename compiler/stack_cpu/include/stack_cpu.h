#ifndef STACK_CPU_H
#define STACK_CPU_H

#include <sys/cdefs.h>

__BEGIN_DECLS

#define IMEMORY_SIZE 256
#define DMEMORY_SIZE 256

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

extern const char* opcode_strings[];

#define OPCODE(a) (opcode_t)(a & 0b00011111)

extern const char* datatype_strings[];

#define DATATYPE(a) (datatype_t)(a & 0b11100000)

void stack_cpu_init(stack_cpu_t*, uint8_t*, uint8_t*);

void stack_cpu_step(stack_cpu_t*);

__END_DECLS

#endif /* STACK_CPU_H */

