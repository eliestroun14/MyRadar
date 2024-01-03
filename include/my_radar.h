/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** my_radar
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_
    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef struct vector_s {
    int x;
    int y;
} vector_t;

typedef struct aircraft_s {
    int id;
    int speed;
    int delay;
    sfVector2f *pos;
    sfVector2f dest;
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *rect;
} aircraft_t;

typedef struct tower_s {
    int rad;
    sfVector2f pos;
    sfCircleShape *rad_circle;
    sfTexture *texture;
    sfSprite *sprite;
} tower_t;

typedef struct radar_link_list_s {
    aircraft_t *plane;
    struct radar_link_list_s *next;
} radar_link_list_t;

typedef struct game_s {
    radar_link_list_t *head;
    sfRenderWindow *window;
    sfClock *game_clock;
    sfTexture *map_texture;
    sfSprite *map_sprite;
    sfEvent event;
    bool show_hitboxes;
    bool show_sprites;
    int plane_count;
    int id_nb;
} game_t;


int my_radar(char const *av, game_t *global, tower_t **tab_tower);
int simulation(game_t *my_game, tower_t **tower_tab);
//open file
char *open_file(char const *filepath);

//plane linked_list
int fill_plane(char **sub_tab, game_t *global);
int destroy_plane(int id1, int id2, game_t *my_game);
int del_plane(radar_link_list_t *tmp, radar_link_list_t *previous,
    radar_link_list_t **head);

//tower_t array
tower_t **fill_tower(char **sub_tab, tower_t **tower_tab, int *nb_tower);

// update plane
int update_plane(game_t *my_game, tower_t **tower_tab);


// lib in comming
sfTexture *texture_init(char const *path);
sfRenderWindow *window_init(int mode_size1, int mode_size2, char *name);
int handle_event(game_t *my_game);
void render_simulation(game_t *my_game, tower_t **tower_tab);

    #define P_sprite plane->sprite
    #define P_texture plane->texture
#endif /* !MY_RADAR_H_ */
