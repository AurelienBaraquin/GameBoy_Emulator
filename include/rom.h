#pragma once

#include <sys/types.h>

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

static const char *romTypeString[256] = {
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

struct romHeader_t {
    u_int32_t entryPoint;       // 0x100 - 0x103
    u_int8_t nintendoLogo[0x30];// 0x104 - 0x133
    char title[ROM_NAME_SIZE];  // 0x134 - 0x143
    u_int8_t cgbFlag;           // 0x143
    u_int16_t newLicenseeCode;  // 0x144 - 0x145
    u_int8_t sgbFlag;           // 0x146
    enum romType romType;       // 0x147
    size_t romSize;             // 0x148
    size_t ramSize;             // 0x149
    u_int8_t destinationCode;   // 0x14A
    u_int8_t oldLicenseeCode;   // 0x14B
    u_int8_t maskRomVersion;    // 0x14C
    u_int8_t headerChecksum;    // 0x14D
    u_int16_t globalChecksum;   // 0x14E - 0x14F
};

extern struct romHeader_t romHeader;

u_int8_t loadROM(char *romPath);
void unloadROM(void);
