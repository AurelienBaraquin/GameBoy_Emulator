#pragma once

#include <sys/types.h>

extern struct registers {
	struct {
		union {
			struct {
				u_int8_t f;
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
