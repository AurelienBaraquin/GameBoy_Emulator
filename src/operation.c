#include <operation.h>
#include <registers.h>

void add(u8 *dest, u8 value) {
    u16 result = (u16)*dest + (u16)value;

    registers.fzero = (result & 0xFF) == 0;       // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an addition
    registers.fhalf_carry = (*dest ^ value ^ (result & 0xFF)) & 0x10; // Set if carry from bit 3
    registers.fcarry = result > 0xFF;             // Set if carry from bit 7

    *dest = result & 0xFF;
}

void addhl(u16 value) {
    u32 result = (u32)registers.hl + (u32)value;

    registers.fsubtract = 0;                      // Reset because it's an addition
    registers.fhalf_carry = (registers.hl ^ value ^ (result & 0xFFFF)) & 0x1000; // Set if carry from bit 11
    registers.fcarry = result > 0xFFFF;           // Set if carry from bit 15

    registers.hl = result & 0xFFFF;
}

void adc(u8 value) {
    u16 result = (u16)registers.a + (u16)value + (u16)registers.fcarry;

    registers.fzero = (result & 0xFF) == 0;       // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an addition
    registers.fhalf_carry = (registers.a ^ value ^ (result & 0xFF)) & 0x10; // Set if carry from bit 3
    registers.fcarry = result > 0xFF;             // Set if carry from bit 7

    registers.a = result & 0xFF;
}

void sub(u8 value) {
    u16 result = (u16)registers.a - (u16)value; // We use a 16-bit result to capture the underflow

    registers.fzero = (result & 0xFF) == 0;       // Set if result is zero
    registers.fsubtract = 1;                      // Set because it's a subtraction
    registers.fhalf_carry = (registers.a ^ value ^ (result & 0xFF)) & 0x10; // Set if carry from bit 3
    registers.fcarry = result > 0xFF;             // Set if carry from bit 7

    registers.a = result & 0xFF;
}

void sbc(u8 value) {
    u16 result = (u16)registers.a - (u16)value - (u16)registers.fcarry;

    registers.fzero = (result & 0xFF) == 0;       // Set if result is zero
    registers.fsubtract = 1;                      // Set because it's a subtraction
    registers.fhalf_carry = (registers.a ^ value ^ (result & 0xFF)) & 0x10; // Set if carry from bit 3
    registers.fcarry = result > 0xFF;             // Set if carry from bit 7

    registers.a = result & 0xFF;
}

void and(u8 value) {
    registers.a &= value;

    registers.fzero = registers.a == 0;           // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an AND
    registers.fhalf_carry = 1;                    // Set because it's an AND
    registers.fcarry = 0;                         // Reset because it's an AND
}

void or(u8 value) {
    registers.a |= value;

    registers.fzero = registers.a == 0;           // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an OR
    registers.fhalf_carry = 0;                    // Reset because it's an OR
    registers.fcarry = 0;                         // Reset because it's an OR
}

void xor(u8 value) {
    registers.a ^= value;

    registers.fzero = registers.a == 0;           // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an XOR
    registers.fhalf_carry = 0;                    // Reset because it's an XOR
    registers.fcarry = 0;                         // Reset because it's an XOR
}

void cp(u8 value) {
    u16 result = (u16)registers.a - (u16)value;

    registers.fzero = (result & 0xFF) == 0;       // Set if result is zero
    registers.fsubtract = 1;                      // Set because it's a subtraction
    registers.fhalf_carry = (registers.a ^ value ^ (result & 0xFF)) & 0x10; // Set if carry from bit 3
    registers.fcarry = result > 0xFF;             // Set if carry from bit 7
}

void inc(u8* reg) {
    u16 result = (u16)*reg + 1;

    registers.fzero = (result & 0xFF) == 0;       // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an addition
    registers.fhalf_carry = (*reg ^ 1 ^ (result & 0xFF)) & 0x10; // Set if carry from bit 3

    *reg = result & 0xFF;
}

void dec(u8* reg) {
    u16 result = (u16)*reg - 1;

    registers.fzero = (result & 0xFF) == 0;       // Set if result is zero
    registers.fsubtract = 1;                      // Set because it's a subtraction
    registers.fhalf_carry = (*reg ^ 1 ^ (result & 0xFF)) & 0x10; // Set if carry from bit 3

    *reg = result & 0xFF;
}

void ccf(void) {
    registers.fsubtract = 0;                      // Reset because it's a CCF
    registers.fhalf_carry = 0;                    // Reset because it's a CCF
    registers.fcarry = !registers.fcarry;         // Complement the carry flag
}

void scf(void) {
    registers.fsubtract = 0;                      // Reset because it's a SCF
    registers.fhalf_carry = 0;                    // Reset because it's a SCF
    registers.fcarry = 1;                         // Set because it's a SCF
}

void rra(void) {
    u8 carry = registers.fcarry;

    registers.fsubtract = 0;                      // Reset because it's a RRA
    registers.fhalf_carry = 0;                    // Reset because it's a RRA
    registers.fcarry = registers.a & 0x01;        // Set if bit 0 of A is set

    registers.a >>= 1;                            // Shift A right by 1
    registers.a |= carry << 7;                    // Set bit 7 of A to the old carry flag
}

