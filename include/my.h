/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#ifndef _MY_H__
    #define _MY_H__

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stddef.h>

    typedef struct square_s {
        char type;
        int x;
        int y;
        int len;
    } square_t;

#endif
