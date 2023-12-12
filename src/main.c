#include <mem.h>
#include <rom.h>
#include <registers.h>
#include <cpu.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("Usage: %s <ROM path>\n", av[0]);
        return 1;
    }

    printf("Loading ROM %s...\n", av[1]);

    if (loadROM(av[1]) != 0) {
        printf("Error loading ROM\n");
        return 1;
    }

    printf("ROM loaded successfully !\n");
    printf("   Name:         %s\n", romHeader.title);
    printf("   Type:         %s\n", romTypeString[romHeader.romType]);
    printf("   Size:         %d Kb\n", romSize[romHeader.romType].bytes / 1024);
    printf("   Entry point:  0x%X\n", romHeader.entryPoint);

    srand(time(NULL));
    initializeRegisters();

    while (1) {
        step();
    }
}
