/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdio.h>

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static int value_pos(double nb, int count, int upper)
{
    int e = 0;

    while (nb >= 10) {
        nb = nb / 10;
        e++;
    }
    my_putfloat(nb, 6);
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

static int value_neg(double nb, int count, int upper)
{
    int e = 0;

    while (nb < 1) {
        nb *= 10;
        e++;
    }
    my_putfloat(nb, 6);
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

int flag_eupper_d(va_list params, int count, format_flags_t *format_f)
{
    double nb = va_arg(params, double);

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 1.0)
        return value_neg(nb, count, 1);
    if (nb > 1.0)
        return value_pos(nb, count, 1);
    return count;
}

int flag_e_d(va_list params, int count, format_flags_t *format_f)
{
    double nb = va_arg(params, double);

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 1.0)
        return value_neg(nb, count, 0);
    if (nb > 1.0)
        return value_pos(nb, count, 0);
    return count;
}
