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
u16 nextId = 0;

void ECS_init(ECS *ecs)
{
    ecs->numEntities = 0;
}

u16 ECS_createEntity(ECS *ecs, Vector2D position, Vector2D velocity)
{
    if (ecs->numEntities < MAX_ENTITIES)
    {
        nextId++;
        ecs->entities[ecs->numEntities].id = nextId;
        ecs->entities[ecs->numEntities].position = position;
        ecs->entities[ecs->numEntities].velocity = velocity;
        
        return nextId;
    }
    return -1;
}

void ECS_destroyEntity(ECS *ecs, u16 id)
{
    for (int i = 0; i < ecs->numEntities; i++)
    {
        if (ecs->entities[i].id == id)
        {
            for (int j = i; j < ecs->numEntities - 1; j++)
            {
                ecs->entities[j] = ecs->entities[j + 1];
            }
            ecs->numEntities--;
            return;
        }
    }
}

Entity *ECS_getEntity(ECS *ecs, u16 id)
{
    for (int i = 0; i < ecs->numEntities; i++)
    {
        if (ecs->entities[i].id == id)
        {
            return &ecs->entities[i];
        }
    }
    return NULL;
}

void ECS_setEntity(ECS *ecs, u16 id, Entity entity)
{
    for (int i = 0; i < ecs->numEntities; i++)
    {
        if (ecs->entities[i].id == id)
        {
            ecs->entities[i] = entity;
            return;
        }
    }
}