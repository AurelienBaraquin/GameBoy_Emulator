#include <mem.h>
#include <registers.h>

// READ/WRITE MEMORY

u8 readByte(u16 address) {
    return memoryBus[address];
}

u16 readWord(u16 address) {
    return readByte(address) | (readByte(address + 1) << 8);
}

void writeByte(u16 address, u8 value) {
    memoryBus[address] = value;
}

void writeWord(u16 address, u16 value) {
    writeByte(address, value & 0xFF);
    writeByte(address + 1, (value >> 8) & 0xFF);
}


// STACK

#include <registers.h>

void pushByte(u8 value)
{
    registers.sp--;
    writeByte(registers.sp, value);
}

void pushWord(u16 value)
{
    pushByte((value >> 8) & 0xFF);
    pushByte(value & 0xFF);
}

u8 popByte(void)
{
    u8 value = readByte(registers.sp);
    registers.sp++;
    return value;
}

u16 popWord(void)
{
    u16 lower = popByte();
    u16 upper = popByte();
    return (upper << 8) | lower;
}
