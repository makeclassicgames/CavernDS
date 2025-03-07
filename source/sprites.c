#include "sprites.h"

u16 frame=0;

void SPR_initSprite(Sprite * sprite,OamState* oamState, u8 * gfx, u8 frame_width, u8 frame_height, int delay_frame, int frames_per_animation){

    sprite->sprite_gfx_frame = oamAllocateGfx(oamState, SpriteSize_32x32, SpriteColorFormat_256Color);
    sprite->frame_gfx = (u8 *)gfx;
    sprite->frame_width = frame_width;
    sprite->frame_height = frame_height;
    sprite->delay_frame = delay_frame;
    sprite->frames_per_animation = frames_per_animation;
    sprite->anim_frame = 0;
    sprite->direction = 0;
}

void SPR_update(Sprite* sprite){
    int size= sprite->frame_width * sprite->frame_height;
    int frame = sprite->anim_frame + sprite->direction * sprite->frames_per_animation;
	u8 *offset = sprite->frame_gfx + frame * size;
	dmaCopy(offset, sprite->sprite_gfx_frame, size);
    frame++;

    if(frame % sprite->delay_frame == 0){
        sprite->anim_frame++;
    }

    if(sprite->anim_frame >= sprite->frames_per_animation){
        sprite->anim_frame = 0;
    }


}
    
        
    
    