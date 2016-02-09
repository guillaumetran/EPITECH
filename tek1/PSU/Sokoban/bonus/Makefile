##
## Makefile for makefile in /home/tran_-/Documents/rendu/PSU_2015_my_printf_bootstrap
## 
## Made by Guillaume TRAN
## Login   <tran_-@epitech.net>
## 
## Started on  Wed Nov  4 17:06:13 2015 Guillaume TRAN
## Last update Sun Jan 17 15:46:32 2016 Guillaume TRAN
##

CC	= 	gcc -g

RM	= 	rm -rf

LDFLAGS	= 	-L ../lib -lmy -lncurses

CFLAGS	+= 	-I -W -Wall -ansi -pedantic -Wextra

SRCS	= 	my_sokoban.c	\
		map.c		\
		movement.c	\
		checking.c	\
		checking_two.c	\
		bonus.c		\
		bonus_two.c	\
		game.c

OBJS	= 	$(SRCS:.c=.o)

NAME	= 	my_sokoban

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
