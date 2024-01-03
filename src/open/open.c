/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** open
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

char *open_file(char const *filepath)
{
    struct stat file_stat;
    int fd = open(filepath, O_RDONLY);
    char *buffer;

    if (fd == -1)
        return NULL;
    if (stat(filepath, &file_stat))
        return NULL;
    buffer = malloc(file_stat.st_size + 1);
    buffer[file_stat.st_size] = '\0';
    if (read(fd, buffer, file_stat.st_size) == -1)
        return NULL;
    close(fd);
    return buffer;
}
