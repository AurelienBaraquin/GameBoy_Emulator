#pragma once

typedef unsigned char u8;

#define MAX_SPRITES_PER_LINE 10
#define SPRITE_HEIGHT 8

typedef struct __attribute__((__packed__)) {
    struct {
        u8 x, y;
    } pos;
    u8 tileIndex;
    union {
        struct {
            u8 priority:1;
            u8 yFlip:1;
            u8 xFlip:1;
            u8 palette:1;
        } flags;
        u8 f;
    };
} Sprite;

extern Sprite sprites[MAX_SPRITES_PER_LINE];
extern u8 spriteCount;
