
#include "player.h"

void PLYR_init(Player *p, Vector2D pos)
{
    p->lives = 3;
    p->score = 0;
    p->level = 1;
    p->entity.id = 0;
    p->entity.position = pos;
    p->entity.velocity.x = 0;
    p->entity.velocity.y = 0;
    p->isJumping = FALSE;
}

void PLYR_setVelocity(Player *p, Vector2D v)
{
    p->entity.velocity.x = v.x;
    p->entity.velocity.y = v.y;
}

void PLYR_jump(Player *p)
{
    p->entity.velocity.y = -JUMP_FORCE;
    p->isJumping = TRUE;
}

void PLYR_update(Player *p)
{
    p->entity.velocity.y += GRAVITY;

    p->entity.position.y += p->entity.velocity.y;

    if (p->entity.position.y >= SCREEN_HEIGHT - 32)
    {
        p->entity.velocity.y = 0;
        p->isJumping = FALSE;
    }
    p->entity.position.x += p->entity.velocity.x;
    p->entity.velocity.x = 0;
    p->entity.velocity.y = 0;
}

u8 PLYR_isJumping(Player *p)
{
    return p->isJumping;
}