#include <gb/gb.h>
#include "../include/parallax.h"

uint8_t section1 = 0;
uint8_t section2 = 0;
uint8_t section3 = 0;
uint8_t currentSection = 0;

void ly_interrupt(void)
{
    switch (currentSection)
    {
    case 0:
        section1 += 1 * speed - 1;
        section1 %= (BackgroundTileMapWidth * 8);
        SCX_REG = section1;
        LYC_REG = 6 * 8;
        break;
    case 1:
        section2 += 2 * speed - 1;
        section2 %= (BackgroundTileMapWidth * 8);
        SCX_REG = section2;
        LYC_REG = 10 * 8;
        break;
    case 2:
        section3 += 1 * speed;
        section3 %= (BackgroundTileMapWidth * 8);
        SCX_REG = section3;
        LYC_REG = 0;
        break;
    }
    currentSection = (currentSection + 1) % 3;
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
    section1 = 0;
    section2 = 0;
    section3 = 0;
}