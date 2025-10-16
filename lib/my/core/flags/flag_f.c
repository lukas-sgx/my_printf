/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"

int flag_f_d(va_list params, int count, length_mod_t mod)
{
    double nb = va_arg(params, double);

    count += my_putfloat(nb, 6);
    return count;
}
