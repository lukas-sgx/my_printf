/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdlib.h>
#include <stdint.h>
#include "../../include/myprintf.h"
#include "../../include/my.h"

char *ulong_to_str_null(void)
{
    char *res = malloc(sizeof(char) * 6);

    my_strcpy(res, "(nil)");
    return res;
}

char *ulong_to_str(unsigned long n)
{
    char buffer[21];
    char *res = NULL;
    int i = 0;

    if (n == 0)
        return ulong_to_str_null();
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

int pointer_d(va_list params, int count)
{
    void *tmp = va_arg(params, void*);
    unsigned long addr = (unsigned long)tmp;
    char *base;
    char bfrom[] = "0123456789";

    if (my_strcmp(ulong_to_str(addr), "(nil)")){
        base = convert_base(ulong_to_str(addr), bfrom, "0123456789abcdef");
        count += my_putstr("0x");
        count += my_putstr(base);
    } else {
        count += my_putstr(ulong_to_str_null());
    }
    return count;
}
