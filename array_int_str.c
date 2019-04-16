/*
** EPITECH PROJECT, 2018
** include functions
** File description:
** include functions
*/
#include "include/my.h"

void find_biggiest_two(coordonne *cor, variable *var, int i, int z)
{
    if (var->tbl[i][z] > cor->biggiest)
        cor->biggiest = var->tbl[i][z];
}

void find_biggiest(coordonne *cor, variable *var)
{
    cor->biggiest = 0;

    for (int i = 0; i != var->nbr_line; i++) {
        for (int z = 0; z != var->nbr_column; z++)
            find_biggiest_two(cor, var, i, z);
    }
}

char *rewrite_str(char *map, variable *var, coordonne *cor)
{
    int i = 0;
    int j = 0;
    int haut_gauche;
    int haut_droit;

    for (i; map[i] != 'x'; i++);
    for (j; map[j] != '\n'; j++);
    haut_droit = (i - ((j+1)*(cor->biggiest-1)));
    haut_gauche = (i - ((j+1)*(cor->biggiest-1)) - (cor->biggiest-1));
    for (int k = 0; k != cor->biggiest; k++) {
        for (int z = haut_gauche; z != haut_droit + 1; z++) {
            map[z] = 'x';
        }
        haut_gauche = haut_gauche + (j+1);
        haut_droit = haut_droit + (j+1);
    }
    return (map);
}

char *array_int_to_str_two(temporel *tem, variable *var, char *map)
{
    if (tem->tempo == var->nbr_column) {
        map[tem->map_i] = '\n';
        tem->map_i++;
        tem->tempo = 0;
    }
    return (map);
}

char *array_int_to_str_three(variable *var, coordonne *cor,
temporel *tem, char *map)
{
    if (var->tbl[tem->i][tem->z] == cor->biggiest && tem->first == 0) {
        map[tem->map_i] = 'x';
        tem->first = 1;
    } else if (var->tbl[tem->i][tem->z] == 0)
        map[tem->map_i] = 'o';
    else
        map[tem->map_i] = '.';
    tem->map_i++;
    return (map);
}