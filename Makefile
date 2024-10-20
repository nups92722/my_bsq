##
## EPITECH PROJECT, 2022
## makefile for do_op
## File description:
## makefile for do_op
##

SRC =		bsq.c			\
		case_create_map.c	\
		case_file.c		\
		char_in_int.c		\
		create_tab.c		\
		find_square.c		\
		my_find_number.c	\
		my_strlen.c		\
		print_bsq.c

NAME	=	bsq

all:	$(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC) -I include/

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	rm -f test

re:	fclean all
