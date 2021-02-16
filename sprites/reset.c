/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** reset
*/

#include "../include/my.h"

void reset_sprites(int nb, sprite_t *dem, sprite_t *mnu)
{
    sfColor transparent = {0};

    for (int i = 0; i < nb; i++) {
        dem[i].mode = 0;
        sfSprite_setColor(dem[i].spt, transparent);
    }
    for (int i = 0; i < 2; i++) {
        mnu[i].mode = 1;
        sfSprite_setColor(mnu[i].spt, mnu[i].clr);
    }
}
