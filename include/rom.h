#pragma once

// ----------------------------------
// This file contains the definitions and declarations related to the Game Boy cartridge ROM.
// The information in this file was obtained from the website: https://gbdev.gg8.se/wiki/articles/The_Cartridge_Header
// ----------------------------------

#include <sys/types.h>

// Enum representing the different types of ROMs
enum romType {
    ROM_PLAIN = 0x00,
    ROM_MBC1 = 0x01,
    ROM_MBC1_RAM = 0x02,
    ROM_MBC1_RAM_BATT = 0x03,
    ROM_MBC2 = 0x05,
    ROM_MBC2_BATTERY = 0x06,
    ROM_RAM = 0x08,
    ROM_RAM_BATTERY = 0x09,
    ROM_MMM01 = 0x0B,
    ROM_MMM01_SRAM = 0x0C,
    ROM_MMM01_SRAM_BATT = 0x0D,
    ROM_MBC3_TIMER_BATT = 0x0F,
    ROM_MBC3_TIMER_RAM_BATT = 0x10,
    ROM_MBC3 = 0x11,
    ROM_MBC3_RAM = 0x12,
    ROM_MBC3_RAM_BATT = 0x13,
    ROM_MBC5 = 0x19,
    ROM_MBC5_RAM = 0x1A,
    ROM_MBC5_RAM_BATT = 0x1B,
    ROM_MBC5_RUMBLE = 0x1C,
    ROM_MBC5_RUMBLE_SRAM = 0x1D,
    ROM_MBC5_RUMBLE_SRAM_BATT = 0x1E,
    ROM_POCKET_CAMERA = 0x1F,
    ROM_BANDAI_TAMA5 = 0xFD,
    ROM_HUDSON_HUC3 = 0xFE,
    ROM_HUDSON_HUC1 = 0xFF,
};

// Array of strings representing the ROM types
static const __attribute__ ((unused)) char *romTypeString[256] = {
    [ROM_PLAIN] = "ROM_PLAIN",
    [ROM_MBC1] = "ROM_MBC1",
    [ROM_MBC1_RAM] = "ROM_MBC1",
    [ROM_MBC1_RAM_BATT] = "ROM_MBC1_RAM_BATT",
    [ROM_MBC2] = "ROM_MBC2",
    [ROM_MBC2_BATTERY] = "ROM_MBC2_BATTERY",
    [ROM_RAM] = "ROM_RAM",
    [ROM_RAM_BATTERY] = "ROM_RAM_BATTERY",
    [ROM_MMM01] = "ROM_MMM01",
    [ROM_MMM01_SRAM] = "ROM_MMM01_SRAM",
    [ROM_MMM01_SRAM_BATT] = "ROM_MMM01_SRAM_BATT",
    [ROM_MBC3_TIMER_BATT] = "ROM_MBC3_TIMER_BATT",
    [ROM_MBC3_TIMER_RAM_BATT] = "ROM_MBC3_TIMER_RAM_BATT",
    [ROM_MBC3] = "ROM_MBC3",
    [ROM_MBC3_RAM] = "ROM_MBC3_RAM",
    [ROM_MBC3_RAM_BATT] = "ROM_MBC3_RAM_BATT",
    [ROM_MBC5] = "ROM_MBC5",
    [ROM_MBC5_RAM] = "ROM_MBC5_RAM",
    [ROM_MBC5_RAM_BATT] = "ROM_MBC5_RAM_BATT",
    [ROM_MBC5_RUMBLE] = "ROM_MBC5_RUMBLE",
    [ROM_MBC5_RUMBLE_SRAM] = "ROM_MBC5_RUMBLE_SRAM",
    [ROM_MBC5_RUMBLE_SRAM_BATT] = "ROM_MBC5_RUMBLE_SRAM_BATT",
    [ROM_POCKET_CAMERA] = "ROM_POCKET_CAMERA",
    [ROM_BANDAI_TAMA5] = "ROM_BANDAI_TAMA5",
    [ROM_HUDSON_HUC3] = "ROM_HUDSON_HUC3",
    [ROM_HUDSON_HUC1] = "ROM_HUDSON_HUC1",
};

