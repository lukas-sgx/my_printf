/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int string_d(va_list params, int count, length_mod_t mod)
{
    switch (mod) {
        case MOD_NONE:
            count += my_putstr(va_arg(params, char*));
            break;
        case MOD_L:
            count += my_putwstr(va_arg(params, unsigned int*));
            break;
        default:
            break;
    }
    return count;
}
