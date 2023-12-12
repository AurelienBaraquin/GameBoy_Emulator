#include <operation.h>
#include <registers.h>
#include <mem.h>

void ld_bc_nn(u16 address)
{
    registers.bc = address;
}

void ld_bcp_a(void)
{
    writeByte(registers.bc, registers.a);
}

void ld_b_n(u8 value)
{
    registers.b = value;
}

void ld_nnp_sp(u16 address)
{
    writeWord(address, registers.sp);
}

void ld_a_bcp(void)
{
    registers.a = readByte(registers.bc);
}

void ld_c_n(u8 value)
{
    registers.c = value;
}

void ld_de_nn(u16 address)
{
    registers.de = address;
}

void ld_dep_a(void)
{
    writeByte(registers.de, registers.a);
}

void ld_d_n(u8 value)
{
    registers.d = value;
}

void ld_a_dep(void)
{
    registers.a = readByte(registers.de);
}

void ld_e_n(u8 value)
{
    registers.e = value;
}

void ld_hl_nn(u16 address)
{
    registers.hl = address;
}

void ldi_hlp_a(void)
{
    writeByte(registers.hl, registers.a);
    registers.hl++;
}

void ld_h_n(u8 value)
{
    registers.h = value;
}

void ldi_a_hlp(void)
{
    registers.a = readByte(registers.hl);
    registers.hl++;
}

void ld_l_n(u8 value)
{
    registers.l = value;
}

void ld_sp_nn(u16 address)
{
    registers.sp = address;
}

void ldd_hlp_a(void)
{
    writeByte(registers.hl, registers.a);
    registers.hl--;
}

void ld_hlp_n(u8 value)
{
    writeByte(registers.hl, value);
}

void ldd_a_hlp(void)
{
    registers.a = readByte(registers.hl);
    registers.hl--;
}

void ld_a_n(u8 value)
{
    registers.a = value;
}

void ld_b_c(void)
{
    registers.b = registers.c;
}

void ld_b_d(void)
{
    registers.b = registers.d;
}

void ld_b_e(void)
{
    registers.b = registers.e;
}

void ld_b_h(void)
{
    registers.b = registers.h;
}

void ld_b_l(void)
{
    registers.b = registers.l;
}

void ld_b_hlp(void)
{
    registers.b = readByte(registers.hl);
}

void ld_b_a(void)
{
    registers.b = registers.a;
}

void ld_c_b(void)
{
    registers.c = registers.b;
}

void ld_c_d(void)
{
    registers.c = registers.d;
}

void ld_c_e(void)
{
    registers.c = registers.e;
}

void ld_c_h(void)
{
    registers.c = registers.h;
}

void ld_c_l(void)
{
    registers.c = registers.l;
}

void ld_c_hlp(void)
{
    registers.c = readByte(registers.hl);
}

void ld_c_a(void)
{
    registers.c = registers.a;
}

void ld_d_b(void)
{
    registers.d = registers.b;
}

void ld_d_c(void)
{
    registers.d = registers.c;
}

void ld_d_e(void)
{
    registers.d = registers.e;
}

void ld_d_h(void)
{
    registers.d = registers.h;
}

void ld_d_l(void)
{
    registers.d = registers.l;
}

void ld_d_hlp(void)
{
    registers.d = readByte(registers.hl);
}

void ld_d_a(void)
{
    registers.d = registers.a;
}

void ld_e_b(void)
{
    registers.e = registers.b;
}

void ld_e_c(void)
{
    registers.e = registers.c;
}

void ld_e_d(void)
{
    registers.e = registers.d;
}

void ld_e_h(void)
{
    registers.e = registers.h;
}

void ld_e_l(void)
{
    registers.e = registers.l;
}

void ld_e_hlp(void)
{
    registers.e = readByte(registers.hl);
}

void ld_e_a(void)
{
    registers.e = registers.a;
}

void ld_h_b(void)
{
    registers.h = registers.b;
}

void ld_h_c(void)
{
    registers.h = registers.c;
}

void ld_h_d(void)
{
    registers.h = registers.d;
}

void ld_h_e(void)
{
    registers.h = registers.e;
}

void ld_h_l(void)
{
    registers.h = registers.l;
}

void ld_h_hlp(void)
{
    registers.h = readByte(registers.hl);
}

void ld_h_a(void)
{
    registers.h = registers.a;
}

void ld_l_b(void)
{
    registers.l = registers.b;
}

void ld_l_c(void)
{
    registers.l = registers.c;
}

void ld_l_d(void)
{
    registers.l = registers.d;
}

void ld_l_e(void)
{
    registers.l = registers.e;
}

void ld_l_h(void)
{
    registers.l = registers.h;
}

void ld_l_hlp(void)
{
    registers.l = readByte(registers.hl);
}

void ld_l_a(void)
{
    registers.l = registers.a;
}

void ld_hlp_b(void)
{
    writeByte(registers.hl, registers.b);
}

void ld_hlp_c(void)
{
    writeByte(registers.hl, registers.c);
}

void ld_hlp_d(void)
{
    writeByte(registers.hl, registers.d);
}

void ld_hlp_e(void)
{
    writeByte(registers.hl, registers.e);
}

void ld_hlp_h(void)
{
    writeByte(registers.hl, registers.h);
}

void ld_hlp_l(void)
{
    writeByte(registers.hl, registers.l);
}

void ld_hlp_a(void)
{
    writeByte(registers.hl, registers.a);
}

void ld_a_b(void)
{
    registers.a = registers.b;
}

void ld_a_c(void)
{
    registers.a = registers.c;
}

void ld_a_d(void)
{
    registers.a = registers.d;
}

void ld_a_e(void)
{
    registers.a = registers.e;
}

void ld_a_h(void)
{
    registers.a = registers.h;
}

void ld_a_l(void)
{
    registers.a = registers.l;
}

void ld_a_hlp(void)
{
    registers.a = readByte(registers.hl);
}

void ld_a_a(void)
{
    registers.a = registers.a;
}

void ld_ff_n_ap(u8 value)
{
    writeByte(0xFF00 + value, registers.a);
}

void ld_ff_c_a(void)
{
    writeByte(0xFF00 + registers.c, registers.a);
}

void ld_nnp_a(u16 address)
{
    writeByte(address, registers.a);
}

void ld_ff_ap_n(u8 value)
{
    registers.a = readByte(0xFF00 + value);
}

void ld_a_ff_c(void)
{
    registers.a = readByte(0xFF00 + registers.c);
}

void ld_hl_sp_n(u8 value)
{
    registers.hl = registers.sp + value;
}

void ld_sp_hl(void)
{
    registers.sp = registers.hl;
}

void ld_a_nnp(u16 address)
{
    registers.a = readByte(address);
}
