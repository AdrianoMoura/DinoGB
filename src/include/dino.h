#ifndef DINO_H
#define DINO_H

#include <gb/gb.h>
#include "../include/assets.h"
#include "../include/tiles.h"
#include "../include/sprites.h"
#include "../include/main.h"

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
void dino_game_over(void);

#endif
