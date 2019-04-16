/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** str to array
*/
#include "include/my.h"

int **str_array_three(int **tbl, temporel *tem)
{
    if (tem->c == 0)
        tbl[tem->rank_tbl][tem->c] = 1;
    else
        tbl[tem->rank_tbl][tem->c] = good_nbr(tbl, tem->c, tem->rank_tbl);
    return (tbl);
}

int **str_array_two(int **tbl, variable *var, temporel *tem)
{
    if (tem->rank_tbl == 0) {
        if (var->str[var->len_first_line] == '.')
            tbl[tem->rank_tbl][tem->c] = 1;
        else if (var->str[var->len_first_line] == 'o')
            tbl[tem->rank_tbl][tem->c] = 0;
        tem->c = tem->c + 1;
    } else {
        if (var->str[var->len_first_line] == '.')
            tbl = str_array_three(tbl, tem);
        else if (var->str[var->len_first_line] == 'o')
            tbl[tem->rank_tbl][tem->c] = 0;
        tem->c = tem->c + 1;
    }
    return (tbl);
}

void str_array(variable *var, temporel *tem)
{
    tem->c = 0;
    tem->rank_tbl = 0;
    int **tbl = malloc(sizeof(int*) * (var->nbr_line));

    tbl[tem->rank_tbl] = malloc(sizeof(int) * (var->nbr_column));
    for (var->len_first_line; var->str[var->len_first_line] != '\0';) {
        if (var->str[var->len_first_line] == '\n') {
            tem->rank_tbl = tem->rank_tbl + 1;
            tbl[tem->rank_tbl] = malloc(sizeof(int) * (var->nbr_column));
            tem->c = 0;
            var->len_first_line++;
        }
        tbl = str_array_two(tbl, var, tem);
        var->len_first_line = var->len_first_line + 1;
    }
    var->tbl = tbl;
}

void map_str(char const *str, variable *var)
{
    struct stat s;
    char *buff;
    unsigned long fd;

    stat(str, &s);
    buff = malloc(sizeof(char) * s.st_size);
    fd = open(str, O_RDONLY);
    if (fd == -1)
        exit(84);
    read(fd, buff, s.st_size);
    close(fd);
    var->str = buff;
    return;
}