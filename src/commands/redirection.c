/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** redirection
*/

#include "minishell.h"

int redirect_output(cmd_tree_t *tree, char ***env, int *last_return)
{
    int fd = 0, stdout = dup(STDOUT_FILENO);

    if (redir_has_error(tree, last_return) ||
        req_is_dir(tree, last_return, true))
        return (EXIT_FAIL);
    fd = open(tree->right->argument, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dup2(fd, STDOUT_FILENO) == ERROR || fd == ERROR)
        return (EXIT_FAIL);
    run_status(tree->left, env, last_return);
    if (dup2(stdout, STDOUT_FILENO) == ERROR)
        return (EXIT_FAIL);
    close(fd);
    return (OK);
}

int redirect_output_append(cmd_tree_t *tree, char ***env, int *last_return)
{
    int fd = 0, stdout = dup(STDOUT_FILENO);

    if (redir_has_error(tree, last_return) ||
        req_is_dir(tree, last_return, true))
        return (EXIT_FAIL);
    fd = open(tree->right->argument, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (dup2(fd, STDOUT_FILENO) == ERROR || fd == ERROR)
        return (EXIT_FAIL);
    run_status(tree->left, env, last_return);
    if (dup2(stdout, STDOUT_FILENO) == ERROR)
        return (EXIT_FAIL);
    close(fd);
    return (OK);
}

int redirect_input(cmd_tree_t *tree, char ***env, int *last_return)
{
    int fd = 0, child = 0;

    if (redir_has_error(tree, last_return) || !(is_file(tree, last_return)))
        return (EXIT_FAIL);
    if ((fd = open(tree->right->argument, O_RDONLY)) == ERROR
    || (child = fork()) == ERROR)
        return (EXIT_FAIL);
    if (child == 0) {
        dup2(fd, STDIN_FILENO), close(fd);
        run_status(tree->left, env, last_return);
        exit((*last_return));
    } else {
        waitpid(child, last_return, 0), close(fd);
        return ((*last_return));
    }
}
