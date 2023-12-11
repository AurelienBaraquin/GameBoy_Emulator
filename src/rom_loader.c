#include <rom.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct romHeader_t romHeader;

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

    memset(&romHeader, 0, sizeof(romHeader));

    // Read header
    fseek(f, ROM_HEADER_OFFSET, SEEK_SET);
    fread(&romHeader, sizeof(romHeader), 1, f);

    printf("title: %s\n", romHeader.title);
    printf("romSize: %ld\n", romHeader.romSize);
    printf("ramSize: %ld\n", romHeader.ramSize);
}
