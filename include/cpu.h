#pragma once

#include <sys/types.h>

struct instruction {
	char *disassembly;
	u_int8_t operandLength;
	void *execute;
} extern const instructions[256];
