/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Full unit tests using Criterion (flags + width + precision + scientific + %n)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/myprintf.h"
#include <string.h>
#include <stdio.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/* -------------------- MACROS UTILES -------------------- */

#define TEST_INT_ID(val, id, fmt) \
Test(my_printf, auto_int_##id, .init=redirect_all_std) { \
    long long tmp_val = (long long)(val); \
    my_printf(fmt, tmp_val); \
    char buf[64]; sprintf(buf, fmt, tmp_val); \
    cr_assert_stdout_eq_str(buf); \
}

#define TEST_UINT_ID(val, id, fmt) \
Test(my_printf, auto_uint_##id, .init=redirect_all_std) { \
    unsigned long long tmp_val = (unsigned long long)(val); \
    my_printf(fmt, tmp_val); \
    char buf[64]; sprintf(buf, fmt, tmp_val); \
    cr_assert_stdout_eq_str(buf); \
}

#define TEST_FLOAT_ID(val, id, fmt) \
Test(my_printf, auto_float_##id, .init=redirect_all_std) { \
    double tmp_val = (double)(val); \
    my_printf(fmt, tmp_val); \
    char buf[64]; sprintf(buf, fmt, tmp_val); \
    cr_assert_stdout_eq_str(buf); \
}

#define TEST_CHAR_ID(c, id) \
Test(my_printf, auto_char_##id, .init=redirect_all_std) { \
    my_printf("%c", c); \
    char buf[2]; buf[0]=c; buf[1]='\0'; \
    cr_assert_stdout_eq_str(buf); \
}

#define TEST_STRING_ID(str, id) \
Test(my_printf, auto_string_##id, .init=redirect_all_std) { \
    my_printf("%s", str); \
    cr_assert_stdout_eq_str(str); \
}

/* -------------------- TESTS DE BASE -------------------- */

// Ints simples
TEST_INT_ID(0, 1, "%d")
TEST_INT_ID(42, 2, "%d")
TEST_INT_ID(-42, 3, "%d")
TEST_INT_ID(2147483647LL, 4, "%d")
TEST_INT_ID((-2147483647LL)-1, 5, "%d")

// Unsigned
TEST_UINT_ID(0, 6, "%u")
TEST_UINT_ID(42, 7, "%u")
TEST_UINT_ID(4294967295ULL, 8, "%u")

// Floats
TEST_FLOAT_ID(0.0, 9, "%f")
TEST_FLOAT_ID(3.141593, 10, "%f")
TEST_FLOAT_ID(-12.34, 11, "%f")
TEST_FLOAT_ID(12345.6789, 12, "%f")

// Char & String
TEST_CHAR_ID('A', 13)
TEST_CHAR_ID('Z', 14)
TEST_STRING_ID("Hello", 15)
TEST_STRING_ID("World", 16)
TEST_STRING_ID("", 17)
TEST_STRING_ID("(null)", 18)

/* -------------------- FLAGS + WIDTH + PRECISION -------------------- */

Test(my_printf, flag_plus_width_prec_int, .init=redirect_all_std)
{
    my_printf("%+10.5d", 42);
    cr_assert_stdout_eq_str("    +00042");
}

Test(my_printf, flag_minus_width_prec_int, .init=redirect_all_std)
{
    my_printf("%+-10.5dl", 42);
    cr_assert_stdout_eq_str("+00042    l");
}

Test(my_printf, flag_zero_width_int, .init=redirect_all_std)
{
    my_printf("%010d", 42);
    cr_assert_stdout_eq_str("0000000042");
}

Test(my_printf, flag_space_width_int, .init=redirect_all_std)
{
    my_printf("% 10d", 42);
    cr_assert_stdout_eq_str("        42");
}

Test(my_printf, flag_sharp_width_hex, .init=redirect_all_std)
{
    my_printf("%#08x", 255);
    cr_assert_stdout_eq_str("0x0000ff");
}

Test(my_printf, width_star_int, .init=redirect_all_std)
{
    my_printf("% -0+12.15ilkkdk",42);
    cr_assert_stdout_eq_str("+000000000000042lkkdk");
}

/* -------------------- FLOAT SCIENTIFIC -------------------- */

Test(my_printf, float_scientific_e, .init=redirect_all_std)
{
    my_printf("%e", 1234.5678);
    cr_assert_stdout_eq_str("1.234568e+03");
}

Test(my_printf, float_scientific_E, .init=redirect_all_std)
{
    my_printf("%E", 1234.5678);
    cr_assert_stdout_eq_str("1.234568E+03");
}

Test(my_printf, float_g, .init=redirect_all_std)
{
    my_printf("%g", 0.0001234);
    const char *out = cr_get_redirected_stdout();
    cr_assert(strstr(out, "0.0001234") != NULL);
}

Test(my_printf, float_G, .init=redirect_all_std)
{
    my_printf("%G", 123456789.0);
    const char *out = cr_get_redirected_stdout();
    cr_assert(strstr(out, "1.234568E+08") != NULL);
}

/* -------------------- FLAG %n -------------------- */

Test(my_printf, flag_n, .init=redirect_all_std)
{
    int count = 0;
    my_printf("Hello%nWorld", &count);
    cr_assert(count == 5);
}

/* -------------------- COMBINATOIRES MULTIPLES -------------------- */

Test(my_printf, combo_flags_length_width, .init=redirect_all_std)
{
    int val = 42;
    my_printf("%-+08d", val);
    cr_assert_stdout_eq_str("+42     ");  // '-' override '0'
}

Test(my_printf, combo_unsigned_sharp_width, .init=redirect_all_std)
{
    unsigned int val = 255;
    my_printf("%#10x", val);
    cr_assert_stdout_eq_str("      0xff");
}

Test(my_printf, combo_float_plus_prec, .init=redirect_all_std)
{
    double val = 3.14;
    my_printf("%+10.2f", val);
    cr_assert_stdout_eq_str("     +3.14");
}
