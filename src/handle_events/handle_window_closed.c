/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** handle_window_closed
*/
#include <SFML/Graphics.h>
#include <stddef.h>

void handle_close_window(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}