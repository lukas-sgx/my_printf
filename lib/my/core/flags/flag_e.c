/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdio.h>

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int flag_eupper_d(va_list params, int count, format_flags_t *format_f)
{
    double nb = va_arg(params, double);

    return display_format_double_e(nb, format_f, &count);
}

int flag_e_d(va_list params, int count, format_flags_t *format_f)
{
    double nb = va_arg(params, double);

    return display_format_double_e(nb, format_f, &count);
}
