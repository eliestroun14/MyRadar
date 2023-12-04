/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main
*/
#include <SFML/Graphics.h>
#include "../../include/radar.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// Renvoie un nombre aléatoire entre a et b
int get_random_number(int a, int b)
{
  return (rand() % (b - a + 1) + a);
}

// Renvoie un vecteur avec des valeurs aléatoires entre a et b
sfVector2f get_random_vector(int a, int b)
{
  return (sfVector2f){get_random_number(a, b), get_random_number(a, b)};
}

int fill_intersect(circle_t *c1, circle_t *c2)
{
    if (is_interecting_circles(c1->circle, c2->circle)) {
        sfCircleShape_setFillColor(c1->circle, sfWhite);
        sfCircleShape_setFillColor(c2->circle, sfWhite);
        c1->alone = sfFalse;
        c2->alone = sfFalse;
        return 0;
    } else {
        if (c1->alone)
            sfCircleShape_setFillColor(c1->circle, sfTransparent);
        if (c2->alone)
            sfCircleShape_setFillColor(c2->circle, sfTransparent);
        return 0;
    }
}

int check_intersec(circle_t **circles_tab, int nb_circles)
{
    int status = 0;

    for (int p = 0; p < nb_circles; p++)
        circles_tab[p]->alone = sfTrue;
    
    for (int i = 0; i < nb_circles; i++) {
        for (int j = 0; j < nb_circles; j++) {
            if (i == j)
                continue;
            if (sfIntRect_contains(rect, ) && sfIntRect_contains(rect, sfCircleShape_getOrigin(circles_tab[j])))
            fill_intersect(circles_tab[i], circles_tab[j]);

        }
    }
    return status;
}

int main(void)
{
    sfVideoMode mode = {1000, 1000, 64};
    sfRenderWindow *window = window_init(mode);
    sfEvent event;
    int nb_circles = 500;
    int a = 1;
    int b = 1000;
    sfVector2f rdm_pos;
    sfVector2f offset;
    sfVector2f origin;
    sfClock *clock = sfClock_create();
    sfTime time;
    float sec;

    circle_t **circle_tab = malloc(sizeof(circle_t *) * nb_circles);

    for (int i = 0; i < nb_circles; i++) {
        rdm_pos = get_random_vector(a, b);
        //printf("rdm_pos = [%f, %f]\n", rdm_pos.x, rdm_pos.y);
        circle_tab[i] = malloc(sizeof(circle_t));
        circle_tab[i]->circle = create_circle(rdm_pos, 10.0);
        circle_tab[i]->alone = sfTrue;
    }

    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        sec = time.microseconds / 100000.0f;
        print_framerate();
        if (sec > 0.25) {
            handle_close_window(window, &event);
            sfRenderWindow_clear(window, sfBlack);
            check_intersec(circle_tab, nb_circles);
            for (int i = 0; i < nb_circles; i++) {
                sfRenderWindow_drawCircleShape(window, circle_tab[i]->circle, NULL);
                offset = get_random_vector(1, 10);
                sfCircleShape_move(circle_tab[i]->circle, offset);
                origin = sfCircleShape_getPosition(circle_tab[i]->circle);
                if (origin.x > 1000.0f) {
                    origin.x = 0;
                    sfCircleShape_setPosition(circle_tab[i]->circle, origin);
                }
                if (origin.y > 1000.0f) {
                    origin.y = 0;
                    sfCircleShape_setPosition(circle_tab[i]->circle, origin);
                }
            }
            sfRenderWindow_display(window);
            sfClock_restart(clock);
        }
    }
    for (int i = 0; i < nb_circles; i++) {
        sfCircleShape_destroy(circle_tab[i]->circle);
    }
    free(circle_tab);
    sfRenderWindow_destroy(window);
}