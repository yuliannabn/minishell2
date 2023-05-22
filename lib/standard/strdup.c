/*
** EPITECH PROJECT, 2022
** myls
** File description:
** strdup
*/

#include "../../include/pui.h"

char *str_dup(char const *src)
{
    int len = str_len(src);
    char *str = malloc(sizeof(char) * (len + 1));
    int a = 0;

    if (!str || !src)
        return (NULL);
    while (src[a]) {
        str[a] = src[a];
        a++;
    }
    str[a] = '\0';

    return (str);
}

char *cut_string(int from, int to, char *src)
{
    char *new = malloc(sizeof(char) * ((to - from) + 1));

    (void) new, (void) from, (void) to, (void) src;

    return (NULL);
}

char *nstr_dup(int lim, char *str)
{
    int a = 0;
    char *new = !(str && lim <= 0) ? malloc(sizeof(char) * (lim + 1)) : NULL;

    if (!new)
        return (NULL);
    while (a < lim) {
        new[a] = str[a];
        a++;
    }
    new[a] = '\0';
    return (new);
}

char *from_str_dup(int start, char *str)
{
    int a = start, size = str_len(str) - (start);
    int b = 0;
    char *new = !(str && size <= 0) ? malloc(sizeof(char) * (size + 1)) : NULL;

    if (!new)
        return (NULL);
    while (str[a]) {
        new[b] = str[a];
        a++, b++;
    }
    new[b] = '\0';
    return (new);
}
