/*
** EPITECH PROJECT, 2025
** MyPrintf
** File description:
** display_format_o.c
*/


#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static void display_precision(format_flags_t *format_f)
{
    if ((format_f->precision) > 0)
        for (int i = 0; i < (format_f->precision); i++)
            my_putchar('0');
}

static void show_padmin(int pad)
{
    for (int i = 0; i < pad; i++)
        my_putchar(' ');
}

static void show_zeromin(int pad)
{
    for (int i = 0; i < pad; i++)
        my_putchar('0');
}

static void select_min(
    format_flags_t *format_f, int pad)
{
    if (!format_f->minus) {
        if (format_f->zero) {
            show_zeromin(pad);
        } else {
            show_padmin(pad);
        }
    }
    display_precision(format_f);
}

static void display_min(format_flags_t *format_f, char *nb)
{
    if (format_f->minus && !format_f->hash)
        for (int i = 0; i < format_f->width - (
                format_f->precision + my_strlen(nb)); i++)
            my_putchar(' ');
    if (format_f->minus && format_f->hash)
        for (int i = 0; i < format_f->width - (
                format_f->precision + my_strlen(nb)) - 1; i++)
            my_putchar(' ');
}

int display_format_str_o(char *nb,
    format_flags_t *format_f, int *count)
{
    int len = my_strlen(nb);
    int precision = (-my_strlen(nb) + format_f->precision) > 0 ?
        (-my_strlen(nb) + format_f->precision) : 0;
    int pad = (format_f->width > len + precision)
        ? format_f->width - (len + precision) : 0;

    if (format_f->hash && format_f->zero)
        my_putstr("0");
    if (format_f->hash)
        pad -= 1;
    format_f->precision = precision;
    select_min(format_f, pad);
    if (format_f->hash && !format_f->zero)
        my_putstr("0");
    *count += my_putstr(nb);
    display_min(format_f, nb);
    return *count;
}
