#include <operation.h>
#include <registers.h>
#include <mem.h>
#include <stack.h>

void jp(u16 address)
{
    registers.pc = address;
}

void jp_nz(u16 address)
{
    if (!registers.fzero)
        jp(address);
}

void jp_z(u16 address)
{
    if (registers.fzero)
        jp(address);
}

void jp_nc(u16 address)
{
    if (!registers.fcarry)
        jp(address);
}

void jp_c(u16 address)
{
    if (registers.fcarry)
        jp(address);
}

void jp_hl(void)
{
    registers.pc = registers.hl;
}

void jr(u8 value)
{
    registers.pc += value;
}

void jr_nz(u8 value)
{
    if (!registers.fzero)
        jr(value);
}

void jr_z(u8 value)
{
    if (registers.fzero)
        jr(value);
}

void jr_nc(u8 value)
{
    if (!registers.fcarry)
        jr(value);
}

void jr_c(u8 value)
{
    if (registers.fcarry)
        jr(value);
}

void call(u16 address)
{
    pushWord(registers.pc);
    jp(address);
}

void call_nz(u16 address)
{
    if (!registers.fzero)
        call(address);
}

void call_z(u16 address)
{
    if (registers.fzero)
        call(address);
}

void call_nc(u16 address)
{
    if (!registers.fcarry)
        call(address);
}

void call_c(u16 address)
{
    if (registers.fcarry)
        call(address);
}
