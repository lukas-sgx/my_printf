/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdlib.h>
#include "../../include/myprintf.h"
#include "../../include/my.h"

int flag_o_d(va_list params, int count)
{
    unsigned int nb = va_arg(params, unsigned int);
    char *tmp;
    char *decimal = uint_to_str(nb);

    if (!decimal)
        return count;
    tmp = convert_base(decimal, "0123456789", "01234567");
    free(decimal);
    count += my_putstr(tmp);
    free(tmp);
    return count;
}
