/*
** EPITECH PROJECT, 2024
** my_radar (Workspace)
** File description:
** int_to_char
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my_radar.h"
#include <math.h>

float calculate_angle(sfVector2f point1, sfVector2f point2)
{
    return atan2(point2.y - point1.y, point2.x - point1.x) * 180 / M_PI;
}

char *int_to_char(int nbr)
{
    int temp = nbr;
    int num_digits = 0;
    char *result = NULL;

    while (temp != 0) {
        temp /= 10;
        num_digits++;
    }
    if (nbr == 0)
        num_digits = 1;
    result = malloc((num_digits + 1) * sizeof(char));
    if (result == NULL)
        return NULL;
    for (int i = num_digits - 1; i >= 0; i--) {
        result[i] = '0' + (nbr % 10);
        nbr /= 10;
    }
    result[num_digits] = '\0';
    return result;
}
