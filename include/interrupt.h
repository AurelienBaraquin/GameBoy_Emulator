#pragma once

// interrupts
#define VBLANK_INTR     0x01
#define LCDC_INTR       0x02
#define TIMER_INTR      0x04
#define SERIAL_INTR     0x08
#define CONTROL_INTR    0x10
#define ANY_INTR        0x1F

// interrupt jump addresses
#define VBLANK_INTR_ADDR    0x0040
#define LCDC_INTR_ADDR      0x0048
#define TIMER_INTR_ADDR     0x0050
#define SERIAL_INTR_ADDR    0x0058
#define CONTROL_INTR_ADDR   0x0060
