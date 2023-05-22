/*
** EPITECH PROJECT, 2023
** BSminishell2
** File description:
** pipe
*/

#include "minishell.h"

bool contains_special_command(char a)
{
    return (a == '|' || a == ';' || a == '<' || a == '>' || a == '&');
}

bool has_request(char *string)
{
    int a = 0;

    while (string[a]) {
        if (contains_special_command(string[a]))
            return (true);
        a++;
    }
    return (false);
}

void child_action(int *fd)
{
    dup2(fd[WRITE], STDOUT_FILENO);
    close(fd[READ]), close(fd[WRITE]);
}

void parent_action(int *fd)
{
    dup2(fd[READ], STDIN_FILENO);
    close(fd[READ]), close(fd[WRITE]);
}

int execute_pipe(cmd_tree_t *tree, char ***env, int *last_return)
{
    int fd[2], child = 0, child2 = 0;

    if (pipe_has_error(tree, last_return) || pipe(fd) == ERROR
    || (child = fork()) == ERROR)
        return (EXIT_FAIL);
    if (child == 0) {
        child_action(fd), run_status(tree->left, env, last_return);
        exit((*last_return));
    }
    if ((child2 = fork()) == ERROR)
        return (EXIT_FAIL);
    if (child2 == 0) {
        waitpid(child, last_return, WUNTRACED);
        parent_action(fd), run_status(tree->right, env, last_return);
        exit((*last_return));
    }
    close(fd[WRITE]), close(fd[READ]);
    waitpid(child2, last_return, WUNTRACED);
    return (OK);
}
