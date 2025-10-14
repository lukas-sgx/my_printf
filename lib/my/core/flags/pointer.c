/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"

int pointer_d(va_list params, int count)
{
    // unsigned long add;
    // add = (unsigned long) (va_arg(params, void*));

    count += my_putstr(va_arg(params, char*));
    return count;
}
