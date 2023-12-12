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
void res(u8 bit, u8* reg);

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

void ret(void);
void ret_nz(void);
void ret_z(void);
void ret_nc(void);
void ret_c(void);
// ----------------------------------------------------------------------

// Loads ---------------------------------------------------------------
void ld_bc_nn(u16 address);
void ld_bcp_a(void);
void ld_b_n(u8 value);
void ld_nnp_sp(u16 address);
void ld_a_bcp(void);
void ld_c_n(u8 value);
void ld_de_nn(u16 address);
void ld_dep_a(void);
void ld_d_n(u8 value);
void ld_a_dep(void);
void ld_e_n(u8 value);
void ld_hl_nn(u16 address);
void ldi_hlp_a(void);
void ld_h_n(u8 value);
void ldi_a_hlp(void);
void ld_l_n(u8 value);
void ld_sp_nn(u16 address);
void ldd_hlp_a(void);
void ld_hlp_n(u8 value);
void ldd_a_hlp(void);
void ld_a_n(u8 value);
void ld_b_c(void);
void ld_b_d(void);
void ld_b_e(void);
void ld_b_h(void);
void ld_b_l(void);
void ld_b_hlp(void);
void ld_b_a(void);
void ld_c_b(void);
void ld_c_d(void);
void ld_c_e(void);
void ld_c_h(void);
void ld_c_l(void);
void ld_c_hlp(void);
void ld_c_a(void);
void ld_d_b(void);
void ld_d_c(void);
void ld_d_e(void);
void ld_d_h(void);
void ld_d_l(void);
void ld_d_hlp(void);
void ld_d_a(void);
void ld_e_b(void);
void ld_e_c(void);
void ld_e_d(void);
void ld_e_h(void);
void ld_e_l(void);
void ld_e_hlp(void);
void ld_e_a(void);
void ld_h_b(void);
void ld_h_c(void);
void ld_h_d(void);
void ld_h_e(void);
void ld_h_l(void);
void ld_h_hlp(void);
void ld_h_a(void);
void ld_l_b(void);
void ld_l_c(void);
void ld_l_d(void);
void ld_l_e(void);
void ld_l_h(void);
void ld_l_hlp(void);
void ld_l_a(void);
void ld_hlp_b(void);
void ld_hlp_c(void);
void ld_hlp_d(void);
void ld_hlp_e(void);
void ld_hlp_h(void);
void ld_hlp_l(void);
void ld_hlp_a(void);
void ld_a_b(void);
void ld_a_c(void);
void ld_a_d(void);
void ld_a_e(void);
void ld_a_h(void);
void ld_a_l(void);
void ld_a_hlp(void);
void ld_a_a(void);
void ld_ff_n_ap(u8 value);
void ld_ff_c_a(void);
void ld_nnp_a(u16 address);
void ld_ff_ap_n(u8 value);
void ld_a_ff_c(void);
void ld_hl_sp_n(u8 value);
void ld_sp_hl(void);
void ld_a_nnp(u16 address);
// ----------------------------------------------------------------------