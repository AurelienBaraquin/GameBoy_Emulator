#include <registers.h>

// Global registers
struct registers registers;

void initializeRegisters(void)
{
    registers.a = 0x01;
    registers.fzero = 0x01;
    registers.fsubtract = 0x00;
    registers.fhalf_carry = 0x01;
    registers.fcarry = 0x01;
    registers.b = 0x00;
    registers.c = 0x13;
    registers.d = 0x00;
    registers.e = 0xD8;
    registers.h = 0x01;
    registers.l = 0x4D;
    registers.sp = 0xFFFE;
    registers.pc = 0x0100;
}
