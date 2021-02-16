/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** destroy sprite
*/

#include "../include/my.h"

void destroy_sprite(sprite_t *spt, int nb)
{
    for (int i = 0; i < nb; i++) {
        sfSprite_destroy(spt[i].spt);
    }
    free(spt);
}
