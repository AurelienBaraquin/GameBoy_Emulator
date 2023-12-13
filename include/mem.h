#pragma once

#include <types.h>

extern const u8 ioReset[0x100]; // Initial values for IO registers

extern struct memoryBus {
    union {
        struct {
            u8 rom[0x8000];          // 32KB ROM
            u8 vram[0x2000];         // 8KB Video RAM
            u8 externalRAM[0x2000];  // 8KB External RAM (Cartridge RAM)
            u8 workingRAM[0x2000];   // 8KB Working RAM
            u8 oam[0xA0];            // 160 bytes Object Attribute Memory
            u8 ioRegisters[0x80];    // 128 bytes I/O Registers
            u8 hram[0x7F];           // 127 bytes High RAM
        };
        u8 memory[0xFFFF + 0x01]; // 64KB of memory
    };
} memoryBus;

u8 readByte(u16 address);
u16 readWord(u16 address);
void writeByte(u16 address, u8 value);
void writeWord(u16 address, u16 value);
