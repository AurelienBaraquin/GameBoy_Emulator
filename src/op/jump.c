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

void jr(s8 value)
{
    registers.pc += (u16)value;
}

void jr_nz(s8 value)
{
    if (!registers.fzero)
        jr(value);
}

void jr_z(s8 value)
{
    if (registers.fzero)
        jr(value);
}

void jr_nc(s8 value)
{
    if (!registers.fcarry)
        jr(value);
}

void jr_c(s8 value)
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

void ret(void)
{
    jp(popWord());
}

void ret_nz(void)
{
    if (!registers.fzero)
        ret();
}

void ret_z(void)
{
    if (registers.fzero)
        ret();
}

void ret_nc(void)
{
    if (!registers.fcarry)
        ret();
}

void ret_c(void)
{
    if (registers.fcarry)
        ret();
}
