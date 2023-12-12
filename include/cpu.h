#pragma once

#include <operation.h>

struct instruction {
	char *disassembly;
	u8 len;
	void *execute;
};

static const struct instruction instructions[256] = {
	[0x00] = {"NOP", 1, nop},
};

void step(void);
void execute(struct instruction instruction);
