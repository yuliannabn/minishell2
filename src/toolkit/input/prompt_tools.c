/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** prompt_wait
*/

#include "minishell.h"

void remove_enter(char **prompt, int len)
{
    if ((*prompt)[len - 1] == '\n')
        (*prompt)[len - 1] = '\0';
    else {
        (*prompt)[len] = '\0';
        if (isatty(STDIN_FILENO))
            put_char('\n');
    }
}

void put_colored_string(char *color, char *str)
{
    put_string(color), put_string(str), put_string(color);
    put_char(' ');
}

void put_wait_text(int prev_ret)
{
    char *arrow_color = prev_ret == OK ? GREEN : RED;

    put_colored_string(BLUE, "$");
    put_colored_string(YELLOW, "[ ");
    put_colored_string(arrow_color, "> ");
    put_colored_string(YELLOW, "] : ");
    put_string(NORMAL);
}

void prompt_wait(int prev_ret)
{
    char *current_path = get_path_name();
    put_colored_string(BLUE, current_path);
    put_wait_text(prev_ret);
    free(current_path);
}
