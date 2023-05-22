/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** read_input
*/

#include "minishell.h"
int run_status(cmd_tree_t *tree, char ***env, int *last_return);

char *get_input_string(int prev_ret)
{
    size_t size = 0;
    int len = 0;
    char *buf = NULL;

    signal(SIGINT, ctrl_c_skip);
    while (string_is_empty(buf) && len > ERROR) {
        if (isatty(STDIN_FILENO))
            prompt_wait(prev_ret);
        len = getline(&buf, &size, stdin);
        if (len == END_OF_FILE)
            return (str_dup(EXIT_MYSHELL));
        remove_enter(&buf, len);
    }
    return (buf);
}

int separator_command(cmd_tree_t *tree, char ***env, int *last_return)
{
    run_status(tree->left, env, last_return);
    return (run_status(tree->right, env, last_return));
}

int run_status(cmd_tree_t *tree, char ***env, int *last_return)
{
    char **args = NULL, *OPERATOR[] = OPERATORS;
    operator OPERATIONS[] = OPS;
    int res = 0;

    if (!tree || !tree->argument)
        return (OK);
    for (int a = 0; OPERATOR[a]; a++)
        if (str_equal(tree->argument, OPERATOR[a]))
            return (OPERATIONS[a](tree, env, last_return));
    if (!string_is_empty(tree->argument)) {
        args = str_to_word_double(tree->argument, SEPARATORS);
        res = execute_prompt(args, env, last_return);
        free_string_array(args);
        return (res);
    }
    return (OK);
}

int read_input(char ***env)
{
    int status = RUNNING;
    cmd_tree_t *tree = NULL;
    int last_return = 0;
    char *input = NULL;

    while (status >= RUNNING) {
        input = get_input_arguments(last_return);
        tree = tree_create(input);
        status = run_status(tree, env, &last_return);
        free(input);
    }
    free_string_array((*env));
    return (last_return);
}
