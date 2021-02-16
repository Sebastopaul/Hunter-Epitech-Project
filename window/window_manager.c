/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** manage window
*/

#include "../include/my.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 16};
    sfRenderWindow *window =
        sfRenderWindow_create(mode, "My Hunter", sfDefaultStyle, NULL);

    return (window);
}
void destroy(sfRenderWindow *win, sprite_t *dem, sprite_t *menu, sfSprite *bg)
{
    destroy_sprite(dem, 4);
    destroy_sprite(menu, 6);
    sfSprite_destroy(bg);
    sfRenderWindow_destroy(win);
}
void correct_size(sfRenderWindow *window)
{
    sfVector2u size = {0};
    sfVector2u size_min = {800, 600};
    sfVector2u size_max = {1920, 1080};

    size = sfRenderWindow_getSize(window);
    if (size.x < size_min.x)
        size.x = size_min.x;
    if (size.y < size_min.y)
        size.y = size_min.y;
    if (size.x > size_max.x)
        size.x = size_max.x;
    if (size.y > size_max.y)
        size.y = size_max.y;
    sfRenderWindow_setSize(window, size);
}
void display_window(sfRenderWindow *window, sfSprite *bg)
{
    correct_size(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, bg, NULL);
}
