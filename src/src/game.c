#include <gb/gb.h>
#include <rand.h>
#include "../include/game.h"

BOOLEAN is_game_over = FALSE;
uint8_t speed = MIN_SPEED; // initial speed
uint8_t max_speed = 5;
uint8_t last_speed = 1;
uint8_t night = FALSE;

uint16_t score = 0;
uint16_t highscore = 0;

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

void main_screen(void)
{
    set_sprite_data(CHARACTER_TILE_START_INDEX, COUNT_CHARACTER_TILE, CharacterTileSet);

    set_sprite_tile(LETTER_1_SPRITE, P_TILE);
    set_sprite_tile(LETTER_2_SPRITE, R_TILE);
    set_sprite_tile(LETTER_3_SPRITE, E_TILE);
    set_sprite_tile(LETTER_4_SPRITE, S_TILE);
    set_sprite_tile(LETTER_5_SPRITE, S_TILE);

    set_sprite_tile(LETTER_6_SPRITE, A_TILE);
    set_sprite_tile(LETTER_7_SPRITE, N_TILE);
    set_sprite_tile(LETTER_8_SPRITE, Y_TILE);

    set_sprite_tile(LETTER_9_SPRITE, K_TILE);
    set_sprite_tile(LETTER_10_SPRITE, E_TILE);
    set_sprite_tile(LETTER_11_SPRITE, Y_TILE);

    move_sprite(LETTER_1_SPRITE, 60, 5 * 10u);
    move_sprite(LETTER_2_SPRITE, 68, 5 * 10u);
    move_sprite(LETTER_3_SPRITE, 76, 5 * 10u);
    move_sprite(LETTER_4_SPRITE, 84, 5 * 10u);
    move_sprite(LETTER_5_SPRITE, 92, 5 * 10u);

    move_sprite(LETTER_6_SPRITE, 68, 6 * 10u);
    move_sprite(LETTER_7_SPRITE, 76, 6 * 10u);
    move_sprite(LETTER_8_SPRITE, 84, 6 * 10u);

    move_sprite(LETTER_9_SPRITE, 68, 7 * 10u);
    move_sprite(LETTER_10_SPRITE, 76, 7 * 10u);
    move_sprite(LETTER_11_SPRITE, 84, 7 * 10u);
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
    set_obstacle();

    SHOW_SPRITES;

    DISPLAY_ON; // Turn on Display
}

void night_transition(void)
{
    pause();
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

    unpause();
    night = !night;
}

void pause(void)
{
    last_speed = speed;
    speed = 0;
}

void unpause(void)
{
    speed = last_speed;
}

void game_over(void)
{
    is_game_over = TRUE;

    if (score > highscore)
    {
        highscore = score;
    }

    speed = 0;
    score = 0;

    play_game_over_sound();
    dino_game_over();

    set_sprite_tile(LETTER_1_SPRITE, G_TILE);
    set_sprite_tile(LETTER_2_SPRITE, A_TILE);
    set_sprite_tile(LETTER_3_SPRITE, M_TILE);
    set_sprite_tile(LETTER_4_SPRITE, E_TILE);

    set_sprite_tile(LETTER_5_SPRITE, O_TILE);
    set_sprite_tile(LETTER_6_SPRITE, V_TILE);
    set_sprite_tile(LETTER_7_SPRITE, E_TILE);
    set_sprite_tile(LETTER_8_SPRITE, R_TILE);

    move_sprite(LETTER_1_SPRITE, 72, 5 * 10u);
    move_sprite(LETTER_2_SPRITE, 80, 5 * 10u);
    move_sprite(LETTER_3_SPRITE, 88, 5 * 10u);
    move_sprite(LETTER_4_SPRITE, 96, 5 * 10u);

    move_sprite(LETTER_5_SPRITE, 72, 6 * 10u);
    move_sprite(LETTER_6_SPRITE, 80, 6 * 10u);
    move_sprite(LETTER_7_SPRITE, 88, 6 * 10u);
    move_sprite(LETTER_8_SPRITE, 96, 6 * 10u);

    delay(500);
}

void restart_game(void)
{
    is_game_over = FALSE;
    frame_count = 0;
    speed = MIN_SPEED;

    clear_sprites();

    draw_highscore();

    dino_reset();
    obstacle_reset();
    parallax_reset();
}

void clear_sprites(void)
{
    for (uint8_t i = 8; i < 35; i++)
    {
        set_sprite_tile(i, 0);
        move_sprite(i, 0, 0);
    }
}

void draw_score(void)
{
    // draw score
    uint16_t remaining_score = score;
    uint8_t count = 0;

    if (remaining_score > 0)
    {
        while (remaining_score > 0)
        {
            uint8_t last_digit = remaining_score % 10;

            set_sprite_tile(SCORE_SPRITE_OFFSET - count, NUMBER_CHARACTERS_OFFSET + last_digit);
            move_sprite(SCORE_SPRITE_OFFSET - count, SCREENWIDTH - count * 7 - 6, 20);

            remaining_score = remaining_score / 10;
            count++;
        }
    }
}

void draw_highscore(void)
{
    // draw highscore
    uint16_t remaining_score = highscore;
    uint8_t count = 0;

    uint16_t divisor = 1;

    while (remaining_score / divisor >= 10)
    {
        divisor *= 10;
    }

    while (divisor > 0)
    {
        uint16_t digit = remaining_score / divisor;

        set_sprite_tile(HIGHSCORE_SPRITE_OFFSET - count, NUMBER_CHARACTERS_OFFSET + digit);
        move_sprite(HIGHSCORE_SPRITE_OFFSET - count, 19 + count * 7 - 6, 20);

        remaining_score %= divisor;
        divisor /= 10;             
        count++;
    }
}

uint8_t random_spawn(void)
{
    uint8_t random_number;

    random_number = rand() % (150 - 50 + 1) + 50;

    // Set the new random spawn to be next to the last one or greater than 100 pixels, prevent to spawn more than 2 cactus next to each other
    return random_number;
}