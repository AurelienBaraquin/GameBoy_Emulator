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
    if ((ime || halted) && (gbregisters.IF & gbregisters.IE & 0x1F)) {
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

    if (!ime)
        return;

    ime = 0;
    pushWord(registers.pc);

    if (gbregisters.IF & gbregisters.IE & VBLANK_INTR) {
        registers.pc = VBLANK_INTR_ADDR;
        gbregisters.IF ^= VBLANK_INTR;
    } else if (gbregisters.IF & gbregisters.IE & LCDC_INTR) {
        registers.pc = LCDC_INTR_ADDR;
        gbregisters.IF ^= LCDC_INTR;
    } else if (gbregisters.IF & gbregisters.IE & TIMER_INTR) {
        registers.pc = TIMER_INTR_ADDR;
        gbregisters.IF ^= TIMER_INTR;
    } else if (gbregisters.IF & gbregisters.IE & SERIAL_INTR) {
        registers.pc = SERIAL_INTR_ADDR;
        gbregisters.IF ^= SERIAL_INTR;
    } else if (gbregisters.IF & gbregisters.IE & CONTROL_INTR) {
        registers.pc = CONTROL_INTR_ADDR;
        gbregisters.IF ^= CONTROL_INTR;
    }
}