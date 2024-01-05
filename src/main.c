/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main
*/

#include "../include/my.h"
#include "../include/my_radar.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int handle_dash_h(char const *av)
{
    if (!my_strcmp(av, "-h")) {
        my_printf("Air traffic simulation panel\n\n");
        my_printf("USAGE\n\t");
        my_printf("./my_radar [OPTIONS] path_to_script\n");
        my_printf("path_to_script\tThe path to the script file.\n\n");
        my_printf("OPTIONS\n");
        my_printf("\t-h print the usage and quit.\n\n");
        my_printf("USER INTERACTIONS\n");
        my_printf("\t'L' key\tenable/disable hitboxes and areas.\n");
        my_printf("\t'S' key\tenable/disable sprites.\n");
        my_printf("\t'I' key\tplane speed x2 (printed in left top corner).\n");
        my_printf("\t'D' key\tplane speed /2 (not printed if < 1).\n");
    return 1;
    } else
        return 0;
}

int is_file(char const *av)
{
    struct stat filestat;
    int rt_dash_h = handle_dash_h(av);

    if (rt_dash_h == 1)
        return -1;
    if (stat(av, &filestat) < 0 &&
        (S_ISREG(filestat.st_mode) == 0 && rt_dash_h == 0))
        return 0;
    else
        return 1;
}

int handle_error(int ac, char const **av)
{
    int rt = 0;
    char *buff_arg = "sorry, too few or too much arguments\n";
    char *buff_file = "sorry, wrong path or not existing file\n";

    if (ac != 2) {
        write(2, buff_arg, my_strlen(buff_arg));
        return 0;
    }
    rt = is_file(av[1]);
    if (!rt) {
        write(2, buff_file, my_strlen(buff_file));
        return 0;
    }
    if (rt == -1)
        return 0;
    else
        return 1;
}

int main(int ac, char const **av)
{
    int return_value = 0;
    game_t global;
    tower_t **tab_tower = malloc(sizeof(tower_t *));

    tab_tower[0] = NULL;
    global.plane_count = 0;
    global.id_nb = 0;
    global.head = NULL;
    return_value = handle_error(ac, av);
    if (return_value == 0)
        return 84;
    if (return_value == -1)
        return 0;
    return_value = my_radar(av[1], &global, tab_tower);
    return return_value;
}
