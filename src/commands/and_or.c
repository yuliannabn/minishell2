/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** and_or
*/

#include "minishell.h"

int and_execution(cmd_tree_t *tree, char ***env, int *last_return)
{
    run_status(tree->left, env, last_return);
    if ((*last_return) == SUCCESS)
        return (run_status(tree->right, env, last_return));
    return (OK);
}

int or_execution(cmd_tree_t *tree, char ***env, int *last_return)
{
    run_status(tree->left, env, last_return);
    if ((*last_return) != SUCCESS)
        return (run_status(tree->right, env, last_return));
    return (OK);
}
