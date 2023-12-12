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
