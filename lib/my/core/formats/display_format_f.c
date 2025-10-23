/*
** EPITECH PROJECT, 2025
** MyPrintf
** File description:
** display_format_f.c
*/

#include <stdio.h>

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static void show_sign(char *sign_char, int pad)
{
    if (*sign_char) {
        my_putchar(*sign_char);
        *sign_char = 0;
    }
    for (int i = 0; i < pad; i++)
        my_putchar('0');
}

static void show_pad(int pad, char *sign_char)
{
    for (int i = 0; i < pad; i++)
        my_putchar(' ');
    if (*sign_char) {
        my_putchar(*sign_char);
        *sign_char = 0;
    }
}

static void select_char(char *sign_char, long long int nb,
    format_flags_t *format_f, int pad)
{
    if (nb < 0 && nb > -2147483648)
        *sign_char = '-';
    if (format_f->plus && nb > 0)
        *sign_char = '+';
    if (nb > 0 && format_f->space && !format_f->plus)
        *sign_char = ' ';
    if (!format_f->minus) {
        if (format_f->zero) {
            show_sign(sign_char, pad);
        } else {
            show_pad(pad, sign_char);
        }
    } else {
        if (*sign_char) {
            my_putchar(*sign_char);
            *sign_char = 0;
        }
    }
}

static void display_minus(long long int nb, format_flags_t *format_f, int pad)
{
    if (format_f->minus && nb > 0)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
    if (nb < 0 && format_f->minus && pad > 0)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
}

int display_format_double(double nb, format_flags_t *format_f, int *count)
{
    int len = count_double(nb, format_f->precision);
    int sign = (nb < 0 || format_f->plus || format_f->space)
        ? 1 : 0;
    int minus = nb < 0 ? 1 : 0;
    int pad = (format_f->width + minus > len + sign + format_f->precision)
        ? format_f->width + minus - (len + sign + format_f->precision) : 0;
    char sign_char = 0;

    if (format_f->precision == -1)
        pad -= 7;
    select_char(&sign_char, nb, format_f, pad);
    *count += my_putfloat(nb < 0 ? -nb : nb, format_f->precision);
    display_minus(nb, format_f, pad);
    return *count;
}
