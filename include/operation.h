#pragma once

#include <types.h>

void nop(void);
void add(u8 *dest, u8 value);
void addhl(u16 value);
void adc(u8 value);
void sub(u8 value);
void sbc(u8 value);
void and(u8 value);
void or(u8 value);
void xor(u8 value);
void cp(u8 value);
void inc(u8* reg);
void dec(u8* reg);
void ccf(void);
void scf(void);
void rra(void);
void rla(void);
void rrca(void);
void rlca(void);
void cpl(void);
void bit(u8 bit, u8 reg);
void reset(u8 bit, u8* reg);
void set(u8 bit, u8* reg);
void srl(u8* reg);
void rr(u8* reg);
void rl(u8* reg);
void rrc(u8* reg);
void rlc(u8* reg);
void sra(u8* reg);
void sla(u8* reg);
void swap(u8* reg);

// Jumps ---------------------------------------------------------------
void jp(u16 address);
void jp_nz(u16 address);
void jp_z(u16 address);
void jp_nc(u16 address);
void jp_c(u16 address);
void jp_hl(void);

void jr(u8 value);
void jr_nz(u8 value);
void jr_z(u8 value);
void jr_nc(u8 value);
void jr_c(u8 value);

void call(u16 address);
void call_nz(u16 address);
void call_z(u16 address);
void call_nc(u16 address);
void call_c(u16 address);
// ----------------------------------------------------------------------
