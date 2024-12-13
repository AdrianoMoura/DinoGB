#ifndef GAME_H
#define GAME_H

#include <gb/gb.h>
#include "../include/assets.h"
#include "../include/tiles.h"
#include "../include/sprites.h"
#include "../include/main.h"
#include "../include/dino.h"
#include "../include/cactus.h"
#include "../include/bird.h"
#include "../include/parallax.h"
#include "../include/sound.h"

extern BOOLEAN is_game_over;
extern uint8_t speed;
extern uint8_t max_speed;
extern uint16_t score;
extern uint16_t highscore;

#define MIN_SPEED 2


void main_screen(void);
void initialize_game(void);
void game_over(void);
void restart_game(void);
void night_transition(void);
void pause(void);
void unpause(void);
void clear_sprites(void);
void draw_score(void);
void draw_highscore(void);

uint8_t random_spawn(void);

#endif
