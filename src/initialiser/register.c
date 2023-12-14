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

    initializeGBRegisters();
}

struct gbregisters gbregisters;

void initializeGBRegisters(void)
{
    gbregisters.cpu_count = 0;
    gbregisters.lcd_count = 0;
    gbregisters.div_count = 0;
    gbregisters.tima_count = 0;
    gbregisters.tac_enable = 0;
    gbregisters.tac_rate = 0;

    gbregisters.P1 = 0x00;
    gbregisters.SB = 0x00;
    gbregisters.SC = 0x00;
    gbregisters.DIV = 0x00;
    gbregisters.TIMA = 0x00;
    gbregisters.TMA = 0x00;
    gbregisters.TAC = 0x00;
    gbregisters.IF = 0x00;
    gbregisters.NR10 = 0x80;
    gbregisters.NR11 = 0xBF;
    gbregisters.NR12 = 0xF3;
    gbregisters.NR13 = 0xFF;
    gbregisters.NR14 = 0xBF;
    gbregisters.NR21 = 0x3F;
    gbregisters.NR22 = 0x00;
    gbregisters.NR24 = 0xBF;
    gbregisters.NR30 = 0x7F;
    gbregisters.NR31 = 0xFF;
    gbregisters.NR32 = 0x9F;
    gbregisters.NR33 = 0xBF;
    gbregisters.NR41 = 0xFF;
    gbregisters.NR42 = 0x00;
    gbregisters.NR43 = 0x00;
    gbregisters.NR44 = 0xBF;
    gbregisters.NR50 = 0x77;
    gbregisters.NR51 = 0xF3;
    gbregisters.NR52 = 0xF1;
    gbregisters.LCDC = 0x91;
    gbregisters.STAT = 0x85;
    gbregisters.SCY = 0x00;
    gbregisters.SCX = 0x00;
    gbregisters.LY = 0x00;
    gbregisters.LYC = 0x00;
    gbregisters.DMA = 0x00;
    gbregisters.BGP = 0xFC;
    gbregisters.OBP0 = 0xFF;
    gbregisters.OBP1 = 0xFF;
    gbregisters.WY = 0x00;
    gbregisters.WX = 0x00;
    gbregisters.IE = 0x00;
}
