/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** main
*/

#include "my.h"

int file(char *argv, square_t square);
int create_map(char **argv, square_t square);

int main(int argc, char **argv)
{
    square_t square;
    square.x = 0;
    square.y = 0;
    square.len = 0;

    if (argc == 2) {
        square.type = 'f';
        return (file(argv[1], square));
    }
    if (argc == 3) {
        square.type = 'c';
        return (create_map(argv, square));
    }
    return (84);
}
