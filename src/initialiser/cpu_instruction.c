#include <registers.h>
#include <mem.h>
#include <cpu.h>

// 0x00
void _nop(void)
{
    // Do nothing
}

// 0x01
void _ld_bc_nn(u_int16_t operand)
{
    registers.bc = operand;
}

// 0x02
void _ld_bcp_a(void)
{
    // writeByte(registers.bc, registers.a);
}

// 0x03
void _inc_bc(void)
{
    registers.bc++;
}

// 0x04
void _inc_b(void)
{
    // registers.b = inc(registers.b);
}

// 0x05
void _dec_b(void)
{
    // registers.b = dec(registers.b);
}
