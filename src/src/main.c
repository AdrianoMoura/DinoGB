#include <gb/gb.h>
#include <rand.h>
#include "../include/main.h"

uint32_t frame_count = 0;

void main(void)
{
    initialize_game();

    // Await player to press a button
    while (!joypad())
    {
        frame_count++;
        update_dino();
        main_screen();
        animate_dino();

        wait_vbl_done();
    }

    clear_sprites();

    // Set random seed based on the carrier register
    initrand(DIV_REG);
    frame_count = 0;
    
    while (1)
    {
        frame_count++;

        if (!is_game_over)
        {
            update_dino();
            update_cactus();
            move_cactus();
            animate_dino();
            check_jump();
            check_down();
            check_collision();

            // Testing increasing speed
            if (frame_count % (60 * 10) == 0)
            {
                speed = speed + 1 > max_speed ? max_speed : speed + 1;
            }

            if (frame_count % (60 * 30) == 0)
            {
                night_transition();
            }

            // Increasing score
            if (frame_count % 60 == 0)
            {
                score++;
                draw_score();
            }
        }
        else
        {
            if (joypad())
            {
                restart_game();
            }
        }

        wait_vbl_done();
    }
}
