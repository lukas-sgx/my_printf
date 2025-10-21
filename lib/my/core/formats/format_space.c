/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** format_space.c
*/

#include "../../../../include/my.h"
#include "../../../../include/myprintf.h"

int format_space(format_flags_t *format_f)
{
    if (format_f->space)
        my_putchar(' ');
    return 1;
}
