#pragma once

#include <types.h>

// CB prefix

void rlc_b(void);
void rlc_c(void);
void rlc_d(void);
void rlc_e(void);
void rlc_h(void);
void rlc_l(void);
void rlc_hl(void);
void rlc_a(void);

void rrc_b(void);
void rrc_c(void);
void rrc_d(void);
void rrc_e(void);
void rrc_h(void);
void rrc_l(void);
void rrc_hl(void);
void rrc_a(void);

void res_0_a(void);
void res_0_b(void);
void res_0_c(void);
void res_0_d(void);
void res_0_e(void);
void res_0_h(void);
void res_0_l(void);
void res_0_hl(void);

void res_1_a(void);
void res_1_b(void);
void res_1_c(void);
void res_1_d(void);
void res_1_e(void);
void res_1_h(void);
void res_1_l(void);
void res_1_hl(void);

void res_2_a(void);
void res_2_b(void);
void res_2_c(void);
void res_2_d(void);
void res_2_e(void);
void res_2_h(void);
void res_2_l(void);
void res_2_hl(void);

void res_3_a(void);
void res_3_b(void);
void res_3_c(void);
void res_3_d(void);
void res_3_e(void);
void res_3_h(void);
void res_3_l(void);
void res_3_hl(void);

void res_4_a(void);
void res_4_b(void);
void res_4_c(void);
void res_4_d(void);
void res_4_e(void);
void res_4_h(void);
void res_4_l(void);
void res_4_hl(void);

void res_5_a(void);
void res_5_b(void);
void res_5_c(void);
void res_5_d(void);
void res_5_e(void);
void res_5_h(void);
void res_5_l(void);
void res_5_hl(void);

void res_6_a(void);
void res_6_b(void);
void res_6_c(void);
void res_6_d(void);
void res_6_e(void);
void res_6_h(void);
void res_6_l(void);
void res_6_hl(void);

void res_7_a(void);
void res_7_b(void);
void res_7_c(void);
void res_7_d(void);
void res_7_e(void);
void res_7_h(void);
void res_7_l(void);
void res_7_hl(void);

void swap_a(void);
void swap_b(void);
void swap_c(void);
void swap_d(void);
void swap_e(void);
void swap_h(void);
void swap_l(void);
void swap_hl(void);

void srl_a(void);
void srl_b(void);
void srl_c(void);
void srl_d(void);
void srl_e(void);
void srl_h(void);
void srl_l(void);
void srl_hl(void);



// Standard

void xor_a(void);
void xor_b(void);
void xor_c(void);
void xor_d(void);
void xor_e(void);
void xor_h(void);
void xor_l(void);
void xor_hl(void);
void xor_n(u8 value);

void or_a(void);
void or_b(void);
void or_c(void);
void or_d(void);
void or_e(void);
void or_h(void);
void or_l(void);
void or_hlp(void);
void or_n(u8 value);

void and_a(void);
void and_b(void);
void and_c(void);
void and_d(void);
void and_e(void);
void and_h(void);
void and_l(void);
void and_hlp(void);
void and_n(u8 value);

void cpl(void);
void cp_b(void);
void cp_c(void);
void cp_d(void);
void cp_e(void);
void cp_h(void);
void cp_l(void);
void cp_hlp(void);
void cp_a(void);
void cp_n(u8 value);

void dec_b(void);
void dec_bc(void);
void dec_c(void);
void dec_d(void);
void dec_de(void);
void dec_e(void);
void dec_h(void);
void dec_hl(void);
void dec_l(void);
void dec_hlp(void);
void dec_sp(void);
void dec_a(void);

void inc_bc(void);
void inc_b(void);
void inc_c(void);
void inc_de(void);
void inc_d(void);
void inc_e(void);
void inc_hl(void);
void inc_h(void);
void inc_l(void);
void inc_sp(void);
void inc_hlp(void);
void inc_a(void);

void add_hl_bc(void);
void add_hl_de(void);
void add_hl_hl(void);
void add_hl_sp(void);
void add_a_b(void);
void add_a_c(void);
void add_a_d(void);
void add_a_e(void);
void add_a_h(void);
void add_a_l(void);
void add_a_hlp(void);
void add_a_a(void);
void add_a_n(u8 value);
void add_sp_n(u8 value);

void adc_b(void);
void adc_c(void);
void adc_d(void);
void adc_e(void);
void adc_h(void);
void adc_l(void);
void adc_hlp(void);
void adc_a(void);
void adc_n(u8 value);

void sub_b(void);
void sub_c(void);
void sub_d(void);
void sub_e(void);
void sub_h(void);
void sub_l(void);
void sub_hlp(void);
void sub_a(void);
void sub_n(u8 value);

void rst_00(void);
void rst_08(void);
void rst_10(void);
void rst_18(void);
void rst_20(void);
void rst_28(void);
void rst_30(void);
void rst_38(void);

void pop_bc(void);
void pop_de(void);
void pop_hl(void);
void pop_af(void);

void push_bc(void);
void push_de(void);
void push_hl(void);
void push_af(void);
