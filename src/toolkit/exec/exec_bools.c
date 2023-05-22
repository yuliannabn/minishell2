/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execute_binary
*/

#include "minishell.h"

bool can_be_executed(char *program)
{
    return (access(program, X_OK) > ERROR);
}

bool is_local_exec(char *exec)
{
    return (is_exec_command(exec) && can_be_executed(exec));
}

char *fill_bin_path(char *exec, char *path)
{
    char *exec_path = str_cat("/", exec);
    char *bin_path = str_cat(path, exec_path);

    free(exec_path);
    return (bin_path);
}

bool is_path_exec(char **exec, char **arg, char **env)
{
    char *var = find_env_var("PATH", env);
    char **paths = str_to_word(var, ':'), *bin_path = NULL;
    int a = 0;

    if (!var || !paths)
        return (false);
    free(var);
    while (paths[a] && arg && (*exec)) {
        bin_path = fill_bin_path((*exec), paths[a]);
        if (can_be_executed(bin_path)) {
            free((*exec)), (*exec) = str_dup(bin_path);
            free(bin_path), free_string_array(paths);
            return (true);
        }
        free(bin_path);
        a++;
    }
    free_string_array(paths);
    return (false);
}

bool is_directory(char *path)
{
    struct stat st;

    if (stat(path, &st) <= ERROR)
        return (false);
    return (S_ISDIR(st.st_mode));
}
