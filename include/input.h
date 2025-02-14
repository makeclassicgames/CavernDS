#ifndef INPUT_H
#define INPUT_H

#include <nds.h>

typedef struct
{
    u32 keysPressed;
    u32 keysHeld;
} InputHanlder;

void INPUT_initHandler(InputHanlder *);
void INPUT_scanKeys(InputHanlder *);
u8 INPUT_keysHeld(InputHanlder *, u8);
u8 INPUT_keysDown(InputHanlder *, u8);

#endif