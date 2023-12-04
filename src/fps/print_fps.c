/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** print_fps
*/

#include <SFML/Graphics.h>
#include <stdio.h>

void print_framerate(void)
{
    static int first = 1;
    static sfClock * clock ;
    static int fps = 0;
    sfTime elapsed;

    if ( first == 1) {
        clock = sfClock_create () ;
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
        if (sfTime_asSeconds(elapsed) >= 1) {
        printf ("%3d FPS \r",fps);
        fflush (stdout) ;
        fps = 0;
        sfClock_restart ( clock ) ;
    }
    else
        fps++;
}