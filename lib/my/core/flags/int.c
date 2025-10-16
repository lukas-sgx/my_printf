/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"

int int_d(va_list params, int count, length_mod_t mod)
{
    switch (mod) {
        case MOD_NONE:
            count += my_put_nbr(va_arg(params, int));
            break;
        case MOD_H:
            count += my_put_nbr((short)va_arg(params, int));
            break;
        case MOD_HH:
            count += my_put_nbr((signed char)va_arg(params, int));
            break;
        default:
            break;
    }
    return count;
}
