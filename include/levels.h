#ifndef LEVELS_H
#define LEVELS_H

#include <nds.h>

#include "engine.h"

//TODO: Add Level Structure



typedef struct{

    Screen screen1;
    Screen screen2;
    Ecs ecs;
}Level;

typedef struct{
    int** tiles;
    u8 compressed;
}Screen;

void initLevel(Level*, int** tilesScreen1, u8 compressedS1, int **tilesScreen2, u8 compressedS2);
void drawLevel(Level*);
#endif