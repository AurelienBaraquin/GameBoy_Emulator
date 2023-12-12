#include <cpu.h>
#include <registers.h>
#include <mem.h>

// CB prefix

void rlc_a(void) { rlc(&registers.a); }
void rlc_b(void) { rlc(&registers.b); }
void rlc_c(void) { rlc(&registers.c); }
void rlc_d(void) { rlc(&registers.d); }
void rlc_e(void) { rlc(&registers.e); }
void rlc_h(void) { rlc(&registers.h); }
void rlc_l(void) { rlc(&registers.l); }
void rlc_hl(void) {
    u8 value = readByte(registers.hl);
    rlc(&value);
    writeByte(registers.hl, value);
}

void rrc_a(void) { rrc(&registers.a); }
void rrc_b(void) { rrc(&registers.b); }
void rrc_c(void) { rrc(&registers.c); }
void rrc_d(void) { rrc(&registers.d); }
void rrc_e(void) { rrc(&registers.e); }
void rrc_h(void) { rrc(&registers.h); }
void rrc_l(void) { rrc(&registers.l); }
void rrc_hl(void) {
    u8 value = readByte(registers.hl);
    rrc(&value);
    writeByte(registers.hl, value);
}

void res_0_a(void) { res(0, &registers.a); }
void res_0_b(void) { res(0, &registers.b); }
void res_0_c(void) { res(0, &registers.c); }
void res_0_d(void) { res(0, &registers.d); }
void res_0_e(void) { res(0, &registers.e); }
void res_0_h(void) { res(0, &registers.h); }
void res_0_l(void) { res(0, &registers.l); }
void res_0_hl(void) {
    u8 value = readByte(registers.hl);
    res(0, &value);
    writeByte(registers.hl, value);
}

void res_1_a(void) { res(1, &registers.a); }
void res_1_b(void) { res(1, &registers.b); }
void res_1_c(void) { res(1, &registers.c); }
void res_1_d(void) { res(1, &registers.d); }
void res_1_e(void) { res(1, &registers.e); }
void res_1_h(void) { res(1, &registers.h); }
void res_1_l(void) { res(1, &registers.l); }
void res_1_hl(void) {
    u8 value = readByte(registers.hl);
    res(1, &value);
    writeByte(registers.hl, value);
}

void res_2_a(void) { res(2, &registers.a); }
void res_2_b(void) { res(2, &registers.b); }
void res_2_c(void) { res(2, &registers.c); }
void res_2_d(void) { res(2, &registers.d); }
void res_2_e(void) { res(2, &registers.e); }
void res_2_h(void) { res(2, &registers.h); }
void res_2_l(void) { res(2, &registers.l); }
void res_2_hl(void) {
    u8 value = readByte(registers.hl);
    res(2, &value);
    writeByte(registers.hl, value);
}

void res_3_a(void) { res(3, &registers.a); }
void res_3_b(void) { res(3, &registers.b); }
void res_3_c(void) { res(3, &registers.c); }
void res_3_d(void) { res(3, &registers.d); }
void res_3_e(void) { res(3, &registers.e); }
void res_3_h(void) { res(3, &registers.h); }
void res_3_l(void) { res(3, &registers.l); }
void res_3_hl(void) {
    u8 value = readByte(registers.hl);
    res(3, &value);
    writeByte(registers.hl, value);
}

void res_4_a(void) { res(4, &registers.a); }
void res_4_b(void) { res(4, &registers.b); }
void res_4_c(void) { res(4, &registers.c); }
void res_4_d(void) { res(4, &registers.d); }
void res_4_e(void) { res(4, &registers.e); }
void res_4_h(void) { res(4, &registers.h); }
void res_4_l(void) { res(4, &registers.l); }
void res_4_hl(void) {
    u8 value = readByte(registers.hl);
    res(4, &value);
    writeByte(registers.hl, value);
}

