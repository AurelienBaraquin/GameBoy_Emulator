#include <registers.h>
#include <interrupt.h>
#include <mem.h>

// If state is 0, the key is pressed, otherwise it is released
void SetKeyStateGB(u8 key, u8 state)
{
    u8 mask = 1 << key;

    if (state == 0)
        memoryBus[JOYP] &= ~mask;
    else
        memoryBus[JOYP] |= mask;

    if (memoryBus[JOYP] & 0x30)
        memoryBus[IF] |= CONTROL_INTR;
}
