/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env
*/

#include "minishell.h"

char *concat_env_var(char *var, char *value)
{
    char *var_prefix = NULL;
    char *var_and_value = NULL;

    if (var && value) {
        var_prefix = str_cat(var, "=");
        var_and_value = str_cat(var_prefix, value);
        free(var_prefix);
        return (var_and_value);
    }
    return (NULL);
}

int print_env(char **arg, char ***env, int *ret)
{
    int a = 0;

    (void) arg;
    while ((*env)[a]) {
        put_string((*env)[a]), put_char('\n');
        a++;
    }
    (*ret) = OK;
    return (SUCCESS);
}

bool var_is_valid(char *env_name, char *prompt)
{
    if ((is_letter(prompt[0]) && is_alphanumeric(prompt)) ||
        str_equal(env_name, UNSETENV))
        return (true);
    return (false);
}

bool find_env_errors(int arg_len, char *env_name, char *prompt)
{
    if (!var_is_valid(env_name, prompt)) {
        print_error(env_name), print_error(PREFIX_VARNAME);
        if (!is_letter(prompt[0]))
            print_error(VAR_BEGIN_LETTER);
        else
            print_error(VAR_ALPHANUM);
        return (true);
    } else if (arg_len > 3) {
        print_error(env_name), print_error(ARG_TOO_MANY);
        return (true);
    }
    return (false);
}
