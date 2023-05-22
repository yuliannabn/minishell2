/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** set_env
*/

#include "minishell.h"

char **variable_exists(char *prompt, char **env)
{
    char **var_ptr = NULL;

    if ((var_ptr = find_env_var_ptr(prompt, env)))
        return (var_ptr);
    return (NULL);
}

void set_new_variable(char *var, char *value, char ***env)
{
    char *env_str = concat_env_var(var, value);

    (*env) = concat_str_array((*env), env_str);
    free(env_str);
}

void set_variable(char *var, char *value, char ***env)
{
    char **var_ptr = NULL;

    if ((var_ptr = variable_exists(var, (*env))) != NULL) {
        free((*var_ptr));
        (*var_ptr) = concat_env_var(var, value);
    } else if (var && value)
        set_new_variable(var, value, env);
}

void free_vars(char *var, char *value)
{
    if (var)
        free(var);
    if (value)
        free(value);
}

int set_env(char **arg, char ***env, int *ret)
{
    int arg_len = arr_len(arg);
    char *var = NULL, *value = NULL;

    if (arg_len == 1)
        return (print_env(arg, env, ret));
    if (arg_len > 1 && find_env_errors(arg_len, SETENV, arg[1])) {
        (*ret) = 84;
    } else if (arg_len >= 2) {
        var = str_dup(arg[1]);
        value = arg[2] ? str_dup(arg[2]) : str_dup(EMPTY);
        set_variable(var, value, env);
        ((*ret) = OK);
    }
    free_vars(var, value);
    return (OK);
}
