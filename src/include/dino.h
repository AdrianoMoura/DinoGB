#ifndef DINO_H
#define DINO_H

#include <gb/gb.h>
#include "assets.h"
#include "sound.h"
#include "main.h"

// Tile Position on Memory for each part of the Dino Sprite
#define TILE_DINO_HEAD_1 0
#define TILE_DINO_HEAD_2 1
#define TILE_DINO_BODY_1 2
#define TILE_DINO_BODY_2 3
#define TILE_DINO_BODY_3 4

#define TILE_DINO_FOOT_LEFT_FLOOR 5
#define TILE_DINO_FOOT_LEFT_UP 7

#define TILE_DINO_FOOT_RIGHT_FLOOR 6
#define TILE_DINO_FOOT_RIGHT_UP 8

#define TILE_DINO_HEAD_1_GAME_OVER 9
#define TILE_DINO_HEAD_2_GAME_OVER 10

// Sprite identification for each part of body
#define SPRITE_DINO_HEAD_1 0
#define SPRITE_DINO_HEAD_2 1
#define SPRITE_DINO_BODY_1 2
#define SPRITE_DINO_BODY_2 3
#define SPRITE_DINO_BODY_3 4

#define SPRITE_DINO_FOOT_LEFT 5
#define SPRITE_DINO_FOOT_RIGHT 6

void set_dino(void);
void update_dino(void);
void animate_dino(void);
void check_jump(void);
void dino_reset(void);

#endif
