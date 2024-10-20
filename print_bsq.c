/*
** EPITECH PROJECT, 2022
** print bsq
** File description:
** print map and bsq
*/

#include <my.h>

int print_bsq (square_t square, char *s, int size)
{
    write (1, s, size);
    if (square.type == 'f')
        write (1, "\n", 1);
    free(s);
    return (0);
}

int prepare_print_bsq(char **tab, square_t square, int h, int l)
{
    int x = 0;
    int y = 0;
    int i = 0;
    int size = h * (l + 1) - 1;
    char *s = malloc(sizeof(char) * (size));

    for (; i < size; i++) {
        if (x < l) {
            s[i] = tab[y][x];
        } else {
            y++;
            x = 0;
            s[i] = '\n';
            i++;
            s[i] = tab[y][x];
        }
        x++;
    }
    print_bsq(square, s, size);
    return (0);
}

int put_x(char **tab, square_t square, int h, int l)
{
    int len_x = square.x + square.len;
    int len_y = square.y + square.len;

    for (int y = square.y; y < len_y; y++)
        for (int x = square.x; x < len_x; x++)
            tab[y][x] = 'x';
    prepare_print_bsq(tab, square, h, l);
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    return (0);
}
