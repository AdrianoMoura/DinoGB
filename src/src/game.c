#include <gb/gb.h>
#include "../include/game.h"

BOOLEAN is_game_over = FALSE;
uint8_t speed = 1; // Set initial speed
uint8_t night = FALSE;

// Pallete transition for night and day effect
const uint8_t palette_normal[] = {
    0b11100100,
    0b10110001,
    0b01001110,
    0b00011011,
};

const uint8_t palette_inverted[] = {
    0b00011011,
    0b01001110,
    0b10110001,
    0b11100100,
};

#define NUM_STEPS 4

void night_transition(void)
{
    if (!night)
    {
        for (uint8_t i = 0; i < NUM_STEPS; i++)
        {
            BGP_REG = palette_normal[i];
            OBP0_REG = palette_normal[i];
            if (i == 2)
            {
                set_bkg_tiles(0u, 0u, BackgroundTileMapWidth, BackgroundTileMapHeight, BackgroundTileMapNight);
            }
            wait_vbl_done();
            delay(200);
        }
    }
    else
    {
        for (uint8_t i = 0; i < NUM_STEPS; i++)
        {
            BGP_REG = palette_inverted[i];
            OBP0_REG = palette_inverted[i];
            if (i == 2)
            {
                set_bkg_tiles(0u, 0u, BackgroundTileMapWidth, BackgroundTileMapHeight, BackgroundTileMapDay);
            }
            wait_vbl_done();
            delay(200);
        }
    }

    night = !night;
}

void initialize_game(void)
{
    set_bkg_data(0u, 17u, BackgroundTileSet);
    set_bkg_tiles(0u, 0u, BackgroundTileMapWidth, BackgroundTileMapHeight, BackgroundTileMapDay);

    SHOW_BKG;

    // Set LYC register to control paralax
    STAT_REG = 0x45;
    LYC_REG = 0;

    // Enable Sound
    NR52_REG = 0x80; // Turn on the sound system
    NR50_REG = 0x77; // Set max volume for both left and right
    NR51_REG = 0xFF; // Enable all sound channels

    config_parallax();

    SPRITES_8x8;

    set_dino();
    set_cactus();

    SHOW_SPRITES;

    DISPLAY_ON; // Turn on Display
}

void game_over(void)
{
    is_game_over = TRUE;

    speed = 0;

    NR10_REG = 0x1E; // Sweep: fast pitch rise
    NR11_REG = 0x10; // Duty cycle: 25%, Length: short
    NR12_REG = 0xF3; // Volume: max, Envelope: quick fade
    NR13_REG = 0x00; // Frequency low bits
    NR14_REG = 0x87; // Frequency high bits + start sound

    set_sprite_tile(SPRITE_DINO_HEAD_1, TILE_DINO_HEAD_1_GAME_OVER);
    set_sprite_tile(SPRITE_DINO_BODY_2, TILE_DINO_HEAD_2_GAME_OVER);
}

void restart_game(void)
{
    is_game_over = FALSE;
    frame_count = 0;
    speed = 1;

    dino_reset();
    parallax_reset();
}
