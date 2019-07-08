/*
** EPITECH PROJECT, 2018
** fs_print_first_line.c
** File description:
** printf_first_line
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "my.h"

int fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[500];
    char number[11];
    int i = 0;

    if (fd == -1)
        return (-1);
    if (read(fd, buffer, 500) == -1)
        return (-1);
    while (buffer[i] != '\n') {
        number[i] = buffer[i];
        i++;
    }
    close(fd);
    return (my_getnbr(number));
}
