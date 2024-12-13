#include <gb/gb.h>
#include <rand.h>
#include "../include/obstacle.h"

Obstacle obstacle_pool[MAX_OBSTACLE]; // obstacle pool
uint8_t obstacle_spawn_timer = 0;
uint8_t obstacle_pointer = 0;
uint8_t obstacle_first_pointer = 0;
uint8_t count_active_obstacle = 0;
uint32_t obstacle_last_frame_count = 0;
uint8_t sprite_index_flag = 0;

void set_obstacle(void)
{
    set_cactus();
    set_bird();

    obstacle_spawn_timer = random_spawn();
}

void update_obstacle(void)
{
    if ((frame_count - obstacle_last_frame_count) % obstacle_spawn_timer == 0 && count_active_obstacle < MAX_OBSTACLE)
    {
        spawn_obstacle();
        obstacle_last_frame_count = frame_count;
    }

    for (uint8_t i = 0; i < MAX_OBSTACLE; i++)
    {
        if (obstacle_pool[i].active)
        {
            move_obstacle(i);

            if (obstacle_pool[i].type == SMALL_CACTUS)
            {
                render_small_cactus(i, obstacle_pool[i].sprite_index);
            }
            if (obstacle_pool[i].type == BIG_CACTUS) // Cactus
            {
                render_big_cactus(i, obstacle_pool[i].sprite_index);
            }
            else if (obstacle_pool[i].type == BIRD) // Bird
            {
                render_bird(i, obstacle_pool[i].sprite_index);
            }
        }
    }

    if (obstacle_pool[obstacle_first_pointer].active == 1 && obstacle_pool[obstacle_first_pointer].x < -30)
    {
        remove_obstacle();
    }
}

void move_obstacle(int8_t index)
{
    obstacle_pool[index].x -= speed;
}

void remove_obstacle(void)
{
    obstacle_pool[obstacle_first_pointer].active = 0;

    obstacle_first_pointer = (obstacle_first_pointer + 1) % MAX_OBSTACLE;
    count_active_obstacle--;
}

void spawn_obstacle(void)
{
    uint8_t type = (rand() % 3) + 1;
    uint16_t x = SCREENWIDTH + 10;

    if (type == SMALL_CACTUS) // Small Cactus
    {
        obstacle_pool[obstacle_pointer].y = 103;
    }
    else if (type == BIG_CACTUS) // Big Cactus
    {
        obstacle_pool[obstacle_pointer].y = 95;
    }
    else if (type == BIRD) // Bird
    {
        obstacle_pool[obstacle_pointer].y = 95;
    }

    obstacle_pool[obstacle_pointer].x = x;
    obstacle_pool[obstacle_pointer].type = type;
    obstacle_pool[obstacle_pointer].active = 1;
    obstacle_pool[obstacle_pointer].sprite_index = sprite_index_flag ? OBSTACLE_SPRITE_START_INDEX_1 : OBSTACLE_SPRITE_START_INDEX_2;

    obstacle_pointer = (obstacle_pointer + 1) % MAX_OBSTACLE;

    count_active_obstacle++;
    obstacle_spawn_timer = random_spawn();
    sprite_index_flag = !sprite_index_flag;
}

void obstacle_reset(void)
{
    obstacle_spawn_timer = random_spawn();
    obstacle_pointer = 0;
    obstacle_last_frame_count = 0;
    count_active_obstacle = 0;
    obstacle_first_pointer = 0;

    for (int i = 0; i < MAX_OBSTACLE; i++)
    {
        obstacle_pool[i].x = 0;
        obstacle_pool[i].y = 0;
        obstacle_pool[i].type = 0;
        obstacle_pool[i].active = 0;
    }
}

BOOLEAN check_collision(void)
{
    uint8_t d_x1 = dino_default_x + 16; // Check the point at the face of the Dino
    uint8_t d_x2 = dino_default_x + 6;  // Check the point at the face of the Dino

    uint8_t d_y = dino_y + 12; // Check the point at the feet of the dino

    uint8_t type = obstacle_pool[obstacle_first_pointer].type;

    uint8_t will_collide = 0;

    if (type == SMALL_CACTUS || type == BIG_CACTUS)
    {
        uint8_t cactus_width = obstacle_pool[obstacle_first_pointer].type == 1 ? 9 : 14;

        uint8_t cactus_x1 = obstacle_pool[obstacle_first_pointer].x;
        uint8_t cactus_x2 = obstacle_pool[obstacle_first_pointer].x + cactus_width;
        uint8_t cactus_y = obstacle_pool[obstacle_first_pointer].y;

        if (d_x1 > cactus_x1 && d_x2 < cactus_x2 && d_y > cactus_y)
        {
            return TRUE;
        }
    }

    if (type == BIRD)
    {
        uint8_t bird_width = 24u;

        uint8_t bird_x1 = obstacle_pool[obstacle_first_pointer].x + 10;
        uint8_t bird_x2 = obstacle_pool[obstacle_first_pointer].x + bird_width;
        uint8_t bird_y = obstacle_pool[obstacle_first_pointer].y;

        if (d_x1 > bird_x1 && d_x2 < bird_x2 && !is_down && d_y > bird_y)
        {
            return TRUE;
        }
    }

    return FALSE;
}