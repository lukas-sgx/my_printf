/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdio.h>

#include "../../../../include/my.h"

void to_neg(double *nb, int *count)
{
    if (*nb < 0) {
        my_putchar('-');
        *nb = -*nb;
        (*count)++;
    }
}

void int_state(long long int power, int *count,
    long long int *frac_part, int *int_part)
{
    if (*frac_part >= power) {
        (*int_part)++;
        *frac_part = 0;
    }
    *count += my_put_nbr(*int_part);
}

void init_var(double *frac, double nb, int *int_part)
{
    *int_part = (int) nb;
    *frac = nb - (double) *int_part;
}

static int get_frac(long long int *power, int precision,
    double frac, long long int *temp)
{
    long long int frac_part;

    *power = my_compute_power_rec(10, precision);
    frac_part = (int) (frac * (*power) + 0.5);
    *temp = *power / 10;
    return frac_part;
}

static void check_precision(int *precision, int *last_precision, double nb)
{
    if (*precision == -1)
        *precision = 6;
    if (*precision == -2) {
        *last_precision = -2;
        *precision = 0;
    }
    if (nb == 0.0)
        (*precision)--;
}

static void display_float(int *count, long long int temp,
    long long int frac_part)
{
    my_putchar('.');
    (*count)++;
    while (frac_part < temp && temp > 0) {
        my_putchar('0');
        count++;
        temp /= 10;
    }
    *count += my_put_dlong_nbr(frac_part);
}

int my_putfloat(double nb, int precision)
{
    int int_part;
    double frac;
    long long int power;
    long long int frac_part;
    long long int temp;
    int count = 0;
    int last_precision;

    check_precision(&precision, &last_precision, nb);
    to_neg(&nb, &count);
    init_var(&frac, nb, &int_part);
    frac_part = get_frac(&power, precision, frac, &temp);
    int_state(power, &count, &frac_part, &int_part);
    if (precision == 0 || last_precision == -2)
        return count;
    display_float(&count, temp, frac_part);
    return count;
}
