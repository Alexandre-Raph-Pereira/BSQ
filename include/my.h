/*
** EPITECH PROJECT, 2018
** malib.h
** File description:
** malib
*/

#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "struct.h"

void my_putchar (char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int **put_num_in_arr(char **str2, int y_max, int x_max);
int calc_0_arr(arr_t arr, int x_max, int y_max);
struct_t find_biggest_square_A(arr_t *arr, char **str, int y_max, int x_max);
void disp_biggest_square(char **str2, struct_t square, int *y, int y_max);
void initialisation(struct_t *s_1, struct_t *s_max, int y_max, int x_max);
int send_biggest_square(arr_t *arr, struct_t s1, struct_t s2);
struct_t comparaison_square(int x, int y, int taille, struct_t *square);
void condition(struct_t square, char **str2, int x, int *y, int x_max);
void disp_square(struct_t square, char **str2, int y_max, int x_max);
int fs_print_first_line(char const *filepath);
int calc_taille_nb_cols(char const *str, int u);
int taille_nb_rows(char const *str);
char **load_2d_arr(char const *filepath, int nb_rows, int *nb_cols, char **str);
char *load_file_in_mem(char const *filepath, long unsigned int *size, int *y);

#endif /* ! BSQ_H */
