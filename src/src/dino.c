#include <gb/gb.h>
#include "../include/dino.h"

uint8_t dino_y;
uint8_t dino_default_x = 24u;
uint8_t dino_default_y = 95u;
uint8_t is_jumping = 0;
uint8_t jump_hold_time = 0;
uint8_t velocity_Y = 0;
uint8_t gravity = 1;
uint8_t is_down = 0;

uint8_t dino_anim_flag = 1;

void set_dino(void)
{
    dino_y = dino_default_y;

    set_sprite_data(FIRST_DINO_TILE_INDEX, COUNT_DINO_TILE, DinoTileSet);

    set_sprite_tile(SPRITE_DINO_HEAD_1, TILE_DINO_HEAD_1);
    set_sprite_tile(SPRITE_DINO_HEAD_2, TILE_DINO_HEAD_2);
    set_sprite_tile(SPRITE_DINO_BODY_1, TILE_DINO_BODY_1);
    set_sprite_tile(SPRITE_DINO_BODY_2, TILE_DINO_BODY_2);
    set_sprite_tile(SPRITE_DINO_BODY_3, TILE_DINO_BODY_3);
    set_sprite_tile(SPRITE_DINO_FOOT_LEFT, TILE_DINO_FOOT_LEFT_FLOOR);
    set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_FOOT_RIGHT_FLOOR);
}

void update_dino(void)
{
    if (frame_count % 5 == 0)
    {
        dino_anim_flag = !dino_anim_flag;
    }

    if (!is_down)
    {
        if (dino_anim_flag)
        {
            set_sprite_tile(SPRITE_DINO_FOOT_LEFT, TILE_DINO_FOOT_LEFT_UP);
            set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_FOOT_RIGHT_FLOOR);
        }
        else
        {
            set_sprite_tile(SPRITE_DINO_FOOT_LEFT, TILE_DINO_FOOT_LEFT_FLOOR);
            set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_FOOT_RIGHT_UP);
        }

        set_sprite_tile(SPRITE_DINO_DOWN_HEAD_2, 0);
        move_sprite(SPRITE_DINO_DOWN_HEAD_2, 0, 0);

        set_sprite_tile(SPRITE_DINO_HEAD_1, TILE_DINO_HEAD_1);
        set_sprite_tile(SPRITE_DINO_HEAD_2, TILE_DINO_HEAD_2);
        set_sprite_tile(SPRITE_DINO_BODY_1, TILE_DINO_BODY_1);
        set_sprite_tile(SPRITE_DINO_BODY_2, TILE_DINO_BODY_2);
        set_sprite_tile(SPRITE_DINO_BODY_3, TILE_DINO_BODY_3);

        move_sprite(SPRITE_DINO_HEAD_1, dino_default_x + 8u, dino_y);
        move_sprite(SPRITE_DINO_HEAD_2, dino_default_x + 16u, dino_y);
        move_sprite(SPRITE_DINO_BODY_1, dino_default_x, dino_y + 8u);
        move_sprite(SPRITE_DINO_BODY_2, dino_default_x + 8u, dino_y + 8u);
        move_sprite(SPRITE_DINO_BODY_3, dino_default_x + 16u, dino_y + 8u);
    }
    else
    {
        if (dino_anim_flag)
        {
            set_sprite_tile(SPRITE_DINO_FOOT_LEFT, TILE_DINO_FOOT_LEFT_UP);
            set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_DOWN_FOOT_RIGHT_FLOOR);
        }
        else
        {
            set_sprite_tile(SPRITE_DINO_FOOT_LEFT, TILE_DINO_FOOT_LEFT_FLOOR);
            set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_DOWN_FOOT_RIGHT_UP);
        }

        set_sprite_tile(SPRITE_DINO_DOWN_BODY_1, TILE_DINO_BODY_1);
        set_sprite_tile(SPRITE_DINO_DOWN_BODY_2, TILE_DINO_DOWN_BODY_1);
        set_sprite_tile(SPRITE_DINO_DOWN_HEAD_1, TILE_DINO_DOWN_HEAD_1);
        set_sprite_tile(SPRITE_DINO_DOWN_HEAD_2, TILE_DINO_DOWN_HEAD_2);
        set_sprite_tile(SPRITE_DINO_DOWN_HEAD_3, TILE_DINO_DOWN_HEAD_3);
        set_sprite_tile(SPRITE_DINO_DOWN_HEAD_4, TILE_DINO_DOWN_HEAD_4);

        move_sprite(SPRITE_DINO_DOWN_BODY_1, dino_default_x, dino_y + 8u);
        move_sprite(SPRITE_DINO_DOWN_BODY_2, dino_default_x + 8u, dino_y + 8u);
        move_sprite(SPRITE_DINO_DOWN_HEAD_1, dino_default_x + 16u, dino_y + 8u);
        move_sprite(SPRITE_DINO_DOWN_HEAD_2, dino_default_x + 24u, dino_y + 8u);
        move_sprite(SPRITE_DINO_DOWN_HEAD_3, dino_default_x + 16u, dino_y + 16u);
        move_sprite(SPRITE_DINO_DOWN_HEAD_4, dino_default_x + 24u, dino_y + 16u);
    }

    if (dino_anim_flag)
    {
        set_sprite_tile(SPRITE_DINO_FOOT_LEFT, TILE_DINO_FOOT_LEFT_UP);

        if (!is_down)
        {
            set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_FOOT_RIGHT_FLOOR);
        }
        else
        {
            set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_DOWN_FOOT_RIGHT_FLOOR);
        }
    }
    else
    {
        set_sprite_tile(SPRITE_DINO_FOOT_LEFT, TILE_DINO_FOOT_LEFT_FLOOR);

        if (!is_down)
        {
            set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_FOOT_RIGHT_UP);
        }
        else
        {
            set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_DOWN_FOOT_RIGHT_UP);
        }
    }

    move_sprite(SPRITE_DINO_FOOT_LEFT, dino_default_x, dino_y + 16u);
    move_sprite(SPRITE_DINO_FOOT_RIGHT, dino_default_x + 8u, dino_y + 16u);
}

