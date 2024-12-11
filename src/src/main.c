#include <gb/gb.h>
#include "../include/main.h"

uint32_t frame_count = 0;

void main(void)
{
    initialize_game();

    while (1)
    {
        frame_count++;
        
        if (!is_game_over)
        {
            update_dino();
            animate_dino();
            check_jump();

            // Testing increasing speed
            if (frame_count % (60 * 10) == 0)
            {
                speed = speed + 1 > max_speed ? max_speed : speed + 1;
            }

            if (frame_count % (60 * 60) == 0)
            {
                night_transition();
            }

            // Testing game over
            // if (frame_count > 60 * 3)
            // {
            //     game_over();
            // }
        }
        else
        {
            if (joypad() & J_START)
            {
                restart_game();
            }
        }

        wait_vbl_done();
    }
}
