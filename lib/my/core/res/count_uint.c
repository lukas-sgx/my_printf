/*
** EPITECH PROJECT, 2025
** MyPrintf
** File description:
** count_uint.c
*/

int count_uint(unsigned int nb)
{
    unsigned int p = 1;
    unsigned int tmp;
    int count = 0;

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

int count_ulint(unsigned long int nb)
{
    unsigned long int p = 1;
    unsigned long int tmp;
    int count = 0;

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

int count_udlint(unsigned long long int nb)
{
    unsigned long long int p = 1;
    unsigned long long int tmp;
    int count = 0;

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
