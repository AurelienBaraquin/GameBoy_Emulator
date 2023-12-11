#include <rom.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ROM_NAME_SIZE 0x10      // 16 bytes
#define ROM_HEADER_SIZE 0x180   // 384 bytes

char romName[ROM_NAME_SIZE + 1]; // +1 for \0 terminator
enum romType romType;
size_t romSize;
size_t ramSize;
u_int8_t header[ROM_HEADER_SIZE];

u_int8_t loadROM(char *romPath)
{

}
