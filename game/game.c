/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** game manager
*/

#include "../include/my.h"

void manage_difficulty(player_t *player)
{
    if (player->score <= 10)
        player->dfclt = 0.8;
    if (player->score > 10)
        player->dfclt = 0.5;
    if (player->score > 20)
        player->dfclt = 0.4;
    if (player->score > 30)
        player->dfclt = 0.3;
    if (player->score > 40)
        player->dfclt = 0.2;
    if (player->score > 50)
        player->dfclt = 0.1;
}
void select_button(sfRenderWindow *win, sprite_t *mnu, player_t *plr)
{
    if (plr->mse.y >= mnu[0].pos.y && plr->mse.x >= mnu[0].pos.x
        && plr->mse.y <= mnu[0].pos.y + mnu[0].rct.height &&
        plr->mse.x <= mnu[0].pos.x + mnu[0].rct.width) {
        plr->score = 0;
        plr->lives = 3;
        reset_score_lives(mnu);
        plr->game = 1;
        plr->mse.x = 0;
        plr->mse.y = 0;
    }
    if (plr->mse.y >= mnu[1].pos.y && plr->mse.x >= mnu[1].pos.x
        && plr->mse.y <= mnu[1].pos.y + mnu[1].rct.height &&
        plr->mse.x <= mnu[1].pos.x + mnu[1].rct.width) {
        sfRenderWindow_close(win);
    }
}
void run_game(sfRenderWindow *win, game_t *gm, sfMusic *music)
{
    draw_score_lives(win, gm->mnu);
    if (gm->plr.game == 0) {
        reset_sprites(4, gm->dem, gm->mnu);
        select_button(win, gm->mnu, &gm->plr);
        draw_sprite(win, gm->mnu, 2);
    }
    if (gm->plr.game == 1) {
        time_spt_change(gm);
        manage_difficulty(&gm->plr);
        draw_sprite(win, gm->dem, 4);
        if (gm->plr.lives == 0)
            gm->plr.game = 0;
    }
}
