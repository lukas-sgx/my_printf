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
        } else {
            n = -n;
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
