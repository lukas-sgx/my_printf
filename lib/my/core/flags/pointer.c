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
    count += my_put_str(va_arg(params, int), &count);
    return count;
}
