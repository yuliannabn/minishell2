/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** exit
*/

#include "minishell.h"

bool has_nbr(char *str)
{
    int a = 0;

    while (str[a]) {
        if (is_number(str[a]))
            return (true);
        a++;
    }
    return (false);
}

int exit_myshell(char **arg, char ***env, int *ret)
{
    int ext_code = 0;
    (void) env;

    if (arr_len(arg) > 1 && (ext_code = get_nbr(arg[1])) != ERROR)
        (*ret) = ext_code;
    else if (arr_len(arg) > 1) {
        print_error(EXIT_MSG);
        has_nbr(arg[1]) ? print_error(BAD_NBR) : print_error(EXPR_SYNTAX);
        (*ret) = EXIT_FAIL;
        return (FAILURE);
    }
    if (isatty(STDIN_FILENO))
        put_string(EXIT_MSG), put_char('\n');
    return (EXIT);
}
