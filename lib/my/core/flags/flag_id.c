/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdio.h>

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static void md_ll(va_list params, int *count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_LL:
            *count += my_put_dlong_nbr(va_arg(params, long long int));
            break;
        default:
            break;
    }
}

static void md_l(va_list params, int *count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_L:
            *count += my_put_long_nbr(va_arg(params, long int));
            break;
        default:
            break;
    }
    md_ll(params, count, format_f);
}

static void md_hh(va_list params, int *count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_HH:
            *count += display_format((signed char)va_arg(params, int),
                format_f, count);
            break;
        default:
            break;
    }
    md_l(params, count, format_f);
}

static void md_h(va_list params, int *count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_H:
            *count += display_format((short)va_arg(params, int),
                format_f, count);
            break;
        default:
            break;
    }
    md_hh(params, count, format_f);
}

static void md_none(va_list params, int *count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_NONE:
            *count += display_format(va_arg(params, int), format_f, count);
            break;
        default:
            break;
    }
    md_h(params, count, format_f);
}

int int_d(va_list params, int count, format_flags_t *format_f)
{
    md_none(params, &count, format_f);
    return count;
}
