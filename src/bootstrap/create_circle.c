/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** create_circle
*/

#include "../../include/my.h"
#include <SFML/Graphics.h>

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1.0f);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    return circle;
}