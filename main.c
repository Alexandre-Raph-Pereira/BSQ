/*
** EPITECH PROJECT, 2018
** main_bsq.c
** File description:
** main_bsq
*/

#include "my.h"

int **put_num_in_arr(char **str2, int y_max, int x_max)
{
    int i = 0;
    int u = 0;
    int **arr = malloc(sizeof(int *) * (y_max));

    while(u < y_max) {
        arr[u] = malloc(sizeof(int) * x_max);
        u++;
    }
    u = 0;
    while (u < y_max) {
        if (str2[u][i] == '.')
            arr[u][i] = 0;
        else if (str2[u][i] == 'o')
            arr[u][i] = 1;
        i++;
        if (i == x_max) {
            i = 0;
            u++;
        }
    }
    return (arr);
}

int calc_0_arr(arr_t arr, int x_max, int y_max)
{
    int result = 0;
    int x_init = arr.x;
    int y_init = arr.y;

    while (arr.y < y_max) {
        arr.x = x_init;
        while (arr.x < x_max) {
            result = result + arr.arr[arr.y][arr.x];
            arr.x++;
        }
        arr.y++;
    }
    return (result);
}

struct_t find_biggest_square_A(arr_t *arr, char **str, int y_max, int x_max)
{
    int taille = 0;
    struct_t square_1;
    struct_t square_max;

    arr->x = 0;
    arr->y = 0;
    initialisation(&square_1, &square_max, y_max, x_max);
    while (arr->y + square_1.t < y_max) {
        while (arr->x + square_1.t < x_max) {
            taille = send_biggest_square(arr, square_1, square_max);
            comparaison_square(arr->x, arr->y, taille, &square_1);
            arr->x++;
            taille = 0;
        }
        arr->x = 0;
        arr->y++;
    }
    return (square_1);
}

void free_function(char *str, char **str2, arr_t arr)
{
    free(str);
    free(arr.arr);
    free(str2);
}

int main(int argc, char **argv)
{
    int y_max = 0;
    int x_max = 0;
    char *str;
    char **str2;
    struct_t square;
    arr_t arr;
    long unsigned int size;

    if (argc != 2)
        return (84);
    str = load_file_in_mem(argv[1], &size, &y_max);
    if (y_max == -1 || str == NULL)
        return (84);
    str2 = load_2d_arr(str, y_max, &x_max, str2);
    if (str2 == NULL)
        return (84);
    arr.arr = put_num_in_arr(str2, y_max, x_max);
    square = find_biggest_square_A(&arr, str2, y_max, x_max);
    disp_square(square, str2, y_max, x_max);
    free_function(str, str2, arr);
    return (0);
}
