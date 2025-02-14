
#include "engine.h"
#include "input.h"
#include "player.h"

#include "elliready.h"
#include "level1-1.h"
#include "level1-2.h"

Player player;
Sprite elli = {0, 0};
u32 frame = 0;

InputHanlder inputHandler;

int main(void)
{

    INPUT_initHandler(&inputHandler);
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_5_2D);

    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankB(VRAM_B_MAIN_SPRITE);
    vramSetBankC(VRAM_C_SUB_BG);

    bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
    bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

    decompress(level1_1Bitmap, BG_GFX, LZ77Vram);
    decompress(level1_2Bitmap, BG_GFX_SUB, LZ77Vram);

    oamInit(&oamMain, SpriteMapping_1D_128, false);

    initSprite(&elli, (u8 *)ellireadyTiles);
    PLYR_init(&player, (Vector2D){32, 32});
    dmaCopy(ellireadyPal, SPRITE_PALETTE, 512);
    elli.anim_frame = 0;
    elli.state = IDLE;
    player.entity.velocity.x = 0;
    player.entity.velocity.y = 0;
    player.sprite = elli;

    while (true)
    {

        INPUT_scanKeys(&inputHandler);

        if (inputHandler.keysHeld)
        {

            if (INPUT_keysHeld(&inputHandler, KEY_LEFT))
            {
                player.sprite.state = LEFT;
                player.entity.velocity.x = -2;
            }
            if (INPUT_keysHeld(&inputHandler, KEY_RIGHT))
            {
                player.sprite.state = RIGHT;
                player.entity.velocity.x = 2;
            }
            if (INPUT_keysDown(&inputHandler, KEY_A) && !PLYR_isJumping(&player))
            {
                player.sprite.state = IDLE;
                PLYR_jump(&player);
            }
        }
        else
        {
            player.sprite.state = IDLE;
            player.entity.velocity.x = 0;
            player.entity.velocity.y = 0;
        }

        PLYR_update(&player);

        animSprite(&player.sprite);
        oamSet(&oamMain, 0, player.entity.position.x, player.entity.position.y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color,
               player.sprite.sprite_gfx_frame, -1, false, false, false, false, false);

        frame++;
        if (frame % 5 == 0)
            player.sprite.anim_frame++;

        if (player.sprite.anim_frame >= FRAMES_PER_ANIMATION)
            player.sprite.anim_frame = 0;

        swiWaitForVBlank();
        oamUpdate(&oamMain);
    }

    return 0;
}