#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "tools.h"

#define DEBUG 1
#if DEBUG
#include <stdio.h>
#include <unistd.h>
#define DEBUG_P(fmt, ...) printf(fmt, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

typedef struct
{
	uint8_t i_memory[256];
	uint8_t d_memory[256];
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
	"STORE"
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

void stack_cpu_init(stack_cpu_t* self)
{
	DEBUG_P("%s\n", __PRETTY_FUNCTION__);
	
	memset(self->i_memory, 0, sizeof(self->i_memory));
	memset(self->d_memory, 0, sizeof(self->d_memory));
	self->sp = 0;
	self->pc = 0;
	
	self->d_memory[0] = 13;
	self->d_memory[1] = 0x12;
	self->d_memory[2] = 0x34;
	
	self->i_memory[1] = OP_LOAD | DT_INT1;
	self->i_memory[2] = 0;
	self->i_memory[3] = OP_LOAD | DT_INT2;
	self->i_memory[4] = 1;
}

void stack_cpu_step(stack_cpu_t* self)
{
	DEBUG_P("%s\n", __PRETTY_FUNCTION__);
	
	DEBUG_P("PC: %x ", self->pc);
	
	uint8_t ib = self->i_memory[self->pc];
	DEBUG_P("byte: %x ", ib);
	
	opcode_t oc = OPCODE(ib);
	DEBUG_P("OPCODE: %s", opcode_strings[oc]);
	
	datatype_t dt = DATATYPE(ib);
	DEBUG_P(".%s", datatype_strings[dt >> 5]);
	
	switch (oc) {
	case OP_LOAD: {
		ib = self->i_memory[++self->pc];
		DEBUG_P(" %02x", ib);
		switch (dt) {
		case DT_INT1:
			self->d_memory[--self->sp] = self->d_memory[ib];
			break;
		case DT_INT2:
			self->sp -= 2;
			readU16((uint16_t*)(self->d_memory+(self->sp)),
			    self->d_memory+ib);
			break;
		case DT_INT4:
			self->sp -= 4;
			readU32((uint32_t*)(self->d_memory+(self->sp)),
			    self->d_memory+ib);
			break;
		case DT_INT8:
			self->sp -= 8;
			readU64((uint64_t*)(self->d_memory+(self->sp)),
			    self->d_memory+ib);
			break;
		case DT_REAL4:
			self->sp -= 4;
			readR32((float*)(self->d_memory+(self->sp)),
			    self->d_memory+ib);
			break;
		case DT_REAL8:
			self->sp -= 8;
			readR64((double*)(self->d_memory+(self->sp)),
			    self->d_memory+ib);
			break;
		}
	} break;
	case OP_STORE: {
		ib = self->i_memory[++self->pc];
		DEBUG_P(" %02x", ib);
		switch (dt) {
		case DT_INT1:
			self->d_memory[ib] = self->d_memory[self->sp++];
			break;
		case DT_INT2:
			readU16((uint16_t*)(self->d_memory+ib),
			    self->d_memory+(self->sp));
			self->sp += 2;
			break;
		case DT_INT4:
			readU32((uint32_t*)(self->d_memory+ib),
			    self->d_memory+(self->sp));
			self->sp += 4;
			break;
		case DT_INT8:
			readU64((uint64_t*)(self->d_memory+ib),
			    self->d_memory+(self->sp));
			self->sp += 8;
			break;
		case DT_REAL4:
			readR32((float*)(self->d_memory+ib),
			    self->d_memory+(self->sp));
			self->sp += 4;
			break;
		case DT_REAL8:
			readR64((double*)(self->d_memory+ib),
			    self->d_memory+(self->sp));
			self->sp += 8;
			break;
		}
	} break;
	case OP_ADD: {
		switch (dt) {
		case DT_INT1: {
			const int8_t a = self->d_memory[self->sp++];
			const int8_t b = self->d_memory[self->sp] + a;
			self->d_memory[self->sp] = b;
		}
			break;
		case DT_INT2: {
			uint16_t a;
			readU16(&a, self->d_memory+self->sp);
			self->sp +=2;
			uint16_t b;
			readU16(&b, self->d_memory+self->sp);
			writeU16((int16_t)a + (int16_t)b, self->d_memory+self->sp);
		}
			break;
		}
	}
	default:
		break;
	}
	
	DEBUG_P("%c", '\n');
	self->pc++;
}

int
main(int argc, char** argv)
{
	stack_cpu_t cpu;
	
	stack_cpu_init(&cpu);
	
	while (1) {
		stack_cpu_step(&cpu);
	}
	
	return EXIT_SUCCESS;
}


HAL_nvram_address_t HAL_nvram_getsize()
{
	return 0;
}

uint8_t HAL_nvram_read(HAL_nvram_address_t)
{
	return 0;
}

void HAL_nvram_write(HAL_nvram_address_t, uint8_t)
{
}
