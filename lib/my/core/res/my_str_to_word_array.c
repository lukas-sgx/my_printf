/*
** EPITECH PROJECT, 2025
** G-CPE-101-NCE-1-1-myprintf-5
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>

int count_words(const char *str)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126 && !in_word) {
            count++;
            in_word = 1;
        } else {
            in_word = 0;
        }
    }
    return count;
}

int count_char(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126)
            count++;
    }
    return count;
}

char **my_str_to_word_array(char const *str)
{
    char **word_array = malloc(sizeof(char **) * (count_words(str) + 1));
    int i = 0;
    int d = 0;

    for (i = 0; i <= count_words(str); i++) {
        word_array[i] = malloc(sizeof(char) * (count_char(str) + 1));
    }
    i = 0;
    for (int e = 0; str[e] != '\0'; e++) {
        if (str[e] >= 32 && str[e] <= 126) {
            word_array[i][d] = str[e];
            d++;
        } else {
            word_array[i][d] = '\0';
            i++;
            d = 0;
        }
    }
    word_array[i + 1] = 0;
    return word_array;
}
