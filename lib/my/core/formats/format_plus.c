/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** format_plus.c
*/

#include "../../../../include/my.h"
#include "../../../../include/myprintf.h"

int format_plus(format_flags_t *format_f, int nb)
{
    if (format_f->plus && nb > 0) {
        my_putchar('+');
        return 1;
    }
    return 0;
}
