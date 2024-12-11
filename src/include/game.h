#ifndef GAME_H
#define GAME_H

#include <gb/gb.h>
#include "sound.h"
#include "assets.h"
#include "main.h"
#include "dino.h"

extern BOOLEAN is_game_over;
extern uint8_t speed;

void initialize_game(void);
void game_over(void);
void restart_game(void);
void night_transition(void);
void pause(void);
void unpause(void);

#endif
