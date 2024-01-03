/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** texture_init
*/
#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <stddef.h>

sfTexture *texture_init(char const *path)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile((path), NULL);
    if (!texture)
        return (NULL);
    return texture;
}
