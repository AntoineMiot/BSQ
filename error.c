/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** Find the biggiest square
*/
#include "include/my.h"

void error_nbrline(variable *var)
{
    int i = 0;
    int z = 0;
    char *nbr_start;
    int nbr_start_int;

    for (i; var->str[i] != '\n'; i++);
    nbr_start = malloc(sizeof(char) * (i + 1));
    for (z; z != i; z++) {
        nbr_start[z] = var->str[z];
    }
    nbr_start[z + 1] = '\0';
    nbr_start_int = my_getnbr(nbr_start);
    if (nbr_start_int != var->nbr_line)
        exit(84);
}

void error_map(variable *var)
{
    for (int i = 0; var->str[i] != '\0'; i++) {
        if (var->str[i] < 48 && var->str[i] > 57 && var->str[i]
            != '.' && var->str[i] != '\n' && var->str[i] != 'o')
            exit(84);
    }
}

void error_map_line_int(variable *var)
{
    int i = 0;

    for (i; var->str[i] != '\n'; i++);
    for (int z = 0; z != i; z++) {
        if (var->str[z] < 48 && var->str[z] > 57)
            exit(84);
    }
}

void disp_error(variable *var)
{
    error_nbrline(var);
    error_map(var);
    error_map_line_int(var);
}