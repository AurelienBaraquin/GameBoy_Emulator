#pragma once

#define SCANLINES 154
#define CYCLES_PER_SCANLINE 456
#define CPU_CYCLES_PER_FRAME (NB_SCANLINES * NB_CYCLES_PER_SCANLINE)

#include <raylib.h>
#include <types.h>

extern Color scanline_buffer[160][SCANLINES];

void initializeRaylib(void);
void gpu_step(u8 scanline, u8 cycle);

#define OAM_START 0xFE00
#define OAM_SIZE  0xA0
#define MAX_SPRITES_PER_LINE 10

void OAM_search(u8 scanline);
void drawing(u8 scanline);
void H_blank(u8 scanline);
void V_blank(u8 scanline);
