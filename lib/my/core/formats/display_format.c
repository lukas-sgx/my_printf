/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** display_format.c
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

static void show_pad(int pad)
{
    for (int i = 0; i < pad; i++)
        my_putchar(' ');
}

static void select_char(char *sign_char, long long int nb,
    format_flags_t *format_f, int pad)
{
    if (format_f->plus && nb > 0)
        *sign_char = '+';
    if (format_f->space && !format_f->minus)
        *sign_char = ' ';
    if (!format_f->minus) {
        if (format_f->zero) {
            show_sign(sign_char, pad);
        } else {
            show_pad(pad);
        }
    }
}

int display_format_int(int nb, format_flags_t *format_f, int *count)
{
    int len = count_int(nb);
    int sign = (nb < 0 || format_f->plus || format_f->space)
        ? 1 : 0;
    int pad = (format_f->width > len + sign)
        ? format_f->width - (len + sign) : 0;
    char sign_char = 0;

    select_char(&sign_char, nb, format_f, pad);
    if (sign_char)
        my_putchar(sign_char);
    if (nb < 0 && nb >= -2147483647)
        my_putchar('-');
    *count += my_put_nbr(nb < 0 ? -nb : nb);
    if (format_f->minus)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
    return *count;
}

int display_format_lint(long int nb,
    format_flags_t *format_f, int *count)
{
    int len = count_lint(nb);
    int sign = (nb < 0 || format_f->plus || format_f->space)
        ? 1 : 0;
    int pad = (format_f->width > len + sign)
        ? format_f->width - (len + sign) : 0;
    char sign_char = 0;

    select_char(&sign_char, nb, format_f, pad);
    if (sign_char)
        my_putchar(sign_char);
    if (nb < 0 && nb >= -9223372036854775807L)
        my_putchar('-');
    *count += my_put_long_nbr(nb < 0 ? -nb : nb);
    if (format_f->minus)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
    return *count;
}

int display_format_dlint(long long int nb,
    format_flags_t *format_f, int *count)
{
    int len = count_dlint(nb);
    printf("%lli\n", nb);
    int sign = (nb < 0 || format_f->plus || format_f->space)
        ? 1 : 0;
    int pad = (format_f->width > len + sign)
        ? format_f->width - (len + sign) : 0;
    char sign_char = 0;

    select_char(&sign_char, nb, format_f, pad);
    if (sign_char)
        my_putchar(sign_char);
    if (nb < 0 && nb >= -9223372036854775807LL)
        my_putchar('-');
    *count += my_put_dlong_nbr(nb < 0 ? -nb : nb);
    if (format_f->minus)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
    return *count;
}
