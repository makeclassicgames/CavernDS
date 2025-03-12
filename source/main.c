
#include "engine.h"
#include "game.h"
#include "input.h"
#include "player.h"

#include "elliready.h"
#include "level1-1.h"
#include "level1-2.h"


Game game;


void init(void);
void update(void);
void draw(void);

int main(void)
{

   
    init();
    loadNextState(&game, PLAYING);
   
    oamInit(&oamMain, SpriteMapping_1D_128, false);

    
    
    dmaCopy(ellireadyPal, SPRITE_PALETTE, 512);
  

    while (true)
    {

        INPUT_scanKeys(&game.inputHandler);
        update();
        draw();
        swiWaitForVBlank();
        oamUpdate(&oamMain);
    }

    return 0;
}

void init(void)
{
    INPUT_initHandler(&game.inputHandler);
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_5_2D);

    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankB(VRAM_B_MAIN_SPRITE);
    vramSetBankC(VRAM_C_SUB_BG);

    bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
    bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
}

void update(void)
{
    switch (game.currentState)
    {
    case MAIN_MENU:
        updateMenu(&game);
        break;
    case PLAYING:

    updateGame(&game);

    
    break;
    default:
        break;
    }
}

void draw(void)
{
    switch (game.currentState)
    {
    case MAIN_MENU:
        drawMenu(&game);
        break;
    case PLAYING:
    drawGame(&game);
        break;
    
    default:
        break;
    }
}