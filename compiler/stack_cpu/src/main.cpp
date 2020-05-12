#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "tools.h"
#include "HAL.h"

#include "stack_cpu.h"

#define DEBUG 1
#if DEBUG
#include <stdio.h>
#include <unistd.h>
#define DEBUG_P(fmt, ...) printf(fmt, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

#define IMEMORY_SIZE 256
#define DMEMORY_SIZE 256

void
stack_cpu_init(
    stack_cpu_t* self,
    uint8_t* imemory,
    uint8_t* dmemory)
{
	DEBUG_P("%s\n", __PRETTY_FUNCTION__);
	
	self->i_memory = imemory;
	self->d_memory = dmemory;
	
	memset(self->i_memory, 0, IMEMORY_SIZE);
	memset(self->d_memory, 0, DMEMORY_SIZE);
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
	DEBUG_P("byte: %02x ", ib);
	
	const opcode_t oc = OPCODE(ib);
	DEBUG_P("OPCODE: %s", opcode_strings[oc]);
	
	const datatype_t dt = DATATYPE(ib);
	DEBUG_P(".%s", datatype_strings[dt >> 5]);
	
	switch (oc) {
	case OP_LOAD: {
		ib = self->i_memory[++self->pc];
		switch (dt) {
		case DT_INT1:
			self->d_memory[--self->sp] = self->d_memory[ib];
			break;
		case DT_INT2: {
			self->sp -= 2;
			uint16_t b;
			readU16(&b, self->d_memory+ib);
			writeU16(b, self->d_memory+(self->sp));
		}
			break;
		case DT_INT4: {
			self->sp -= 4;
			uint32_t b;
			readU32(&b, self->d_memory+ib);
			writeU32(b, self->d_memory+(self->sp));
		}
			break;
		case DT_INT8: {
			self->sp -= 8;
			uint64_t b;
			readU64(&b, self->d_memory+ib);
			writeU64(b, self->d_memory+(self->sp));
		}
			break;
		case DT_REAL4: {
			self->sp -= 4;
			float b;
			readR32(&b, self->d_memory+ib);
			writeR32(b, self->d_memory+(self->sp));
		}
			break;
		case DT_REAL8: {
			self->sp -= 8;
			double b;
			readR64(&b, self->d_memory+ib);
			writeR64(b, self->d_memory+(self->sp));
		}
			break;
		}
	} break;
	case OP_STORE: {
		ib = self->i_memory[++self->pc];
		switch (dt) {
		case DT_INT1:
			self->d_memory[ib] = self->d_memory[self->sp++];
			break;
		case DT_INT2: {
			uint16_t b;
			readU16(&b, self->d_memory+(self->sp));
			writeU16(b, self->d_memory+ib);
			self->sp += 2;
		}
			break;
		case DT_INT4: {
			uint32_t b;
			readU32(&b, self->d_memory+(self->sp));
			writeU32(b, self->d_memory+ib);
			self->sp += 4;
		}
			break;
		case DT_INT8: {
			uint64_t b;
			readU64(&b, self->d_memory+(self->sp));
			writeU64(b, self->d_memory+ib);
			self->sp += 8;
		}
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
			self->sp += 2;
			uint16_t b;
			readU16(&b, self->d_memory+self->sp);
			writeU16((int16_t)a + (int16_t)b, self->d_memory+self->sp);
		}
			break;
		case DT_INT4: {
			uint32_t a;
			readU32(&a, self->d_memory+self->sp);
			self->sp += 4;
			uint16_t b;
			readU16(&b, self->d_memory+self->sp);
			writeU16((int16_t)a + (int16_t)b, self->d_memory+self->sp);
		}
			break;
		case DT_REAL4: {
			float a;
			readR32(&a, self->d_memory+self->sp);
			self->sp += 4;
			float b;
			readR32(&b, self->d_memory+self->sp);
			writeR32(a + b, self->d_memory+self->sp);
		}
			break;
		case DT_REAL8: {
			double a;
			readR64(&a, self->d_memory+self->sp);
			self->sp += 4;
			double b;
			readR64(&b, self->d_memory+self->sp);
			writeR64(a + b, self->d_memory+self->sp);
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

typedef struct
{
	stack_cpu_t* cpu;
} monitor_t;

int
main(int argc, char** argv)
{
	stack_cpu_t cpu;
	
	uint8_t imemory[IMEMORY_SIZE], dmemory[DMEMORY_SIZE];
	
	stack_cpu_init(&cpu, imemory, dmemory);
	
	while (1) {
		stack_cpu_step(&cpu);
	}
	
	return EXIT_SUCCESS;
}
