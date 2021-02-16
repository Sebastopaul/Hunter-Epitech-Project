/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** proto
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include "my.h"

sfRenderWindow *create_window(void);
sfSprite *init_bg(sfTexture *tex);
sfTexture **init_tex(void);
sprite_t *create_sprite(int nb, sfTexture *tex);
sprite_t *init_menu(int nb, sfTexture *tex);
void analyse_events(sfRenderWindow *window, sfEvent event, player_t *player);
void draw_sprites(sfRenderWindow *window, sprite_t *sprite, int nb);
void destroy(sfRenderWindow *win, sprite_t *dem, sprite_t *menu, sfSprite *bg);
void move_rect(sprite_t *sprite, int offset, int max_value, int origin);
void move_pos(sprite_t *spt);
void analyse_mode(game_t *gm);
void run_game(sfRenderWindow *win, game_t *gm, sfMusic *music);
void manage_score(sfRenderWindow *window, sprite_t *menu, player_t *player);
void display_window(sfRenderWindow *window, sfSprite *bg);
void time_spt_change(game_t *gm);
void init_sprite(sprite_t *spt, sfIntRect rct, sfVector2f pos, sfVector2f sz);
void setup_sprite(sprite_t *sprite, sfTexture *tex);
void destroy_sprite(sprite_t *spt, int nb);
void draw_score_lives(sfRenderWindow *window, sprite_t *menu);
void destroy_texture(int nb, sfTexture **tex);
void reset_sprites(int nb, sprite_t *dem, sprite_t *mnu);
void add_score(sprite_t *mnu);
void draw_sprite(sfRenderWindow *win, sprite_t *spt, int nb);
void verif_mode3(sprite_t *sprite, player_t *player);
void reset_score_lives(sprite_t *mnu);
void remove_life(sprite_t *mnu);
void play_music(sfMusic *music);

#endif /* PROTOTYPES_H_ */
