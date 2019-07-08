/*
** EPITECH PROJECT, 2018
** load_2d_arr_from_file.c
** File description:
** load_2d_arr_from_file
*/

#include "my.h"

int calc_taille_nb_cols(char const *str, int u)
{
    int i = 0;

    while(str[u] != '\n') {
        i++;
        u++;
    }
    return (i);
}

int taille_nb_rows(char const *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    i++;
    return (i);
}

int string_length(char **str, int nb_rows)
{
    int i = 1;

    while (i < nb_rows) {
        if (my_strlen(str[i]) != my_strlen(str[i - 1]))
            return (1);
        else
            i++;
    }
    return (0);
}

char **load_2d_arr(char const *filepath, int nb_rows, int *nb_cols, char **str)
{
    int i = 0;
    int j = 0;
    int u = taille_nb_rows(filepath);

    str = malloc(sizeof(char *) * nb_rows);
    (*nb_cols) = calc_taille_nb_cols(filepath, u);
    while (filepath[u] != '\0') {
        str[i] = malloc(sizeof(str[i]) * (*nb_cols));
        while (filepath[u] != '\n') {
            str[i][j] = filepath[u];
            u++;
            j++;
        }
        j = 0;
        u++;
        i++;
    }
    if (i != nb_rows || string_length(str, nb_rows) == 1)
        return (NULL);
    return (str);
}
