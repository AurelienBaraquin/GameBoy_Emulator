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

#pragma pack(pop)

void initializeRegisters(void);
