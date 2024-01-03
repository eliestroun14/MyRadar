/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** fill_plane
*/

#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <stddef.h>
#include <stdlib.h>

sfRectangleShape *create_rect(sfVector2f position, sfVector2f size)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(rectangle, 1.0f);
    sfRectangleShape_setOutlineColor(rectangle, sfBlue);
    return rectangle;
}

static void fill_struct(game_t *global, char **sub_tab)
{
    radar_link_list_t *new_node = malloc(sizeof(radar_link_list_t));

    new_node->plane = malloc(sizeof(aircraft_t));
    new_node->plane->pos = malloc(sizeof(vector_t));
    new_node->plane->id = global->id_nb;
    new_node->plane->pos->x = my_getnbr(sub_tab[1]);
    new_node->plane->pos->y = my_getnbr(sub_tab[2]);
    new_node->plane->dest.x = my_getnbr(sub_tab[3]);
    new_node->plane->dest.y = my_getnbr(sub_tab[4]);
    new_node->plane->speed = my_getnbr(sub_tab[5]);
    new_node->plane->delay = my_getnbr(sub_tab[6]);
    new_node->plane->rect = create_rect(*new_node->plane->pos,
        (sfVector2f){20, 20});
    new_node->P_texture = texture_init("assets/plane.png");
    new_node->P_sprite = sfSprite_create();
    sfSprite_setTexture(new_node->P_sprite, new_node->P_texture, sfTrue);
    sfSprite_setPosition(new_node->plane->sprite, *new_node->plane->pos);
    sfSprite_scale(new_node->plane->sprite, (sfVector2f){0.1, 0.1});
    new_node->next = global->head;
    global->head = new_node;
}

//if (!check_param())
// return 0;
int fill_plane(char **sub_tab, game_t *global)
{
    global->plane_count++;
    fill_struct(global, sub_tab);
    global->id_nb++;
    return 1;
}
