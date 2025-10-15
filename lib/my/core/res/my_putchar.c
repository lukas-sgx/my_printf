/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
