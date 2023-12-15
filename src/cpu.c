#include <cpu.h>
#include <mem.h>
#include <registers.h>
#include <stack.h>
#include <interrupt.h>

#include <stdio.h>
#include <stdlib.h>

void handleInterrupts(void);

// Global CPU

u8 cpu_step(void)
{
    if (halted && memoryBus[IF] & memoryBus[IE] & (VBLANK_INTR | LCDC_INTR | TIMER_INTR | SERIAL_INTR | CONTROL_INTR)) {
        handleInterrupts();
    }

    if (halted)
        return 1;

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

    execute(instruction);

    return op_cycles[byte];
}

void execute(struct instruction instruction)
{
    // printf("0x%04X: %s\n", registers.pc - instruction.len, instruction.disassembly);
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

    return;

error:
    printf("ERROR\n");
    exit(1);
}

void handleInterrupts(void)
{
    halted = 0;

    u8 interrupt = memoryBus[IF] & memoryBus[IE] & (VBLANK_INTR | LCDC_INTR | TIMER_INTR | SERIAL_INTR | CONTROL_INTR);

    pushWord(registers.pc);

    if (interrupt & VBLANK_INTR) {
        memoryBus[IF] &= ~VBLANK_INTR;
        registers.pc = 0x40;
    } else if (interrupt & LCDC_INTR) {
        memoryBus[IF] &= ~LCDC_INTR;
        registers.pc = 0x48;
    } else if (interrupt & TIMER_INTR) {
        memoryBus[IF] &= ~TIMER_INTR;
        registers.pc = 0x50;
    } else if (interrupt & SERIAL_INTR) {
        memoryBus[IF] &= ~SERIAL_INTR;
        registers.pc = 0x58;
    } else if (interrupt & CONTROL_INTR) {
        memoryBus[IF] &= ~CONTROL_INTR;
        registers.pc = 0x60;
    }
}
