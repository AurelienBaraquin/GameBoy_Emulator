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

#define NB_SCANLINES 154
#define NB_CYCLES_PER_SCANLINE 456
#define CPU_CYCLES_PER_FRAME (NB_SCANLINES * NB_CYCLES_PER_SCANLINE)

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void cpu(void)
{
    while (1) {
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < CPU_CYCLES_PER_FRAME; i++)
            cpu_step();
        pthread_mutex_unlock(&mutex);
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

    SetTargetFPS(60);

    pthread_t cpuThread;
    pthread_create(&cpuThread, NULL, (void *)cpu, NULL);

    while (!WindowShouldClose()) {
        pthread_mutex_lock(&mutex);

        if (IsKeyPressed(KEY_SPACE))
            break;

        BeginDrawing(); {
            ClearBackground(BLACK);
        } EndDrawing();

        pthread_mutex_unlock(&mutex);
    }

    CloseWindow();
    pthread_cancel(cpuThread);

    return 0;
}
