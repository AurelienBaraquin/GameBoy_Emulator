#include <operation.h>
#include <registers.h>
#include <mem.h>

void jp(void)
{
    u16 address = readWord(registers.pc);
    registers.pc = address;
}

void jp_nz(void)
{
    if (!registers.fzero)
        jp();
}

void jp_z(void)
{
    if (registers.fzero)
        jp();
}

void jp_nc(void)
{
    if (!registers.fcarry)
        jp();
}

void jp_c(void)
{
    if (registers.fcarry)
        jp();
}

void jp_hl(void)
{
    registers.pc = registers.hl;
}
