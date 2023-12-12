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
	[0x03] = {"RLC E", 2, rlc_e},
	[0x04] = {"RLC H", 2, rlc_h},
	[0x05] = {"RLC L", 2, rlc_l},
	[0x06] = {"RLC (HL)", 2, rlc_hl},
	[0x07] = {"RLC A", 2, rlc_a},

	[0x08] = {"RRC B", 2, rrc_b},
	[0x09] = {"RRC C", 2, rrc_c},
	[0x0A] = {"RRC D", 2, rrc_d},
	[0x0B] = {"RRC E", 2, rrc_e},
	[0x0C] = {"RRC H", 2, rrc_h},
	[0x0D] = {"RRC L", 2, rrc_l},
	[0x0E] = {"RRC (HL)", 2, rrc_hl},
	[0x0F] = {"RRC A", 2, rrc_a},

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

	// RET
	[0xC9] = {"RET", 1, ret},
	[0xC0] = {"RET NZ", 1, ret_nz},
	[0xC8] = {"RET Z", 1, ret_z},
	[0xD0] = {"RET NC", 1, ret_nc},
	[0xD8] = {"RET C", 1, ret_c},

	// LD
	[0x01] = { "LD BC", 3, ld_bc_nn },
	[0x02] = { "LD (BC), A", 1, ld_bcp_a },
	[0x06] = { "LD B", 2, ld_b_n },
	[0x08] = { "LD, SP", 3, ld_nnp_sp },
	[0x0a] = { "LD A, (BC)", 1, ld_a_bcp },
	[0x0e] = { "LD C", 2, ld_c_n },
	[0x11] = { "LD DE", 3, ld_de_nn },
	[0x12] = { "LD (DE), A", 1, ld_dep_a },
	[0x16] = { "LD D", 2, ld_d_n },
	[0x1a] = { "LD A, (DE)", 1, ld_a_dep },
	[0x1e] = { "LD E", 2, ld_e_n },
	[0x21] = { "LD HL", 3, ld_hl_nn },
	[0x22] = { "LDI (HL), A", 1, ldi_hlp_a },
	[0x26] = { "LD H", 2, ld_h_n },
	[0x2a] = { "LDI A, (HL)", 1, ldi_a_hlp },
	[0x2e] = { "LD L", 2, ld_l_n },
	[0x31] = { "LD SP", 3, ld_sp_nn },
	[0x32] = { "LDD (HL), A", 1, ldd_hlp_a },
	[0x36] = { "LD (HL)", 2, ld_hlp_n },
	[0x3a] = { "LDD A, (HL)", 1, ldd_a_hlp },
	[0x3e] = { "LD A", 2, ld_a_n },
	[0x40] = { "LD B, B", 1, nop },
	[0x41] = { "LD B, C", 1, ld_b_c },
	[0x42] = { "LD B, D", 1, ld_b_d },
	[0x43] = { "LD B, E", 1, ld_b_e },
	[0x44] = { "LD B, H", 1, ld_b_h },
	[0x45] = { "LD B, L", 1, ld_b_l },
	[0x46] = { "LD B, (HL)", 1, ld_b_hlp },
	[0x47] = { "LD B, A", 1, ld_b_a },
	[0x48] = { "LD C, B", 1, ld_c_b },
	[0x49] = { "LD C, C", 1, nop },
	[0x4a] = { "LD C, D", 1, ld_c_d },
	[0x4b] = { "LD C, E", 1, ld_c_e },
	[0x4c] = { "LD C, H", 1, ld_c_h },
	[0x4d] = { "LD C, L", 1, ld_c_l },
	[0x4e] = { "LD C, (HL)", 1, ld_c_hlp },
	[0x4f] = { "LD C, A", 1, ld_c_a },
	[0x50] = { "LD D, B", 1, ld_d_b },
	[0x51] = { "LD D, C", 1, ld_d_c },
	[0x52] = { "LD D, D", 1, nop },
	[0x53] = { "LD D, E", 1, ld_d_e },
	[0x54] = { "LD D, H", 1, ld_d_h },
	[0x55] = { "LD D, L", 1, ld_d_l },
	[0x56] = { "LD D, (HL)", 1, ld_d_hlp },
	[0x57] = { "LD D, A", 1, ld_d_a },
	[0x58] = { "LD E, B", 1, ld_e_b },
	[0x59] = { "LD E, C", 1, ld_e_c },
	[0x5a] = { "LD E, D", 1, ld_e_d },
	[0x5b] = { "LD E, E", 1, nop },
	[0x5c] = { "LD E, H", 1, ld_e_h },
	[0x5d] = { "LD E, L", 1, ld_e_l },
	[0x5e] = { "LD E, (HL)", 1, ld_e_hlp },
	[0x5f] = { "LD E, A", 1, ld_e_a },
	[0x60] = { "LD H, B", 1, ld_h_b },
	[0x61] = { "LD H, C", 1, ld_h_c },
	[0x62] = { "LD H, D", 1, ld_h_d },
	[0x63] = { "LD H, E", 1, ld_h_e },
	[0x64] = { "LD H, H", 1, nop },
	[0x65] = { "LD H, L", 1, ld_h_l },
	[0x66] = { "LD H, (HL)", 1, ld_h_hlp },
	[0x67] = { "LD H, A", 1, ld_h_a },
	[0x68] = { "LD L, B", 1, ld_l_b },
	[0x69] = { "LD L, C", 1, ld_l_c },
	[0x6a] = { "LD L, D", 1, ld_l_d },
	[0x6b] = { "LD L, E", 1, ld_l_e },
	[0x6c] = { "LD L, H", 1, ld_l_h },
	[0x6d] = { "LD L, L", 1, nop },
	[0x6e] = { "LD L, (HL)", 1, ld_l_hlp },
	[0x6f] = { "LD L, A", 1, ld_l_a },
	[0x70] = { "LD (HL), B", 1, ld_hlp_b },
	[0x71] = { "LD (HL), C", 1, ld_hlp_c },
	[0x72] = { "LD (HL), D", 1, ld_hlp_d },
	[0x73] = { "LD (HL), E", 1, ld_hlp_e },
	[0x74] = { "LD (HL), H", 1, ld_hlp_h },
	[0x75] = { "LD (HL), L", 1, ld_hlp_l },
	[0x77] = { "LD (HL), A", 1, ld_hlp_a },
	[0x78] = { "LD A, B", 1, ld_a_b },
	[0x79] = { "LD A, C", 1, ld_a_c },
	[0x7a] = { "LD A, D", 1, ld_a_d },
	[0x7b] = { "LD A, E", 1, ld_a_e },
	[0x7c] = { "LD A, H", 1, ld_a_h },
	[0x7d] = { "LD A, L", 1, ld_a_l },
	[0x7e] = { "LD A, (HL)", 1, ld_a_hlp },
	[0x7f] = { "LD A, A", 1, nop },
	[0xe0] = { "LD ADDR, A", 2, ld_ff_n_ap },
	[0xe2] = { "LD (0xFF00 + C), A", 1, ld_ff_c_a },
	[0xea] = { "LD, A", 3, ld_nnp_a },
	[0xf0] = { "LD A, ADDR", 2, ld_ff_ap_n },
	[0xf2] = { "LD A, (0xFF00 + C)", 1, ld_a_ff_c },
	[0xf8] = { "LD HL, SP + <NB>", 2, ld_hl_sp_n },
	[0xf9] = { "LD SP, HL", 1, ld_sp_hl },
	[0xfa] = { "LD A,", 3, ld_a_nnp },

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
