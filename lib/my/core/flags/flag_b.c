/*
** EPITECH PROJECT, 2025
** G-CPE-101-NCE-1-1-myprintf-5
** File description:
** flag_b.c
*/

#include <stdlib.h>
#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int flag_b_d(va_list params, int count, length_mod_t mod)
{
    unsigned int nb = va_arg(params, unsigned int);
    char *tmp;
    char *decimal = uint_to_str(nb);

    if (!decimal)
        return count;
    tmp = convert_base(decimal, "0123456789", "01");
    free(decimal);
    count += my_putstr(tmp);
    free(tmp);
    return count;
}
