#include <gb/gb.h>
#include <rand.h>
#include "../include/cactus.h"

Cactus cactus[MAX_CACTUS]; // cactus pool
uint8_t spawn_timer = 0;
uint8_t cactus_pointer = 0;
uint8_t cactus_first_pointer = 0;
uint8_t count_active_cactus = 0;
uint32_t last_frame_count = 0;

void set_cactus(void)
{
    set_sprite_data(19, 9, CactusTileSet);
    // Configure cactus sprites

    // set_sprite_tile(TILE_SMALL_CACTUS_0_0, SPRITE_SMALL_CACTUS_0_0);
    // set_sprite_tile(TILE_SMALL_CACTUS_0_1, SPRITE_SMALL_CACTUS_0_1);
    // set_sprite_tile(TILE_SMALL_CACTUS_1_1, SPRITE_SMALL_CACTUS_1_1);

    // set_sprite_tile(TILE_BIG_CACTUS_0_0, SPRITE_BIG_CACTUS_0_0);
    // set_sprite_tile(TILE_BIG_CACTUS_0_1, SPRITE_BIG_CACTUS_0_1);
    // set_sprite_tile(TILE_BIG_CACTUS_0_2, SPRITE_BIG_CACTUS_0_2);
    // set_sprite_tile(TILE_BIG_CACTUS_1_0, SPRITE_BIG_CACTUS_1_0);
    // set_sprite_tile(TILE_BIG_CACTUS_1_1, SPRITE_BIG_CACTUS_1_1);
    // set_sprite_tile(TILE_BIG_CACTUS_1_2, SPRITE_BIG_CACTUS_1_2);
    // set_sprite_tile(TILE_BIG_CACTUS_2_1, SPRITE_BIG_CACTUS_2_1);

    spawn_timer = random_spawn();
}

void update_cactus(void)
{
    if ((frame_count - last_frame_count) % spawn_timer == 0 && count_active_cactus < MAX_CACTUS)
    {
        spawn_cactus();
        last_frame_count = frame_count;
    }

    for (uint8_t i = 0; i < MAX_CACTUS; i++)
    {
        if (cactus[i].x > -14)
        {
            render_cactus(i);
        }
    }

    if (cactus[cactus_first_pointer].active == 1 && cactus[cactus_first_pointer].x < 0)
    {
        remove_cactus();
    }
}

void move_cactus(void)
{
    for (uint8_t i = 0; i < MAX_CACTUS; i++)
    {
        if (cactus[i].x > -14)
        {
            cactus[i].x -= speed;
        }
    }
}

void remove_cactus(void)
{
    cactus[cactus_first_pointer].active = 0;

    cactus_first_pointer = (cactus_first_pointer + 1) % MAX_CACTUS;
    count_active_cactus--;
}

void render_cactus(uint8_t index)
{
    uint8_t sprite_1 = SPRITE_START_INDEX + index * 6;
    uint8_t sprite_2 = SPRITE_START_INDEX + index * 6 + 1;
    uint8_t sprite_3 = SPRITE_START_INDEX + index * 6 + 2;
    uint8_t sprite_4 = SPRITE_START_INDEX + index * 6 + 3;
    uint8_t sprite_5 = SPRITE_START_INDEX + index * 6 + 4;
    uint8_t sprite_6 = SPRITE_START_INDEX + index * 6 + 5;

    if (cactus[index].cactus_type == 1) // Small cactus
    {
        set_sprite_tile(sprite_1, TILE_SMALL_CACTUS_0_0);
        set_sprite_tile(sprite_2, TILE_SMALL_CACTUS_0_1);
        set_sprite_tile(sprite_3, TILE_SMALL_CACTUS_1_1);

        move_sprite(sprite_1, cactus[index].x, cactus[index].y);
        move_sprite(sprite_2, cactus[index].x + 8u, cactus[index].y);
        move_sprite(sprite_3, cactus[index].x, cactus[index].y + 8u);
    }
    else if (cactus[index].cactus_type == 2) // Big Cactus
    {
        set_sprite_tile(sprite_1, TILE_BIG_CACTUS_0_0);
        set_sprite_tile(sprite_2, TILE_BIG_CACTUS_0_1);
        set_sprite_tile(sprite_3, TILE_BIG_CACTUS_1_0);
        set_sprite_tile(sprite_4, TILE_BIG_CACTUS_1_1);
        set_sprite_tile(sprite_5, TILE_BIG_CACTUS_2_1);
        set_sprite_tile(sprite_6, TILE_BIG_CACTUS_2_2);

        move_sprite(sprite_1, cactus[index].x, cactus[index].y);
        move_sprite(sprite_2, cactus[index].x + 8u, cactus[index].y);
        move_sprite(sprite_3, cactus[index].x, cactus[index].y + 8u);
        move_sprite(sprite_4, cactus[index].x + 8u, cactus[index].y + 8u);
        move_sprite(sprite_5, cactus[index].x, cactus[index].y + 16u);
        move_sprite(sprite_6, cactus[index].x + 8u, cactus[index].y + 16u);
    }
}

void spawn_cactus(void)
{
    uint8_t cactus_type = (rand() % 2) + 1;
    uint16_t cactus_x = SCREENWIDTH + 10;

    cactus[cactus_pointer].x = cactus_x;
    cactus[cactus_pointer].y = cactus_type == 1 ? 103 : 95;
    cactus[cactus_pointer].cactus_type = cactus_type;
    cactus[cactus_pointer].active = 1;

    cactus_pointer = (cactus_pointer + 1) % MAX_CACTUS;
    count_active_cactus++;
    spawn_timer = random_spawn();
}

uint8_t random_spawn(void)
{
    uint8_t random_number;

    random_number = rand() % (255 - 100 + 1) + 100;

    // Set the new random spawn to be next to the last one or greater than 100 pixels, prevent to spawn more than 2 cactus next to each other
    return random_number;
}

void cactus_reset(void)
{
    spawn_timer = random_spawn();
    cactus_pointer = 0;
    last_frame_count = 0;
    count_active_cactus = 0;
    cactus_first_pointer = 0;

    clear_sprites();

    for (int i = 0; i < MAX_CACTUS; i++)
    {
        cactus[i].x = 0;
        cactus[i].y = 0;
        cactus[i].cactus_type = 0;
        cactus[i].active = 0;
    }
}