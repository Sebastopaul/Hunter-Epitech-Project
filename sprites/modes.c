/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** modes
*/

#include "../include/my.h"

void set_mode0(sprite_t *sprite, player_t *player, sprite_t *mnu)
{
    sfColor transparent = {0};
    unsigned int reset = rand();

    sfSprite_setColor(sprite->spt, transparent);
    move_rect(sprite, 1, 0, 0);
    sfSprite_setScale(sprite->spt, sprite->size);
    sfSprite_setPosition(sprite->spt, sprite->pos);
    if (reset < RAND_MAX / 5) {
        sprite->mode = 1;
        sfSprite_setColor(sprite->spt, sprite->clr);
    }
}
void set_mode1(sprite_t *sprite, player_t *player, sprite_t *mnu)
{
    int offset = 60;
    int origin = 0;
    int max_value = 240;
    sfVector2f pos = sfSprite_getPosition(sprite->spt);
    int toler = 10;

    if (pos.x > sprite->reach.x - toler && pos.x < sprite->reach.x + toler
        && pos.y > sprite->reach.y - toler && pos.y < sprite->reach.y + toler)
        sprite->mode = 2;
    verif_mode3(sprite, player);
    if (sprite->rct.left < origin)
        offset = origin - sprite->rct.left;
    move_rect(sprite, offset, max_value, origin);
    move_pos(sprite);
    pos = sfSprite_getPosition(sprite->spt);
}
void set_mode2(sprite_t *sprite, player_t *player, sprite_t *mnu)
{
    int offset = 60;
    int origin = 240;
    int max_value = 420;

    verif_mode3(sprite, player);
    if (sprite->rct.left < origin)
        offset = origin - sprite->rct.left;
    move_rect(sprite, offset, max_value, origin);
    if (sprite->rct.left == max_value - offset) {
        player->lives--;
        remove_life(mnu);
        sprite->mode = 0;
    }
}
void set_mode3(sprite_t *sprite, player_t *player, sprite_t *mnu)
{
    int offset = 60;
    int origin = 420;
    int max_value = 720;

    if (sprite->rct.left < origin) {
        player->score++;
        if (player->score < 1000)
            add_score(mnu);
        else
            player->game = 0;
        offset = origin - sprite->rct.left;
    }
    move_rect(sprite, offset, max_value, origin);
    if (sprite->rct.left == max_value - offset)
        sprite->mode = 0;
}
void analyse_mode(game_t *gm)
{
    void (*set_mode[4])(sprite_t *, player_t *, sprite_t *) =
        {set_mode0, set_mode1, set_mode2, set_mode3};

    for (int i = 0; i < 4; i++)
        set_mode[gm->dem[i].mode](&gm->dem[i], &gm->plr, gm->mnu);
}
