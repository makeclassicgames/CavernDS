#include "input.h"

void INPUT_initHandler(InputHanlder *handler)
{
    handler->keysPressed = 0;
    handler->keysHeld = 0;
}

void INPUT_scanKeys(InputHanlder *handler)
{
    scanKeys();
    handler->keysPressed = keysDown();
    handler->keysHeld = keysHeld();
}

u8 INPUT_keysHeld(InputHanlder *handler, u8 button)
{
    return handler->keysHeld & button;
}

u8 INPUT_keysDown(InputHanlder *handler, u8 button)
{
    return handler->keysPressed & button;
}