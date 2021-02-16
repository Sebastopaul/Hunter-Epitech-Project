/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** main
*/

#include "include/my.h"

void my_hunter(void)
{
    sfRenderWindow *window = create_window();
    sfEvent event;
    sfTexture **tex = init_tex();
    sfSprite *bg = init_bg(tex[0]);
    game_t game = {create_sprite(4, tex[2]), init_menu(8, tex[1]),
                   {0, 3, 0, 1, sfClock_create(), {0}, {0}}};
    sfMusic *music = sfMusic_createFromFile("sources/music.ogg");

    play_music(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, &game.plr);
        display_window(window, bg);
        run_game(window, &game, music);
        sfRenderWindow_display(window);
    }
    sfMusic_stop(music);
    sfClock_destroy(game.plr.clk);
    sfMusic_destroy(music);
    destroy_texture(3, tex);
    destroy(window, game.dem, game.mnu, bg);
}
char *make_usage(char *path, int size)
{
    char *buff = malloc(sizeof(char) * size);
    int fd = open(path, O_RDONLY);

    read(fd, buff, size);
    return (buff);
}
int main(int ac, char **av)
{
    stat_t st_file = {0};
    char *usage;

    if (ac < 2) {
        my_hunter();
        return (0);
    } else if (ac == 2 && my_strcmp(av[1], "-h") == 0 &&
               stat("sources/usage", &st_file) != -1) {
        usage = make_usage("sources/usage", st_file.st_size);
        write(1, usage, my_strlen(usage));
        return (0);
    }
    if (ac > 2)
        write
        (2, "/!\\ERROR/!\\\nBad usage. Use -h for more informations\n", 52);
    else
        write(2, "/!\\ERROR/!\\\n'usage' file not found.\n", 36);
    return (84);
}
