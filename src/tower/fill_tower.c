/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** fill_tower
*/
#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <stddef.h>
#include <stdlib.h>

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, (sfVector2f){position.x - radius,
        position.y - radius});
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1.0f);
    sfCircleShape_setOutlineColor(circle, sfRed);
    return circle;
}

void fill_tab(tower_t **new_tab, char **sub_tab, int i)
{
    new_tab[i] = malloc(sizeof(tower_t));
    new_tab[i]->pos.x = my_getnbr(sub_tab[1]);
    new_tab[i]->pos.y = my_getnbr(sub_tab[2]);
    new_tab[i]->rad = my_getnbr(sub_tab[3]);
    new_tab[i]->rad_circle = create_circle(new_tab[i]->pos, new_tab[i]->rad);
    new_tab[i]->texture = texture_init("assets/tower.png");
    new_tab[i]->sprite = sfSprite_create();
}

tower_t **fill_tower(char **sub_tab, tower_t **tower_tab, int *nb_tower)
{
    tower_t **new_tab = NULL;
    int i = 0;
    int null_end = 1;

    for (; tower_tab[i] != NULL; i++);
    new_tab = malloc(sizeof(tower_t *) * (i + null_end + 1));
    for (int j = 0; j <= i; j++)
        new_tab[j] = tower_tab[j];
    fill_tab(new_tab, sub_tab, i);
    sfSprite_setOrigin(new_tab[i]->sprite, (sfVector2f){250, 250});
    sfSprite_setPosition(new_tab[i]->sprite, new_tab[i]->pos);
    sfSprite_setTexture(new_tab[i]->sprite, new_tab[i]->texture, sfTrue);
    sfSprite_scale(new_tab[i]->sprite, (sfVector2f){0.1, 0.1});
    new_tab[i + null_end] = NULL;
    free(tower_tab);
    (*nb_tower) += 1;
    return new_tab;
}
