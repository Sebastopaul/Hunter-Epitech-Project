/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** init bg
*/

#include "../include/my.h"

sfSprite *init_bg(sfTexture *tex)
{
    sfSprite *bg = sfSprite_create();
    sfVector2f scale = {3.75, 3.2};

    sfSprite_setTexture(bg, tex, sfTrue);
    sfSprite_setScale(bg, scale);
    return (bg);
}
