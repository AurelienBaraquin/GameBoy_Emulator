#pragma once

#include <types.h>

extern const u8 ioReset[0x100]; // Initial values for IO registers

extern struct memoryBus {
    union {
        struct {
            u8 cartridge[0x8000]; // 2MB of cartridge ROM
            u8 sram[0x2000]; // 8KB of SRAM
            u8 io[0x100]; // IO registers
            u8 vram[0x2000]; // 8KB of video RAM
            u8 oam[0x100]; // 256 bytes of OAM
            u8 wram[0x2000]; // 8KB of working RAM
            u8 hram[0x80]; // 128 bytes of high RAM
        };
        u8 memory[0xFFFF + 0x01]; // 64KB of memory
    };
} memoryBus;

u8 readByte(u16 address);
void writeByte(u16 address, u8 value);
