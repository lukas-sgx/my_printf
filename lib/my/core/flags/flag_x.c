/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdlib.h>
#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static void md_ll(va_list params, int *count, length_mod_t mod, char *base_to)
{
    unsigned long long arg;
    char *decimal;
    char *tmp;

    switch (mod) {
        case MOD_LL:
            arg = va_arg(params, unsigned long long);
            decimal = ullint_to_str(arg);
            tmp = convert_base(decimal, "0123456789", base_to);
            *count += my_putstr(tmp);
            break;
        default:
            break;
    }
}

static void md_l(va_list params, int *count, length_mod_t mod, char *base_to)
{
    unsigned long arg;
    char *decimal;
    char *tmp;

    switch (mod) {
        case MOD_L:
            arg = va_arg(params, unsigned long);
            decimal = ulint_to_str(arg);
            tmp = convert_base(decimal, "0123456789", base_to);
            *count += my_putstr(tmp);
            break;
        default:
            break;
    }
    md_ll(params, count, mod, base_to);
}

static void md_hh(va_list params, int *count, length_mod_t mod, char *base_to)
{
    unsigned int arg;
    char *decimal;
    char *tmp;

    switch (mod) {
        case MOD_HH:
            arg = va_arg(params, unsigned int);
            decimal = uint_to_str((unsigned char)arg);
            tmp = convert_base(decimal, "0123456789", base_to);
            *count += my_putstr(tmp);
            break;
        default:
            break;
    }
    md_l(params, count, mod, base_to);
}

static void md_h(va_list params, int *count, length_mod_t mod, char *base_to)
{
    unsigned int arg;
    char *decimal;
    char *tmp;

    switch (mod) {
        case MOD_H:
            arg = va_arg(params, unsigned int);
            decimal = uint_to_str((unsigned short)arg);
            tmp = convert_base(decimal, "0123456789", base_to);
            count += my_putstr(tmp);
            break;
        default:
            break;
    }
    md_hh(params, count, mod, base_to);
}

int flag_x_d(va_list params, int count, length_mod_t mod)
{
    unsigned int arg;
    char *decimal;
    char *tmp;

    switch (mod) {
        case MOD_NONE:
            arg = va_arg(params, unsigned int);
            decimal = uint_to_str(arg);
            tmp = convert_base(decimal, "0123456789", "0123456789abcdef");
            count += my_putstr(tmp);
            break;
        default:
            break;
    }
    md_h(params, &count, mod, "0123456789abcdef");
    return count;
}

int flag_xupper_d(va_list params, int count, length_mod_t mod)
{
    unsigned int arg;
    char *decimal;
    char *tmp;

    switch (mod) {
        case MOD_NONE:
            arg = va_arg(params, unsigned int);
            decimal = uint_to_str(arg);
            tmp = convert_base(decimal, "0123456789", "0123456789ABCDEF");
            count += my_putstr(tmp);
            break;
        default:
            break;
    }
    md_h(params, &count, mod, "0123456789ABCDEF");
    return count;
}
