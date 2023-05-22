/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** prompt_record
*/

#include "minishell.h"

int execute_prompt(char **arg, char ***env, int *last_return)
{
    char *prompt = str_dup(arg[0]);
    char *builtin_list[] = BUILTIN_NAMES;
    builtin_ptr fnc_array[] = BUILTIN_FNC;

    for (int a = 0; a < BUILTIN_AMOUNT; a++) {
        if (str_equal(builtin_list[a], arg[0])) {
            free(prompt);
            return (fnc_array[a](arg, env, last_return));
        }
    }
    if (try_executable(&prompt, arg, (*env), last_return)) {
        free(prompt);
        return (OK);
    }
    access_error_print(prompt, last_return);
    return (NOT_CMD);
}
