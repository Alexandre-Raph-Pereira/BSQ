/*
** EPITECH PROJECT, 2018
** disp_biggest_square.c
** File description:
** disp_square
*/

#include "my.h"

void initialisation(struct_t *s_1, struct_t *s_max, int y_max, int x_max)
{
    s_max->x = x_max;
    s_max->y = y_max;
    s_1->x = x_max;
    s_1->y = y_max;
    s_1->t = 0;
}
