#include <mem.h>
#include <rom.h>
#include <stdio.h>

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
    printf("   Size:         %d Kb\n", romSize[romHeader.romType].bytes);
    printf("   Entry point:  0x%X\n", romHeader.entryPoint);
}
