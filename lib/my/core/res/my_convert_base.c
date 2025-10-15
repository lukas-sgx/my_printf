/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdlib.h>

static int check_mult(char const *dest, char const src)
{
    int j = 0;

    for (int i = 0; dest[i] != '\0'; i++) {
        if (dest[i] == src)
            j++;
        if (j >= 2)
            return 1;
    }
    return 0;
}

static int check_base(char const *base)
{
    int i;

    for (i = 0; base[i] != '\0'; i++) {
        if (base[i] == '-' || base[i] == '+' || check_mult(base, base[i]))
            return 1;
    }
    if (i < 2)
        return 1;
    return 0;
}

static void check_val(const char *base, char const *nbr, int *val, int i)
{
    *val = -1;
    for (int j = 0; base[j]; j++)
        if (base[j] == nbr[i])
            *val = j;
}

static unsigned long long convert_char_star_to_ull(char const *nbr,
    char const *base)
{
    unsigned long long result = 0;
    unsigned long long len = 0;
    int i;
    int val;

    for (len = 0; base[len]; len++);
    for (i = 0; nbr[i]; i++) {
        check_val(base, nbr, &val, i);
        if (val == -1)
            return 0;
        result = result * len + val;
    }
    return result;
}

static void reverse(int nb, char *res, int *i, char *buffer)
{
    for (int j = 0; j < *i; j++)
        res[j] = buffer[*i - j - 1];
    res[*i] = '\0';
}

static char *convert_ull_to_char_star(unsigned long long nb,
    char const *base)
{
    int len_base = 0;
    int i = 0;
    char buffer[65];
    char *res = NULL;

    for (len_base = 0; base[len_base]; len_base++);
    if (nb == 0) {
        res = malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    while (nb > 0) {
        buffer[i] = base[nb % len_base];
        i++;
        nb /= len_base;
    }
    res = malloc(i + 1);
    reverse(nb, res, &i, buffer);
    return res;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    unsigned long long nb;

    if (check_base(base_from) || check_base(base_to))
        return NULL;
    nb = convert_char_star_to_ull(nbr, base_from);
    return convert_ull_to_char_star(nb, base_to);
}
