
#include "levels.h"

void initLevel(Level *level, int **tilesScreen1, u8 compressedS1, int **tilesScreen2, u8 compressedS2)
{
    level->screen1.tiles = tilesScreen1;
    level->screen1.compressed = compressedS1;
    level->screen2.tiles = tilesScreen2;
    level->screen2.compressed = compressedS2;
}

void drawLevel(Level *level)
{
    if (level->screen1.compressed)
    {
        decompress(level->screen1.tiles, BG_GFX, LZ77Vram);
    }
    else
    {
        dmaCopy(level->screen1.tiles, BG_GFX, 256 * 192 * 2);
    }

    if (level->screen2.compressed)
    {
        decompress(level->screen2.tiles, BG_GFX_SUB, LZ77Vram);
    }
    else
    {
        dmaCopy(level->screen2.tiles, BG_GFX_SUB, 256 * 192 * 2);
    }
}