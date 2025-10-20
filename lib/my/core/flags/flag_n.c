/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

void md_ll(va_list params, int count, length_mod_t mod)
{
    long long *p;

    switch (mod) {
        case MOD_LL:
            p = va_arg(params, long long*);
            *p = count;
            break;
        default:
            break;
    }
}

void md_l(va_list params, int count, length_mod_t mod)
{
    long *p;

    switch (mod) {
        case MOD_L:
            p = va_arg(params, long*);
            *p = count;
            break;
        default:
            break;
    }
    md_ll(params, count, mod);
}

void md_hh(va_list params, int count, length_mod_t mod)
{
    signed char *p;

    switch (mod) {
        case MOD_HH:
            p = va_arg(params, signed char*);
            *p = count;
            break;
        default:
            break;
    }
    md_l(params, count, mod);
}

void md_h(va_list params, int count, length_mod_t mod)
{
    short *p;

    switch (mod) {
        case MOD_H:
            p = va_arg(params, short*);
            *p = count;
            break;
        default:
            break;
    }
    md_hh(params, count, mod);
}

int flag_n_d(va_list params, int count, length_mod_t mod)
{
    int *p;

    switch (mod) {
        case MOD_NONE:
            p = va_arg(params, int*);
            *p = count;
            break;
        default:
            break;
    }
    md_h(params, count, mod);
    return count;
}
