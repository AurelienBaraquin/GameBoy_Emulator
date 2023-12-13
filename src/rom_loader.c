#include <rom.h>
#include <mem.h>

#include <fcntl.h>
#include <unistd.h>
#include <types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct romHeader_t romHeader;

int loadROM(char *romPath)
{
    if (romPath == NULL) {
        printf("Error: romPath is NULL\n");
        return 1;
    }

    FILE *f = fopen(romPath, "rb"); // rb = read binary
    if (f == NULL) {
        printf("Error opening file %s\n", romPath);
        return 1;
    }

    // Get file size
    struct stat st;
    stat(romPath, &st);
    unsigned int fileSize = st.st_size;

    if (fileSize < ROM_HEADER_SIZE) {
        printf("Error: ROM file is too small\n");
        return 1;
    }

    memset(&romHeader, 0, sizeof(romHeader));

    // Read header
    fseek(f, ROM_HEADER_OFFSET, SEEK_SET);
    if (fread(&romHeader, sizeof(romHeader), 1, f) != 1) {
        printf("Error reading ROM header\n");
        return 1;
    }

    // Check if the ROM is nintendo official
    if (romHeader.nintendoLogo[0] != 0xCE || romHeader.nintendoLogo[1] != 0xED || romHeader.nintendoLogo[2] != 0x66 || romHeader.nintendoLogo[3] != 0x66 || romHeader.nintendoLogo[4] != 0xCC || romHeader.nintendoLogo[5] != 0x0D || romHeader.nintendoLogo[6] != 0x00 || romHeader.nintendoLogo[7] != 0x0B) {
        printf("Warning: ROM isn't a Nintendo Official ROM\n");
    }

    if (fileSize != romSize[romHeader.romType].bytes) {
        printf("Error: ROM size doesn't match ROM type\n");
        return 1;
    }

    rewind(f); // Go back to the beginning of the file
    if (fread(&memoryBus.rom, fileSize, 1, f) != 1) {
        printf("Error reading ROM\n");
        return 1;
    }

    fclose(f);

    return 0;
}
