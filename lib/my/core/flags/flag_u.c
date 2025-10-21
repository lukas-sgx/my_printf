/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static void llunsigned(va_list params, int *count, length_mod_t mod)
{
    unsigned long long arg;

    switch (mod) {
        case MOD_LL:
            arg = va_arg(params, unsigned long long);
            *count += my_put_llunsigned(arg);
            break;
        default:
            break;
    }
}

static void lunsigned(va_list params, int *count, length_mod_t mod)
{
    unsigned long arg;

    switch (mod) {
        case MOD_L:
            arg = va_arg(params, unsigned long);
            *count += my_put_lunsigned(arg);
            break;
        default:
            break;
    }
    llunsigned(params, count, mod);
}

int flag_u_d(va_list params, int count, format_flags_t *format_f)
{
    unsigned int arg;

    switch (format_f->mod) {
        case MOD_NONE:
            arg = va_arg(params, unsigned int);
            count += my_put_unsigned(arg);
            break;
        case MOD_H:
            arg = va_arg(params, unsigned int);
            count += my_put_unsigned((unsigned short)arg);
            break;
        case MOD_HH:
            arg = va_arg(params, unsigned int);
            count += my_put_unsigned((unsigned char)arg);
            break;
        default:
            break;
    }
    lunsigned(params, &count, format_f->mod);
    return count;
}
