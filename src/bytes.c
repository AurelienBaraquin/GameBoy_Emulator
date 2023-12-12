#include <mem.h>

u8 readByte(u16 address)
{
    return memoryBus.memory[address];
}

void writeByte(u16 address, u8 value)
{
    memoryBus.memory[address] = value;
}
