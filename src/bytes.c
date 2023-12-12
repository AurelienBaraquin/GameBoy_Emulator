#include <mem.h>

u8 readByte(u16 address)
{
    return memoryBus.memory[address];
}

u16 readWord(u16 address)
{
    return (memoryBus.memory[address + 1] << 8) | memoryBus.memory[address];
}

void writeByte(u16 address, u8 value)
{
    memoryBus.memory[address] = value;
}

void writeWord(u16 address, u16 value)
{
    memoryBus.memory[address] = value & 0xFF;
    memoryBus.memory[address + 1] = value >> 8;
}
