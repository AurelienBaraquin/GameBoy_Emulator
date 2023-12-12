#pragma once

#include <types.h>

extern const u8 ioReset[0x100]; // Initial values for IO registers

extern u8 cartridge[0x8000]; // 2MB of cartridge ROM
extern u8 sram[0x2000]; // 8KB of SRAM
extern u8 io[0x100]; // IO registers
extern u8 vram[0x2000]; // 8KB of video RAM
extern u8 oam[0x100]; // 256 bytes of OAM
extern u8 wram[0x2000]; // 8KB of working RAM
extern u8 hram[0x80]; // 128 bytes of high RAM
