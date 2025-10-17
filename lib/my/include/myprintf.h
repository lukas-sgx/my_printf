/*
** EPITECH PROJECT, 2025
** mylist
** File description:
** mylist
*/

#include <stdarg.h>

#ifndef PRINTF_H
    #define PRINTF_H


typedef enum {
    MOD_NONE,
    MOD_HH,
    MOD_H,
    MOD_L,
    MOD_LL
} length_mod_t;
typedef int (*flags_t)(va_list, int, length_mod_t mod);
typedef struct list_handler
{
    char symbols;
    flags_t flag;
} list_handler_t;

typedef struct {
    char specifier;
    length_mod_t modifier;
} format_info_t;

int perc_d(va_list params, int count, length_mod_t mod);
int int_d(va_list params, int count, length_mod_t mod);
int char_d(va_list params, int count, length_mod_t mod);
int string_d(va_list params, int count, length_mod_t mod);
int pointer_d(va_list params, int count, length_mod_t mod);
int flag_n_d(va_list params, int count, length_mod_t mod);
int flag_u_d(va_list params, int count, length_mod_t mod);
int flag_x_d(va_list params, int count, length_mod_t mod);
int flag_xupper_d(va_list params, int count, length_mod_t mod);
int flag_o_d(va_list params, int count, length_mod_t mod);
int flag_f_d(va_list params, int count, length_mod_t mod);
int flag_eupper_d(va_list params, int count, length_mod_t mod);
int flag_e_d(va_list params,
    int count, length_mod_t mod);
int default_d(char c, int count, length_mod_t mod);
int point_precision(va_list params, int count, length_mod_t mod);
#endif
