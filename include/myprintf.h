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
    MOD_LL,
    MOD_DIEZ,

} length_mod_t;

typedef struct format_flags_s {
    int hash;
    int zero;
    int minus;
    int plus;
    int space;
    int width;
    int precision;
    int c;
    length_mod_t mod;
} format_flags_t;

typedef int (*flags_t)(va_list, int, format_flags_t *format_f);
typedef struct list_handler
{
    char symbols;
    flags_t flag;
} list_handler_t;

int perc_d(va_list params, int count, format_flags_t *format_f);
int int_d(va_list params, int count, format_flags_t *format_f);
int char_d(va_list params, int count, format_flags_t *format_f);
int string_d(va_list params, int count, format_flags_t *format_f);
int pointer_d(va_list params, int count, format_flags_t *format_f);
int flag_n_d(va_list params, int count, format_flags_t *format_f);
int flag_u_d(va_list params, int count, format_flags_t *format_f);
int flag_x_d(va_list params, int count, format_flags_t *format_f);
int flag_xupper_d(va_list params, int count, format_flags_t *format_f);
int flag_o_d(va_list params, int count, format_flags_t *format_f);
int flag_f_d(va_list params, int count, format_flags_t *format_f);
int flag_j_d(va_list params, int count, format_flags_t *format_f);
int flag_eupper_d(va_list params, int count, format_flags_t *format_f);
int flag_e_d(va_list params,
    int count, format_flags_t *format_f);
int flag_b_d(va_list params, int count, format_flags_t *format_f);
int flag_ss_d(va_list params, int count, format_flags_t *format_f);
int default_d(char c, int count, format_flags_t *format_f);
int point_precision(va_list params, int count, format_flags_t *format_f);
int format_space(format_flags_t *format_f, int count);
int format_plus(format_flags_t *format_f, int nb);
int format_zero(format_flags_t *format_f, int count);
int display_format_int(int nb,
    format_flags_t *format_f, int *count);
int display_format_lint(long int nb,
    format_flags_t *format_f, int *count);
int display_format_dlint(long long int nb,
    format_flags_t *format_f, int *count);
int display_format_str(char *nb,
    format_flags_t *format_f, int *count, int upper);
int display_format_uint(unsigned int nb,
    format_flags_t *format_f, int *count);
int display_format_ulint(unsigned long int nb,
    format_flags_t *format_f, int *count);
int display_format_udlint(unsigned long long int nb,
    format_flags_t *format_f, int *count);
int display_format_str_o(char *nb,
    format_flags_t *format_f, int *count);

int my_printf(const char *format, ...);
#endif
