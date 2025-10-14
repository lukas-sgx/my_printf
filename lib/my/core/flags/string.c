/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"

int string_d(va_list params, int count)
{
    count += my_putstr(va_arg(params, char*));
    return count;
}
