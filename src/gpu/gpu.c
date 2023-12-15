#include <gpu.h>
#include <registers.h>
#include <mem.h>
#include <interrupt.h>
#include <sprite.h>
#include <lcd.h>

Sprite sprites[MAX_SPRITES_PER_LINE];
u8 spriteCount = 0;

Color scanline_buffer[GB_LCD_WIDTH][SCANLINES];

void gpu_step(u8 scanline, u8 cycle) {
    if (scanline < 144) { // Modes 2, 3, 0
        if (cycle < 80) {
            OAM_search(scanline);
            memoryBus[STAT] = (memoryBus[STAT] & 0xFC) | 0x02; // Mode 2
        } else if (cycle < 252) {
            drawing(scanline);
            memoryBus[STAT] = (memoryBus[STAT] & 0xFC) | 0x03; // Mode 3
        } else {
            H_blank(scanline);
            memoryBus[STAT] = (memoryBus[STAT] & 0xFC); // Mode 0
        }
    } else if (scanline >= 144 && scanline < 154) { // Mode 1
        V_blank(scanline);
        memoryBus[STAT] = (memoryBus[STAT] & 0xFC) | 0x01; // Mode 1
    }

    if (scanline == 153 && cycle == 0) {
        memoryBus[LY] = 0;
    } else if (cycle == 0) {
        memoryBus[LY]++;
    }

    if (memoryBus[LY] == memoryBus[LYC]) {
        memoryBus[STAT] |= 0x04;
        if (memoryBus[STAT] & 0x40) {
            memoryBus[IF] |= LCDC_INTR;
        }
    } else {
        memoryBus[STAT] &= ~0x04;
    }
}

void OAM_search(u8 scanline) {
    spriteCount = 0;
    for (int i = 0; i < OAM_SIZE; i += 4) {
        u8 yPosition = memoryBus[OAM_START + i];
        u8 xPosition = memoryBus[OAM_START + i + 1];
        u8 tileNumber = memoryBus[OAM_START + i + 2];
        u8 attributes = memoryBus[OAM_START + i + 3];

        int spriteSize = (memoryBus[LCDC] & 0x04) ? 16 : 8;
        if (yPosition <= scanline && (yPosition + spriteSize) > scanline) {
            sprites[spriteCount].pos.y = yPosition;
            sprites[spriteCount].pos.x = xPosition;
            sprites[spriteCount].tileIndex = tileNumber;
            sprites[spriteCount].f = attributes;

            spriteCount++;
            if (spriteCount >= MAX_SPRITES_PER_LINE) {
                break;
            }
        }
    }
}

Color getGBColor(u8 color) {
    switch (color) {
        case 0:
            return WHITE;
        case 1:
            return (Color){ 0xCC, 0xCC, 0xCC, 0xFF }; // Light gray (0xCCCCCC)
        case 2:
            return (Color){ 0x77, 0x77, 0x77, 0xFF }; // Dark gray (0x777777)
        case 3:
            return BLACK;
    }

    return BLACK;
}

void drawing(u8 scanline) {
    // Rendu du fond (simplifié pour cet exemple)
    for (int x = 0; x < GB_LCD_WIDTH; x++) {
        u8 tileIndex = memoryBus[0x9800 + (memoryBus[SCY] + scanline) / 8 * 32 + (memoryBus[SCX] + x) / 8];
        u8 tileLine = memoryBus[0x8000 + tileIndex * 16 + (memoryBus[SCY] + scanline) % 8 * 2];
        u8 tileLine2 = memoryBus[0x8000 + tileIndex * 16 + (memoryBus[SCY] + scanline) % 8 * 2 + 1];

        u8 color = ((tileLine >> (7 - ((memoryBus[SCX] + x) % 8))) & 1) | (((tileLine2 >> (7 - ((memoryBus[SCX] + x) % 8))) & 1) << 1);
        scanline_buffer[x][scanline] = getGBColor(color);
    }

    for (int i = 0; i < spriteCount; i++) {
        Sprite sprite = sprites[i];

        if (sprite.pos.y <= scanline && sprite.pos.y + SPRITE_HEIGHT > scanline) {
            u8 tileLine = memoryBus[0x8000 + sprite.tileIndex * 16 + (scanline - sprite.pos.y) % 8 * 2];
            u8 tileLine2 = memoryBus[0x8000 + sprite.tileIndex * 16 + (scanline - sprite.pos.y) % 8 * 2 + 1];

            for (int x = 0; x < sprite.pos.x; x++) {
                u8 color = ((tileLine >> (7 - x)) & 1) | (((tileLine2 >> (7 - x)) & 1) << 1);
                if (color == 0) {
                    continue;
                }

                Color c = getGBColor(color);
                if (sprite.f & 0x20) {
                    c = (Color){ c.r / 2, c.g / 2, c.b / 2, c.a };
                }

                scanline_buffer[sprite.pos.x + x][scanline] = c;
            }
        }
    }
}

void H_blank(u8 __attribute__((unused)) scanline) {
    // Rien à faire
}

void V_blank(u8 __attribute__((unused)) scanline) {
    // Rien à faire
}
