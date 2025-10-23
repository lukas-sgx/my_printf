/*
** EPITECH PROJECT, 2025
** MyPrintf
** File description:
** count_double.c
*/

#include "../../../../include/my.h"

static void to_neg(double *nb, int *count)
{
    if (*nb < 0) {
        *nb = -*nb;
        (*count)++;
    }
}

static void int_state(long long int power, int *count,
    int *frac_part, int *int_part)
{
    if (*frac_part >= power) {
        (*int_part)++;
        *frac_part = 0;
    }
    *count += count_dlint(*int_part);
    (*count)++;
}

static void init_var(double *frac, double nb, int *int_part)
{
    *int_part = (int) nb;
    *frac = nb - (double) *int_part;
}

static void count_precision(int precision, int frac_part,
    int *count, long long int temp)
{
    if (precision > 0) {
        while (frac_part < temp && temp > 0) {
            count++;
            temp /= 10;
        }
        if (frac_part == 0)
            *count += precision;
        else
            *count += count_dlint(frac_part);
    }
}

static int get_frac(int precision, double frac,
    long long int *tmp, long long int *power)
{
    int frac_part;

    *power = my_compute_power_rec(10, precision);
    frac_part = (int)(frac * (*power) + 0.5);
    *tmp = *power / 10;
    return frac_part;
}

int count_double(double nb, int precision)
{
    int int_part;
    double frac;
    long long int tmp;
    long long int power;
    int count = 0;
    int frac_part;

    to_neg(&nb, &count);
    init_var(&frac, nb, &int_part);
    frac_part = get_frac(precision, frac, &tmp, &power);
    int_state(power, &count, &frac_part, &int_part);
    if (precision == -2)
        count += 1;
    if (precision == 0)
        count--;
    if (precision == -2 || precision == 0)
        return count;
    count_precision(precision, frac_part, &int_part, tmp);
    return count;
}
