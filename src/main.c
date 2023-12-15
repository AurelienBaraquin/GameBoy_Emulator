#include <mem.h>
#include <rom.h>
#include <registers.h>
#include <cpu.h>
#include <gpu.h>
#include <interrupt.h>
#include <lcd.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void frame(void)
{
    u8 cycle = 0;
    for (int i = 0; i < SCANLINES; ++i) {
        for (int j = 0; j < CYCLES_PER_SCANLINE; j += cycle) {
            cycle = cpu_step();
            gpu_step(i, j);
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

            for (int i = 0; i < GB_LCD_WIDTH; ++i) {
                for (int j = 0; j < GB_LCD_HEIGHT; ++j) {
                    DrawPixel(i, j, scanline_buffer[i][j]);
                }
            }

            DrawText(TextFormat("Registre A: %04X", registers.a), 200, 10, 15, WHITE);
            DrawText(TextFormat("Registre B: %04X", registers.b), 200, 30, 15, WHITE);
            DrawText(TextFormat("Registre C: %04X", registers.c), 200, 50, 15, WHITE);
            DrawText(TextFormat("Registre D: %04X", registers.d), 200, 70, 15, WHITE);
            DrawText(TextFormat("Registre E: %04X", registers.e), 200, 90, 15, WHITE);
            DrawText(TextFormat("Registre F: %04X", registers.f), 200, 110, 15, WHITE);
            DrawText(TextFormat("Registre H: %04X", registers.h), 200, 130, 15, WHITE);
            DrawText(TextFormat("Registre L: %04X", registers.l), 200, 150, 15, WHITE);
            DrawText(TextFormat("Registre SP: %04X", registers.sp), 200, 170, 15, WHITE);
            DrawText(TextFormat("Registre PC: %04X", registers.pc), 200, 190, 15, WHITE);
        } EndDrawing();
        usleep(500000);
    }

    CloseWindow();

    return 0;
}