void check_jump(void)
{
    if ((joypad() & J_A) && !is_jumping && !is_down)
    {
        velocity_Y = velocity_Y - 10;
        is_jumping = 1;
        jump_hold_time = 0;
        play_jump_sound();
    }

    dino_y += velocity_Y;

    if (is_jumping)
    {
        velocity_Y += gravity;
    }

    if (dino_y >= dino_default_y)
    {
        dino_y = dino_default_y;
        velocity_Y = 0;
        is_jumping = 0;
    }
}

void dino_game_over(void)
{
    set_sprite_tile(SPRITE_DINO_DOWN_HEAD_2, 0);
    move_sprite(SPRITE_DINO_DOWN_HEAD_2, 0, 0);

    set_sprite_tile(SPRITE_DINO_HEAD_1, TILE_DINO_HEAD_1_GAME_OVER);
    set_sprite_tile(SPRITE_DINO_BODY_1, TILE_DINO_BODY_1);
    set_sprite_tile(SPRITE_DINO_BODY_2, TILE_DINO_HEAD_2_GAME_OVER);
    set_sprite_tile(SPRITE_DINO_HEAD_2, TILE_DINO_HEAD_2);
    set_sprite_tile(SPRITE_DINO_BODY_3, TILE_DINO_BODY_3);

    set_sprite_tile(SPRITE_DINO_FOOT_LEFT, TILE_DINO_FOOT_LEFT_FLOOR);
    set_sprite_tile(SPRITE_DINO_FOOT_RIGHT, TILE_DINO_FOOT_RIGHT_FLOOR);

    move_sprite(SPRITE_DINO_HEAD_1, dino_default_x + 8u, dino_y);
    move_sprite(SPRITE_DINO_HEAD_2, dino_default_x + 16u, dino_y);
    move_sprite(SPRITE_DINO_BODY_1, dino_default_x, dino_y + 8u);
    move_sprite(SPRITE_DINO_BODY_2, dino_default_x + 8u, dino_y + 8u);
    move_sprite(SPRITE_DINO_BODY_3, dino_default_x + 16u, dino_y + 8u);

    move_sprite(SPRITE_DINO_FOOT_LEFT, dino_default_x, dino_y + 16u);
    move_sprite(SPRITE_DINO_FOOT_RIGHT, dino_default_x + 8u, dino_y + 16u);
}

void check_down(void)
{
    if ((joypad() & J_DOWN) && !is_jumping)
    {
        is_down = 1;
    }
    else
    {
        is_down = 0;
    }
}

void dino_reset(void)
{
    dino_y = dino_default_y;
    velocity_Y = 0;     // Vertical velocity for jump control
    is_jumping = 0;     // flag for jump control
    jump_hold_time = 0; // Time the jump button is held
}