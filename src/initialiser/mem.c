#include "mem.h"
#include <string.h>

u8 memoryBus[0xFFFF + 0x1]; // Memory bus

void initializeMemory(void)
{
	memset(&memoryBus, 0, sizeof(memoryBus));

	// Initialize memory regions
	memoryBus[JOYP] = 0xCF;
	memoryBus[DIV] = 0xAB;
	memoryBus[TIMA] = 0x00;
	memoryBus[TMA] = 0x00;
	memoryBus[TAC] = 0x00;
	memoryBus[IF] = 0xE1;
	memoryBus[NR10] = 0x80;
	memoryBus[NR11] = 0xBF;
	memoryBus[NR12] = 0xF3;
	memoryBus[NR14] = 0xBF;
	memoryBus[NR21] = 0x3F;
	memoryBus[NR22] = 0x00;
	memoryBus[NR24] = 0xBF;
	memoryBus[NR30] = 0x7F;
	memoryBus[NR31] = 0xFF;
	memoryBus[NR32] = 0x9F;
	memoryBus[NR33] = 0xBF;
	memoryBus[NR41] = 0xFF;
	memoryBus[NR42] = 0x00;
	memoryBus[NR43] = 0x00;
	memoryBus[NR44] = 0xBF;
	memoryBus[NR50] = 0x77;
	memoryBus[NR51] = 0xF3;
	memoryBus[NR52] = 0xF1;
	memoryBus[LCDC] = 0x91;
	memoryBus[SCY] = 0x00;
	memoryBus[SCX] = 0x00;
	memoryBus[LY] = 0x00;
	memoryBus[LYC] = 0x00;
	memoryBus[BGP] = 0xFC;
	memoryBus[OBP0] = 0xFF;
	memoryBus[OBJOYP] = 0xFF;
	memoryBus[WY] = 0x00;
	memoryBus[WX] = 0x00;
	memoryBus[IE] = 0x00;
}
