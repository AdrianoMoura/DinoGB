#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <gb/gb.h>
#include "../include/game.h"

typedef struct
{
    int16_t x;
    uint8_t y;
    uint8_t type; // 1 - Small Cactus / 2 - Big Cactus / 3 - Bird
    uint8_t active;
    uint8_t sprite_index;
} Obstacle;

#define MAX_OBSTACLE 3 // Max number o obstacle at the same time

#define SMALL_CACTUS 1
#define BIG_CACTUS 2
#define BIRD 3

extern Obstacle obstacle_pool[MAX_OBSTACLE]; // obstacle pool
extern uint8_t obstacle_first_pointer;

void set_obstacle(void);
void initialize_obstacle(void);
void update_obstacle(void);
void move_obstacle(int8_t index);
void remove_obstacle(void);
void spawn_obstacle(void);
uint8_t obstacle_random_spawn(void);
void obstacle_reset(void);

BOOLEAN check_collision(void);

#endif
