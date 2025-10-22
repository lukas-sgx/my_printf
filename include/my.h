/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** libmy
*/

#ifndef LIB_H
    #define LIB_H

void my_putchar(char c);
void my_putwchar(unsigned int c);
int my_puterror(char *str);
int my_putwstr(unsigned int *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_put_unsigned(unsigned int nb);
int my_putfloat(double nb, int precision);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char *uint_to_str(unsigned int n);
char *ulint_to_str(unsigned long int n);
char *ullint_to_str(unsigned long long int n);
int my_compute_power_rec(int nb, int p);
char **my_str_to_word_array(char const *str);
int my_put_long_nbr(long int nb);
int my_put_dlong_nbr(long long int nb);
int my_put_llunsigned(unsigned long long int nb);
int my_put_lunsigned(unsigned long int nb);
char *int_to_str(int n);
int my_strlen(char *str);
char *float_to_str(double nb, int precision);
int count_int(int nb);
int count_lint(long int nb);
int count_dlint(long long int nb);
#endif
