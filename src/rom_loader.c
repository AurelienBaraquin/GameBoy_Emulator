#include <rom.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROM_NAME_SIZE 0x10      // 16 bytes
#define ROM_HEADER_SIZE 0x180   // 384 bytes

char romName[ROM_NAME_SIZE + 1]; // +1 for \0 terminator
enum romType romType;
size_t romSize;
size_t ramSize;
u_int8_t header[ROM_HEADER_SIZE];

u_int8_t loadROM(char *romPath)
{
    if (romPath == NULL) {
        printf("Error: romPath is NULL\n");
        exit(EXIT_FAILURE);
    }

    FILE *f = fopen(romPath, "rb"); // rb = read binary
    if (f == NULL) {
        printf("Error opening file %s\n", romPath);
        exit(EXIT_FAILURE);
    }

    // Get file size
    struct stat st;
    stat(romPath, &st);
    size_t fileSize = st.st_size;

    if (fileSize < ROM_HEADER_SIZE) {
        printf("Error: ROM file is too small\n");
        exit(EXIT_FAILURE);
    }

    // Read header
    fread(header, 1, ROM_HEADER_SIZE, f);
}
