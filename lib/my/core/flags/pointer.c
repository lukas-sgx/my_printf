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
    char *data = va_arg(params, char*);

    count += my_putstr(data);
    return count;
}
