/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** minishell1
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include "./files.h"
    #include <string.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <signal.h>
    #include <sys/wait.h>
    #include "operations.h"

    #define MAX_SIZE                        1026
    #define RUNNING                         0
    #define OK                              0
    #define BAD_ARG_BUILTIN                 84
    #define POSSIBLE_OUTCOMES               0
    #define NO_RETURN                       -9999
    #define EXIT                           -1
    #define EXIT_FAIL                       84
    #define VALID_ARG_LENGTH                2
    #define NOT_CMD                         1
    #define END_OF_FILE                     -1
    #define CTRLD                           -1
    #define RED                             "\x1b[31m"
    #define BLUE                            "\x1b[34m"
    #define YELLOW                          "\x1b[1m\x1b[33m"
    #define GREEN                           "\x1b[32m"
    #define NORMAL                          "\x1b[m"
    #define COREDUMPED                      " (core dumped)"
    #define ARG_TOO_MANY                    ": Too many arguments.\n"
    #define PREFIX_VARNAME                  ": Variable name must "
    #define VAR_BEGIN_LETTER                "begin with a letter.\n"
    #define VAR_ALPHANUM                   "contain alphanumeric characters.\n"
    #define CMD_NOT_FOUND                   ": Command not found.\n"
    #define FILE_NOT_FOUND                  ": No such file or directory.\n"
    #define PERSMISSION_DENIED              ": Permission denied.\n"
    #define TOO_FEW_ARG                     ": Too few arguments.\n"
    #define EXIT_MSG                        "exit"
    #define ENV_REQUEST                     "env"
    #define SETENV                          "setenv"
    #define UNSETENV                        "unsetenv"
    #define CD_COMMAND                      "cd"
    #define EXIT_MYSHELL                    "exit"
    #define VAR_NOT_FOUND                   "null"
    #define EMPTY                           ""
    #define HOME_ERROR                   ": Can't change to home directory.\n"
    #define EXPR_SYNTAX                     ": Expression Syntax.\n"
    #define BAD_NBR                         ": Badly formed number.\n"
    #define INVALID_NULL                    "Invalid null command.\n"
    #define BIN_NOT_EXEC                    ". Binary file not executable.\n"
    #define NO_ERROR                        0
    #define SIG_AMT                         4
    #define HAS_ERROR                       1
    #define NONE                            0
    #define LOCAL_BIN                       1
    #define PATH_BIN                        2
    #define HOME_REQ                        5
    #define PREV_REQ                        6
    #define NO_PREV                         7
    #define BUILTIN_AMOUNT                  5
    #define NOT_BUILTIN                     -84
    #define BUILTIN_NAMES {                                     \
        EXIT_MYSHELL, ENV_REQUEST, CD_COMMAND, SETENV, UNSETENV \
    }
    #define BUILTIN_FNC {                                       \
        &exit_myshell, &print_env, &change_directory, &set_env, \
        &unset_env                                              \
    }

    typedef int(*builtin_ptr)    (char **arg, char ***env, int *ret);

    bool   try_executable       (char **x, char **a, char **env, int *pr);
    bool   is_exec_command      (char *path);
    bool   is_printable_signal  (int last_return);
    bool   no_permissions       (char *program);
    bool   file_exists          (char *program);
    bool   is_directory         (char *path);
    bool   pipe_has_error       (cmd_tree_t *tree, int *ret);
    bool   is_local_exec        (char *exec);
    bool   is_path_exec         (char **exec, char **arg, char **env);
    bool   chdir_has_error      (char **arg, char **path, int len);
    bool   find_env_errors      (int arg_len, char *env_name, char *prompt);
    char  *get_input_string     (int prev_ret);
    char  *get_current_location (void);
    char  *get_path_name        (void);
    char  *get_path_from_name   (char *path);
    char  *find_env_var         (char *prompt, char **env);
    char  *concat_env_var       (char *var, char *value);
    char **find_env_var_ptr     (char *prompt, char **env);
    char  *get_input_arguments  (int prev_ret);
    char **concat_str_array     (char **arr, char *new);
    char **delete_in_str_array  (char **arr, char **str_ptr);
    int    find_pathname_index  (char *here);
    int    execute_prompt       (char **arg, char ***env, int *last_return);
    int    print_env            (char **arg, char ***env, int *ret);
    int    set_env              (char **arg, char ***env, int *ret);
    int    unset_env            (char **arg, char ***env, int *ret);
    int    exit_myshell         (char **arg, char ***env, int *ret);
    int    change_directory     (char **arg, char ***env, int *ret);
    int    is_executable        (char **exec, char **arg, char **env);
    int    execute_binary       (char *x, char **arg, char **env, int *pr);
    int    read_input           (char ***env);
    void   print_signal_out     (int ret);
    void   remove_enter         (char **prompt, int len);
    void   set_cd_vars          (char *old_pwd, char *req,char ***env);
    void   set_variable         (char *var, char *value, char ***env);
    void   access_error_print   (char *program, int *program_return);
    void   print_error          (char *str);
    void   ctrl_c_skip          (int signal);
    void   prompt_wait          (int prev_ret);

#endif
