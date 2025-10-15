/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdlib.h>
#include "../../include/myprintf.h"
#include "../../include/my.h"

char *uint_to_str_null(void)
{
    char *res = malloc(2);

    if (!res)
        return NULL;
    res[0] = '0';
    res[1] = '\0';
    return res;
}

char *uint_to_str(unsigned int n)
{
    char buffer[12];
    char *res = NULL;
    int i = 0;

    if (n == 0)
        return uint_to_str_null();
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

int flag_x_d(va_list params, int count)
{
    unsigned int nb = va_arg(params, unsigned int);
    char *tmp;
    char *decimal = uint_to_str(nb);

    if (!decimal)
        return count;
    tmp = convert_base(decimal, "0123456789", "0123456789ABCDEF");
    free(decimal);
    count += my_putstr(tmp);
    free(tmp);
    return count;
}
