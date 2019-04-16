/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** Find the biggiest square
*/
#include "include/my.h"

char *array_int_to_str(variable *var, temporel *tem)
{
    char *map = malloc(sizeof(char)*((var->nbr_column+1)*(var->nbr_line+1)));
    tem->map_i = 0;
    tem->tempo = 0;
    tem->first = 0;

    struct coordonne cor;
    find_biggiest(&cor, var);
    for (int i = 0; i != var->nbr_line; i++) {
        for (int z = 0; z != var->nbr_column; z++) {
            map = array_int_to_str_two(tem, var, map);
            tem->tempo++;
            tem->i = i;
            tem->z = z;
            map = array_int_to_str_three(var, &cor, tem, map);
        }
    }
    map[tem->map_i] = '\n';
    return (rewrite_str(map, var, &cor));
}

void distrib_var(char const *str, variable *var)
{
    struct temporel tem;
    map_str(str, var);
    len(var);
    nbrline(var);
    disp_error(var);
    nbrcolumn(var);
    str_array(var, &tem);
    my_putstr(array_int_to_str(var, &tem));
}

int main(int ac, char **av)
{
    struct variable var;
    if (ac != 2)
        return (84);
    distrib_var(av[1], &var);
    return (0);
}