/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** simulation
*/
#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <stddef.h>

int init_game(game_t *my_game)
{
    my_game->show_hitboxes = true;
    my_game->show_sprites = true;
    my_game->window = window_init(1920, 1080, "Radar simulation");
    if (my_game->window == NULL)
        return 84;
    my_game->map_texture = texture_init("assets/map.png");
    my_game->map_sprite = sfSprite_create();
    sfSprite_setTexture(my_game->map_sprite, my_game->map_texture, sfTrue);
    my_game->game_clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(my_game->window, 60);
    return 0;
}

//destroy_game();
int simulation(game_t *my_game, tower_t **tower_tab)
{
    if (init_game(my_game) == 84)
        return 84;
    while (sfRenderWindow_isOpen(my_game->window)) {
        handle_event(my_game);
        update_plane(my_game, tower_tab);
        render_simulation(my_game, tower_tab);
    }
    return 0;
}
