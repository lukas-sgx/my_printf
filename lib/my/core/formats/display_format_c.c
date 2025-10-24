/*
** EPITECH PROJECT, 2025
** MyPrintf
** File description:
** display_format_c.c
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

int display_format_c(char c, format_flags_t *format_f,
    int *count)
{
    int len = c > 0 ? 1 : 0;
    int pad = (format_f->width > len)
        ? format_f->width - len : 0;

    my_putchar(c);
    *count += len + pad;
    display_minus(format_f, pad);
    return *count;
}

int display_format_wc(unsigned int c, format_flags_t *format_f,
    int *count)
{
    int len = c > 0 ? 1 : 0;
    int pad = (format_f->width > len)
        ? format_f->width - len : 0;

    my_putwchar(c);
    *count += len + pad;
    display_minus(format_f, pad);
    return *count;
}
