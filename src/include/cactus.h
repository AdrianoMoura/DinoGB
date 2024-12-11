#ifndef CACTUS_H
#define CACTUS_H

#include <gb/gb.h>
#include "assets.h"
#include "../include/game.h"

typedef struct
{
    int16_t x;
    uint8_t y;
    uint8_t cactus_type;
    uint8_t active;
} Cactus;

#define MAX_CACTUS 3       // Max number o cacti at the same time
#define SPAWN_INTERVAL 120 // Spawn interval

extern Cactus cactus[MAX_CACTUS]; // cactus pool
extern uint8_t cactus_first_pointer;

// Tile Position on Memory for each part of the Cactus Sprite
// 16 are the total position reserved for the Dino Sprite
#define TILE_SMALL_CACTUS_0_0 6 + 16
#define TILE_SMALL_CACTUS_0_1 7 + 16
#define TILE_SMALL_CACTUS_1_1 8 + 16

#define TILE_BIG_CACTUS_0_0 0 + 16
#define TILE_BIG_CACTUS_0_1 1 + 16
#define TILE_BIG_CACTUS_1_0 2 + 16
#define TILE_BIG_CACTUS_1_1 3 + 16
#define TILE_BIG_CACTUS_2_1 4 + 16
#define TILE_BIG_CACTUS_2_2 5 + 16

#define SPRITE_START_INDEX 11
#define MIN_DISTANCE 200
#define MAX_RAND_DISTANCE 100

void set_cactus(void);
void initialize_cactus(void);
void update_cactus(void);
void move_cactus(void);
void remove_cactus(void);
void render_cactus(uint8_t index);
void spawn_cactus(void);
uint8_t random_spawn(void);
void cactus_reset(void);

#endif
