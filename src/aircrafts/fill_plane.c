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

    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(rectangle, 1.0f);
    sfRectangleShape_setOutlineColor(rectangle, sfBlue);
    sfRectangleShape_setOrigin(rectangle, (sfVector2f){size.x / 2,
        size.y / 2});
    sfRectangleShape_setPosition(rectangle, position);
    return rectangle;
}

static void set_plane_data(radar_link_list_t *new_node, char **sub_tab)
{
    new_node->plane->pos->x = my_getnbr(sub_tab[1]);
    new_node->plane->pos->y = my_getnbr(sub_tab[2]);
    new_node->plane->dest.x = my_getnbr(sub_tab[3]);
    new_node->plane->dest.y = my_getnbr(sub_tab[4]);
    new_node->plane->speed = my_getnbr(sub_tab[5]);
    new_node->plane->delay = my_getnbr(sub_tab[6]);
}

static void fill_struct(game_t *global, char **sub_tab)
{
    radar_link_list_t *new_node = malloc(sizeof(radar_link_list_t));

    new_node->plane = malloc(sizeof(aircraft_t));
    new_node->plane->pos = malloc(sizeof(vector_t));
    new_node->plane->id = global->id_nb;
    set_plane_data(new_node, sub_tab);
    new_node->plane->is_waiting = false;
    new_node->P_TEXTURE = texture_init("assets/plane.png");
    new_node->P_SPRITE = sfSprite_create();
    sfSprite_setOrigin(new_node->plane->sprite,
    (sfVector2f){WIDTH / 2, HEIGHT / 2});
    new_node->plane->rect = create_rect(*new_node->plane->pos,
        (sfVector2f){20, 20});
    sfSprite_setTexture(new_node->P_SPRITE, new_node->P_TEXTURE, sfTrue);
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
