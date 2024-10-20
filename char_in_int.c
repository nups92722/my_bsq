/*
** EPITECH PROJECT, 2022
** char_in_int_for_base_10
** File description:
** char_in_int_for_base_10
*/
#include <stdio.h>
int my_find_number(int i, char *format);

float char_in_float(char *s, int i, double f)
{
    double f_deci = 0;
    int nb_c = my_find_number(i, s) - i;
    while (nb_c > 0) {
        f_deci += s[i] - 48;
        f_deci /= 10;
        nb_c--;
    }
    f += f_deci;
    return (f);
}

float char_in_int(char *s)
{
    int nb_c = my_find_number(0, s);
    int i = 0;
    int sign = 1;
    double f = 0;
    for (; s[i] == '-' || s[i] == '+'; i++) {
        if (s[i] == '-')
            sign *= - 1;
    }
    while (i < nb_c) {
        f *= 10;
        f += s[i] - 48;
        i++;
    }
    f *= sign;
    if (s[nb_c] != '.') {
        return (f);
    } else {
        f = char_in_float(s, nb_c + 1, f);
        return (f);
    }
}
