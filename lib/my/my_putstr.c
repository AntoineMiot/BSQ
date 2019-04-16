/*
** EPITECH PROJECT, 2018
** swap
** File description:
** swap to integer
*/
#include <unistd.h>
int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}