#pragma once

#include <sys/types.h>

extern const u_int8_t ioReset[0x100];

extern u_int8_t cart[0x8000];
extern u_int8_t sram[0x2000];
extern u_int8_t io[0x100];
extern u_int8_t vram[0x2000];
extern u_int8_t oam[0x100];
extern u_int8_t wram[0x2000];
extern u_int8_t hram[0x80];
