#pragma once

#include <types.h>

extern const u8 ioReset[0x100]; // Initial values for IO registers

extern struct memoryBus {
    u8 cartridge[0x8000]; // 2MB of cartridge ROM
    u8 sram[0x2000]; // 8KB of SRAM
    u8 io[0x100]; // IO registers
    u8 vram[0x2000]; // 8KB of video RAM
    u8 oam[0x100]; // 256 bytes of OAM
    u8 wram[0x2000]; // 8KB of working RAM
    u8 hram[0x80]; // 128 bytes of high RAM
} memoryBus;
