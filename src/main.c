#include <mem.h>

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("Usage: %s <ROM path>\n", av[0]);
        return 1;
    }

    if (loadROM(av[1]) != 0)
        return 1;
}
