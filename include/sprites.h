#ifndef SPRITES_H
#define SPRITES_H

#include <nds.h>

typedef struct
{

    u16 *sprite_gfx_frame;
    u8 *frame_gfx;
    int anim;
    int frame;
    int delay_frame;
    int frames_per_animation;
    u8 frame_width;
    u8 frame_height;
} Sprite;

enum SpriteState
{
    UP = 0,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 1,
    IDLE = 4
};



void animSprite(Sprite *);
void initSprite(Sprite *, u8 *);

void SPR_initSprite(Sprite *,OamState*, u8 *, u8, u8, int, int );
void SPR_update(Sprite*);
void SPR_setAnim(Sprite*, int);
void SPR_setFrame(Sprite*, int);

#endif