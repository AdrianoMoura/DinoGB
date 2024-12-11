#include <gb/gb.h>
#include "../include/parallax.h"

uint8_t scrollSkySpeed = 0;
uint8_t scrollFloorSpeed = 0;
uint8_t currentSection = 0;

void ly_interrupt(void)
{
    switch (currentSection)
    {
    case 0:
        scrollSkySpeed += 2 * speed;
        scrollSkySpeed %= (BackgroundTileMapWidth * 8);
        SCX_REG = scrollSkySpeed;
        LYC_REG = 0x0A * 8;
        break;
    case 1:
        scrollFloorSpeed += 1 * speed;
        scrollFloorSpeed %= (BackgroundTileMapWidth * 8);
        SCX_REG = scrollFloorSpeed;
        LYC_REG = 0x00;
        break;
    }
    currentSection = (currentSection + 1) % 2;
}

void config_parallax(void)
{
    // Enable LY interruptor
    disable_interrupts();
    add_LCD(ly_interrupt);
    enable_interrupts();

    set_interrupts(VBL_IFLAG | LCD_IFLAG);
}

void parallax_reset(void)
{
    // Reset the parallax position
    scrollSkySpeed = 0;
    scrollFloorSpeed = 0;
}