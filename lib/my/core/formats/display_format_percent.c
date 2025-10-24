/*
** EPITECH PROJECT, 2025
** MyPrintf
** File description:
** display_format_p.c
*/

#include <stdio.h>

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static void display_minus(format_flags_t *format_f, int pad)
{
    if (format_f->minus)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
}

int display_format_percent(format_flags_t *format_f,
    int *count)
{
    int len = 1;
    int pad = (format_f->width > len)
        ? format_f->width - len : 0;

    my_putchar('%');
    *count += len + pad;
    display_minus(format_f, pad);
    return *count;
}
