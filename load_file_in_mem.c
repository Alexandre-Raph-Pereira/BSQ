/*
** EPITECH PROJECT, 2018
** load_file_in_mem.c
** File description:
** load_file_in_mem
*/

#include <stdlib.h>
#include "my.h"

int check_read(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n' || str[i] == '.' || str[i] == 'o' ||
            (str[i] >= '0' && str[i] <= '9'))
            i++;
        else
            return (-1);
    }
    return (0);
}

char *load_file_in_mem(char const *filepath , long unsigned int *size, int *y)
{
    int fd;
    char *str = NULL;
    struct stat sb;

    fd = open(filepath, O_RDONLY);
    if (stat(filepath, &sb) == -1 || fd == -1)
        return (NULL);
    else {
        str = malloc(sizeof(char *) * sb.st_size + 1);
        if (str == NULL)
            return (NULL);
        if (read(fd, str, sb.st_size) == -1)
            return (NULL);
    }
    if (close(fd) == -1 || str[0] == '\0' || check_read(str) == -1)
        return (NULL);
    (*size) = sb.st_size;
    (*y) = my_getnbr(str);
    return (str);
}
