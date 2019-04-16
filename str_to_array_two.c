/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** str to array
*/
#include "include/my.h"

void nbrline(variable *var)
{
    var->nbr_line = -1;

    for (unsigned long e = 0; var->str[e] != '\0'; e++) {
        if (var->str[e] == '\n')
            var->nbr_line++;
    }
    return;
}

void nbrcolumn(variable *var)
{
    unsigned long i = 0;
    var->nbr_column = 0;

    for (i; var->str[i] != '\n'; i++);
    var->nbr_column = i;
    for (var->nbr_column; var->str[var->nbr_column + 1]
    != '\n'; var->nbr_column++);
    var->nbr_column = var->nbr_column - i;
    return;
}

void len(variable *var)
{
    for (var->len_first_line = 0; var->str[var->len_first_line]
    != '\n'; var->len_first_line++);
    var->len_first_line = var->len_first_line + 1;
    return;
}

int good_nbr_two(int **tbl, int c, int rank_tbl)
{
    if (tbl[rank_tbl-1][c] < tbl[rank_tbl-1][c-1] && tbl[rank_tbl-1][c]
        < tbl[rank_tbl][c-1] || tbl[rank_tbl-1][c] == tbl[rank_tbl-1][c-1] &&
        tbl[rank_tbl-1][c] < tbl[rank_tbl][c-1] || tbl[rank_tbl-1][c] <
        tbl[rank_tbl-1][c-1] && tbl[rank_tbl-1][c] == tbl[rank_tbl][c-1])
        return (tbl[rank_tbl-1][c]+1);
    else if (tbl[rank_tbl-1][c-1] < tbl[rank_tbl-1][c] && tbl[rank_tbl-1][c-1]
        < tbl[rank_tbl][c-1] || tbl[rank_tbl-1][c-1] == tbl[rank_tbl-1][c] &&
        tbl[rank_tbl-1][c-1] < tbl[rank_tbl][c-1] || tbl[rank_tbl-1][c-1] <
        tbl[rank_tbl-1][c] && tbl[rank_tbl-1][c-1] == tbl[rank_tbl][c-1])
        return (tbl[rank_tbl-1][c-1]+1);
    else
        return (tbl[rank_tbl][c-1]+1);
}

int good_nbr(int **tbl, int c, int rank_tbl)
{
    if (tbl[rank_tbl][c - 1] == tbl[rank_tbl - 1][c]
        && tbl[rank_tbl][c - 1] == tbl[rank_tbl - 1][c - 1])
        return (tbl[rank_tbl - 1][c] + 1);
    else
        return (good_nbr_two(tbl, c, rank_tbl));
}