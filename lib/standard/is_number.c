/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** char-checkers
*/

#include "../../include/pui.h"

bool is_number(char a)
{
    if (a < '0' || a > '9')
        return (false);
    return (true);
}

bool is_letter(char a)
{
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a == '_'))
        return (true);
    return (false);
}

bool is_alphanumeric(char *str)
{
    int a = 0;

    while (str[a]) {
        if (!is_number(str[a]) && !is_letter(str[a]))
            return (false);
        a++;
    }
    return (true);
}
