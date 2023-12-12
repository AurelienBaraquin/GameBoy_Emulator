#pragma once

#include <operation.h>

struct instruction {
	char *disassembly;
	u8 len;
	void *execute;
};

#include <opcode.h>

#define CB_PREFIX 0xCB

static const struct instruction cbInstructions[256] = {
	[0x00] = {"RLC B", 2, rlc_b},
	[0x01] = {"RLC C", 2, rlc_c},
	[0x02] = {"RLC D", 2, rlc_d},

	[0x80] = {"RES 0, B", 2, res_0_a},
	[0x81] = {"RES 0, C", 2, res_0_b},
	[0x82] = {"RES 0, D", 2, res_0_c},
	[0x83] = {"RES 0, E", 2, res_0_d},
	[0x84] = {"RES 0, H", 2, res_0_e},
	[0x85] = {"RES 0, L", 2, res_0_h},
	[0x86] = {"RES 0, (HL)", 2, res_0_l},
	[0x87] = {"RES 0, A", 2, res_0_hl},

	[0x88] = {"RES 1, B", 2, res_1_a},
	[0x89] = {"RES 1, C", 2, res_1_b},
	[0x8A] = {"RES 1, D", 2, res_1_c},
	[0x8B] = {"RES 1, E", 2, res_1_d},
	[0x8C] = {"RES 1, H", 2, res_1_e},
	[0x8D] = {"RES 1, L", 2, res_1_h},
	[0x8E] = {"RES 1, (HL)", 2, res_1_l},
	[0x8F] = {"RES 1, A", 2, res_1_hl},

	[0x90] = {"RES 2, B", 2, res_2_a},
	[0x91] = {"RES 2, C", 2, res_2_b},
	[0x92] = {"RES 2, D", 2, res_2_c},
	[0x93] = {"RES 2, E", 2, res_2_d},
	[0x94] = {"RES 2, H", 2, res_2_e},
	[0x95] = {"RES 2, L", 2, res_2_h},
	[0x96] = {"RES 2, (HL)", 2, res_2_l},
	[0x97] = {"RES 2, A", 2, res_2_hl},

	[0x98] = {"RES 3, B", 2, res_3_a},
	[0x99] = {"RES 3, C", 2, res_3_b},
	[0x9A] = {"RES 3, D", 2, res_3_c},
	[0x9B] = {"RES 3, E", 2, res_3_d},
	[0x9C] = {"RES 3, H", 2, res_3_e},
	[0x9D] = {"RES 3, L", 2, res_3_h},
	[0x9E] = {"RES 3, (HL)", 2, res_3_l},
	[0x9F] = {"RES 3, A", 2, res_3_hl},

	[0xA0] = {"RES 4, B", 2, res_4_a},
	[0xA1] = {"RES 4, C", 2, res_4_b},
	[0xA2] = {"RES 4, D", 2, res_4_c},
	[0xA3] = {"RES 4, E", 2, res_4_d},
	[0xA4] = {"RES 4, H", 2, res_4_e},
	[0xA5] = {"RES 4, L", 2, res_4_h},
	[0xA6] = {"RES 4, (HL)", 2, res_4_l},
	[0xA7] = {"RES 4, A", 2, res_4_hl},

	[0xA8] = {"RES 5, B", 2, res_5_a},
	[0xA9] = {"RES 5, C", 2, res_5_b},
	[0xAA] = {"RES 5, D", 2, res_5_c},
	[0xAB] = {"RES 5, E", 2, res_5_d},
	[0xAC] = {"RES 5, H", 2, res_5_e},
	[0xAD] = {"RES 5, L", 2, res_5_h},
	[0xAE] = {"RES 5, (HL)", 2, res_5_l},
	[0xAF] = {"RES 5, A", 2, res_5_hl},

	[0xB0] = {"RES 6, B", 2, res_6_a},
	[0xB1] = {"RES 6, C", 2, res_6_b},
	[0xB2] = {"RES 6, D", 2, res_6_c},
	[0xB3] = {"RES 6, E", 2, res_6_d},
	[0xB4] = {"RES 6, H", 2, res_6_e},
	[0xB5] = {"RES 6, L", 2, res_6_h},
	[0xB6] = {"RES 6, (HL)", 2, res_6_l},
	[0xB7] = {"RES 6, A", 2, res_6_hl},

	[0xB8] = {"RES 7, B", 2, res_7_a},
	[0xB9] = {"RES 7, C", 2, res_7_b},
	[0xBA] = {"RES 7, D", 2, res_7_c},
	[0xBB] = {"RES 7, E", 2, res_7_d},
	[0xBC] = {"RES 7, H", 2, res_7_e},
	[0xBD] = {"RES 7, L", 2, res_7_h},
	[0xBE] = {"RES 7, (HL)", 2, res_7_l},
	[0xBF] = {"RES 7, A", 2, res_7_hl},
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

	// XOR
	[0xAF] = {"XOR A", 1, xor_a},
	[0xA8] = {"XOR B", 1, xor_b},
	[0xA9] = {"XOR C", 1, xor_c},
	[0xAA] = {"XOR D", 1, xor_d},
	[0xAB] = {"XOR E", 1, xor_e},
	[0xAC] = {"XOR H", 1, xor_h},
	[0xAD] = {"XOR L", 1, xor_l},
	[0xAE] = {"XOR (HL)", 1, xor_hl},
	[0xEE] = {"XOR n", 2, xor_n},
};

void step(void);
void execute(struct instruction instruction);
