#include "sprites.h"

u16 frame=0;

void SPR_initSprite(Sprite * sprite,OamState* oamState, u8 * gfx, u8 frame_width, u8 frame_height, int delay_frame, int frames_per_animation){

    sprite->sprite_gfx_frame = oamAllocateGfx(oamState, SpriteSize_32x32, SpriteColorFormat_256Color);
    sprite->frame_gfx = (u8 *)gfx;
    sprite->frame_width = frame_width;
    sprite->frame_height = frame_height;
    sprite->delay_frame = delay_frame;
    sprite->frames_per_animation = frames_per_animation;
    sprite->frame = 0;
    sprite->anim = 0;
}

void SPR_update(Sprite* sprite){
    int size= sprite->frame_width * sprite->frame_height;
    int frame = sprite->frame + sprite->anim * sprite->frames_per_animation;
	u8 *offset = sprite->frame_gfx + frame * size;
	dmaCopy(offset, sprite->sprite_gfx_frame, size);
    frame++;

    if(frame % sprite->delay_frame == 0){
        sprite->frame++;
    }

    if(sprite->frame >= sprite->frames_per_animation){
        sprite->frame = 0;
    }


}

void SPR_setAnim(Sprite* sprite, int anim){
    sprite->anim = anim;
}

void SPR_setFrame(Sprite* sprite, int frame){
    sprite->frame = frame;
}
    
        
    
    