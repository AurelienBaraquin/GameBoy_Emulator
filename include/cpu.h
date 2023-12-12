#pragma once

#include <operation.h>

struct instruction {
	char *disassembly;
	u8 len;
	void *execute;
};

#include <opcode.h>

static const struct instruction cbInstructions[256] = {
	[0x00] = {"RLC B", 2, rlc_b},
	[0x01] = {"RLC C", 2, rlc_c},
	[0x02] = {"RLC D", 2, rlc_d},
};

static const struct instruction instructions[256] = {
	[0x00] = {"NOP", 1, nop},

	// JP
	[0xC3] = {"JP nn", 3, jp},
	[0xC2] = {"JP NZ, nn", 3, jp_nz},
	[0xCA] = {"JP Z, nn", 3, jp_z},
	[0xD2] = {"JP NC, nn", 3, jp_nc},
	[0xDA] = {"JP C, nn", 3, jp_c},
	[0xE9] = {"JP (HL)", 1, jp_hl},

	// JR
	[0x18] = {"JR n", 2, jr},
	[0x20] = {"JR NZ, n", 2, jr_nz},
	[0x28] = {"JR Z, n", 2, jr_z},
	[0x30] = {"JR NC, n", 2, jr_nc},
	[0x38] = {"JR C, n", 2, jr_c},

	// JPI
	[0xCD] = {"CALL nn", 3, call},
	[0xC4] = {"CALL NZ, nn", 3, call_nz},
	[0xCC] = {"CALL Z, nn", 3, call_z},
	[0xD4] = {"CALL NC, nn", 3, call_nc},
	[0xDC] = {"CALL C, nn", 3, call_c},
};

void step(void);
void execute(struct instruction instruction);
