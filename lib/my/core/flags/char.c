/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"

int char_d(va_list params, int count, length_mod_t mod)
{
    my_putchar(va_arg(params, int));
    count++;
    return count;
}
