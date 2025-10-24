/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** MyFile
*/

#include <stdlib.h>
#include <stdio.h>
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
    {'F', flag_f_d},
    {'e', flag_e_d},
    {'E', flag_eupper_d},
    {'b', flag_b_d},
    {'S', flag_ss_d},
    {'\0', 0}
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

static void check_format(char const *format, format_flags_t *format_flags,
    int const i)
{
    switch (format[i]) {
        case '#':
            format_flags->hash = 1;
            break;
        case '0':
            format_flags->zero = 1;
            break;
        case '+':
            format_flags->plus = 1;
            break;
        case '-':
            format_flags->minus = 1;
            break;
        case ' ':
            format_flags->space = 1;
            break;
        default:
            break;
    }
}

static void add_width(char const *format, format_flags_t *format_flags, int *i)
{
    if (format[*i - 1] == ' ' || format_flags->minus)
        format_flags->zero = 0;
    while (format[*i] >= '0' && format[*i] <= '9') {
        format_flags->width = format_flags->width * 10 + (format[*i] - '0');
        (*i)++;
    }
}

static void add_precision(char const *format, format_flags_t *format_flags,
    int *i)
{
    if (format[*i] == '.') {
        (*i)++;
        if (format[*i] == 'f' || format[*i] == 'F' || format[*i] == 'E') {
            format_flags->precision = -2;
            return;
        }
        format_flags->precision = 0;
        while (format[*i] >= '0' && format[*i] <= '9') {
            format_flags->precision = format_flags->precision * 10 +
                (format[*i] - '0');
            (*i)++;
        }
    } else if (format[*i] == 'f' || format[*i] == 'F' || format[*i] == 'E') {
        format_flags->precision = -1;
    }
}

format_flags_t *get_format(char const *format, int *i)
{
    format_flags_t *format_flags = malloc(sizeof(format_flags_t));

    if (!format_flags)
        return NULL;
    *format_flags = (format_flags_t){0};
    while (format[*i] == '#' || format[*i] == '0' || format[*i] == '+' ||
        format[*i] == '-' || format[*i] == ' ') {
        check_format(format, format_flags, *i);
        (*i)++;
    }
    add_width(format, format_flags, i);
    add_precision(format, format_flags, i);
    format_flags->mod = get_length_modifier(format, i);
    if (format_flags->minus)
        format_flags->zero = 0;
    return format_flags;
}

int select_f(char c, va_list params, int count, format_flags_t *format_f)
{
    int tmp = 0;

    for (int i = 0; list[i].symbols != '\0'; i++) {
        if (list[i].symbols == c) {
            count = list[i].flag(params, count, format_f);
            tmp = 1;
        }
    }
    if (tmp == 0)
        count = default_d(c, count, format_f);
    return count;
}

int my_printf(const char *format, ...)
{
    va_list params;
    format_flags_t *format_f;
    int count = 0;

    va_start(params, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0' &&
            format[i + 1] >= 32 && format[i + 1] <= 126) {
            i++;
            format_f = get_format(format, &i);
            count = select_f(format[i], params, count, format_f);
            free(format_f);
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(params);
    return count;
}
