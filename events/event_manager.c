/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** manage events
*/

#include "../include/my.h"

void manage_mouse_click(sfMouseButtonEvent event, player_t *player)
{
    if (event.button == sfMouseLeft) {
        player->mse.x = event.x;
        player->mse.y = event.y;
    }
}
void analyse_events(sfRenderWindow *window, sfEvent event, player_t *player)
{
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, player);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}
