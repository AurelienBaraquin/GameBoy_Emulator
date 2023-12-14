#pragma once

#include <types.h>

#pragma pack(push, 1)

extern struct registers {
	struct {
		union {
			struct {
				// Flags register
				// [ 0 1 2 3 4 5 6 7 ]
					// Bit 4: "carry"
					// Bit 5: "half carry"
					// Bit 6: "subtraction"
					// Bit 7: "zero"
				union {
					struct {
    					u8 funused:4; // The upper 4 bits are not used (or are used by the system)
    					u8 fcarry:1;      // Carry flag
    					u8 fhalf_carry:1;      // Half carry flag
    					u8 fsubtract:1;      // Subtract flag
    					u8 fzero:1;      // Zero flag
					};
					u8 f;
				};
				u8 a;
			};
			u16 af;
		};
	};
	
	struct {
		union {
			struct {
				u8 c;
				u8 b;
			};
			u16 bc;
		};
	};
	
	struct {
		union {
			struct {
				u8 e;
				u8 d;
			};
			u16 de;
		};
	};
	
	struct {
		union {
			struct {
				u8 l;
				u8 h;
			};
			u16 hl;
		};
	};
	
	u16 sp;
	u16 pc;
} registers;

// u8 R_P1;    u8 R_SB;    u8 R_SC;    u8 R_DIV;
// u8 R_TIMA;  u8 R_TMA;   u8 R_TAC;   u8 R_IF;
// u8 R_NR10;  u8 R_NR11;  u8 R_NR12;  u8 R_NR14;
// u8 R_NR21;  u8 R_NR22;  u8 R_NR24;  u8 R_NR30;
// u8 R_NR31;  u8 R_NR32;  u8 R_NR33;  u8 R_NR41;
// u8 R_NR42;  u8 R_NR43;  u8 R_NR44;  u8 R_NR50;
// u8 R_NR51;  u8 R_NR52;  u8 R_LCDC;  u8 R_STAT;
// u8 R_SCY;   u8 R_SCX;   u8 R_LY;    u8 R_LYC;
// u8 R_DMA;   u8 R_BGP;   u8 R_OBP0;  u8 R_OBP1;
// u8 R_WY;    u8 R_WX;    u8 R_IE;

extern struct gbregisters {
    u32 cpu_count;   // Counts the number of CPU cycles
    u32 lcd_count;   // Counts the number of LCD cycles for screen refresh
    u32 div_count;   // Divider register count, increments at a constant rate
    u32 tima_count;  // Timer counter (TIMA) count, increments based on TAC settings
    u8 tac_enable;   // Timer Controller (TAC) enable flag
    u8 tac_rate;     // Timer Controller (TAC) rate selector

	u8 P1;           // Joypad, controls which buttons are pressed
	u8 SB;           // Serial Transfer Data, data to be sent or received over serial port
	u8 SC;           // Serial Transfer Control, controls serial port operation
	u8 DIV;          // Divider Register, increments at a constant rate

    u8 TIMA;         // Timer Counter, increments at a rate specified by TAC
    u8 TMA;          // Timer Modulo, value loaded into TIMA when it overflows
    u8 TAC;          // Timer Controller, controls TIMA and its increment rate

	u8 IF;           // Interrupt Flag, flags which interrupts are requested

    // Sound registers (NR10, NR11, NR12, NR13, NR14, NR21, NR22, NR23, NR24, NR30, NR31, NR32, NR33, NR41, NR42, NR43, NR44, NR50, NR51, NR52)
    // control different aspects of sound generation and playback
	u8 NR10;
	u8 NR11;
	u8 NR12;

	u8 NR13; // Sound Mode 1 Register, Low 8 bits of frequency

	u8 NR14;
	u8 NR21;
	u8 NR22;
	u8 NR24;
	u8 NR30;
	u8 NR31;
	u8 NR32;
	u8 NR33;
	u8 NR41;
	u8 NR42;
	u8 NR43;
	u8 NR44;
	u8 NR50;
	u8 NR51;
	u8 NR52;

    u8 LCDC;         // LCD Control, controls the operation of the LCD
	u8 STAT;         // LCDC Status, provides information about the current LCD status
    u8 SCY;          // Scroll Y, vertical scroll position of background
    u8 SCX;          // Scroll X, horizontal scroll position of background
	u8 LY;           // LCDC Y-Coordinate, indicates the current vertical line being drawn
    u8 LYC;          // LY Compare, compared with current scanline (LY)
	u8 DMA;          // DMA Transfer and Start Address, used to initiate DMA transfer
    u8 BGP;          // Background Palette, defines colors for background
    u8 OBP0;         // Object Palette 0, defines colors for sprites
    u8 OBP1;         // Object Palette 1, defines colors for sprites
    u8 WY;           // Window Y Position, controls window layer vertical position
    u8 WX;           // Window X Position minus 7, controls window layer horizontal position
    u8 IE;           // Interrupt Enable, controls which interrupts are enabled
} gbregisters;

#pragma pack(pop)

#define AF_START 0x01B0
#define BC_START 0x0013
#define DE_START 0x00D8
#define HL_START 0x014D
#define SP_START 0xFFFE
#define PC_START 0x0100
#define IE_START 0x00FF

void initializeRegisters(void);
void initializeGBRegisters(void);
