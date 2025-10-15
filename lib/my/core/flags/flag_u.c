/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"

int flag_u_d(va_list params, int count)
{
    unsigned int p = va_arg(params, unsigned int);

    count += my_put_unsigned(p);
    return count;
}
