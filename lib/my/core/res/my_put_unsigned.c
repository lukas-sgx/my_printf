/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/my.h"

int my_put_unsigned(unsigned int nb)
{
    int count = 0;

    if (nb >= 10)
        count = my_put_unsigned(nb / 10);
    my_putchar((nb % 10) + '0');
    count++;
    return count;
}
