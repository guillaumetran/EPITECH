##
## Makefile for makefile in /home/tran_-/Documents/rendu/PSU_2015_my_printf_bootstrap
## 
## Made by Guillaume TRAN
## Login   <tran_-@epitech.net>
## 
## Started on  Wed Nov  4 17:06:13 2015 Guillaume TRAN
## Last update Tue Dec 22 16:45:05 2015 Guillaume TRAN
##

CC	:= gcc

RM	:= rm -rf

CFLAGS	+= -W -Wall -Wextra -pedantic -ansi -I./../include

SRCS	:= my/my_putchar.c	\
	my/my_putstr.c		\
	my/my_strlen.c		\
	my/my_getnbr.c

OBJS	:= $(SRCS:.c=.o)

NAME	:= libmy.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
