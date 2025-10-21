/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/my.h"
#include <stdlib.h>

int my_putstr(char const *str)
{
    int i;

    if (str == NULL)
        str = "(null)";
    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return i;
}
