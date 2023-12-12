#include <cpu.h>
#include <registers.h>

void add(u_int8_t *dest, u_int8_t value) {
    u_int16_t result = (u_int16_t)*dest + (u_int16_t)value;

    // Update flags
    registers.fzero = (result & 0xFF) == 0;       // Set if result is zero
    registers.fsubtract = 0;                      // Reset because it's an addition
    registers.fhalf_carry = (*dest ^ value ^ (result & 0xFF)) & 0x10; // Set if carry from bit 3
    registers.fcarry = result > 0xFF;             // Set if carry from bit 7

    // Store result in destination register
    *dest = result & 0xFF;
}
