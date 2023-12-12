#include <operation.h>
#include <registers.h>
#include <mem.h>

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
