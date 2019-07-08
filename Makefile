##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		load_file_in_mem.c	\
		load_2d_arr_from_file.c	\
		disp_square.c	\
		disp_biggest_square.c	\
		fs_print_first_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CC	=	gcc -g3

CFLAGS	=	-I./include/

LDFLAGS	=	-L./lib/my -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make re -C lib/my/
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
		rm -f $(OBJ)
		make clean -C lib/my/

fclean:		clean
		rm -f $(NAME)
		make fclean -C lib/my/

re:		fclean all
		make re -C lib/my/
