#pragma once

#include <types.h>

extern u8 memoryBus[0xFFFF + 0x1]; // Memory bus

// Define memory regions
#define ROM_FIX_START 0x0000
#define ROM_FIX_END   0x3FFF
#define ROM_SW_START  0x4000
#define ROM_SW_END    0x7FFF
#define VRAM_START 0x8000
#define VRAM_END   0x9FFF
#define ERAM_START 0xA000
#define ERAM_END   0xBFFF
#define WRAM0_START 0xC000
#define WRAM0_END   0xCFFF
#define WRAM1_START 0xD000
#define WRAM1_END   0xDFFF
#define ECHO_START  0xE000
#define ECHO_END    0xFDFF
#define OAM_START   0xFE00
#define OAM_END     0xFE9F
#define IO_START    0xFF00
#define IO_END      0xFF7F
#define HRAM_START  0xFF80
#define HRAM_END    0xFFFE
#define IE          0xFFFF

// Define IO registers
#define JOYP          0xFF00 // Joypad
#define SB          0xFF01 // Serial Transfer Data
#define SC          0xFF02 // SIO Control
#define DIV         0xFF04 // Divider Register
#define TIMA        0xFF05 // Timer Counter
#define TMA         0xFF06 // Timer Modulo
#define TAC         0xFF07 // Timer Control
#define IF          0xFF0F // Interrupt Flag
#define NR10        0xFF10 // Sound Mode 1 Register, Sweep Register
#define NR11        0xFF11 // Sound Mode 1 Register, Sound Length/Wave Pattern Duty
#define NR12        0xFF12 // Sound Mode 1 Register, Envelope
#define NR13        0xFF13 // Sound Mode 1 Register, Frequency Low
#define NR14        0xFF14 // Sound Mode 1 Register, Frequency High
#define NR15        0xFF15 // Sound Mode 2 Register, Unused
#define NR21        0xFF16 // Sound Mode 2 Register, Sound Length/Wave Pattern Duty
#define NR22        0xFF17 // Sound Mode 2 Register, Envelope
#define NR23        0xFF18 // Sound Mode 2 Register, Frequency Low
#define NR24        0xFF19 // Sound Mode 2 Register, Frequency High
#define NR30        0xFF1A // Sound Mode 3 Register, Sound On/Off
#define NR31        0xFF1B // Sound Mode 3 Register, Sound Length
#define NR32        0xFF1C // Sound Mode 3 Register, Select Output Level
#define NR33        0xFF1D // Sound Mode 3 Register, Frequency Low
#define NR34        0xFF1E // Sound Mode 3 Register, Frequency High
#define NR35        0xFF1F // Sound Mode 4 Register, Unused
#define NR41        0xFF20 // Sound Mode 4 Register, Sound Length
#define NR42        0xFF21 // Sound Mode 4 Register, Envelope
#define NR43        0xFF22 // Sound Mode 4 Register, Polynomial Counter
#define NR44        0xFF23 // Sound Mode 4 Register, Counter/Consecutive; Inital
#define NR50        0xFF24 // Channel Control / ON-OFF / Volume
#define NR51        0xFF25 // Selection of Sound Output Terminal
#define NR52        0xFF26 // Sound ON/OFF
#define LCDC        0xFF40 // LCD Control
#define STAT        0xFF41 // LCD Status
#define SCY         0xFF42 // Scroll Y
#define SCX         0xFF43 // Scroll X
#define LY          0xFF44 // LCDC Y-Coordinate
#define LYC         0xFF45 // LY Compare
#define DMA         0xFF46 // DMA Transfer and Start
#define BGP         0xFF47 // BG Palette Data
#define OBP0        0xFF48 // Object Palette 0 Data
#define OBJOYP        0xFF49 // Object Palette 1 Data
#define WY          0xFF4A // Window Y Position
#define WX          0xFF4B // Window X Position
#define IE          0xFFFF // Interrupt Enable

u8 readByte(u16 address);
u16 readWord(u16 address);
void writeByte(u16 address, u8 value);
void writeWord(u16 address, u16 value);

void initializeMemory(void);
