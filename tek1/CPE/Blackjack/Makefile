##
## Makefile for Makefile in /home/ladenb_p/rendu/minishell1
## 
## Made by Pierre Ladenburger
## Login   <ladenb_p@epitech.net>
## 
## Started on  Sat Jan 23 18:15:51 2016 Pierre Ladenburger
## Last update Sat Mar 26 19:59:58 2016 Pierre Ladenburger
##

CC	= gcc -g

CFLAGS	+= -W -Wextra -Wall -lmy -L./lib/my

RM	= rm -f

NAME	= blackjack

SRCS	= main.c		\
	  fcnt.c		\
	  get_next_line.c	\
	  cards.c		\
	  as.c			\
	  display.c

OBJ	= $(SRCS:.c=.o)

$(NAME):	$(OBJ)
	cd ./lib/my ; $(MAKE) -f Makefile
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all:	$(NAME)

clean:
	cd ./lib/my ; $(MAKE) -f Makefile clean
	$(RM) $(OBJ)

fclean: clean
	cd ./lib/my ; $(MAKE) -f Makefile fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
