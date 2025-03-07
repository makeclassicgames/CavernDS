#include "game.h"
#include "input.h"
#include "player.h"

#include "elliready.h"
#include "logo.h"
#include "level1-1.h"
#include "level1-2.h"
#include "menu-logo.h"

void initGame(Game *game)
{
    game->frame = 0;
    Sprite elli = {0, 0};
    PLYR_init(&game->player, (Vector2D){32, 32});
   
    SPR_initSprite(&elli, &oamMain, (u8 *)ellireadyTiles, 32, 32, 5, 3);
    elli.anim_frame = 0;
    elli.direction = IDLE;
    // initSprite(&elli, (u8 *)ellireadyTiles);
    game->player.entity.velocity.x = 0;
    game->player.entity.velocity.y = 0;
    game->player.sprite = elli;
    decompress(level1_1Bitmap, BG_GFX, LZ77Vram);
    decompress(level1_2Bitmap, BG_GFX_SUB, LZ77Vram);

}

void updateGame(Game *game)
{
    if (game->inputHandler.keysHeld)
    {

        if (INPUT_keysHeld(&game->inputHandler, KEY_LEFT))
        {
            game->player.sprite.direction = LEFT;
            game->player.entity.velocity.x = -2;
        }
        if (INPUT_keysHeld(&game->inputHandler, KEY_RIGHT))
        {
            game->player.sprite.direction = RIGHT;
            game->player.entity.velocity.x = 2;
        }
        if (INPUT_keysDown(&game->inputHandler, KEY_A) && !PLYR_isJumping(&game->player))
        {
            game->player.sprite.direction = IDLE;
            PLYR_jump(&game->player);
        }
    }
    else
    {
        game->player.sprite.direction = IDLE;
        game->player.entity.velocity.x = 0;
        game->player.entity.velocity.y = 0;
    }

    PLYR_update(&game->player);
}

void drawGame(Game *game)
{
    //animSprite(&game->player.sprite);
    SPR_update(&game->player.sprite);
    oamSet(&oamMain, 0, game->player.entity.position.x, game->player.entity.position.y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color,
           game->player.sprite.sprite_gfx_frame, -1, false, false, false, false, false);

    game->frame++;
    if (game->frame % 5 == 0)
        game->player.sprite.anim_frame++;

    if (game->player.sprite.anim_frame >= FRAMES_PER_ANIMATION)
        game->player.sprite.anim_frame = 0;
}

void initMenu(Game *game)
{
    decompress(logoBitmap, BG_GFX_SUB, LZ77Vram);
    decompress(menu_logoBitmap, BG_GFX, LZ77Vram);
} 


void updateMenu(Game* game){
    if(INPUT_keysDown(&game->inputHandler, KEY_START)){
        loadNextState(game, PLAYING);
    }
}

void loadNextState(Game *game, u8 state)
{
    switch (state)
    {
    case SPLASH_SCREEN:
        initMenu(game);
        break;
    case MAIN_MENU:
        initMenu(game);
        break;
    case PLAYING:
        initGame(game);
        break;
    case PAUSED:
        break;
    case GAME_OVER:
        break;
    }
    game->currentState = state;
}