#pragma once

#include <sys/types.h>

struct instruction {
	char *disassembly;
	u_int8_t len;
	void *execute;
};

void add(u_int8_t *dest, u_int8_t value);

static const struct instruction instructions[256] = {

};
