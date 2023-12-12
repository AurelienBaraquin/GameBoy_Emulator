#include <registers.h>

// Global registers
struct registers registers;

void initializeRegisters(void)
{
    registers.af = AF_START; // A is unspecified, Flags are 0b10110000 (Z=0, N=0, H=1, C=1)
    registers.bc = BC_START;
    registers.de = DE_START;
    registers.hl = HL_START;
    registers.sp = SP_START;
    registers.pc = PC_START;
}
