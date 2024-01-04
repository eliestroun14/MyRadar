/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** destroy_plane
*/

#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <stddef.h>
#include <stdlib.h>

static void del_head(radar_link_list_t *tmp, radar_link_list_t **begin)
{
    *begin = tmp->next;
    return;
}

static void del_tail(radar_link_list_t *tmp, radar_link_list_t *previous)
{
    previous->next = NULL;
    return;
}

int del_plane(radar_link_list_t *tmp, radar_link_list_t *previous,
    radar_link_list_t **head)
{
    if (previous == NULL) {
        del_head(tmp, head);
        return 1;
    }
    if (tmp->next == NULL) {
        del_tail(tmp, previous);
        return 1;
    } else {
        previous->next = tmp->next;
        return 1;
    }
}

int destroy_plane(int id1, int id2, game_t *my_game)
{
    radar_link_list_t *tmp = my_game->head;
    radar_link_list_t *previous = NULL;
    radar_link_list_t *savior = NULL;

    while (tmp != NULL) {
        savior = tmp->next;
        if (tmp->plane->id == id1) {
            del_plane(tmp, previous, &my_game->head);
            my_game->plane_count--;
        }
        if (tmp->plane->id == id2) {
            del_plane(tmp, previous, &my_game->head);
            my_game->plane_count--;
        }
        previous = tmp;
        tmp = savior;
    }
    return 84;
}
