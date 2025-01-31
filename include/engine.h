
#ifndef _H_SPRITE
#define _H_SPRITE

#include <nds.h>

#define FRAMES_PER_ANIMATION 3

typedef struct{

    int x;
    int y;
    int velx;
    int vely;
    u16* sprite_gfx_frame;
    u8* frame_gfx;
    int state;
    int anim_frame;
}Sprite;

enum SpriteState{UP=0,DOWN=2,LEFT=3,RIGHT=1,IDLE=4};

void animSprite(Sprite*);
void initSprite(Sprite *, u8*);
#endif