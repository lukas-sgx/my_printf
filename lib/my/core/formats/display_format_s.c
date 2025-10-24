/*
** EPITECH PROJECT, 2025
** MyPrintf
** File description:
** display_format_s.c
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

static void display_minus(format_flags_t *format_f, int pad)
{
    if (format_f->minus)
        for (int i = 0; i < pad; i++)
            my_putchar(' ');
}

int display_format_s(char *c, format_flags_t *format_f,
    int *count)
{
    int len = my_strlen(c);
    int pad = (format_f->width > len)
        ? format_f->width - len : 0;

    my_putstr(c);
    *count += len + pad;
    display_minus(format_f, pad);
    return *count;
}

static int my_wcwidth(unsigned int c)
{
    if (c == 0)
        return 0;
    if (c < 32 || (c >= 0x7f && c < 0xa0))
        return 0;
    if (c >= 0x1100)
        return 5;
    return 1;
}

static int my_wstrlen(unsigned int *str)
{
    int width = 0;

    for (int i = 0; str[i] != L'\0'; i++)
        width += my_wcwidth(str[i]);
    return width;
}

int display_format_ws(unsigned int *c, format_flags_t *format_f, int *count)
{
    int len = my_wstrlen(c);
    int pad = (format_f->width > len) ? format_f->width - len : 0;

    if (!format_f->minus)
        display_minus(format_f, pad);
    my_putwstr(c);
    if (format_f->minus)
        display_minus(format_f, pad);
    *count += len + pad;
    return *count;
}
