/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** int_to_str.c
*/

#include <stdlib.h>

char *int_to_str_null(void)
{
    char *res = malloc(2);

    if (!res)
        return NULL;
    res[0] = '0';
    res[1] = '\0';
    return res;
}

char *int_to_str(int n)
{
    char buffer[12];
    char *res = NULL;
    int i = 0;

    if (n == 0)
        return int_to_str_null();
    while (n > 0) {
        buffer[i] = '0' + (n % 10);
        i++;
        n /= 10;
    }
    res = malloc(i + 1);
    if (!res)
        return NULL;
    for (int j = 0; j < i; j++)
        res[j] = buffer[i - j - 1];
    res[i] = '\0';
    return res;
}
