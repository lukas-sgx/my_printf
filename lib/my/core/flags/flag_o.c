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
    unsigned long long arg;
    char *decimal;
    char *tmp;

    switch (format_f->mod) {
        case MOD_LL:
            arg = va_arg(params, unsigned long long);
            decimal = ullint_to_str(arg);
            tmp = convert_base(decimal, "0123456789", "01234567");
            display_format_str_o(tmp, format_f, count);
            break;
        default:
            break;
    }
}

static void md_l(va_list params, int *count, format_flags_t *format_f)
{
    unsigned long arg;
    char *decimal;
    char *tmp;

    switch (format_f->mod) {
        case MOD_L:
            arg = va_arg(params, unsigned long);
            decimal = ulint_to_str(arg);
            tmp = convert_base(decimal, "0123456789", "01234567");
            display_format_str_o(tmp, format_f, count);
            break;
        default:
            break;
    }
    md_ll(params, count, format_f);
}

static void md_hh(va_list params, int *count, format_flags_t *format_f)
{
    unsigned int arg;
    char *decimal;
    char *tmp;

    switch (format_f->mod) {
        case MOD_HH:
            arg = va_arg(params, unsigned int);
            decimal = uint_to_str((unsigned char)arg);
            tmp = convert_base(decimal, "0123456789", "01234567");
            display_format_str_o(tmp, format_f, count);
            break;
        default:
            break;
    }
    md_l(params, count, format_f);
}

static void md_h(va_list params, int *count, format_flags_t *format_f)
{
    unsigned int arg;
    char *decimal;
    char *tmp;

    switch (format_f->mod) {
        case MOD_H:
            arg = va_arg(params, unsigned int);
            decimal = uint_to_str((unsigned short)arg);
            tmp = convert_base(decimal, "0123456789", "01234567");
            display_format_str_o(tmp, format_f, count);
            break;
        default:
            break;
    }
    md_hh(params, count, format_f);
}

int flag_o_d(va_list params, int count, format_flags_t *format_f)
{
    unsigned int arg;
    char *decimal;
    char *tmp;

    switch (format_f->mod) {
        case MOD_NONE:
            arg = va_arg(params, unsigned int);
            decimal = uint_to_str(arg);
            tmp = convert_base(decimal, "0123456789", "01234567");
            display_format_str_o(tmp, format_f, &count);
            break;
        default:
            break;
    }
    md_h(params, &count, format_f);
    return count;
}
