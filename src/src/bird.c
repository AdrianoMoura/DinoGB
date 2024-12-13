#include <gb/gb.h>
#include "../include/bird.h"

uint8_t bird_anim_flag = 1;

void set_bird(void)
{
    set_sprite_data(FIRST_BIRD_TILE_INDEX, COUNT_BIRD_TILE, BirdTileSet);
}

void render_bird(uint8_t index, uint8_t sprite_index)
{
    uint8_t sprite_1 = sprite_index + 0;
    uint8_t sprite_2 = sprite_index + 1;
    uint8_t sprite_3 = sprite_index + 2;
    uint8_t sprite_4 = sprite_index + 3;

    set_sprite_tile(sprite_1, TILE_BIRD_HEAD);
    set_sprite_tile(sprite_3, TILE_BIRD_TAIL);

    if (frame_count % 5 == 0)
    {
        if (bird_anim_flag)
        {
            // Bird Frame of animation wing down
            set_sprite_tile(sprite_4, TILE_BIRD_WING_DOWN);
            set_sprite_tile(sprite_2, TILE_BIRD_BODY_WING_DOWN);

            move_sprite(sprite_1, obstacle_pool[index].x, obstacle_pool[index].y);
            move_sprite(sprite_2, obstacle_pool[index].x + 8u, obstacle_pool[index].y);
            move_sprite(sprite_3, obstacle_pool[index].x + 16u, obstacle_pool[index].y);
            move_sprite(sprite_4, obstacle_pool[index].x + 8u, obstacle_pool[index].y + 8u);
        }
        else
        {
            set_sprite_tile(sprite_2, TILE_BIRD_BODY_WING_UP);
            set_sprite_tile(sprite_4, TILE_BIRD_WING_UP);

            move_sprite(sprite_1, obstacle_pool[index].x, obstacle_pool[index].y);
            move_sprite(sprite_2, obstacle_pool[index].x + 8u, obstacle_pool[index].y);
            move_sprite(sprite_3, obstacle_pool[index].x + 16u, obstacle_pool[index].y);
            move_sprite(sprite_4, obstacle_pool[index].x + 8u, obstacle_pool[index].y - 8u);
        }

        bird_anim_flag = !bird_anim_flag;
    }
}
