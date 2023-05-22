/*
** EPITECH PROJECT, 2023
** standard
** File description:
** str_to_word
*/

#include "../../include/pui.h"

bool is_separator(char ch, char *seps)
{
    if (ch == seps[0] || ch == seps[1])
        return (true);
    return (false);
}

int get_dbl_arg_count(char *argstring, char *seps)
{
    int args = 0;
    bool word_start = true;

    for (int b = 0; argstring[b]; b++) {
        if (is_separator(argstring[b], seps))
            word_start = true;
        if (!is_separator(argstring[b], seps) && word_start) {
            word_start = false;
            args++;
        }
    }
    return (args);
}

int get_dbl_word_size(char *string, int index, char *seps)
{
    int size = 0;

    while (string[index] != '\0' && !is_separator(string[index], seps))
        size++, index++;
    return (size);
}

char **str_to_word_double(char *arguments, char *seps)
{
    int array_size = get_dbl_arg_count(arguments, seps);
    char **res = malloc(sizeof(char *) * (array_size + 1));
    int space = false, a = 0, b = 0, word_size = 0;

    if (!res)
        return (NULL);
    while (arguments[a]) {
        word_size = get_dbl_word_size(arguments, a, seps);
        res[b] = malloc(sizeof(char) * (word_size + 1));
        space = is_separator(arguments[a], seps) ? true : false;
        if (!res[b])
            return (NULL);
        if (!space) {
            copy_word(&a, word_size, res[b], arguments);
            b++;
        } else
            free(res[b]), a++;
    }
    res[array_size] = NULL;
    return (res);
}
