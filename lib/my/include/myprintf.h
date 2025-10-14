/*
** EPITECH PROJECT, 2025
** mylist
** File description:
** mylist
*/

#include <stdarg.h>

#ifndef PRINTF_H
    #define PRINTF_H

typedef int (*flags_t)(va_list, int);
typedef struct list_handler
{
    char symbols;
    flags_t flag;
} list_handler_t;

int perc_d(va_list params, int count);
int int_d(va_list params, int count);
int char_d(va_list params, int count);
int string_d(va_list params, int count);
int pointer_d(va_list params, int count);
int flag_n_d(va_list params, int count);
int default_d(char c, int count);
#endif
