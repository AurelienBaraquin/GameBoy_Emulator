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
}
