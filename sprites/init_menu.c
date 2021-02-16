/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** init menu
*/

#include "../include/my.h"

sprite_t *init_menu(int nb, sfTexture *tex)
{
    sprite_t *menu = malloc(sizeof(sprite_t) * nb);
    sfIntRect rct[8] = {{0, 0, 168, 37}, {169, 0, 125, 41},
                        {295, 0, 195, 37}, {0, 83, 156, 37}, {0, 43, 40, 37},
                        {0, 43, 40, 37}, {0, 43, 40, 37}, {120, 43, 40, 37}};
    sfVector2f pos[8] = {{860, 450}, {880, 525}, {10, 950}, {1660, 950},
                        {260, 950}, {305, 950}, {350, 950}, {1860, 950}};
    sfVector2f scale = {1.25, 1.25};

    for (int i = 0; i < nb; i++) {
        init_sprite(&menu[i], rct[i], pos[i], scale);
        menu[i].mode = 1;
        setup_sprite(&menu[i], tex);
    }
    return (menu);
}
