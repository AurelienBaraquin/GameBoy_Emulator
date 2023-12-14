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

void cpu(void)
{
    while (1) {
        cpu_step();
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

    pthread_t cpuThread;
    pthread_create(&cpuThread, NULL, (void *)cpu, NULL);

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_SPACE))
            break;

        BeginDrawing(); {
            ClearBackground(BLACK);
        } EndDrawing();
    }

    CloseWindow();
    pthread_cancel(cpuThread);

    return 0;
}
