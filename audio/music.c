/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** audio
*/

#include "../include/my.h"

void play_music(sfMusic *music)
{
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
}
