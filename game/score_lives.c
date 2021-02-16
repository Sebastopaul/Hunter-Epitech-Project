/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** score
*/

#include "../include/my.h"

void draw_score_lives(sfRenderWindow *window, sprite_t *menu)
{
    for (int i = 2; i < 8; i++)
        sfRenderWindow_drawSprite(window, menu[i].spt, NULL);
}
void reset_score_lives(sprite_t *mnu)
{
    for (int i = 4; i < 7; i++) {
        mnu[i].rct.left = 0;
        sfSprite_setTextureRect(mnu[i].spt, mnu[i].rct);
    }
    mnu[7].rct.left = 120;
    sfSprite_setTextureRect(mnu[7].spt, mnu[7].rct);
}
void add_score(sprite_t *mnu)
{
    int offset = 40;
    int max_value = 400;
    int origin = 0;

    move_rect(&mnu[6], offset, max_value, origin);
    if (mnu[6].rct.left == 0) {
        move_rect(&mnu[5], offset, max_value, origin);
        if (mnu[5].rct.left == 0)
            move_rect(&mnu[4], offset, max_value, origin);
    }
}
void remove_life(sprite_t *mnu)
{
    int offset = -40;
    int max_value = 160;
    int origin = 0;

    move_rect(&mnu[7], offset, max_value, origin);
}
