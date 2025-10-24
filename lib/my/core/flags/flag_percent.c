/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int perc_d(va_list params, int count, format_flags_t *format_f)
{
    my_putchar('%');
    count++;
    return count;
}
