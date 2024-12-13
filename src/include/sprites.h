#ifndef SPRITES_H
#define SPRITES_H

// -- Dino Sprite Index Definition

#define SPRITE_DINO_HEAD_1 0
#define SPRITE_DINO_HEAD_2 1
#define SPRITE_DINO_BODY_1 2
#define SPRITE_DINO_BODY_2 3
#define SPRITE_DINO_BODY_3 4

// Using the same pos for legs because it will be animated
#define SPRITE_DINO_FOOT_LEFT 5
#define SPRITE_DINO_FOOT_RIGHT 6

// Sprite when is down - reuse some sprite index for some of the sprites that could be overriden during the down action
#define SPRITE_DINO_DOWN_BODY_1 2
#define SPRITE_DINO_DOWN_BODY_2 3
#define SPRITE_DINO_DOWN_HEAD_1 4
#define SPRITE_DINO_DOWN_HEAD_2 7
#define SPRITE_DINO_DOWN_HEAD_3 0
#define SPRITE_DINO_DOWN_HEAD_4 1


// -- Obstacle Sprite Index Definition

// The obstacle sprite index is defined programatically to allow multiples sprites at the same time reusing the location of the sprite that is out of bounds
#define OBSTACLE_SPRITE_START_INDEX_1 8
#define OBSTACLE_SPRITE_START_INDEX_2 OBSTACLE_SPRITE_START_INDEX_1 + 6


// -- Characters and Numbers Sprite Index Definition

// Use the last position on the sprite array, allowing 4 position for the numbers
#define LETTER_1_SPRITE 29 - 1
#define LETTER_2_SPRITE 29 - 2
#define LETTER_3_SPRITE 29 - 3
#define LETTER_4_SPRITE 29 - 4
#define LETTER_5_SPRITE 29 - 5

#define LETTER_6_SPRITE 29 - 6
#define LETTER_7_SPRITE 29 - 7
#define LETTER_8_SPRITE 29 - 8

#define LETTER_9_SPRITE 29 - 9
#define LETTER_10_SPRITE 29 - 10
#define LETTER_11_SPRITE 29 - 11

// The number sprite is written at the last sprite position available and 5 position is reserved
#define HIGHSCORE_SPRITE_OFFSET 39
#define SCORE_SPRITE_OFFSET 34


#endif
