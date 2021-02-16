/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** manage sprites
*/

#include "../include/my.h"

void verif_mode3(sprite_t *sprite, player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(sprite->spt);
    sfVector2f scale = sfSprite_getScale(sprite->spt);

    if (player->mse.x > pos.x &&
        player->mse.x < pos.x + (sprite->rct.width * scale.x) &&
        player->mse.y > pos.y &&
        player->mse.y < pos.y + (sprite->rct.height * scale.y)) {
        sprite->mode = 3;
        player->mse.x = 0;
        player->mse.y = 0;
    }
}
void move_rect(sprite_t *sprite, int offset, int max_value, int origin)
{
    sfIntRect rct = sprite->rct;

    rct.left += offset;
    if (rct.left >= max_value)
        rct.left = origin;
    sprite->rct = rct;
    sfSprite_setTextureRect(sprite->spt, rct);
}
void move_pos(sprite_t *spt)
{
    sfVector2f size = sfSprite_getScale(spt->spt);
    sfVector2f resize = {size.x * spt->multi_sz, size.y * spt->multi_sz};
    sfVector2f actu_pos = sfSprite_getPosition(spt->spt);
    sfVector2f move = {(spt->reach.x - spt->pos.x) / 10,
                       (spt->reach.y - spt->pos.y) / 10};
    sfVector2f new_pos = {actu_pos.x + move.x,
                          actu_pos.y + move.y};

    sfSprite_setPosition(spt->spt, new_pos);
    sfSprite_setScale(spt->spt, resize);
}
void time_spt_change(game_t *gm)
{
    float sec = 0;

    gm->plr.time = sfClock_getElapsedTime(gm->plr.clk);
    sec = gm->plr.time.microseconds / 1000000.0;
    if (sec > gm->plr.dfclt) {
        analyse_mode(gm);
        sfClock_restart(gm->plr.clk);
    }
}
