#include "engine.h"
#include "physics.h"
#include <stdio.h>

// void animSprite(Sprite *sprite)
// {
// 	int frame = sprite->anim_frame + sprite->state * sprite->frames_per_animation;
// 	u8 *offset = sprite->frame_gfx + frame * 32 * 32;
// 	dmaCopy(offset, sprite->sprite_gfx_frame, 32 * 32);
// }
// void initSprite(Sprite *sprite, u8 *gfx)
// {

// 	sprite->sprite_gfx_frame = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

// 	sprite->frame_gfx = (u8 *)gfx;
// }
