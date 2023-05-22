/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cd_misc
*/

#include "minishell.h"

bool chdir_has_error(char **arg, char **path, int len)
{
    char *err_str;
    int chdir_return = chdir((*path));
    bool arg_overflow = (len > 2) ? true : false;
    (*path) = len == 2 ? str_dup(arg[1]) : NULL;

    if (arg_overflow) {
        print_error(CD_COMMAND), print_error(ARG_TOO_MANY);
        return (true);
    }
    if ((*path) && chdir_return <= ERROR) {
        err_str = strerror(errno);
        print_error((*path)), print_error(": ");
        print_error(err_str), print_error(".\n");
        free((*path));
        return (true);
    }
    return (false);
}

char *get_current_location(void)
{
    char *here = NULL;
    size_t size = 0;

    return (getcwd(here, size));
}

void set_cd_vars(char *old_pwd, char *requested_path, char ***env)
{
    char *curr = get_current_location();

    set_variable("OLDPWD", old_pwd, env);
    set_variable("PWD", curr, env);
    free(requested_path), free(old_pwd), free(curr);
}
