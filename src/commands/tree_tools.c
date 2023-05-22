/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** tree_tools
*/

#include "minishell.h"

bool string_is_empty(char *str)
{
    int a = 0;

    if (!str)
        return (true);
    while (str[a]) {
        if (str[a] != ' ' && str[a] != '\t' && str[a] != '\n')
            return (false);
        a++;
    }
    return (true);
}

bool rev_index_has_string(char *str, char *lookup, int index)
{
    int a = 0;

    while (str[index] && lookup[a]) {
        if (str[index] != lookup[a])
            return (false);
        index++;
        a++;
    }
    if (lookup[a])
        return (false);
    return (true);
}

int find_latest_index(char *op, char *arg)
{
    for (int a = str_len(arg); a >= 0; a--) {
        if (rev_index_has_string(arg, op, a))
            return (a);
    }
    return (ERROR);
}

int get_split_index(char *arg, char **type)
{
    int b = 0, index = 0;
    char *op[] = OPERATORS;

    while (op[b]) {
        if ((index = find_latest_index(op[b], arg)) != ERROR) {
            (*type) = str_dup(op[b]);
            return (index);
        }
        b++;
    }
    return (ERROR);
}

int find_cut_index(char *arg)
{
    int a = 0;

    while (arg[a] == ' ' || arg[a] == '\t'
    || contains_special_command(arg[a])) {
        a++;
    }
    return (a);
}
