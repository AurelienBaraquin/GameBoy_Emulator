#include <mem.h>
#include <rom.h>
#include <registers.h>
#include <cpu.h>
#include <gpu.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define SCANLINES 154
#define CYCLES_PER_SCANLINE 456
#define CPU_CYCLES_PER_FRAME (NB_SCANLINES * NB_CYCLES_PER_SCANLINE)

void frame(void)
{
    u8 cycle = 0;
    for (int i = 0; i < SCANLINES; ++i) {
        for (int j = 0; j < CYCLES_PER_SCANLINE; j += cycle) {
            cycle = cpu_step();
            // gpu_step(i, j);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("Usage: %s <ROM path>\n", av[0]);
        return 1;
    }

    if (loadROM(av[1]) != 0)
        return 1;

    srand(time(NULL));
    initializeRegisters();
    initializeMemory();
    initializeRaylib();

    while (!WindowShouldClose()) {
        frame();

        if (IsKeyPressed(KEY_SPACE))
            break;

        BeginDrawing(); {
            ClearBackground(BLACK);
        } EndDrawing();
    }

    CloseWindow();

    return 0;
}
