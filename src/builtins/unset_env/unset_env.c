/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** unset_env
*/

#include "minishell.h"

int unset_env(char **arg, char ***env, int *ret)
{
    char **prompt_ptr = NULL;
    int a = 1;

    if (!arg[a]) {
        print_error(UNSETENV), print_error(TOO_FEW_ARG);
        (*ret) = FAILURE;
    } else {
        while (arg[a]) {
            prompt_ptr = find_env_var_ptr(arg[a], (*env));
            (*env) = prompt_ptr ?
            delete_in_str_array((*env), prompt_ptr) : (*env);
            a++;
        }
        (*ret) = OK;
    }
    return (OK);
}
