#pragma once

#include <sys/types.h>

struct instruction {
	char *disassembly;
	u_int8_t len;
	void *execute;
} extern const instructions[256];

void _nop(void);
void _ld_bc_nn(unsigned short operand);
void _ld_bcp_a(void);
void _inc_bc(void);
void _inc_b(void);
void _dec_b(void);

const struct instruction instructions[256] = {
	{"NOP", 0, _nop},				// 0x00
	{"LD BC, %04X", 2, _ld_bc_nn},	// 0x01
	{"LD (BC), A", 0, _ld_bcp_a},	// 0x02
	{"INC BC", 0, _inc_bc},			// 0x03
	{"INC B", 0, _inc_b},			// 0x04
	{"DEC B", 0, _dec_b},			// 0x05
};
