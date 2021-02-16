##
## EPITECH PROJECT, 2020
## My Printf
## File description:
## Makefile
##

SRC	=	my_strlen.c	\
		my_strcmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp lib.h ../../include
	mv $(NAME) ..
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)
	rm -f ../../include/lib.h

re:	fclean all
