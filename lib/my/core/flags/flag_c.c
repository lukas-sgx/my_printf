/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int char_d(va_list params, int count, length_mod_t mod)
{
    switch (mod) {
        case MOD_NONE:
            my_putchar(va_arg(params, int));
            break;
        case MOD_H:
            my_putchar((short)va_arg(params, int));
        case MOD_HH:
            my_putchar((signed char)va_arg(params, int));
        case MOD_L:
            my_putwchar(va_arg(params, unsigned int));
        default:
            break;
    }
    count++;
    return count;
}
