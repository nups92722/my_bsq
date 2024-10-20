/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** case open file
*/

#include <my.h>

int my_strlen_s(char *s);
int create_tab(char *buffer, int h, int l, square_t square);

int find_number(char *s)
{
    int nb = 0;
    int i = 0;
    for (; s[i] != '\n' && s[i] >= '0' && s[i] <= '9'; i++)
        nb = (nb * 10) + (s[i] - 48);
    if (s[i] != '\n')
        nb = 0;
    return (nb);
}

int len_s(char *s)
{
    int i = 0;
    int j = 0;

    for (; s[i] != '\n'; i++);
    j = i + 1;
    i += 2;
    for (; s[i] != '\n'; i++);
    return (i - j);
}

int open_file(int fd, char *argv, int st_size, square_t square)
{
    int x = 0;
    int y = 0;
    char *buffer = malloc(sizeof(char) * (st_size + 1));

    read(fd, buffer, st_size);
    buffer[st_size] = '\0';
    y = find_number(buffer);
    if (y == 0)
        return (84);
    x = len_s(buffer);
    return (create_tab(buffer, y, x, square));
}

int file(char *argv, square_t square)
{
    int re = 0;
    int fd = open(argv, O_RDONLY);
    struct stat data_base;
    struct stat *data = &data_base;

    if (fd == -1)
        return (84);
    re = stat(argv, data);
    if (re == 0) {
        re = open_file(fd, argv, data->st_size, square);
        close(fd);
        return (re);
    }
    return (84);
}
