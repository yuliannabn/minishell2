/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execute_binary
*/

#include "minishell.h"

void print_signal_out(int ret)
{
    int ext_code = WTERMSIG(ret);

    if (ext_code == SIGBUS || ext_code == SIGSEGV)
        print_error(strsignal(WTERMSIG(ret)));
    if (ext_code == SIGABRT)
        print_error("Abort");
    if (ext_code == SIGFPE)
        print_error("Floating exception");
    if (WCOREDUMP(ret))
        print_error(COREDUMPED);
    print_error("\n");
}

bool is_printable_signal(int last_return)
{
    int sigs[] = {SIGBUS, SIGSEGV, SIGABRT, SIGFPE};
    int a = 0;

    while (a < SIG_AMT) {
        if (WTERMSIG(last_return) == sigs[a])
            return (true);
        a++;
    }
    return (false);
}

bool no_permissions(char *program)
{
    return (access(program, R_OK) <= ERROR ||
            access(program, X_OK) <= ERROR ||
            access(program, W_OK) <= ERROR);
}
