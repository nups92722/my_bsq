/*
** EPITECH PROJECT, 2022
** find squares
** File description:
** find squares
*/

#include "my.h"

int put_x(char **tab, square_t square, int h, int l);

int find_new_square(char **tab, int y, int x, int len)
{
    int yb = y;
    int xb = x;
    int	actual_len = 0;
    int past_len = 2147483647;

    while (tab[yb] != NULL && yb - y + 1 <= past_len) {
        for (xb = x; tab[yb][xb] == '.' && actual_len <= past_len; xb++)
            actual_len++;
        if (actual_len < yb - y + 1)
            return (yb - y);
        if (actual_len == yb - y + 1)
            return (actual_len);
        if (past_len <= len)
            return (len);
        if (actual_len < past_len)
            past_len = actual_len;
        actual_len = 0;
        yb++;
    }
    return (yb - y);
}

int find_square(char **tab, int h, int l, square_t square)
{
    int x = 0;
    int y = 0;
    int actual_len = 0;
    while (tab[y] != NULL) {
        for (; tab[y][x] != '.' && tab[y][x] != '\0'; x++);
        actual_len = find_new_square(tab, y, x, square.len);
        if (actual_len > square.len) {
            square.len = actual_len;
            square.x = x;
            square.y = y;
        }
        if (tab[y][x] != '\0')
            x++;
        if (tab[y][x] == '\0') {
            y++;
            x = 0;
        }
    }
    put_x(tab, square, h, l);
    return (0);
}
