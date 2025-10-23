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
            display_format_dlint(va_arg(params, long long int),
                format_f, count);
            break;
        default:
            break;
    }
}

static void md_l(va_list params, int *count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_L:
            display_format_lint(va_arg(params, long int),
                format_f, count);
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
            display_format_int((signed char)va_arg(params, int),
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
            display_format_int((short)va_arg(params, int),
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
            display_format_int(va_arg(params, int), format_f, count);
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
