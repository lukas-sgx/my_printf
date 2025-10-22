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
    if (nb < 0)
        *sign_char = '-';
    if (format_f->plus && nb > 0)
        *sign_char = '+';
    if (format_f->space && !format_f->minus && !format_f->plus)
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

int display_format_int(int nb, format_flags_t *format_f, int *count)
{
    int len = count_int(nb);
    int sign = (nb < 0 || format_f->plus || format_f->space)
        ? 1 : 0;
    int pad = (format_f->width > len + sign)
        ? format_f->width - (len + sign) : 0;
    char sign_char = 0;

    select_char(&sign_char, nb, format_f, pad);
    *count += my_put_nbr(nb < 0 ? -nb : nb);
    if (format_f->minus && nb > 0)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
    if (nb < 0 && pad > 0)
        for (int i = 0; i <= pad; i++)
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
    *count += my_put_long_nbr(nb < 0 ? -nb : nb);
    if (format_f->minus && nb > 0)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
    if (nb < 0 && pad > 0)
        for (int i = 0; i <= pad; i++)
            my_putchar(' ');
    return *count;
}

int display_format_dlint(long long int nb,
    format_flags_t *format_f, int *count)
{
    int len = count_dlint(nb);
    int sign = (nb < 0 || format_f->plus || format_f->space)
        ? 1 : 0;
    int pad = (format_f->width > len + sign)
        ? format_f->width - (len + sign) : 0;
    char sign_char = 0;

    select_char(&sign_char, nb, format_f, pad);
    if (sign_char)
        my_putchar(sign_char);
    *count += my_put_dlong_nbr(nb < 0 ? -nb : nb);
    if (format_f->minus && nb > 0)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
    if (nb < 0 && pad > 0)
        for (int i = 0; i <= pad; i++)
            my_putchar(' ');
    return *count;
}
