/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** count_int.c
*/

static int my_isnegnbr(int n, int *count)
{
    if (n < 0) {
        n = -n;
        (*count)++;
        if (n < -2147483647) {
            (*count)++;
            n = 147483648;
        }
    }
    return n;
}

int count_int(int nb)
{
    int p = 1;
    int tmp;
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
        nb %= p;
        p /= 10;
    }
    return count;
}

static int my_isneglnbr(long int n, int *count)
{
    if (n < 0) {
        n = -n;
        (*count)++;
        if (n < -9223372036854775807L) {
            (*count)++;
            n = 223372036854775808L;
        }
    }
    return n;
}

int count_lint(long int nb)
{
    long int p = 1;
    long int tmp;
    int count = 0;

    nb = my_isneglnbr(nb, &count);
    tmp = nb;
    count++;
    while (tmp >= 10) {
        tmp /= 10;
        p *= 10;
        count++;
    }
    while (p > 0) {
        nb %= p;
        p /= 10;
    }
    return count;
}

static int my_isnegdlnbr(long long int n, int *count)
{
    if (n < 0) {
        n = -n;
        (*count)++;
        if (n < -9223372036854775807L) {
            (*count)++;
            n = 223372036854775808LL;
        }
    }
    return n;
}

int count_dlint(long long int nb)
{
    long long int p = 1;
    long long int tmp;
    int count = 0;

    nb = my_isnegdlnbr(nb, &count);
    tmp = nb;
    count++;
    while (tmp >= 10) {
        tmp /= 10;
        p *= 10;
        count++;
    }
    while (p > 0) {
        nb %= p;
        p /= 10;
    }
    return count;
}
