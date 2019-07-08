/*
** EPITECH PROJECT, 2018
** disp_square.c
** File description:
** disp_square
*/

#include "my.h"

int send_biggest_square(arr_t *arr, struct_t s1, struct_t s2)
{
    int x_f = arr->x;
    int y_f = arr->y;
    int result = 0;

    while (x_f <= s2.x && y_f <= s2.y) {
        result = calc_0_arr(*arr, x_f, y_f);
        if (result == 0) {
            x_f++;
            y_f++;
        }
        else {
            return (y_f - arr->y - 1);
        }
    }
    if (result == 0)
        return (y_f - arr->y -1);
    else
        return (0);
}

struct_t comparaison_square(int x, int y, int taille, struct_t *square)
{
    if (taille > square->t) {
        square->x = x;
        square->y = y;
        square->t = taille;
    }
}

void condition(struct_t square, char **str2, int x, int *y, int x_max)
{
    while ((*y) >= square.y && (*y) < square.y + square.t) {
        if (x >= square.x && x < square.x + square.t)
            my_putchar('x');
        else
            my_putchar(str2[(*y)][x]);
        x++;
        if (x == x_max) {
            my_putchar('\n');
            (*y)++;
            x = 0;
        }
    }
}

void disp_square(struct_t square, char **str2, int y_max, int x_max)
{
    int x = square.x;
    int y = square.y;
    int length = my_strlen(str2[0]);

    while (y < square.y + square.t) {
        while (x < square.x + square.t) {
            str2[y][x] = 'x';
            x++;
        }
        x = square.x;
        y++;
    }
    y = 0;
    while (y < y_max) {
        write(1, str2[y], length);
        my_putchar('\n');
        y++;
    }
}
