##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

DOS	=	my_strlen.c	\
		my_getnbr.c	\
		my_putchar.c	\
		my_putstr.c	\

NAME	=	libmy.a

HEADERS	=	my.h

all: $(NAME)

$(NAME):	$(NAME)
		gcc -c $(DOS)
		ar rc $(NAME) *.o
		cp $(HEADERS) ../../include/$(HEADERS)

clean:
		rm -f *.o
fclean:		clean
		rm -f $(NAME)

re:		fclean all
