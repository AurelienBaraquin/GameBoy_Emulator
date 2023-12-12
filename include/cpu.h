#pragma once

#include <operation.h>

struct instruction {
	char *disassembly;
	u8 len;
	void *execute;
};

static const struct instruction cbInstructions[256] = {
	[0x00] = {"RLC B", 2, rlc_b},
	[0x01] = {"RLC C", 2, rlc_c},
	[0x02] = {"RLC D", 2, rlc_d},
};

static const struct instruction instructions[256] = {
	[0x00] = {"NOP", 1, nop},
};

void step(void);
void execute(struct instruction instruction);
