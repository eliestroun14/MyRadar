/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** window_texture_map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

sfRenderWindow *window_init(sfVideoMode mode)
{
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "Game Window", sfResize | sfClose,
        NULL);
    if (!window)
        exit(84);
    return window;
}
