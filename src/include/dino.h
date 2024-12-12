#ifndef DINO_H
#define DINO_H

#include <gb/gb.h>
#include "assets.h"
#include "sound.h"
#include "main.h"

// Tile Position on Memory for each part of the Dino Sprite
#define TILE_DINO_HEAD_1 1
#define TILE_DINO_HEAD_2 2
#define TILE_DINO_BODY_1 3
#define TILE_DINO_BODY_2 4
#define TILE_DINO_BODY_3 5

#define TILE_DINO_FOOT_LEFT_FLOOR 6
#define TILE_DINO_FOOT_LEFT_UP 8

#define TILE_DINO_FOOT_RIGHT_FLOOR 7
#define TILE_DINO_FOOT_RIGHT_UP 9

#define TILE_DINO_HEAD_1_GAME_OVER 10
#define TILE_DINO_HEAD_2_GAME_OVER 11

// When Dino is Down
#define TILE_DINO_DOWN_BODY_1 12
#define TILE_DINO_DOWN_HEAD_1 13
#define TILE_DINO_DOWN_HEAD_2 14
#define TILE_DINO_DOWN_HEAD_3 16
#define TILE_DINO_DOWN_HEAD_4 17
#define TILE_DINO_DOWN_FOOT_RIGHT_FLOOR 15
#define TILE_DINO_DOWN_FOOT_RIGHT_UP 18

// Sprite identification for each part of body
#define SPRITE_DINO_HEAD_1 0
#define SPRITE_DINO_HEAD_2 1
#define SPRITE_DINO_BODY_1 2
#define SPRITE_DINO_BODY_2 3
#define SPRITE_DINO_BODY_3 4

#define SPRITE_DINO_FOOT_LEFT 5
#define SPRITE_DINO_FOOT_RIGHT 6

// Sprite when is down
#define SPRITE_DINO_DOWN_BODY_1 2
#define SPRITE_DINO_DOWN_BODY_2 3
#define SPRITE_DINO_DOWN_HEAD_1 4
#define SPRITE_DINO_DOWN_HEAD_2 7
#define SPRITE_DINO_DOWN_HEAD_3 0
#define SPRITE_DINO_DOWN_HEAD_4 1

#define SPRITE_DINO_DOWN_FOOT_LEFT 5
#define SPRITE_DINO_DOWN_FOOT_RIGHT 6

extern uint8_t dino_default_x;
extern uint8_t dino_default_y;
extern uint8_t dino_y;
extern uint8_t is_down;

void set_dino(void);
void update_dino(void);
void animate_dino(void);
void check_jump(void);
void check_down(void);
void dino_reset(void);

#endif
