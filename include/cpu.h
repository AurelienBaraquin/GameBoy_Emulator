#pragma once

#include <sys/types.h>

extern struct instruction {
	char *disassembly;
	u_int8_t len;
	void *execute;
} const instructions[256];

const struct instruction instructions[256] = {
};
