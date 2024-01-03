/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** window_texture_map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

sfRenderWindow *window_init(int mode_size1, int mode_size2, char *name)
{
    sfVideoMode mode = {mode_size1, mode_size2, 64};
    sfRenderWindow *window = sfRenderWindow_create(mode, name, sfClose |
    sfResize, NULL);

    if (!window)
        return NULL;
    return window;
}
