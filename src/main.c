#include <sys/types.h>

u_int8_t loadROM(char *romPath);

int main(int ac, char **av)
{
    loadROM(av[1]);
}