#ifndef CACTUS_H
#define CACTUS_H

#include <gb/gb.h>
#include "assets.h"

// Tile Position on Memory for each part of the Cactus Sprite
#define TILE_SMALL_CACTUS_0_0 7 + 10
#define TILE_SMALL_CACTUS_0_1 8 + 10
#define TILE_SMALL_CACTUS_1_1 9 + 10

#define TILE_BIG_CACTUS_0_0 0 + 10
#define TILE_BIG_CACTUS_0_1 2 + 10
#define TILE_BIG_CACTUS_0_2 1 + 10
#define TILE_BIG_CACTUS_1_0 4 + 10
#define TILE_BIG_CACTUS_1_1 3 + 10
#define TILE_BIG_CACTUS_1_2 5 + 10
#define TILE_BIG_CACTUS_2_1 6 + 10

// Sprite identification for each part of cactus body
#define SPRITE_SMALL_CACTUS_0_0 7
#define SPRITE_SMALL_CACTUS_0_1 8
#define SPRITE_SMALL_CACTUS_1_1 9

#define SPRITE_BIG_CACTUS_0_0 10
#define SPRITE_BIG_CACTUS_0_1 11
#define SPRITE_BIG_CACTUS_0_2 12
#define SPRITE_BIG_CACTUS_1_0 13
#define SPRITE_BIG_CACTUS_1_1 14
#define SPRITE_BIG_CACTUS_1_2 15
#define SPRITE_BIG_CACTUS_2_1 16

void set_cactus(void);
void update_cactus(void);

#endif
