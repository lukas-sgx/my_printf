/*
** EPITECH PROJECT, 2025
** G-CPE-101-NCE-1-1-myprintf-5
** File description:
** my_putwstr.c
*/

#include "../../../../include/myprintf.h"
#include "../../../../include/my.h"

int my_putwstr(unsigned int *str)
{
    int i;

    for (i = 0; str[i] != 0; i++) {
        my_putwchar(str[i]);
    }
    return i;
}