#define ROM_NAME_SIZE 0x10      // 16 bytes
#define ROM_HEADER_SIZE 0x150   // 336 bytes

#define ROM_HEADER_OFFSET 0x100 // 256 bytes


#pragma pack(push, 1) // Disable padding

// Struct representing the ROM header
struct romHeader_t {
    u_int32_t entryPoint;       // 0x100 - 0x103
    u_int8_t nintendoLogo[0x30];// 0x104 - 0x133
    char title[ROM_NAME_SIZE];  // 0x134 - 0x143
    u_int8_t cgbFlag;           // 0x143
    u_int16_t newLicenseeCode;  // 0x144 - 0x145
    u_int8_t sgbFlag;           // 0x146
    u_int8_t romType;           // 0x147
    u_int8_t romSize;           // 0x148
    u_int8_t ramSize;           // 0x149
    u_int8_t destinationCode;   // 0x14A
    u_int8_t oldLicenseeCode;   // 0x14B
    u_int8_t maskRomVersion;    // 0x14C
    u_int8_t headerChecksum;    // 0x14D
    u_int16_t globalChecksum;   // 0x14E - 0x14F
};

#pragma pack(pop) // Enable padding



struct sizeDecode_t {
    u_int8_t size;
    u_int32_t bytes;
};

//          00h -  32KByte (no ROM banking)
//          01h -  64KByte (4 banks)
//          02h - 128KByte (8 banks)
//          03h - 256KByte (16 banks)
//          04h - 512KByte (32 banks)
//          05h -   1MByte (64 banks)  - only 63 banks used by MBC1
//          06h -   2MByte (128 banks) - only 125 banks used by MBC1
//          07h -   4MByte (256 banks)
//          08h -   8MByte (512 banks)
//          52h - 1.1MByte (72 banks)
//          53h - 1.2MByte (80 banks)
//          54h - 1.5M].bytesByte (96 banks)

// Array of structs representing the ROM sizes
static const struct sizeDecode_t romSize[256] = {
    [0x00] = { .size = 0x00, .bytes = 0x8000 },
    [0x01] = { .size = 0x01, .bytes = 0x10000 },
    [0x02] = { .size = 0x02, .bytes = 0x20000 },
    [0x03] = { .size = 0x03, .bytes = 0x40000 },
    [0x04] = { .size = 0x04, .bytes = 0x80000 },
    [0x05] = { .size = 0x05, .bytes = 0x100000 },
    [0x06] = { .size = 0x06, .bytes = 0x200000 },
    [0x07] = { .size = 0x07, .bytes = 0x400000 },
    [0x08] = { .size = 0x08, .bytes = 0x800000 },
    [0x52] = { .size = 0x52, .bytes = 0x117000 },
    [0x53] = { .size = 0x53, .bytes = 0x120000 },
    [0x54] = { .size = 0x54, .bytes = 0x150000 },
};

//          00h - None
//          01h - 2 KBytes
//          02h - 8 Kbytes
//          03h - 32 KBytes (4 banks of 8KBytes each)
//          04h - 128 KBytes (16 banks of 8KBytes each)
//          05h - 64 KBytes (8 banks of 8KBytes each)

// Array of structs representing the RAM sizes
static const struct sizeDecode_t ramSize[256] = {
    [0x00] = { .size = 0x00, .bytes = 0x0 },
    [0x01] = { .size = 0x01, .bytes = 0x800 },
    [0x02] = { .size = 0x02, .bytes = 0x2000 },
    [0x03] = { .size = 0x03, .bytes = 0x8000 },
    [0x04] = { .size = 0x04, .bytes = 0x20000 },
    [0x05] = { .size = 0x05, .bytes = 0x10000 },
};

extern struct romHeader_t romHeader;

// Function declarations
int loadROM(char *romPath);
