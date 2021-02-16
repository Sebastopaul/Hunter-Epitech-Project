##
## EPITECH PROJECT, 2020
## EvalExpr
## File description:
## Makefile
##

SRC	=	main.c	\
		audio/music.c	\
		events/event_manager.c	\
		game/game.c	\
		game/score_lives.c	\
		sprites/destroy.c	\
		sprites/draw.c	\
		sprites/init_bg.c	\
		sprites/init_demon.c	\
		sprites/init_menu.c	\
		sprites/modes.c	\
		sprites/move.c	\
		sprites/reset.c	\
		textures/destroy.c	\
		textures/init.c	\
		window/window_manager.c

LIB_INCLUDE	=	include/lib.h

CFLAGS	=	-Iinclude -Llib -lmy -Wall -g3

LDFLAGS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(LIB_INCLUDE) $(NAME)

$(LIB_INCLUDE):
	make -C lib/my

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	make clean

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all
