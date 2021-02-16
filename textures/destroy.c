/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** destroy
*/

#include "../include/my.h"

void destroy_texture(int nb, sfTexture **tex)
{
    for (int i = 0; i < nb; i++)
        sfTexture_destroy(tex[i]);
    free(tex);
}
