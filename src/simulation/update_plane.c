/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** move_plane
*/

#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <math.h>

static float calculate_angle(sfVector2f point1, sfVector2f point2)
{
    return atan2(point2.y - point1.y, point2.x - point1.x) * 180 / M_PI;
}

static void plane_face_dest(sfVector2f plane_pos, sfVector2f plane_dest,
    aircraft_t *plane)
{
    int angle = calculate_angle(plane_pos, plane_dest);

    sfSprite_setRotation(plane->sprite, angle);
    sfRectangleShape_setOrigin(plane->rect, (sfVector2f){-4.5, -4.5});
    sfRectangleShape_setRotation(plane->rect, angle);
}

sfVector2f set_direction(sfVector2f *direction,
    radar_link_list_t *tmp)
{
    sfVector2f tmp_dir = *direction;
    float length = 0;

    tmp_dir.x = tmp->plane->dest.x - tmp->plane->pos->x;
    tmp_dir.y = tmp->plane->dest.y - tmp->plane->pos->y;
    length = sqrt(tmp_dir.x * tmp_dir.x + tmp_dir.y * tmp_dir.y);
    tmp_dir.x /= length;
    tmp_dir.y /= length;
    return tmp_dir;
}

static int move_plane(game_t *my_game)
{
    radar_link_list_t *tmp = my_game->head;
    sfVector2f direction;
    sfTime time = sfClock_getElapsedTime(my_game->game_clock);
    float sec = time.microseconds / 1000000.0f;

    while (tmp != NULL) {
        direction = set_direction(&direction, tmp);
        if (tmp->plane->pos->x != tmp->plane->dest.x)
            tmp->plane->pos->x += (tmp->plane->speed * 5) * direction.x * sec;
        if (tmp->plane->pos->y != tmp->plane->dest.y)
            tmp->plane->pos->y += (tmp->plane->speed * 5) * direction.y * sec;
        sfSprite_setPosition(tmp->plane->sprite, *tmp->plane->pos);
        sfRectangleShape_setPosition(tmp->plane->rect, *tmp->plane->pos);
        plane_face_dest(*tmp->plane->pos, tmp->plane->dest, tmp->plane);
        tmp = tmp->next;
    }
    sfClock_restart(my_game->game_clock);
    return 0;
}

static sfBool planes_collides(sfRectangleShape *rect1, sfRectangleShape *rect2)
{
    sfVector2f rect1Pos = sfRectangleShape_getPosition(rect1);
    sfVector2f rect2Pos = sfRectangleShape_getPosition(rect2);
    sfVector2f rect1Size = sfRectangleShape_getSize(rect1);
    sfVector2f rect2Size = sfRectangleShape_getSize(rect2);

    if ((rect1Pos.x < rect2Pos.x + rect2Size.x) &&
        (rect1Pos.x + rect1Size.x > rect2Pos.x) &&
        (rect1Pos.y < rect2Pos.y + rect2Size.y) &&
        (rect1Pos.y + rect1Size.y > rect2Pos.y)) {
        return sfTrue;
    }
    return sfFalse;
}

/* sfBool is_in_range_tower(sfRectangleShape *rect1, sfRectangleShape *rect2,
    tower_t **tower_tab)
{
    sfVector2f center1, center2;
    center1.x = sfRectangleShape_getPosition(rect1).x +
        sfRectangleShape_getSize(rect1).x / 2;
    center1.y = sfRectangleShape_getPosition(rect1).y +
        sfRectangleShape_getSize(rect1).y / 2;
    center2.x = sfRectangleShape_getPosition(rect2).x +
        sfRectangleShape_getSize(rect2).x / 2;
    center2.y = sfRectangleShape_getPosition(rect2).y +
        sfRectangleShape_getSize(rect2).y / 2;

    float distance;
    for (int i = 0; tower_tab[i] != NULL; ++i) {
        distance = sqrt(pow(center1.x - tower_tab[i]->pos.x, 2) +
            pow(center1.y - tower_tab[i]->pos.y, 2));
        if (distance <= tower_tab[i]->rad) {
            distance = sqrt(pow(center2.x - tower_tab[i]->pos.x, 2) +
                pow(center2.y - tower_tab[i]->pos.y, 2));
            if (distance <= tower_tab[i]->rad) {
                return sfTrue;
            }
        }
    }
    return sfFalse;
} */

/* int check_collisions(game_t *my_game, tower_t **tower_tab)
{
    radar_link_list_t *list1 = my_game->head;
    radar_link_list_t *list2;

    while (list1 != NULL) {
        list2 = my_game->head;
        while (list2 != NULL) {
            //if (list1->plane->id == list2->plane->id)
            //    continue;
            if (planes_collides(list1->plane->rect, list2->plane->rect)) {
                if (is_in_range_tower(list1->plane->rect, list2->plane->rect,
                    tower_tab) ==  sfTrue) {
                    my_printf("in range tower");
                    destroy_plane(list1->plane->id, list2->plane->id, my_game);
                }

            }
            list2 = list2->next;
        }
        list1 = list1->next;
    }
    return 0;
} */
int planes_arrived(game_t *my_game)
{
    radar_link_list_t *tmp = my_game->head;
    radar_link_list_t *previous = NULL;
    radar_link_list_t *savior = NULL;
    int vel;

    while (tmp != NULL) {
        savior = tmp->next;
        vel = tmp->plane->speed;
        if (((int)tmp->plane->dest.x - (float)vel) < (int)tmp->plane->pos->x
            && (int)tmp->plane->pos->x < ((int)tmp->plane->dest.x + (float)vel)
            && ((int)tmp->plane->dest.y - (float)vel) < (int)tmp->plane->pos->y
            && (int)tmp->plane->pos->y < ((int)tmp->plane->dest.y +
            (float)vel)) {
            del_plane(tmp, previous, &my_game->head);
            my_game->plane_count--;
        }
        previous = tmp;
        tmp = savior;
    }
    return 0;
}

//check_collisions(my_game, tower_tab);
int update_plane(game_t *my_game, tower_t **tower_tab)
{
    planes_arrived(my_game);
    move_plane(my_game);
    return 0;
}