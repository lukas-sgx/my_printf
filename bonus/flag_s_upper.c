/*
** EPITECH PROJECT, 2025
** G-CPE-101-NCE-1-1-myprintf-5
** File description:
** flag_ss.c
*/

#include <stdio.h>
#include "../include/myprintf.h"
#include "../include/my.h"

int flag_ss_d(va_list params, int count, format_flags_t *format_f)
{
    char **tab;
    char *str;

    switch (format_f->mod) {
        case MOD_NONE:
            str = va_arg(params, char*);
            tab = my_str_to_word_array(str);
            for (int y = 0; tab[y] != 0; y++) {
                count += my_putstr(tab[y]);
                my_putchar('\n');
                count++;
            }
            break;
        case MOD_L:
            break;
        default:
            break;
    }
    return count;
}
