/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}
