/*
** EPITECH PROJECT, 2023
** standard
** File description:
** str_to_word
*/

#include "../../include/pui.h"

int get_arg_count(char *argstring, char sep)
{
    int args = 0;
    bool word_start = true;

    if (!argstring)
        return (args);
    for (int b = 0; argstring[b]; b++) {
        if (argstring[b] == sep)
            word_start = true;
        if (argstring[b] != sep && word_start) {
            word_start = false;
            args++;
        }
    }
    return (args);
}

int get_word_size(char *string, int index, char sep)
{
    int size = 0;

    while (string[index] != '\0' && string[index] != sep)
        size++, index++;
    return (size);
}

void copy_word(int *a, int word_size, char *res, char *arg)
{
    int g = 0;

    for (g = 0; g < word_size; g++, (*a) += 1)
        res[g] = arg[(*a)];
    res[g] = '\0';
}

char **str_to_word(char *arguments, char sep)
{
    int array_size = get_arg_count(arguments, sep);
    char **res = malloc(sizeof(char *) * (array_size + 1));
    int space = false, a = 0, b = 0, word_size = 0;

    if (!res || !arguments)
        return (NULL);
    while (arguments[a]) {
        word_size = get_word_size(arguments, a, sep);
        res[b] = malloc(sizeof(char) * (word_size + 1));
        space = arguments[a] == sep ? true : false;
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
