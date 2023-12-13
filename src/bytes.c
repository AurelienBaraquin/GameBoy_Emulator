#include <mem.h>
#include <registers.h>

// READ/WRITE MEMORY

u8 readROM(u16 address);
u8 readVRAM(u16 address);
u8 readExternalRAM(u16 address);
u8 readWorkingRAM(u16 address);
u8 readEchoRAM(u16 address);
u8 readOAM(u16 address);
u8 readIORegisters(u16 address);
u8 readHRAM(u16 address);
u8 readInterruptEnableRegister(void);

void writeROM(u16 address, u8 value);
void writeVRAM(u16 address, u8 value);
void writeExternalRAM(u16 address, u8 value);
void writeWorkingRAM(u16 address, u8 value);
void writeEchoRAM(u16 address, u8 value);
void writeOAM(u16 address, u8 value);
void writeIORegisters(u16 address, u8 value);
void writeHRAM(u16 address, u8 value);
void writeInterruptEnableRegister(u8 value);

u8 readByte(u16 address) {
    if (address < 0x8000) {
        // Handle ROM
        return readROM(address);
    } else if (address >= 0x8000 && address <= 0x9FFF) {
        // Handle VRAM
        return readVRAM(address);
    } else if (address >= 0xA000 && address <= 0xBFFF) {
        // Handle External RAM
        return readExternalRAM(address);
    } else if (address >= 0xC000 && address <= 0xDFFF) {
        // Handle Working RAM
        return readWorkingRAM(address);
    } else if (address >= 0xE000 && address < 0xFE00) {
        // Handle Echo RAM
        return readEchoRAM(address);
    } else if (address >= 0xFE00 && address <= 0xFE9F) {
        // Handle OAM
        return readOAM(address);
    } else if (address >= 0xFF00 && address <= 0xFF7F) {
        // Handle IO Registers
        return readIORegisters(address);
    } else if (address >= 0xFF80 && address <= 0xFFFE) {
        // Handle HRAM
        return readHRAM(address);
    } else if (address == 0xFFFF) {
        // Handle Interrupt Enable Register
        return readInterruptEnableRegister();
    }

    // Default case for unhandled addresses
    return 0xFF;
}

u8 readROM(u16 address) {
    return memoryBus.rom[address];
}

u8 readVRAM(u16 address) {
    return memoryBus.vram[address - 0x8000];
}

u8 readExternalRAM(u16 address) {
    return memoryBus.externalRAM[address - 0xA000];
}

u8 readWorkingRAM(u16 address) {
    return memoryBus.workingRAM[address - 0xC000];
}

u8 readEchoRAM(u16 address) {
    // Echo RAM mirrors the Working RAM (C000-DDFF)
    return memoryBus.workingRAM[address - 0xE000];
}

u8 readOAM(u16 address) {
    return memoryBus.oam[address - 0xFE00];
}

u8 readIORegisters(u16 address) {
    return memoryBus.ioRegisters[address - 0xFF00];
}

u8 readHRAM(u16 address) {
    return memoryBus.hram[address - 0xFF80];
}

u8 readInterruptEnableRegister(void) {
    return gbregisters.IE;
}

void writeByte(u16 address, u8 value) {
    if (address < 0x8000) {
        // Handle writes to ROM area (MBC logic)
        writeROM(address, value);
    } else if (address >= 0x8000 && address <= 0x9FFF) {
        // Handle writes to VRAM
        writeVRAM(address, value);
    } else if (address >= 0xA000 && address <= 0xBFFF) {
        // Handle writes to External RAM
        writeExternalRAM(address, value);
    } else if (address >= 0xC000 && address <= 0xDFFF) {
        // Handle writes to Working RAM
        writeWorkingRAM(address, value);
    } else if (address >= 0xE000 && address < 0xFE00) {
        // Handle writes to Echo RAM
        writeEchoRAM(address, value);
    } else if (address >= 0xFE00 && address <= 0xFE9F) {
        // Handle writes to OAM
        writeOAM(address, value);
    } else if (address >= 0xFF00 && address <= 0xFF7F) {
        // Handle writes to I/O Registers
        writeIORegisters(address, value);
    } else if (address >= 0xFF80 && address <= 0xFFFE) {
        // Handle writes to High RAM (HRAM)
        writeHRAM(address, value);
    } else if (address == 0xFFFF) {
        // Handle writes to the Interrupt Enable Register
        writeInterruptEnableRegister(value);
    }
    // Optionally, handle other unhandled addresses or log warnings for out-of-range writes
}

void writeROM(u16 address, u8 value) {
    memoryBus.rom[address] = value;
}

void writeVRAM(u16 address, u8 value) {
    memoryBus.vram[address - 0x8000] = value;
}

void writeExternalRAM(u16 address, u8 value) {
    memoryBus.externalRAM[address - 0xA000] = value;
}

void writeWorkingRAM(u16 address, u8 value) {
    memoryBus.workingRAM[address - 0xC000] = value;
}

void writeEchoRAM(u16 address, u8 value) {
    memoryBus.workingRAM[address - 0xE000] = value;
}

void writeOAM(u16 address, u8 value) {
    memoryBus.oam[address - 0xFE00] = value;
}

void writeIORegisters(u16 address, u8 value) {
    memoryBus.ioRegisters[address - 0xFF00] = value;
    // Additional handling might be necessary depending on the specific register
}

void writeHRAM(u16 address, u8 value) {
    memoryBus.hram[address - 0xFF80] = value;
}

void writeInterruptEnableRegister(u8 value) {
    gbregisters.IE = value;
}

u16 readWord(u16 address) {
    return (readByte(address + 1) << 8) | readByte(address);
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