void rla(void) {
    u8 carry = registers.fcarry;

    registers.fsubtract = 0;                      // Reset because it's a RLA
    registers.fhalf_carry = 0;                    // Reset because it's a RLA
    registers.fcarry = (registers.a & 0x80) >> 7; // Set if bit 7 of A is set (bit 7 becomes the new carry flag

    registers.a <<= 1;                            // Shift A left by 1
    registers.a |= carry;                         // Set bit 0 of A to the old carry flag
}

void rrca(void) {
    registers.fsubtract = 0;                      // Reset because it's a RRCA
    registers.fhalf_carry = 0;                    // Reset because it's a RRCA
    registers.fcarry = registers.a & 0x01;        // Set if bit 0 of A is set

    registers.a >>= 1;                            // Shift A right by 1
    registers.a |= registers.fcarry << 7;         // Set bit 7 of A to the old carry flag
}

void rlca(void) {
    registers.fsubtract = 0;                      // Reset because it's a RLCA
    registers.fhalf_carry = 0;                    // Reset because it's a RLCA
    registers.fcarry = (registers.a & 0x80) >> 7; // Set if bit 7 of A is set (bit 7 becomes the new carry flag

    registers.a <<= 1;                            // Shift A left by 1
    registers.a |= registers.fcarry;              // Set bit 0 of A to the old carry flag
}

void cpl(void) {
    registers.a = ~registers.a;

    registers.fsubtract = 1;                      // Set because it's a CPL
    registers.fhalf_carry = 1;                    // Set because it's a CPL
}

void bit(u8 bit, u8 reg) {
    registers.fzero = !(reg & (1 << bit));        // Set if bit is not set
    registers.fsubtract = 0;                      // Reset because it's a BIT
    registers.fhalf_carry = 1;                    // Set because it's a BIT
}

void reset(u8 bit, u8* reg) {
    *reg &= ~(1 << bit);
}

void set(u8 bit, u8* reg) {
    *reg |= (1 << bit);
}

void srl(u8* reg) {
    registers.fcarry = *reg & 0x01;               // Set if bit 0 of reg is set
    *reg >>= 1;                                   // Shift reg right by 1
    registers.fzero = *reg == 0;                  // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an SRL
    registers.fhalf_carry = 0;                    // Reset because it's an SRL
}

void rr(u8* reg) {
    u8 carry = registers.fcarry;

    registers.fcarry = *reg & 0x01;               // Set if bit 0 of reg is set
    *reg >>= 1;                                   // Shift reg right by 1
    *reg |= carry << 7;                           // Set bit 7 of reg to the old carry flag
    registers.fzero = *reg == 0;                  // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an RR
    registers.fhalf_carry = 0;                    // Reset because it's an RR
}

void rl(u8* reg) {
    u8 carry = registers.fcarry;

    registers.fcarry = (*reg & 0x80) >> 7;        // Set if bit 7 of reg is set (bit 7 becomes the new carry flag)
    *reg <<= 1;                                   // Shift reg left by 1
    *reg |= carry;                                // Set bit 0 of reg to the old carry flag
    registers.fzero = *reg == 0;                  // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an RL
    registers.fhalf_carry = 0;                    // Reset because it's an RL
}

void rrc(u8* reg) {
    registers.fcarry = *reg & 0x01;               // Set if bit 0 of reg is set
    *reg >>= 1;                                   // Shift reg right by 1
    *reg |= registers.fcarry << 7;                // Set bit 7 of reg to the old carry flag
    registers.fzero = *reg == 0;                  // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an RRC
    registers.fhalf_carry = 0;                    // Reset because it's an RRC
}

void rlc(u8* reg) {
    registers.fcarry = (*reg & 0x80) >> 7;        // Set if bit 7 of reg is set (bit 7 becomes the new carry flag)
    *reg <<= 1;                                   // Shift reg left by 1
    *reg |= registers.fcarry;                     // Set bit 0 of reg to the old carry flag
    registers.fzero = *reg == 0;                  // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an RLC
    registers.fhalf_carry = 0;                    // Reset because it's an RLC
}

void sra(u8* reg) {
    registers.fcarry = *reg & 0x01;               // Set if bit 0 of reg is set
    *reg = (*reg >> 1) | (*reg & 0x80);           // Shift reg right by 1, but keep bit 7 the same
    registers.fzero = *reg == 0;                  // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an SRA
    registers.fhalf_carry = 0;                    // Reset because it's an SRA
}

void sla(u8* reg) {
    registers.fcarry = (*reg & 0x80) >> 7;        // Set if bit 7 of reg is set (bit 7 becomes the new carry flag)
    *reg <<= 1;                                   // Shift reg left by 1
    registers.fzero = *reg == 0;                  // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an SLA
    registers.fhalf_carry = 0;                    // Reset because it's an SLA
}

void swap(u8* reg) {
    *reg = (*reg << 4) | (*reg >> 4);             // Swap the upper and lower nibbles
    registers.fzero = *reg == 0;                  // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's a SWAP
    registers.fhalf_carry = 0;                    // Reset because it's a SWAP
}
