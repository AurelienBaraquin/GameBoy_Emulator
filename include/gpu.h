#pragma once

#include <raylib.h>

enum gpuMode {
	GPU_MODE_HBLANK = 0,
	GPU_MODE_VBLANK = 1,
	GPU_MODE_OAM = 2,
	GPU_MODE_VRAM = 3,
};

void initializeRaylib(void);
