#pragma once

#include <sys/types.h>

extern const u_int8_t ioReset[0x100]; // Initial values for IO registers

extern u_int8_t cartridge[0x8000]; // 2MB of cartridge ROM
extern u_int8_t sram[0x2000]; // 8KB of SRAM
extern u_int8_t io[0x100]; // IO registers
extern u_int8_t vram[0x2000]; // 8KB of video RAM
extern u_int8_t oam[0x100]; // 256 bytes of OAM
extern u_int8_t wram[0x2000]; // 8KB of working RAM
extern u_int8_t hram[0x80]; // 128 bytes of high RAM
