/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"

int flag_eupper_d(va_list params, const char *format,
    int count, length_mod_t mod)
{
    int e = 0;
    double nb = va_arg(params, double);

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb >= 10) {
        nb = nb / 10;
        e++;
    }
    my_putfloat(nb, 6);
    my_putchar('e');
    my_putchar('+');
    if (e < 10)
        my_putchar('0');
    count += my_put_nbr(e);
    return count;
}

int flag_e_d(va_list params, const char *format,
    int count, length_mod_t mod)
{
    int e = 0;
    double nb = va_arg(params, double);

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb >= 10) {
        nb = nb / 10;
        e++;
    }
    my_putfloat(nb, 6);
    my_putchar('e');
    my_putchar('+');
    if (e < 10)
        my_putchar('0');
    count += my_put_nbr(e);
    return count;
}
