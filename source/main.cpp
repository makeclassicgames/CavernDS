
#include <nds.h>
#include "engine.h"

#include "elliready.h"
#include "level1-1.h"
#include "level1-2.h"

Sprite elli={0,0};
u32 frame=0;

int main(void){

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

    initSprite(&elli, (u8*)ellireadyTiles);
    dmaCopy(ellireadyPal, SPRITE_PALETTE, 512);
    elli.anim_frame=0;
    elli.state=IDLE;
    elli.velx=0;
    elli.vely=0;

    while(true){

        scanKeys();

		int keys = keysHeld();

        if(keys & KEY_START) break;
            
        if(keys){

            if(keys & KEY_UP){
                elli.state=UP;
                elli.vely=-2;

            }
            if(keys & KEY_DOWN){
                elli.state=DOWN;
                elli.vely=2;
            }

            if(keys & KEY_LEFT){
                elli.state=LEFT;
                elli.velx=-2;
            }
            if(keys & KEY_RIGHT){
                elli.state=RIGHT;
                elli.velx=2;
            }
        }else{
            elli.state=IDLE;
            elli.velx=0;
            elli.vely=0;
        }
   
        elli.x+=elli.velx;
        elli.y+=elli.vely;

        animSprite(&elli);
        oamSet(&oamMain, 0, elli.x, elli.y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color, 
			elli.sprite_gfx_frame, -1, false, false, false, false, false);
        
        frame++;
        if(frame%5==0)
            elli.anim_frame++;

        if(elli.anim_frame>=FRAMES_PER_ANIMATION) elli.anim_frame=0;

        swiWaitForVBlank();
        oamUpdate(&oamMain);
    }

    return 0;

}