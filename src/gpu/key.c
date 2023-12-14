#include <registers.h>
#include <interrupt.h>

void SetKeyStateGB(u8 key, u8 state)
{
    gbregisters.P1 |= 0x0F;
    if (state == 0) {
        key |= 0x01 << key;
    } else {
        key &= (0x01 << key) ^ 0xFF;
    }

    if (!(gbregisters.P1 & INPUT_P14))
        gbregisters.P1 &= 0x0F | ((key & 0x0F) ^ 0xFF);
    if (!(gbregisters.P1 & INPUT_P15))
        gbregisters.P1 &= 0xF0 | (((key >> 4) & 0x0F) ^ 0xFF);
}