void res_5_a(void) { res(5, &registers.a); }
void res_5_b(void) { res(5, &registers.b); }
void res_5_c(void) { res(5, &registers.c); }
void res_5_d(void) { res(5, &registers.d); }
void res_5_e(void) { res(5, &registers.e); }
void res_5_h(void) { res(5, &registers.h); }
void res_5_l(void) { res(5, &registers.l); }
void res_5_hl(void) {
    u8 value = readByte(registers.hl);
    res(5, &value);
    writeByte(registers.hl, value);
}

void res_6_a(void) { res(6, &registers.a); }
void res_6_b(void) { res(6, &registers.b); }
void res_6_c(void) { res(6, &registers.c); }
void res_6_d(void) { res(6, &registers.d); }
void res_6_e(void) { res(6, &registers.e); }
void res_6_h(void) { res(6, &registers.h); }
void res_6_l(void) { res(6, &registers.l); }
void res_6_hl(void) {
    u8 value = readByte(registers.hl);
    res(6, &value);
    writeByte(registers.hl, value);
}

void res_7_a(void) { res(7, &registers.a); }
void res_7_b(void) { res(7, &registers.b); }
void res_7_c(void) { res(7, &registers.c); }
void res_7_d(void) { res(7, &registers.d); }
void res_7_e(void) { res(7, &registers.e); }
void res_7_h(void) { res(7, &registers.h); }
void res_7_l(void) { res(7, &registers.l); }
void res_7_hl(void) {
    u8 value = readByte(registers.hl);
    res(7, &value);
    writeByte(registers.hl, value);
}



// Standard

// XOR
void xor_a(void) { xor(registers.a); }
void xor_b(void) { xor(registers.b); }
void xor_c(void) { xor(registers.c); }
void xor_d(void) { xor(registers.d); }
void xor_e(void) { xor(registers.e); }
void xor_h(void) { xor(registers.h); }
void xor_l(void) { xor(registers.l); }
void xor_hl(void) { xor(readByte(registers.hl)); }
void xor_n(u8 value) { xor(value); }

// OR
void or_a(void) { or(registers.a); }
void or_b(void) { or(registers.b); }
void or_c(void) { or(registers.c); }
void or_d(void) { or(registers.d); }
void or_e(void) { or(registers.e); }
void or_h(void) { or(registers.h); }
void or_l(void) { or(registers.l); }
void or_hlp(void) { or(readByte(registers.hl)); }
void or_n(u8 value) { or(value); }

// CP
void cpl(void);
void cp_b(void) { cp(registers.b); }
void cp_c(void) { cp(registers.c); }
void cp_d(void) { cp(registers.d); }
void cp_e(void) { cp(registers.e); }
void cp_h(void) { cp(registers.h); }
void cp_l(void) { cp(registers.l); }
void cp_hlp(void) { cp(readByte(registers.hl)); }
void cp_a(void) { cp(registers.a); }
void cp_n(u8 value) { cp(value); }

// DEC
void dec_b(void) { dec(&registers.b); }
void dec_bc(void) { registers.bc--; } // NOTE: In 16-bit registers, flags are not affected
void dec_c(void) { dec(&registers.c); }
void dec_d(void) { dec(&registers.d); }
void dec_de(void) { registers.de--; }
void dec_e(void) { dec(&registers.e); }
void dec_h(void) { dec(&registers.h); }
void dec_hl(void) { registers.hl--; }
void dec_l(void) { dec(&registers.l); }
void dec_hlp(void) {
    u8 value = readByte(registers.hl);
    dec(&value);
    writeByte(registers.hl, value);
}
void dec_sp(void) { registers.sp--; }
void dec_a(void) { dec(&registers.a); }

// INC
void inc_bc(void) { registers.bc++; }
void inc_b(void) { inc(&registers.b); }
void inc_c(void) { inc(&registers.c); }
void inc_de(void) { registers.de++; }
void inc_d(void) { inc(&registers.d); }
void inc_e(void) { inc(&registers.e); }
void inc_hl(void) { registers.hl++; }
void inc_h(void) { inc(&registers.h); }
void inc_l(void) { inc(&registers.l); }
void inc_sp(void) { registers.sp++; }
void inc_hlp(void) {
    u8 value = readByte(registers.hl);
    inc(&value);
    writeByte(registers.hl, value);
}
void inc_a(void) { inc(&registers.a); }
