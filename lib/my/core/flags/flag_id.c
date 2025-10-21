/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static void md_ll(va_list params, int *count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_LL:
            *count += my_put_dlong_nbr(va_arg(params, long long int),
                format_f->plus);
            break;
        default:
            break;
    }
}

static void md_l(va_list params, int *count, format_flags_t *format_f)
{
    switch (format_f->mod) {
        case MOD_L:
            *count += my_put_long_nbr(va_arg(params, long int), format_f->plus);
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
            *count += my_put_nbr((signed char)va_arg(params, int),
                format_f->plus);
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
            *count += my_put_nbr((short)va_arg(params, int), format_f->plus);
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
            *(count) += my_put_nbr(va_arg(params, int), format_f->plus);
            break;
        default:
            break;
    }
    md_h(params, count, format_f);
}

int int_d(va_list params, int count, format_flags_t *format_f)
{
    count += format_space(format_f);
    md_none(params, &count, format_f);
    return count;
}
