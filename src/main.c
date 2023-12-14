#include <mem.h>
#include <rom.h>
#include <registers.h>
#include <cpu.h>

#include <raylib.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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
    // initializeRaylib();

    while (1) {
        cpu_step();
        usleep(10000);
    }
}
