/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** operations
*/

#ifndef OPERATIONS_H_
    #define OPERATIONS_H_

    #define PIPE_FAIL       "Pipe failed.\n"
    #define EXCEPT           1
    #define MISSING_REDIR   "Missing name for redirect.\n"
    #define INVALID_REDIR   "Invalid null command.\n"
    #define IS_DIR          ": Is a directory\n"
    #define SEPARATORS      " \t"
    #define OP_COUNT        6
    #define LONGEST_OP      2

    typedef struct cmd_tree_s {
        char *argument;
        struct cmd_tree_s *left;
        struct cmd_tree_s *right;
    } cmd_tree_t;

    typedef int (*operator)(cmd_tree_t *tree, char ***env, int *last_return);

    #define OPERATORS { \
        ";", "&&", "||", ">>", "<<", ">", "<", "|", NULL \
    }

    #define OPS { \
        &separator_command, &and_execution, &or_execution,          \
        &redirect_output_append, &here_document, &redirect_output,  \
        &redirect_input, &execute_pipe                              \
    }

    int     find_cut_index              (char *arg);
    int     get_split_index             (char *arg, char **type);
    int     find_latest_index           (char *op, char *arg);
    int     and_execution               (cmd_tree_t *, char ***, int *);
    int     or_execution                (cmd_tree_t *, char ***, int *);
    bool    rev_index_has_string        (char *str, char *lookup, int index);
    int     here_document               (cmd_tree_t *tree, char ***env, int *last_return);
    bool    contains_special_command    (char a);
    bool    req_is_dir                  (cmd_tree_t *tree, int *ret, bool show);
    bool    redir_has_error             (cmd_tree_t *tree, int *ret);
    bool    is_file                     (cmd_tree_t *tree, int *ret);
    bool    invalid_tree                (cmd_tree_t *tree, int *ret);
    bool    string_is_empty             (char *str);
    bool    has_request                 (char *string);
    int     here_document               (cmd_tree_t *tree, char ***env,
    int *last_return);
    int     execute_pipe                (cmd_tree_t *tree, char ***env,
    int *last_return);
    int     redirect_input              (cmd_tree_t *tree, char ***env,
    int *last_return);
    int     separator_command           (cmd_tree_t *tree, char ***env,
    int *last_return);
    int     redirect_output             (cmd_tree_t *tree, char ***env,
    int *last_return);
    int     redirect_output_append      (cmd_tree_t *tree, char ***env,
    int *last_return);
    int     run_status                  (cmd_tree_t *tree, char ***env,
    int *last_return);
    cmd_tree_t *tree_create                 (char *arg);
    cmd_tree_t *tree_fill                   (cmd_tree_t *tree, char *arg);
    void    tree_print                  (cmd_tree_t *tree);
#endif
