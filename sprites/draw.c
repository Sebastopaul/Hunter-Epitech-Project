/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** draw
*/

#include "../include/my.h"

void draw_sprite(sfRenderWindow *win, sprite_t *spt, int nb)
{
    for (int i = 0; i < nb; i++)
        sfRenderWindow_drawSprite(win, spt[i].spt, NULL);
}
