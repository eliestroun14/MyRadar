/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** render_simulation
*/
#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <stddef.h>

void show_sprites(game_t *my_game, tower_t **tower_tab)
{
    radar_link_list_t *tmp = my_game->head;

    for (int i = 0; tower_tab[i] != NULL; ++i) {
            sfRenderWindow_drawSprite(my_game->window, tower_tab[i]->sprite,
                NULL);
    }
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(my_game->window, tmp->plane->sprite, NULL);
        tmp = tmp->next;
    }
}

void show_hitboxes(game_t *my_game, tower_t **tower_tab)
{
    radar_link_list_t *tmp = my_game->head;

    for (int i = 0; tower_tab[i] != NULL; ++i) {
            sfRenderWindow_drawCircleShape(my_game->window,
                tower_tab[i]->rad_circle, NULL);
    }
    while (tmp != NULL) {
        sfRenderWindow_drawRectangleShape(my_game->window,
        tmp->plane->rect, NULL);
        tmp = tmp->next;
    }
}

//sfRenderWindow_drawText(my_game->window, my_game->score->pts, NULL);
void render_simulation(game_t *my_game, tower_t **tower_tab)
{
    sfRenderWindow_clear(my_game->window, sfGreen);
    sfRenderWindow_drawSprite(my_game->window, my_game->map_sprite, NULL);
    if (my_game->show_sprites) {
        show_sprites(my_game, tower_tab);
    }
    if (my_game->show_hitboxes) {
        show_hitboxes(my_game, tower_tab);
    }
    sfRenderWindow_display(my_game->window);
}
