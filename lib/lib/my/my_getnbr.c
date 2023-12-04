/*
** EPITECH PROJECT, 2023
** C-POOL
** File description:
** my_getnbr.c
*/

#include "my.h"

static int find_digit(char const *str)
{
    int i = 0;

    while (!is_digit(str[i]))
        i++;
    return i;
}

static int find_letter(char const *str)
{
    int i = 0;

    while (is_digit(str[i]))
        i++;
    return i;
}

static int find_sign(char const *str, int nb_start)
{
    int i = 1;
    int sign = 1;
    char value;

    do {
        value = str[nb_start - i];
        if (value == '-')
            sign = -sign;
        i++;
    } while (i <= nb_start && (value == '-' || value == '+'));
    return sign;
}

static int build_nbr(char const *str, int nbr_length, int nb_start)
{
    int i = nbr_length;
    int j = nb_start;
    int nb = 0;

    while (i > 0) {
        set_digit(&nb, i, str[j] - '0');
        i--;
        j++;
    }
    return nb;
}

int my_getnbr(char const *str)
{
    int nb;
    int start = find_digit(str);
    int end = find_letter(str + start) + start;
    int sign = find_sign(str, start);

    nb = build_nbr(str, end - start, start);
    return nb < 0 ? 0 : nb * sign;
}
