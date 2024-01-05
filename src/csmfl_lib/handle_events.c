/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** handle_events
*/
#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <SFML/Graphics.h>
#include <stddef.h>

int handle_event(game_t *my_game)
{
    sfEvent *event = &my_game->event;

    while (sfRenderWindow_pollEvent(my_game->window, event)) {
        if (my_game->event.type == sfEvtClosed)
            sfRenderWindow_close(my_game->window);
        if (my_game->event.type == sfEvtKeyPressed &&
            event->key.code == sfKeyS)
            my_game->show_sprites = !my_game->show_sprites;
        if (my_game->event.type == sfEvtKeyPressed &&
            event->key.code == sfKeyL)
            my_game->show_hitboxes = !my_game->show_hitboxes;
        if (my_game->event.type == sfEvtKeyPressed &&
            event->key.code == sfKeyI) {
            SP *= 2.0;
        }
        if (my_game->event.type == sfEvtKeyPressed &&
            event->key.code == sfKeyD) {
            SP /= 2.0;
        }
    }
    //printf("SP = [%f]\n", SP);
    return 0;
}
