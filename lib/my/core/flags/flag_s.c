/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int string_d(va_list params, int count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_NONE:
            count += display_format_s(va_arg(params, char*), format_f, &count);
            break;
        case MOD_L:
            count += display_format_ws(va_arg(params, unsigned int*),
                format_f, &count);
            break;
        default:
            break;
    }
    return count;
}
