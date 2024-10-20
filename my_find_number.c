/*
** EPITECH PROJECT, 2022
** my_find_number
** File description:
** my_find_number
*/

int my_find_number(int i, char *format)
{
    while (format[i] == '-' || format[i] == '+')
        i++;
    while (format[i] >= '0' && format[i] <= '9') {
        i++;
    }
    return (i);
}
