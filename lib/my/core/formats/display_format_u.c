/*
** EPITECH PROJECT, 2025
** MyPrintf
** File description:
** display_format_u.c
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"
#include <stdio.h>

static void show_sign(int pad)
{
    for (int i = 0; i < pad; i++)
        my_putchar('0');
}

static void show_pad(int pad)
{
    for (int i = 0; i < pad; i++)
        my_putchar(' ');
}

static void display_precision(format_flags_t *format_f)
{
    if ((format_f->precision) > 0)
        for (int i = 0; i < (format_f->precision); i++)
            my_putchar('0');
}

static void select_char(format_flags_t *format_f, int pad)
{
    if (!format_f->minus) {
        if (format_f->zero) {
            show_sign(pad);
        } else {
            show_pad(pad);
        }
    }
    display_precision(format_f);
}

static void display_minus(format_flags_t *format_f, unsigned long long int nb)
{
    if (format_f->minus)
        for (int i = 0; i < format_f->width - (
                format_f->precision + count_udlint(nb)); i++)
            my_putchar(' ');
}

int display_format_uint(unsigned int nb, format_flags_t *format_f, int *count)
{
    int len = count_uint(nb);
    int precision = (-count_udlint(nb) + format_f->precision) > 0 ?
        (-count_udlint(nb) + format_f->precision) : 0;
    int pad = (format_f->width > len + precision)
        ? format_f->width - (len + precision) : 0;

    format_f->precision = precision;
    select_char(format_f, pad);
    *count += my_put_unsigned(nb);
    display_minus(format_f, nb);
    return *count;
}

int display_format_ulint(unsigned long int nb,
    format_flags_t *format_f, int *count)
{
    int len = count_uint(nb);
    int precision = (-count_udlint(nb) + format_f->precision) > 0 ?
        (-count_udlint(nb) + format_f->precision) : 0;
    int pad = (format_f->width > len + precision)
        ? format_f->width - (len + precision) : 0;

    format_f->precision = precision;
    select_char(format_f, pad);
    *count += my_put_lunsigned(nb);
    display_minus(format_f, nb);
    return *count;
}

int display_format_udlint(unsigned long long int nb,
    format_flags_t *format_f, int *count)
{
    int len = count_uint(nb);
    int precision = (-count_udlint(nb) + format_f->precision) > 0 ?
        (-count_udlint(nb) + format_f->precision) : 0;
    int pad = (format_f->width > len + precision)
        ? format_f->width - (len + precision) : 0;

    format_f->precision = precision;
    select_char(format_f, pad);
    *count += my_put_llunsigned(nb);
    display_minus(format_f, nb);
    return *count;
}
