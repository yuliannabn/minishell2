/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cd
*/

#include "minishell.h"

bool has_previous(char **env, bool has_old)
{
    char *oldpwd = find_env_var("OLDPWD", env);

    if (!oldpwd || !has_old || !is_directory(oldpwd)) {
        has_old = false;
        free(oldpwd);
        return (false);
    }
    free(oldpwd);
    return (true);
}

int request_type(int len, char **request, char ***env, bool has_old)
{
    bool home = (len == 1) || str_equal((*request), "~") ? true : false;
    bool prev = str_equal((*request), "-") ? true : false;

    if (home)
        return (HOME_REQ);
    if (prev && has_previous((*env), has_old))
        return (PREV_REQ);
    if (prev && !has_previous((*env), has_old))
        (*request)[0] = '\0';
    return (NONE);
}

void check_home(char ***env, char **req_path)
{
    char *home = find_env_var("HOME", (*env));
    if (!home || !is_directory(home)) {
        print_error(CD_COMMAND), print_error(HOME_ERROR);
    } else {
        (*req_path) = home;
        chdir(home);
    }
}

int change_directory(char **arg, char ***env, int *ret)
{
    static bool has_old = false;
    int len = arr_len(arg);
    char *requested_path = len == 1 ? NULL : arg[1];
    char *old_pwd = get_current_location();
    int req_type = request_type(len, &requested_path, env, has_old);

    if (req_type != NONE) {
        if (req_type == HOME_REQ)
            check_home(env, &requested_path);
        if (req_type == PREV_REQ) {
            requested_path = find_env_var("OLDPWD", (*env));
            chdir(requested_path);
        }
    } else if (chdir_has_error(arg, &requested_path, len))
        return ((*ret) = FAILURE);
    has_old = true;
    set_cd_vars(old_pwd, requested_path, env);
    return ((*ret) = OK);
}
