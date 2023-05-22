/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** here_document
*/

#include "minishell.h"

bool no_right_stem(cmd_tree_t *tree)
{
    return (!tree || !tree->right || !tree->right->argument
        || string_is_empty(tree->right->argument));
}

bool no_left_stem(cmd_tree_t *tree)
{
    return (!tree || !tree->left || !tree->left->argument
        || string_is_empty(tree->left->argument));
}

bool heredoc_has_error(cmd_tree_t *tree, int *last_return)
{
    if (no_left_stem(tree)) {
        print_error(INVALID_NULL), (*last_return) = EXIT_FAIL; return (true);
    }
    if (no_right_stem(tree)) {
        print_error(MISSING_REDIR), (*last_return) = EXIT_FAIL; return (true);
    }
    return (false);
}

int here_document(cmd_tree_t *tree, char ***env, int *last_return)
{
    int fd = 0;
    char *file = str_dup(".heredoc"), *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (heredoc_has_error(tree, last_return))
        return (EXIT_FAIL);
    fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) return (EXIT_FAIL);
    if (isatty(0)) put_string("? ");
    while ((read = getline(&line, &len, stdin)) != -1) {
        line[read - 1] = '\0';
        if (!no_right_stem(tree) && str_equal(line, tree->right->argument))
            break;
        line[read - 1] = '\n', write(fd, line, read);
        if (isatty(0)) put_string("? ");
    }
    close(fd), free(line);
    if (!no_right_stem(tree)) free(tree->right->argument);
    tree->right->argument = file, redirect_input(tree, env, last_return);
    remove(".heredoc");
    return (OK);
}
