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

static void free_tab_info(char ***tab_info)
{
    for (int k = 0; (*tab_info)[k] != NULL; k++)
        free((*tab_info)[k]);
    free((*tab_info));
}

tower_t **fill_plane_tower(char **tab_info, tower_t **tab_tower,
    game_t *global)
{
    char **sub_tab;
    int status;

    for (int i = 0; tab_info[i] != NULL; i++) {
        sub_tab = my_str_to_word_array(tab_info[i], ' ');
        if (!my_strcmp(sub_tab[0], "A"))
            status = fill_plane(sub_tab, global);
        if (!my_strcmp(sub_tab[0], "T"))
            tab_tower = fill_tower(sub_tab, tab_tower, global);
        if ((my_strcmp(sub_tab[0], "A") && my_strcmp(sub_tab[0], "T"))
            || tab_tower == NULL || status == 84)
            return NULL;
        for (int k = 0; sub_tab[k] != NULL; k++)
            free(sub_tab[k]);
        free(sub_tab);
    }
    return tab_tower;
}

int my_radar(char const *av, game_t *global, tower_t **tab_tower)
{
    char *buffer = open_file(av);
    char **tab_info = my_str_to_word_array(buffer, '\n');

    global->tower_nb = 0;
    tab_tower = fill_plane_tower(tab_info, tab_tower, global);
    if (tab_tower == NULL) {
        my_printf("error while filling structure\n");
        return 84;
    }
    free_tab_info(&tab_info);
    simulation(global, tab_tower);
    return 0;
}
