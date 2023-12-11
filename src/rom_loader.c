#include <rom.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

u_int8_t loadROM(char *romPath)
{
    int fd = open(romPath, O_RDONLY);
    if (fd == -1) {
        return 1;
    }
    
    struct stat st;
    if (fstat(fd, &st) == -1) {
        return 1;
    }
    
    u_int8_t *rom = malloc(st.st_size);
    if (read(fd, rom, st.st_size) == -1) {
        return 1;
    }
    
    close(fd);
}
