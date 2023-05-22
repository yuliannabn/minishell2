/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** bool_misc
*/

#include "minishell.h"

void print_error(char *str)
{
    write(ERROR_OUT, str, str_len(str));
}

int find_pathname_index(char *here)
{
    int index = 0, bookmark = 0;

    while (here && here[index]) {
        if (here[index] == '/')
            bookmark = index + 1;
        index++;
    }
    return (bookmark);
}

char *get_path_from_name(char *path)
{
    int bookmark = find_pathname_index(path), index = 0;
    char *pathname = malloc(sizeof(char) * (bookmark + 1));

    if (!pathname)
        return (NULL);
    while (index < bookmark - 1) {
        pathname[index] = (path[index]);
        index++;
    }
    pathname[index] = '\0';
    return (pathname);
}

char *get_path_name(void)
{
    char *here = get_current_location();
    int bookmark = find_pathname_index(here), index = 0;
    char *pathname = malloc(sizeof(char) * ((str_len(here) - bookmark) + 1));

    if (!pathname)
        return (NULL);
    while (here[bookmark]) {
        pathname[index] = (here[bookmark]);
        index++, bookmark++;
    }
    pathname[index] = '\0';
    free(here);
    return (pathname);
}

bool file_exists(char *program)
{
    return (access(program, F_OK) > ERROR ? true : false);
}
