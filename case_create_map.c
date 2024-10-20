/*
** EPITECH PROJECT, 2022
** create map
** File description:
** create map
*/

#include "my.h"

int my_strlen(char *s);
float char_in_int(char *s);
int create_tab(char *buffer, int h, int l, square_t square);

int caractere_verification(char *nb, char *map)
{
    int i = 0;
    int len_nb = my_strlen(nb);
    int len_map = my_strlen(map);

    for (i = 0; nb[i] >= '0' && nb[i] <= '9'; i++);
    if (i != len_nb)
        return (84);
    for (i = 0; map[i] == '.' || map[i] == 'o'; i++);
    if (i != len_map || len_map == 0)
        return (84);
    return (0);
}

int filling(char *s, char *argv, int len, square_t square)
{
    int nb = 1;
    int j = 0;
    int first_line = 0;
    for (int i = 0; i < square.x; i++) {
        if (i == (len * nb) + first_line) {
            s[i] = '\n';
            nb++;
            first_line++;
        } else if (argv[j] != '\0') {
            s[i] = argv[j];
            j++;
        } else {
            j = 0;
            s[i] = argv[j];
            j++;
        }
    }
    create_tab(s, len, len, square);
    return (0);
}

int create_map(char **argv, square_t square)
{
    int re = caractere_verification(argv[1], argv[2]);
    int len = 0;
    int size = 0;
    char *s;

    if (re == 84)
        return (84);
    len = char_in_int(argv[1]);
    size = len * (len + 1);
    s = malloc(sizeof(char) * size);
    square.x = size;
    filling(s, argv[2], len, square);
    return (0);
}
