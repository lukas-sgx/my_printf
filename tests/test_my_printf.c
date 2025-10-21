/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Unit tests for my_printf using Criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdio.h>
#include "../include/myprintf.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Fonction utilitaire pour lire le contenu actuel du stdout redirigé
static const char *get_stdout_content(void)
{
    fflush(stdout);
    FILE *out = cr_get_redirected_stdout();
    static char buffer[4096];
    long pos = ftell(out);
    fseek(out, 0, SEEK_SET);
    size_t len = fread(buffer, 1, sizeof(buffer) - 1, out);
    buffer[len] = '\0';
    fseek(out, pos, SEEK_SET);
    return buffer;
}

/* ---------------------------------------------------------
**  BASIC FORMAT TESTS
** --------------------------------------------------------- */

Test(my_printf, print_char, .init=redirect_all_std)
{
    my_printf("A%cB", 'Z');
    cr_assert_stdout_eq_str("AZB");
}

Test(my_printf, print_string, .init=redirect_all_std)
{
    my_printf("Hello %s !", "world");
    cr_assert_stdout_eq_str("Hello world !");
}

Test(my_printf, print_int, .init=redirect_all_std)
{
    my_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf, print_negative_int, .init=redirect_all_std)
{
    my_printf("%i", -123);
    cr_assert_stdout_eq_str("-123");
}

Test(my_printf, print_unsigned, .init=redirect_all_std)
{
    my_printf("%u", 4294967295u);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_printf, print_hex_lower, .init=redirect_all_std)
{
    my_printf("%x", 255);
    cr_assert_stdout_eq_str("ff");
}

Test(my_printf, print_hex_upper, .init=redirect_all_std)
{
    my_printf("%X", 255);
    cr_assert_stdout_eq_str("FF");
}

Test(my_printf, print_octal, .init=redirect_all_std)
{
    my_printf("%o", 83);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, print_pointer, .init=redirect_all_std)
{
    int a = 42;
    my_printf("%p", &a);
    const char *out = get_stdout_content();
    cr_assert(strstr(out, "0x") != NULL, "Expected pointer to start with 0x");
}

Test(my_printf, print_percent, .init=redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

/* ---------------------------------------------------------
**  FLAGS TESTS
** --------------------------------------------------------- */

Test(my_printf, flag_plus, .init=redirect_all_std)
{
    my_printf("%+d", 42);
    cr_assert_stdout_eq_str("+42");
}

Test(my_printf, flag_space, .init=redirect_all_std)
{
    my_printf("% d", 42);
    cr_assert_stdout_eq_str(" 42");
}

Test(my_printf, flag_zero_padding, .init=redirect_all_std)
{
    my_printf("%05d", 42);
    cr_assert_stdout_eq_str("00042");
}

Test(my_printf, flag_left_align, .init=redirect_all_std)
{
    my_printf("%-5d", 42);
    cr_assert_stdout_eq_str("42   ");
}

Test(my_printf, flag_sharp_hex, .init=redirect_all_std)
{
    my_printf("%#x", 255);
    cr_assert_stdout_eq_str("0xff");
}

Test(my_printf, flag_sharp_octal, .init=redirect_all_std)
{
    my_printf("%#o", 83);
    cr_assert_stdout_eq_str("0123");
}

/* ---------------------------------------------------------
**  LENGTH MODIFIERS TESTS
** --------------------------------------------------------- */

Test(my_printf, length_h_short, .init=redirect_all_std)
{
    short val = 32767;
    my_printf("%hd", val);
    cr_assert_stdout_eq_str("32767");
}

Test(my_printf, length_hh_char, .init=redirect_all_std)
{
    signed char val = -128;
    my_printf("%hhd", val);
    cr_assert_stdout_eq_str("-128");
}

Test(my_printf, length_l_long, .init=redirect_all_std)
{
    long val = 2147483648;
    my_printf("%ld", val);
    cr_assert_stdout_eq_str("2147483648");
}

Test(my_printf, length_ll_longlong, .init=redirect_all_std)
{
    long long val = 9223372036854775807LL;
    my_printf("%lld", val);
    cr_assert_stdout_eq_str("9223372036854775807");
}

Test(my_printf, length_L_long_double, .init=redirect_all_std)
{
    long double val = 3.141592653589793238L;
    my_printf("%Lf", val);
    const char *out = get_stdout_content();
    cr_assert(strstr(out, "3.1415") != NULL);
}

/* ---------------------------------------------------------
**  FLOAT TESTS
** --------------------------------------------------------- */

Test(my_printf, print_float, .init=redirect_all_std)
{
    my_printf("%f", 3.141593);
    const char *out = get_stdout_content();
    cr_assert(strstr(out, "3.141") != NULL);
}

// Test(my_printf, print_float_with_precision, .init=redirect_all_std)
// {
//     my_printf("%.2f", 3.141593);
//     cr_assert_stdout_eq_str("3.14");
// }

Test(my_printf, print_negative_float, .init=redirect_all_std)
{
    my_printf("%f", -12.34);
    const char *out = get_stdout_content();
    cr_assert(strstr(out, "-12.34") != NULL);
}

/* ---------------------------------------------------------
**  EDGE CASES
** --------------------------------------------------------- */

Test(my_printf, zero_value, .init=redirect_all_std)
{
    my_printf("%d", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, null_string, .init=redirect_all_std)
{
    my_printf("%s", NULL);
    cr_assert_stdout_eq_str("(null)");
}

Test(my_printf, max_unsigned, .init=redirect_all_std)
{
    my_printf("%llu", 18446744073709551615ULL);
    cr_assert_stdout_eq_str("18446744073709551615");
}
