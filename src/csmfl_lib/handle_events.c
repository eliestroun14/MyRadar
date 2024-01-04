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

/* int handle_event(game_t *my_game)
{
    while (sfRenderWindow_pollEvent(my_game->window, &my_game->event)) {
        if (my_game->event.type == sfEvtClosed)
            sfRenderWindow_close(my_game->window);
        if (sfKeyboard_isKeyPressed(sfKeyL)) {
                my_game->show_hitboxes = (my_game->show_hitboxes == false) ?
                    true : false;
        }
        else if (sfKeyboard_isKeyPressed(sfKeyS)) {
            my_game->show_sprites = (my_game->show_sprites == false) ?
                true : false;
        }
    }
    return 0;
} */

/* int handle_event(game_t *my_game)
{
    sfEvent *event = &my_game->event;

    while (sfRenderWindow_pollEvent(my_game->window, event)) {
        if (my_game->event.type == sfEvtClosed)
            sfRenderWindow_close(my_game->window);
        switch (event->key.code){
        case sfKeyL:
            my_game->show_hitboxes = (my_game->show_hitboxes == false) ?
                    true : false;
            break;
        case sfKeyS:
            my_game->show_sprites = (my_game->show_sprites == false) ?
                true : false;
            break;
        default:
            break;
        }
    }
    return 0;
} */

int handle_event(game_t *my_game)
{
    sfEvent *event = &my_game->event;

    while (sfRenderWindow_pollEvent(my_game->window, event)) {
        if (my_game->event.type == sfEvtClosed)
            sfRenderWindow_close(my_game->window);
        if (event->key.code == sfKeyboard_isKeyPressed(sfKeyL)) {
            my_game->show_hitboxes = (my_game->show_hitboxes == false) ? true :
            false;
        }
        if (event->key.code == sfKeyboard_isKeyPressed(sfKeyS)) {
            my_game->show_sprites = (my_game->show_sprites == false) ? true :
            false;
        }
    }
    return 0;
}
