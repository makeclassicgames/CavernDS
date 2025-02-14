#ifndef PLAYER_H
#define PLAYER_H

#include <nds.h>
#include "engine.h"

#define JUMP_FORCE 18
#define GRAVITY 1

typedef struct
{
    u8 lives;
    u8 score;
    u8 level;
    Entity entity;
    Sprite sprite;
    u8 isJumping;
} Player;

void PLYR_init(Player *, Vector2D);
void PLYR_setVelocity(Player *, Vector2D);
void PLYR_jump(Player *);
void PLYR_update(Player *);
void PLYR_draw(Player *);
u8 PLYR_isJumping(Player *);
#endif