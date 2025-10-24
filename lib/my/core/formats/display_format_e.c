/*
** EPITECH PROJECT, 2025
** MyPrintf
** File description:
** display_format_e.c
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"
#include <stdio.h>

static double round_double(double nb, int precision)
{
    int power = 1;
    for (int i = 0; i < precision; i++)
        power *= 10;
    nb = (int)(nb * power + 0.5);
    return nb / (double)power;
}

static int value_pos(double nb, int count, int upper, format_flags_t *format_f)
{
    int e = 0;

    while (nb >= 10) {
        nb = nb / 10;
        e++;
    }
    nb = round_double(nb, format_f->precision);
    if (nb == 1.0 && format_f->precision != -2)
        my_putfloat(nb, 5);
    else
        my_putfloat(nb, format_f->precision);
    if (format_f->hash && format_f->precision == -2)
        my_putchar('.');
    if (upper)
        my_putchar('E');
    else
        my_putchar('e');
    my_putchar('+');
    if (e < 10)
        my_putchar('0');
    my_put_nbr(e);
    return count;
}

static int value_neg(double nb, int count, int upper, format_flags_t *format_f)
{
    int e = 0;

    while (nb < 1) {
        nb *= 10;
        e++;
    }
    nb = round_double(nb, format_f->precision);
    if (nb == 1.0 && !format_f->hash)
        my_putfloat(nb, 5);
    else
        my_putfloat(nb, format_f->precision);
    if (format_f->hash && format_f->precision == -2)
        my_putchar('.');
    if (upper)
        my_putchar('E');
    else
        my_putchar('e');
    my_putchar('-');
    if (e < 10)
        my_putchar('0');
    my_put_nbr(e);
    return count;
}

static int my_putscientific(double nb, int count, int upper, format_flags_t *format_f)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 1.0)
        return value_neg(nb, count, upper, format_f);
    if (nb >= 1.0)
        return value_pos(nb, count, upper, format_f);
    return count;
}

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

int display_format_double_e(double nb, format_flags_t *format_f, int *count)
{
    int len = count_double(nb, format_f->precision);
    int sign = (nb < 0 || format_f->plus || format_f->space)
        ? 1 : 0;
    int minus = nb < 0 ? 1 : 0;
    int pad = (format_f->width + minus > len + sign + format_f->precision + 2)
        ? format_f->width + minus - (len + sign + format_f->precision + 2) : 0;
    char sign_char = 0;

    if (format_f->precision == -1) {
        pad -= 9;
        format_f->precision = 6;
    }
    if (format_f->precision == -2) {
        pad--;
    }
    select_char(&sign_char, nb, format_f, pad);
    *count += my_putscientific(nb < 0 ? -nb : nb, *count, 1, format_f);
    display_minus(nb, format_f, pad);
    return *count;
}
