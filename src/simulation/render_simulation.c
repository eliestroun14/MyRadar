/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** render_simulation
*/
#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <stddef.h>

static void show_sprites(game_t *my_game, tower_t **tower_tab)
{
    radar_link_list_t *tmp = my_game->head;

    for (int i = 0; tower_tab[i] != NULL; ++i) {
        sfRenderWindow_drawSprite(my_game->window, tower_tab[i]->sprite,
            NULL);
    }
    while (tmp != NULL) {
        if (tmp->plane->is_waiting) {
        sfRenderWindow_drawSprite(my_game->window, tmp->plane->sprite, NULL);
        }
        tmp = tmp->next;
    }
}

static void show_hitboxes(game_t *my_game, tower_t **tower_tab)
{
    radar_link_list_t *tmp = my_game->head;

    for (int i = 0; tower_tab[i] != NULL; ++i) {
            sfRenderWindow_drawCircleShape(my_game->window,
                tower_tabcs[i]->rad_circle, NULL);
    }
    while (tmp != NULL) {
        if (tmp->plane->is_waiting) {
        sfRenderWindow_drawRectangleShape(my_game->window,
        tmp->plane->rect, NULL);
        }
        tmp = tmp->next;
    }
}

static void set_text(char *minutes, char *seconds, sfFont *font,
    sfRenderWindow *window)
{
    sfText *text_min = sfText_create();
    sfText *text_sec = sfText_create();

    sfText_setString(text_min, minutes);
    sfText_setString(text_sec, seconds);
    sfText_setFont(text_min, font);
    sfText_setFont(text_sec, font);
    sfText_setCharacterSize(text_min, 50);
    sfText_setCharacterSize(text_sec, 50);
    sfText_setColor(text_min, sfRed);
    sfText_setColor(text_sec, sfRed);
    sfText_setPosition(text_min, (sfVector2f){1810, 0});
    sfText_setPosition(text_sec, (sfVector2f){1855, 0});
    sfRenderWindow_drawText(window, text_min, NULL);
    sfRenderWindow_drawText(window, text_sec, NULL);
}

static int show_timer(sfClock *timer, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(timer);
    sfFont *font;
    float sec = time.microseconds / 1000000.0f;
    int min = 0;
    char *minutes;
    char *seconds;

    for (; sec - 60 >= 0; sec -= 60)
        min++;
    minutes = int_to_char(min);
    seconds = int_to_char(sec);
    font = sfFont_createFromFile("assets/font.otf");
    set_text(minutes, seconds, font, window);
    return 0;
}

static int show_sp(game_t *my_game)
{
    int speed_to_char = SP;
    char *speed_char;
    sfText *text_sp = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.otf");

    if (SP >= 1) {
        speed_char = int_to_char(speed_to_char);
        sfText_setString(text_sp, speed_char);
        sfText_setFont(text_sp, font);
        sfText_setCharacterSize(text_sp, 50);
        sfText_setColor(text_sp, sfRed);
        sfText_setPosition(text_sp, (sfVector2f){10, 0});
        sfRenderWindow_drawText(my_game->window, text_sp, NULL);
    }
    return 0;
}

void render_simulation(game_t *my_game, tower_t **tower_tab)
{
    sfRenderWindow_clear(my_game->window, sfWhite);
    sfRenderWindow_drawSprite(my_game->window, my_game->map_sprite, NULL);
    if (my_game->show_sprites) {
        show_sprites(my_game, tower_tab);
    }
    if (my_game->show_hitboxes) {
        show_hitboxes(my_game, tower_tab);
    }
    show_timer(my_game->timer, my_game->window);
    show_sp(my_game);
    sfRenderWindow_display(my_game->window);
}
