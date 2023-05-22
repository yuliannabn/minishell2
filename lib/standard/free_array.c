/*
** EPITECH PROJECT, 2023
** antman
** File description:
** free_array
*/

#include "../../include/pui.h"

void free_array(char **array)
{
    int a = 0;

    if (!array)
        return;
    while (array[a]) {
        if (array[a])
            free(array[a]);
        a++;
    }
    free(array);
}
