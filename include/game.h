#ifndef GAME_H
#define GAME_H

#include <nds.h>

#include "player.h"
#include "input.h"
#include "engine.h"

enum GameState{
    SPLASH_SCREEN,
    MAIN_MENU,
    PLAYING,
    PAUSED,
    GAME_OVER
};

typedef struct{
    u8 currentState;
    Player player;
    InputHanlder inputHandler;
    u32 frame;
}Game;


void initGame(Game*);
void updateGame(Game*);
void drawGame(Game*);

void initMenu(Game*);
void updateMenu(Game*);
void drawMenu(Game*);

void loadNextState(Game*, u8);

#endif