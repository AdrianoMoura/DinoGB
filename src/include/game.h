#ifndef GAME_H
#define GAME_H

#include <gb/gb.h>
#include "assets.h"
#include "sound.h"
#include "main.h"
#include "dino.h"

extern BOOLEAN is_game_over;
extern uint8_t speed;
extern uint8_t max_speed;
extern uint32_t score;

#define MIN_SPEED 2

#define P_TILE 1 + 24
#define R_TILE 2 + 24
#define E_TILE 3 + 24
#define S_TILE 4 + 24
#define A_TILE 5 + 24
#define N_TILE 6 + 24
#define Y_TILE 7 + 24
#define K_TILE 8 + 24
#define G_TILE 9 + 24
#define M_TILE 10 + 24
#define O_TILE 11 + 24
#define V_TILE 12 + 24

#define NUMBER_CHARACTERS_OFFSET 13 + 24
#define NUMBER_SPRITE_OFFSET 39

#define LETTER_1_SPRITE 35 - 1
#define LETTER_2_SPRITE 35 - 2
#define LETTER_3_SPRITE 35 - 3
#define LETTER_4_SPRITE 35 - 4
#define LETTER_5_SPRITE 35 - 5

#define LETTER_6_SPRITE 35 - 6
#define LETTER_7_SPRITE 35 - 7
#define LETTER_8_SPRITE 35 - 8

#define LETTER_9_SPRITE 35 - 9
#define LETTER_10_SPRITE 35 - 10
#define LETTER_11_SPRITE 35 - 11

void main_screen(void);
void initialize_game(void);
void game_over(void);
void restart_game(void);
void night_transition(void);
void pause(void);
void unpause(void);
void check_collision(void);
void clear_sprites(void);
void draw_score(void);

#endif
