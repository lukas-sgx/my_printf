/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/my.h"

void to_neg(double *nb, int *count)
{
    if (*nb < 0) {
        my_putchar('-');
        *nb = -*nb;
        (*count)++;
    }
}

void int_state(int power, int *count, int *frac_part, int *int_part)
{
    if (*frac_part >= power) {
        (*int_part)++;
        *frac_part = 0;
    }
    *count += my_put_nbr(*int_part);
    my_putchar('.');
    (*count)++;
}

void init_var(double *frac, double nb, int *int_part)
{
    *int_part = (int) nb;
    *frac = nb - (double) *int_part;
}

int my_putfloat(double nb, int precision)
{
    int int_part;
    double frac;
    int power;
    int frac_part;
    int temp;
    int count = 0;

    to_neg(&nb, &count);
    init_var(&frac, nb, &int_part);
    power = my_compute_power_rec(10, precision);
    frac_part = (int) (frac * power + 0.5);
    temp = power / 10;
    int_state(power, &count, &frac_part, &int_part);
    while (frac_part < temp && temp > 0) {
        my_putchar('0');
        count++;
        temp /= 10;
    }
    count += my_put_nbr(frac_part);
    return count;
}
