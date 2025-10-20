/*
** EPITECH PROJECT, 2025
** G-CPE-101-NCE-1-1-myprintf-5
** File description:
** my_put_long_nbr.c
*/

#include "../../../../include/my.h"

static long int my_isneglong(long int n, int *count)
{
    if (n < 0) {
        my_putchar(45);
        n = -n;
        (*count)++;
        if (n < -9223372036854775807L) {
            my_putchar('9');
            (*count)++;
            n = 223372036854775808L;
        } else {
            n = -n;
        }
    }
    return n;
}

int my_put_long_nbr(long int nb)
{
    long int p = 1;
    long int tmp;
    long int r;
    int count = 0;

    nb = my_isneglong(nb, &count);
    tmp = nb;
    count++;
    while (tmp >= 10) {
        tmp /= 10;
        p *= 10;
        count++;
    }
    while (p > 0) {
        r = nb / p;
        my_putchar(r + 48);
        nb %= p;
        p /= 10;
    }
    return count;
}
