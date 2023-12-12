#include <cpu.h>
#include <registers.h>
#include <mem.h>

// CB prefix

void rlc_b(void) { rlc(&registers.b); }
void rlc_c(void) { rlc(&registers.c); }
void rlc_d(void) { rlc(&registers.d); }




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
