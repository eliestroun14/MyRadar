/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** intersecting_circles
*/

#include <SFML/Graphics.h>
#include <math.h>

int is_interecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f pos1 = sfCircleShape_getPosition(c1);
    float rad1 = sfCircleShape_getRadius(c1);
    sfVector2f pos2 = sfCircleShape_getPosition(c2);
    float rad2 = sfCircleShape_getRadius(c2);
    float distance = powf(pos2.x - pos1.x, 2) + powf(pos2.y - pos1.y, 2);

    if (distance <= pow(rad1 + rad2, 2)) {
        return 1;
    } else {
        return 0;
    }
}