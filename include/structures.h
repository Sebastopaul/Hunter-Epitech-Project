/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** struct
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include "my.h"

typedef struct stat stat_t;
typedef struct sprite_s {
    sfSprite *spt;
    sfIntRect rct;
    sfColor clr;
    sfVector2f pos;
    sfVector2f reach;
    sfVector2f size;
    float multi_sz;
    unsigned int mode;
} sprite_t;
typedef struct player_s {
    unsigned int game;
    unsigned int lives;
    unsigned int score;
    float dfclt;
    sfClock *clk;
    sfTime time;
    sfVector2f mse;
} player_t;
typedef struct game_s {
    sprite_t *dem;
    sprite_t *mnu;
    player_t plr;
} game_t;

#endif /* STRUCTURES_H_ */
