/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** redirection_tools
*/

#include "minishell.h"

bool invalid_tree(cmd_tree_t *tree, int *ret)
{
    if (!tree || !tree->right || !tree->right->argument) {
        print_error(MISSING_REDIR), (*ret) = EXIT_FAIL;
        return (true);
    }
    return (false);
}

bool pipe_has_error(cmd_tree_t *tree, int *ret)
{
    if (!tree || !tree->right || !tree->right->argument
    || string_is_empty(tree->right->argument) || !tree->left
    || !tree->left->argument || string_is_empty(tree->left->argument)) {
        print_error(INVALID_NULL), (*ret) = EXIT_FAIL;
        return (true);
    }
    return (false);
}

bool req_is_dir(cmd_tree_t *tree, int *ret, bool show)
{
    struct stat st;
    stat(tree->right->argument, &st);

    if (S_ISDIR(st.st_mode)) {
        if (show) {
            print_error(tree->right->argument);
            print_error(IS_DIR), (*ret) = EXIT_FAIL;
        }
        return (true);
    }
    return (false);
}

bool is_file(cmd_tree_t *tree, int *ret)
{
    if (!file_exists(tree->right->argument) &&
        !req_is_dir(tree, ret, false)) {
        print_error(tree->right->argument),
        print_error(FILE_NOT_FOUND), (*ret) = EXIT_FAIL;
        return (false);
    }
    return (true);
}

bool redir_has_error(cmd_tree_t *tree, int *ret)
{
    if (invalid_tree(tree, ret))
        return (true);
    if (!tree->left || !tree->left->argument
    || string_is_empty(tree->left->argument)) {
        print_error(INVALID_NULL), (*ret) = EXIT_FAIL;
        return (true);
    }
    return (false);
}
