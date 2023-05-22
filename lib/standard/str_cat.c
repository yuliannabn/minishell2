/*
** EPITECH PROJECT, 2022
** CPool_07
** File description:
** my_strcat
*/

#include "../../include/pui.h"

char *str_cat(char *dest, char const *src)
{
    int a = 0;
    int len = str_len(dest);
    char *_dest = malloc(sizeof(char) * (len + str_len(src)) + 1);

    if (!_dest || !src)
        return (NULL);
    for (int b = 0; dest[b] != '\0'; b++)
        _dest[b] = dest[b];
    for (; src[a] != '\0'; a++)
        _dest[len + a] = src[a];
    _dest[len + a] = '\0';
    return (_dest);
}
