#include <gb/gb.h>
#include <rand.h>
#include "../include/cactus.h"

void set_cactus(void)
{
    set_sprite_data(FIRST_CACTUS_TILE_INDEX, COUNT_CACTUS_TILE, CactusTileSet);
}

void render_small_cactus(uint8_t index, uint8_t sprite_index)
{
    uint8_t sprite_1 = sprite_index + 0;
    uint8_t sprite_2 = sprite_index + 1;
    uint8_t sprite_3 = sprite_index + 2;

    set_sprite_tile(sprite_1, TILE_SMALL_CACTUS_0_0);
    set_sprite_tile(sprite_2, TILE_SMALL_CACTUS_0_1);
    set_sprite_tile(sprite_3, TILE_SMALL_CACTUS_1_1);

    move_sprite(sprite_1, obstacle_pool[index].x, obstacle_pool[index].y);
    move_sprite(sprite_2, obstacle_pool[index].x + 8u, obstacle_pool[index].y);
    move_sprite(sprite_3, obstacle_pool[index].x, obstacle_pool[index].y + 8u);
}

void render_big_cactus(uint8_t index, uint8_t sprite_index)
{
    uint8_t sprite_1 = sprite_index + 0;
    uint8_t sprite_2 = sprite_index + 1;
    uint8_t sprite_3 = sprite_index + 2;
    uint8_t sprite_4 = sprite_index + 3;
    uint8_t sprite_5 = sprite_index + 4;
    uint8_t sprite_6 = sprite_index + 5;

    set_sprite_tile(sprite_1, TILE_BIG_CACTUS_0_0);
    set_sprite_tile(sprite_2, TILE_BIG_CACTUS_0_1);
    set_sprite_tile(sprite_3, TILE_BIG_CACTUS_1_0);
    set_sprite_tile(sprite_4, TILE_BIG_CACTUS_1_1);
    set_sprite_tile(sprite_5, TILE_BIG_CACTUS_2_1);
    set_sprite_tile(sprite_6, TILE_BIG_CACTUS_2_2);

    move_sprite(sprite_1, obstacle_pool[index].x, obstacle_pool[index].y);
    move_sprite(sprite_2, obstacle_pool[index].x + 8u, obstacle_pool[index].y);
    move_sprite(sprite_3, obstacle_pool[index].x, obstacle_pool[index].y + 8u);
    move_sprite(sprite_4, obstacle_pool[index].x + 8u, obstacle_pool[index].y + 8u);
    move_sprite(sprite_5, obstacle_pool[index].x, obstacle_pool[index].y + 16u);
    move_sprite(sprite_6, obstacle_pool[index].x + 8u, obstacle_pool[index].y + 16u);
}
