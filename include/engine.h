
#ifndef _H_SPRITE
#define _H_SPRITE

#include <nds.h>

#include "physics.h"
#include "sprites.h"

#define FRAMES_PER_ANIMATION 3

#define MAX_ENTITIES 64

typedef struct
{
    u16 id;
    Vector2D position;
    Vector2D velocity;
} Entity;

//TODO: Add ECS Structure

typedef struct{
    Entity entities[MAX_ENTITIES];
    u16 numEntities;
}ECS;

//TODO: Add ECS Functions

void ECS_init(ECS*);
u16 ECS_createEntity(ECS*, Vector2D, Vector2D);
void ECS_destroyEntity(ECS*, u16);
Entity* ECS_getEntity(ECS*, u16);
void ECS_setEntity(ECS*, u16, Entity);


#endif