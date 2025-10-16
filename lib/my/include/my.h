/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** libmy
*/

#ifndef LIB_H
    #define LIB_H

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_put_unsigned(unsigned int nb);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char *uint_to_str(unsigned int n);
#endif
