/*
** EPITECH PROJECT, 2022
** create tab
** File description:
** create tab
*/

#include "my.h"

int find_square(char **tab, int h, int l, square_t square);
int my_strlen_s(char *s);

int verif(char c)
{
    if (c == '.' || c == 'o') {
        return (0);
    }
    return (84);
}

int create_tab(char *buffer, int h, int l, square_t square)
{
    int re = 0;
    int i = my_strlen_s(buffer) + 1;
    char **tab = malloc(sizeof(char *) * (h + 1));

    for (int j = 0; j < h; j++)
        tab[j] = malloc(sizeof(char) * (l + 1));
    tab[h] = NULL;
    for (int y = 0; y < h && re == 0; y++) {
        for (int x = 0; x < l && re == 0; x++) {
            re = verif(buffer[i]);
            tab[y][x] = buffer[i];
            i++;
        }
        tab[y][l] = '\0';
        i++;
    }
    if (re == 0)
        find_square(tab, h, l, square);
    free(buffer);
    return (re);
}
