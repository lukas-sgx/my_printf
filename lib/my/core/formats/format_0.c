/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** format_0.c
*/

#include "../../../../include/my.h"
#include "../../../../include/myprintf.h"

int format_zero(format_flags_t *format_f, int count)
{
    int printed = 0;

    if (format_f->zero) {
        for (int i = 0; i < format_f->width - count; i++) {
            my_putchar('0');
            printed++;
        }
    }
    return printed;
}
