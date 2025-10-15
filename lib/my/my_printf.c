/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** MyFile
*/

#include <stdarg.h>
#include "include/myprintf.h"
#include "include/my.h"

const list_handler_t list[] = {
    {'%', perc_d},
    {'s', string_d},
    {'c', char_d},
    {'i', int_d},
    {'d', int_d},
    {'p', pointer_d},
    {'n', flag_n_d},
    {'u', flag_u_d},
};

int select_f(char c, va_list params, int count)
{
    int tmp = 0;

    for (int i = 0; list[i].symbols != '\0'; i++) {
        if (list[i].symbols == c) {
            count = list[i].flag(params, count);
            tmp = 1;
        }
    }
    if (tmp == 0)
        count = default_d(c, count);
    return count;
}

int my_printf(const char *format, ...)
{
    va_list params;
    int count = 0;

    va_start(params, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            count = select_f(format[i], params, count);
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(params);
    return count;
}
