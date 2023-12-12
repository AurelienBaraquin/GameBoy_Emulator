#include <cpu.h>
#include <mem.h>
#include <registers.h>

#include <stdio.h>
#include <stdlib.h>

// Global CPU

void step(void)
{
    u8 byte = readByte(registers.pc);

    struct instruction instruction = instructions[byte];
    if (instruction.execute == NULL) {
        printf("Unimplemented instruction: 0x%02X\n", byte);
        exit(1);
    }
    printf("0x%04X: %s\n", registers.pc, instruction.disassembly);
    registers.pc += instruction.len + 1;
}
