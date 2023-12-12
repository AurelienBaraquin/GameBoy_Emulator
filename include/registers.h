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
    					uint8_t unused:4; // The upper 4 bits are not used (or are used by the system)
    					uint8_t carry:1;      // Carry flag
    					uint8_t half_carry:1;      // Half carry flag
    					uint8_t subtract:1;      // Subtract flag
    					uint8_t zero:1;      // Zero flag
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
