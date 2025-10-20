/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** MyFile
*/

#include <stdarg.h>
#include "../../include/myprintf.h"
#include "../../include/my.h"

const list_handler_t list[] = {
    {'%', perc_d},
    {'s', string_d},
    {'c', char_d},
    {'i', int_d},
    {'d', int_d},
    {'p', pointer_d},
    {'n', flag_n_d},
    {'u', flag_u_d},
    {'x', flag_x_d},
    {'X', flag_xupper_d},
    {'o', flag_o_d},
    {'f', flag_f_d},
    {'e', flag_e_d},
    {'E', flag_eupper_d},
    {'b', flag_b_d},
    {'S', flag_ss_d},
};


length_mod_t get_length_modifier(const char *format, int *i)
{
    if (format[*i] == 'h' && format[*i + 1] == 'h') {
        *i += 2;
        return MOD_HH;
    }
    if (format[*i] == 'h') {
        *i += 1;
        return MOD_H;
    }
    if (format[*i] == 'l' && format[*i + 1] == 'l') {
        *i += 2;
        return MOD_LL;
    }
    if (format[*i] == 'l') {
        *i += 1;
        return MOD_L;
    }
    return MOD_NONE;
}

int select_f(char c, va_list params, int count, length_mod_t mod)
{
    int tmp = 0;

    for (int i = 0; list[i].symbols != '\0'; i++) {
        if (list[i].symbols == c) {
            count = list[i].flag(params, count, mod);
            tmp = 1;
        }
    }
    if (tmp == 0)
        count = default_d(c, count, mod);
    return count;
}

int my_printf(const char *format, ...)
{
    va_list params;
    length_mod_t mod;
    int count = 0;

    va_start(params, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0' &&
            format[i + 1] > 32 && format[i + 1] < 126) {
            i++;
            mod = get_length_modifier(format, &i);
            count = select_f(format[i], params, count, mod);
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(params);
    return count;
}
