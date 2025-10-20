/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/my.h"

static int my_isnegnbr(int n, int *count)
{
    if (n < 0) {
        my_putchar(45);
        n = -n;
        (*count)++;
        if (n < -2147483647) {
            my_putchar('2');
            (*count)++;
            n = 147483648;
        } else {
            n = -n;
        }
    }
    return n;
}

int my_put_nbr(int nb)
{
    int p = 1;
    int tmp;
    int r;
    int count = 0;

    nb = my_isnegnbr(nb, &count);
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
