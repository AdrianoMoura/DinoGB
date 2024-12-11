#include <gb/gb.h>
#include "../include/main.h"

uint32_t frame_count = 0;

void main(void)
{
    initialize_game();

    while (1)
    {
        frame_count++;
        
        // Testing the night transition
        if (joypad() & J_START)
        {
            night_transition();
        }

        if (!is_game_over)
        {
            update_dino();
            animate_dino();
            check_jump();

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
