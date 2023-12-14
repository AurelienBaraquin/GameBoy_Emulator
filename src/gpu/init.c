#include <lcd.h>
#include <raylib.h>

u8 lcd_scale = 4;

void initializeRaylib(void)
{
    InitWindow(GB_LCD_WIDTH * lcd_scale, GB_LCD_HEIGHT * lcd_scale, "GameBoy");
    SetTargetFPS(60);
}
