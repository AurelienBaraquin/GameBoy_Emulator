#include <mem.h>
#include <rom.h>
#include <registers.h>
#include <cpu.h>
#include <gpu.h>
#include <interrupt.h>

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

    initializeMemory();

    if (loadROM(av[1]) != 0)
        return 1;

    srand(time(NULL));
    initializeRegisters();
    initializeRaylib();

    while (!WindowShouldClose()) {
        frame();

        for (int i = 0; i < (int)(sizeof(keys) / sizeof(keys[0])); ++i) {
            if (IsKeyPressed(keys[i]))
                SetKeyStateGB(i, 0);
            else if (IsKeyReleased(keys[i]))
                SetKeyStateGB(i, 1);
        }

        BeginDrawing(); {
            ClearBackground(BLACK);
            DrawText(TextFormat("Registre A: %04X", registers.a), 10, 10, 15, WHITE);
            DrawText(TextFormat("Registre B: %04X", registers.b), 10, 30, 15, WHITE);
            DrawText(TextFormat("Registre C: %04X", registers.c), 10, 50, 15, WHITE);
            DrawText(TextFormat("Registre D: %04X", registers.d), 10, 70, 15, WHITE);
            DrawText(TextFormat("Registre E: %04X", registers.e), 10, 90, 15, WHITE);
            DrawText(TextFormat("Registre F: %04X", registers.f), 10, 110, 15, WHITE);
            DrawText(TextFormat("Registre H: %04X", registers.h), 10, 130, 15, WHITE);
            DrawText(TextFormat("Registre L: %04X", registers.l), 10, 150, 15, WHITE);
            DrawText(TextFormat("Registre SP: %04X", registers.sp), 10, 170, 15, WHITE);
            DrawText(TextFormat("Registre PC: %04X", registers.pc), 10, 190, 15, WHITE);
        } EndDrawing();
    }

    CloseWindow();

    return 0;
}
