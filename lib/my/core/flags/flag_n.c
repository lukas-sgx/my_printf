/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"

int flag_n_d(va_list params, int count, length_mod_t mod)
{
    int *p = va_arg(params, int*);

    *p = count;
    return count;
}
