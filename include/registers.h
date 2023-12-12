#pragma once

#include <sys/types.h>

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
    					u_int8_t funused:4; // The upper 4 bits are not used (or are used by the system)
    					u_int8_t fcarry:1;      // Carry flag
    					u_int8_t fhalf_carry:1;      // Half carry flag
    					u_int8_t fsubtract:1;      // Subtract flag
    					u_int8_t fzero:1;      // Zero flag
					};
					u_int8_t f;
				};
				u_int8_t a;
			};
			u_int16_t af;
		};
	};
	
	struct {
		union {
			struct {
				u_int8_t c;
				u_int8_t b;
			};
			u_int16_t bc;
		};
	};
	
	struct {
		union {
			struct {
				u_int8_t e;
				u_int8_t d;
			};
			u_int16_t de;
		};
	};
	
	struct {
		union {
			struct {
				u_int8_t l;
				u_int8_t h;
			};
			u_int16_t hl;
		};
	};
	
	u_int16_t sp;
	u_int16_t pc;
} registers;

#pragma pack(pop)

void initializeRegisters(void);
