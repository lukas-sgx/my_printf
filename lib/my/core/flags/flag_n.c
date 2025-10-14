/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"
#include <stdio.h>

int flag_n_d(va_list params, int count)
{
    int *p = va_arg(params, int*);

    *p = count;
    return count;
}
