/*
** EPITECH PROJECT, 2023
** C-POOL
** File description:
** my_str_to_word_array.c
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

char char_word(char const *str, int n, int nl, char ch)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && str[i] != ch) {
            sp = 0;
            nb++;
        }
        sp = (str[i] == ch) ? 1 : 0;
        let += (str[i] != ch && nb == n) ? 1 : 0;
        if (let == nl)
            return (str[i]);
        i++;
    }
    return ('\0');
}

int nb_char(char const *str, int n, char ch)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && str[i] != ch) {
            sp = 0;
            nb++;
        }
        sp = (str[i] == ch) ? 1 : 0;
        let += (str[i] != ch && nb == n) ? 1 : 0;
        i++;
    }
    return (let);
}

int nb_word(char const *str, char ch)
{
    int i = 0;
    int sp = 1;
    int nb = 0;

    while (str[i] != '\0') {
        if (sp == 1 && str[i] != ch) {
            sp = 0;
            nb++;
        }
        sp = (str[i] == ch) ? 1 : 0;
        i++;
    }
    return (nb);
}

char **my_str_to_word_array(char const *str, char ch)
{
    int y = 0;
    int x = 0;
    char **tab = malloc(sizeof(char *) * (nb_word(str, ch) + 1));

    while (y < nb_word(str, ch)) {
        tab[y] = malloc(sizeof(char) * (nb_char(str, y + 1, ch) + 1));
        x = 0;
        while (x < nb_char(str, y + 1, ch)) {
            tab[y][x] = char_word(str, y + 1, x + 1, ch);
            x++;
        }
        tab[y][x] = '\0';
        y++;
    }
    tab[y] = 0;
    return (tab);
}
