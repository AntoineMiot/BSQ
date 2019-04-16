##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC	=	main_bsq.c	\
		str_to_array.c	\
		str_to_array_two.c	\
		array_int_str.c	\
		error.c

OBJ		=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -g3 -o $(NAME) $(OBJ) -L./lib -lmy -I./include
	rm *.o

clean:
	rm -f $(OBJ)
	rm -f vgcore.*
	rm -f *.o

fclean:	clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all
