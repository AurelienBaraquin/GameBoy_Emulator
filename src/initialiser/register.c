#include <registers.h>

// Global registers
struct registers registers;

void initializeRegisters(void)
{
    registers.af = 0x01B0; // A is unspecified, Flags are 0b10110000 (Z=0, N=0, H=1, C=1)
    registers.bc = 0x0013;
    registers.de = 0x00D8;
    registers.hl = 0x014D;
    registers.sp = 0xFFFE;
    registers.pc = 0x0100;
}
