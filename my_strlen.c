/*
** EPITECH PROJECT, 2022
** strlen
** File description:
** strlen
*/

int my_strlen_s(char *s)
{
    int i = 0;

    for (; s[i] != '\n'; i++);
    return (i);
}

int my_strlen(char *s)
{
    int i = 0;

    for (; s[i] != '\0'; i++);
    return (i);
}
