#pragma once

#include <types.h>

struct instruction {
	char *disassembly;
	u8 len;
	void *execute;
};

static const struct instruction instructions[256] = {

};
