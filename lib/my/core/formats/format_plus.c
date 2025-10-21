/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** format_plus.c
*/

#include "my.h"
#include "../../../../include/myprintf.h"

void format_plus(format_flags_t *format_f)
{
    if (format_f->plus)
        my_putchar('+');
}
