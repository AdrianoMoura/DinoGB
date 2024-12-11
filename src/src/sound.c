#include <gb/gb.h>
#include "../include/sound.h"

void play_jump_sound(void) {
    NR10_REG = 0x16;
    NR11_REG = 0x40;
    NR12_REG = 0x73;
    NR13_REG = 0x30;
    NR14_REG = 0xC6;
}

void play_game_over_sound(void) {
    NR10_REG = 0x1E;
    NR11_REG = 0x10;
    NR12_REG = 0xF3;
    NR13_REG = 0x00;
    NR14_REG = 0x87;
}
