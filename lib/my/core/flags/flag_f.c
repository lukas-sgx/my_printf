/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int flag_f_d(va_list params, int count, format_flags_t *format_f)
{
    double nb = va_arg(params, double);

    display_format_double(nb, format_f, &count);
    return count;
}
