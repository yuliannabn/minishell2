/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cpy_str_array
*/

#include "../../include/pui.h"

void free_string_array(char **array)
{
    int a = 0;

    while (array[a]) {
        free(array[a]);
        a++;
    }
    free(array);
}

char **cpy_str_array(char **arr)
{
    char **arr2 = malloc(sizeof(char *) * (arr_len(arr) + 1));
    int a = 0;

    while (arr[a]) {
        arr2[a] = str_dup(arr[a]);
        a++;
    }
    arr2[a] = NULL;
    return (arr2);
}

char **concat_str_array(char **arr, char *new)
{
    int old_size = arr_len(arr);
    char **new_arr = malloc(sizeof(char *) * (old_size + 2));
    int a = 0;

    while (arr[a]) {
        new_arr[a] = str_dup(arr[a]);
        a++;
    }
    new_arr[a] = str_dup(new), new_arr[a + 1] = NULL;
    free_string_array(arr);
    return (new_arr);
}

char **delete_in_str_array(char **arr, char **str_ptr)
{
    int old_len = arr_len(arr);
    char **new = malloc(sizeof(char *) * (old_len));
    int a = 0, b = 0;

    while (arr[a]) {
        if (arr[a] == (*str_ptr)) {
            a++;
            continue;
        }
        new[b] = str_dup(arr[a]);
        a++, b++;
    }
    new[b] = NULL;
    free_string_array(arr);
    return (new);
}
