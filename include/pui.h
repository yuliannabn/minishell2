/*
** EPITECH PROJECT, 2023
** pui_print
** File description:
** pui
*/

#ifndef PUI_H_
    #define PUI_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>

    #define     bool            int
    #define     mode            char
    #define     true            1
    #define     false           0
    #define     FAILURE         84
    #define     ERROR          -1
    #define     SUCCESS         0
    #define     ERROR_OUT       2
    #define     STD_OUT         1
    #define     READ            0
    #define     WRITE           1

    void        put_char            (char a);
    void        put_nbr             (int number);
    void        put_float           (float number, int decimals);
    void        put_string          (char *string);
    void        free_string_array   (char **array);
    void        copy_word       (int *a, int word_size, char *res, char *arg);
    int         str_len             (char const *string);
    int         arr_len             (char **array);
    double      get_nbr             (char *src);
    double      get_float           (int a, char *src, int num);
    bool        str_equal           (char *str, char *other);
    bool        is_number           (char a);
    bool        is_letter           (char a);
    bool        is_alphanumeric     (char *str);
    char       *number_string       (int number);
    char       *str_num             (int number);
    char       *str_dup             (char const *src);
    char       *nstr_dup            (int limit, char *str);
    char       *from_str_dup        (int start, char *str);
    char       *str_cat             (char *dest, char const *src);
    char      **delete_in_str_array (char **arr, char **str_ptr);
    char      **cpy_str_array       (char **arr);
    char      **str_to_word_double  (char *arguments, char *seps);
    char      **str_to_word         (char *arguments, char sep);

#endif
