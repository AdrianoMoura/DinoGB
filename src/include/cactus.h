#ifndef CACTUS_H
#define CACTUS_H

#include <gb/gb.h>
#include "../include/assets.h"
#include "../include/tiles.h"
#include "../include/sprites.h"
#include "../include/main.h"
#include "../include/game.h"
#include "../include/obstacle.h"

void set_cactus(void);
void render_small_cactus(uint8_t index, uint8_t sprite_index);
void render_big_cactus(uint8_t index, uint8_t sprite_index);

#endif
