/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** init
*/

#include "../include/my.h"

void init_sprite(sprite_t *spt, sfIntRect rct, sfVector2f pos, sfVector2f sz)
{
    spt->spt = sfSprite_create();
    spt->rct = rct;
    spt->clr = sfSprite_getColor(spt->spt);
    spt->pos = pos;
    spt->size = sz;
}
void setup_sprite(sprite_t *sprite, sfTexture *tex)
{
    sfColor transparent = {0};

    sfSprite_setTexture(sprite->spt, tex, sfTrue);
    sfSprite_setPosition(sprite->spt, sprite->pos);
    sfSprite_setTextureRect(sprite->spt, sprite->rct);
    sfSprite_setScale(sprite->spt, sprite->size);
    if (sprite->mode == 0)
        sfSprite_setColor(sprite->spt, transparent);
}
sprite_t *create_sprite(int nb, sfTexture *tex)
{
    sprite_t *sprite = malloc(sizeof(sprite_t) * nb);
    sfIntRect rct = {0, 0, 60, 62};
    sfVector2f pos[4] = {{170, 530}, {735, 500}, {1125, 500}, {1620, 530}};
    sfVector2f size[4] = {{2.25, 2.5}, {1.25, 1.5}, {1.25, 1.5}, {2.75, 3}};
    sfVector2f reach[4] = {{700, 600}, {700, 600}, {800, 600}, {1000, 600}};
    float multi_sz[4] = {1.1, 1.2, 1.2, 1.1};

    for (int i = 0; i < nb; i++) {
        init_sprite(&sprite[i], rct, pos[i], size[i]);
        sprite[i].reach = reach[i];
        sprite[i].multi_sz = multi_sz[i];
        sprite[i].mode = 0;
        setup_sprite(&sprite[i], tex);
    }
    return (sprite);
}
