/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** radar
*/

#ifndef RADAR_H_
    #define RADAR_H_

    #include <SFML/Graphics.h>

typedef struct circle_s {
    sfCircleShape *circle;
    sfBool alone;
} circle_t;

typedef struct rectangle_4_s {
    sfIntRect one;
    sfIntRect two;
    sfIntRect three;
    sfIntRect four;
} rectangle_4_t;

// bootstrap
sfRenderWindow *window_init(sfVideoMode mode);
sfCircleShape *create_circle(sfVector2f position, float radius);
int is_interecting_circles(sfCircleShape *c1, sfCircleShape *c2);

//print fps
void print_framerate(void);

// handle event
void handle_close_window(sfRenderWindow *window, sfEvent *event);
#endif /* !RADAR_H_ */
