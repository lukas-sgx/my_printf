/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdlib.h>
#include "../../include/myprintf.h"
#include "../../include/my.h"

int flag_x_d(va_list params, int count, length_mod_t mod)
{
    unsigned int nb = va_arg(params, unsigned int);
    char *tmp;
    char *decimal = uint_to_str(nb);

    if (!decimal)
        return count;
    tmp = convert_base(decimal, "0123456789", "0123456789abcdef");
    free(decimal);
    count += my_putstr(tmp);
    free(tmp);
    return count;
}

int flag_xupper_d(va_list params, int count, length_mod_t mod)
{
    unsigned int nb = va_arg(params, unsigned int);
    char *tmp;
    char *decimal = uint_to_str(nb);

    if (!decimal)
        return count;
    tmp = convert_base(decimal, "0123456789", "0123456789ABCDEF");
    free(decimal);
    count += my_putstr(tmp);
    free(tmp);
    return count;
}
