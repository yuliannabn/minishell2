/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include "minishell.h"

int check_argument_validity(char *arg)
{
    if (open(arg, O_RDONLY) > ERROR)
        return (SUCCESS);
    print_error(arg), print_error(FILE_NOT_FOUND);
    return (FAILURE);
}

int main(int argc, char **arg, char **env)
{
    char **new_env = cpy_str_array(env);

    if (argc > 1)
        return (check_argument_validity(arg[1]));
    return (read_input(&new_env));
}
