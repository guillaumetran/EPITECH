##
## Makefile for Makefile in /home/tran/Documents/rendu/LIB
## 
## Made by Guillaume TRAN
## Login   <tran@epitech.net>
## 
## Started on  Thu Apr 28 21:03:59 2016 Guillaume TRAN
## Last update Fri Apr 29 00:49:06 2016 Guillaume TRAN
##

ARRC	=	ar rc

CFLAGS  += -Wextra -Wall
CFLAGS  += -ansi -pedantic
CFLAGS  += -I../include

RANLIB	=	ranlib

RM	=	rm -f

NAME	=	libmy.a

SRCS	=	my_printf.c		\
		my_putchar.c 		\
		my_putstr.c 		\
		my_revstr.c 		\
		my_strlen.c 		\
		my_putnbr_base.c 	\
		my_getnbr.c	 	\
		my_strcmp.c		\
		my_put_float.c		\
		my_str_to_wt.c		\
		get_next_line.c		\
		my_getnbr.c 		\
		flags_printf.c		\
		flags2_printf.c

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
		$(ARRC) $(NAME) $(OBJS)
		$(RANLIB) $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY: all clean fclean re
