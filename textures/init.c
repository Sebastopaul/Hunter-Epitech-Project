/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** texture
*/

#include "../include/my.h"

sfTexture **init_tex(void)
{
    sfTexture **tex = malloc(sizeof(sfTexture *) * 3);

    tex[0] = sfTexture_createFromFile("sources/bg.jpg", NULL);
    tex[1] = sfTexture_createFromFile("sources/menu.png", NULL);
    tex[2] = sfTexture_createFromFile("sources/demon.png", NULL);
    return(tex);
}
