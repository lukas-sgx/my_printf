/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../include/myprintf.h"
#include "../../include/my.h"

int perc_d(va_list params, int count)
{
    my_putchar('%');
    count++;
    return count;
}