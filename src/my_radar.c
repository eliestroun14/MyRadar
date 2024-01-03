/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** my_radar
*/

#include "../include/my.h"
#include "../include/my_radar.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/*disp(global);
    my_printf("j'ai disp\n\n");
    for (int i = 0; tab_tower[i] != NULL; i++) {
        my_printf("tab_tower[%d] radius = %d / pos = %d / %d\n", i,
        tab_tower[i]->radius, tab_tower[i]->pos.x, tab_tower[i]->pos.y);
    }*/
/* static int disp(game_t *global)
{
    radar_link_list_t *tmp = NULL;

    tmp = global->head;
    while (tmp != NULL) {
        my_printf("node[%d]\n", tmp->plane->id);
        my_printf("node_pos = [%d / %d]\n", tmp->plane->pos->x,
            tmp->plane->pos->y);
        my_printf("node_dest = [%d / %d]\n", tmp->plane->dest.x,
            tmp->plane->dest.y);
        my_printf("node_speed = [%d]\n", tmp->plane->speed);
        my_printf("node_delay = [%d]\n", tmp->plane->delay);
        tmp = tmp->next;
    }
    return 0;
} */

static void free_tab_info(char ***tab_info)
{
    for (int k = 0; (*tab_info)[k] != NULL; k++)
        free((*tab_info)[k]);
    free((*tab_info));
}

int my_radar(char const *av, game_t *global, tower_t **tab_tower)
{
    char *buffer = open_file(av);
    char **tab_info = my_str_to_word_array(buffer, '\n');
    char **sub_tab;
    int nb_tower = 0;

    for (int i = 0; tab_info[i] != NULL; i++) {
        sub_tab = my_str_to_word_array(tab_info[i], ' ');
        if (!my_strcmp(sub_tab[0], "A"))
            fill_plane(sub_tab, global);
        if (!my_strcmp(sub_tab[0], "T"))
            tab_tower = fill_tower(sub_tab, tab_tower, &nb_tower);
        for (int k = 0; sub_tab[k] != NULL; k++)
            free(sub_tab[k]);
        free(sub_tab);
    }
    free_tab_info(&tab_info);
    simulation(global, tab_tower);
    return 0;
}
