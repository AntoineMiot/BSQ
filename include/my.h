/*
** EPITECH PROJECT, 2018
** include functions
** File description:
** include functions
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

struct variable{
    int **tbl;
    char *str;
    unsigned long nbr_column;
    unsigned long nbr_line;
    int len_first_line;
};

typedef struct variable variable;

struct coordonne{
    int rank_tbl;
    int c;
    int biggiest;
    int h_g_x;
    int h_d_x;
    int b_g_x;
    int b_d_x;
    int h_g_y;
    int h_d_y;
    int b_g_y;
    int b_d_y;
};

typedef struct coordonne coordonne;

struct temporel{
    int tempo;
    int map_i;
    int first;
    int c;
    int rank_tbl;
    int i;
    int z;
};

typedef struct temporel temporel;
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int check_number(char *str);
int my_getnbr(char const *str);
void my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int nb_special(long nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
int low(char c);
int up(char c);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_str_isalpha(char *str);
char *my_str_islower(char *str);
char *my_str_isnum(char *str);
char *my_str_isprintable(char *str);
char *my_str_isupper(char *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int nb);
char *my_strstr(char *str, char *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void *infin_add(char *nb1, char *nb2);
int my_str_taller(char const *s1, char const *s2);
char *big_nb(char *nb1, char *nb2);
char *small_nb(char *nb1, char *nb2);
int my_str_is_equal(char *str1, char *str2);
void my_put_infinadd(int ret, char *nb, int type);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
void map_str(char const *str, variable *var);
void len(variable *var);
void nbrline(variable *var);
void nbrcolumn(variable *var);
void str_array(variable *var, temporel *tem);
void distrib_square(coordonne *coor, variable *var);
void find_biggiest(coordonne *cor, variable *var);
char *rewrite_str(char *map, variable *var, coordonne *cor);
char *array_int_to_str_two(temporel *tem, variable *var, char *map);
char *array_int_to_str_three(variable *var, coordonne *cor,
temporel *tem, char *map);
char *array_int_to_str(variable *var, temporel *tem);
void disp_error(variable *var);
int good_nbr(int **tbl, int c, int rank_tbl);