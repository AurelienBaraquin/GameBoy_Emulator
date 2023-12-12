#include <cpu.h>
#include <registers.h>
#include <mem.h>

// CB prefix

void rlc_b(void) { rlc(&registers.b); }
void rlc_c(void) { rlc(&registers.c); }
void rlc_d(void) { rlc(&registers.d); }

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

void xor_a(void) { xor(registers.a); }
void xor_b(void) { xor(registers.b); }
void xor_c(void) { xor(registers.c); }
void xor_d(void) { xor(registers.d); }
void xor_e(void) { xor(registers.e); }
void xor_h(void) { xor(registers.h); }
void xor_l(void) { xor(registers.l); }
void xor_hl(void) { xor(readByte(registers.hl)); }
void xor_n(u8 value) { xor(value); }
