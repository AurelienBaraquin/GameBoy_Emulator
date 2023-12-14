#include <cpu.h>
#include <mem.h>
#include <registers.h>

#include <stdio.h>
#include <stdlib.h>

// Global CPU

void cpu_step(void)
{
    if (halted)
        return;

    u8 byte = readByte(registers.pc);

    struct instruction instruction = instructions[byte];

    if (byte == CB_PREFIX) {
        byte = readByte(registers.pc + 1);
        instruction = cbInstructions[byte];
    }

    if (instruction.execute == NULL) {
        if (byte == CB_PREFIX)
            printf("Unimplemented CB instruction: 0x%02X at 0x%04X\n", byte, registers.pc);
        else
            printf("Unimplemented instruction: 0x%02X at 0x%04X\n", byte, registers.pc);
        exit(1);
    }

    registers.pc += instruction.len;

    printf("(0x%02X) ", byte);
    execute(instruction);
}

void execute(struct instruction instruction)
{
    printf("0x%04X: %s -> ", registers.pc, instruction.disassembly);

    switch (instruction.len) {
        case 1:
            ((void (*)(void))instruction.execute)();
            break;
        case 2:
            ((void (*)(u8))instruction.execute)(readByte(registers.pc - 1));
            break;
        case 3:
            ((void (*)(u16))instruction.execute)(readByte(registers.pc - 2) | (readByte(registers.pc - 1) << 8));
            break;
        default:
            goto error;
    }

    printf("OK\n");
    return;

error:
    printf("ERROR\n");
    exit(1);
}
