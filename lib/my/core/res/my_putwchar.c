/*
** EPITECH PROJECT, 2025
** G-CPE-101-NCE-1-1-myprintf-5
** File description:
** my_putwchar.c
*/

#include <unistd.h>

void my_putwcharif(unsigned char *bytes, int *len, unsigned int c)
{
    if (c <= 0xFFFF) {
        bytes[0] = 0xE0 | ((c >> 12) & 0x0F);
        bytes[1] = 0x80 | ((c >> 6) & 0x3F);
        bytes[2] = 0x80 | (c & 0x3F);
        *len = 3;
        write(1, bytes, *len);
        return;
    }
    if (c <= 0x10FFFF) {
        bytes[0] = 0xF0 | ((c >> 18) & 0x07);
        bytes[1] = 0x80 | ((c >> 12) & 0x3F);
        bytes[2] = 0x80 | ((c >> 6) & 0x3F);
        bytes[3] = 0x80 | (c & 0x3F);
        *len = 4;
        write(1, bytes, *len);
        return;
    }
}

void my_putwchar(unsigned int c)
{
    unsigned char bytes[4];
    int len = 0;

    if (c <= 0x7F) {
        bytes[0] = c;
        len = 1;
        write(1, bytes, len);
        return;
    }
    if (c <= 0x7FF) {
        bytes[0] = 0xC0 | ((c >> 6) & 0x1F);
        bytes[1] = 0x80 | (c & 0x3F);
        len = 2;
        write(1, bytes, len);
        return;
    }
    my_putwcharif(bytes, &len, c);
}
