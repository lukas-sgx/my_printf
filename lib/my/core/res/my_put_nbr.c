/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/my.h"

static void nbextremum(int nb)
{
    my_putchar(45);
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

static int my_isneg(int n, int *count)
{
    if (n < 0) {
        my_putchar(45);
        n = -n;
        count++;
    }
    return n;
}

static int isextrem(int nb)
{
    int p = 1;
    int tmp;
    int r;
    int count = 0;

    nb = my_isneg(nb, &count);
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

int my_put_nbr(int nb)
{
    if (!(nb == -2147483648)) {
        return isextrem(nb);
    } else {
        nbextremum(nb);
        return 11;
    }
}
