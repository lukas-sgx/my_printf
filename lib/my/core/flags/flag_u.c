/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static void llunsigned(va_list params, int *count, format_flags_t *format_f)
{
    unsigned long long arg;

    switch (format_f->mod) {
        case MOD_LL:
            arg = va_arg(params, unsigned long long);
            display_format_udlint(arg, format_f, count);
            break;
        default:
            break;
    }
}

static void lunsigned(va_list params, int *count, format_flags_t *format_f)
{
    unsigned long arg;

    switch (format_f->mod) {
        case MOD_L:
            arg = va_arg(params, unsigned long);
            display_format_ulint(arg, format_f, count);
            break;
        default:
            break;
    }
    llunsigned(params, count, format_f);
}

int flag_u_d(va_list params, int count, format_flags_t *format_f)
{
    unsigned int arg;

    switch (format_f->mod) {
        case MOD_NONE:
            arg = va_arg(params, unsigned int);
            display_format_uint(arg, format_f, &count);
            break;
        case MOD_H:
            arg = va_arg(params, unsigned int);
            display_format_uint((unsigned short)arg, format_f, &count);
            break;
        case MOD_HH:
            arg = va_arg(params, unsigned int);
            display_format_uint((unsigned char)arg, format_f, &count);
            break;
        default:
            break;
    }
    lunsigned(params, &count, format_f);
    return count;
}
