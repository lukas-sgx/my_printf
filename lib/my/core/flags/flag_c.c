/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int char_d(va_list params, int count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_NONE:
            display_format_c(va_arg(params, int), format_f, &count);
            break;
        case MOD_H:
            display_format_c((short)va_arg(params, int), format_f, &count);
        case MOD_HH:
            display_format_c((signed char) va_arg(params, int),
                format_f, &count);
        case MOD_L:
            display_format_wc(va_arg(params, unsigned int), format_f, &count);
        default:
            break;
    }
    count++;
    return count;
}
