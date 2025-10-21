/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int default_d(char c, int count, format_flags_t *format_f)
{
    my_putchar('%');
    my_putchar(c);
    count += 2;
    return count;
}
