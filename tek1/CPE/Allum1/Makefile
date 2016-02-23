##
## Makefile for Allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1
## 
## Made by tran_-
## Login   <tran_-@epitech.net>
## 
## Started on  Mon Feb  8 13:47:09 2016 tran_-
## Last update Fri Feb 19 21:40:01 2016 Guillaume TRAN
##

CC	= 	gcc -g

RM	= 	rm -rf

LDFLAGS	= 	-L lib -lmy

CFLAGS	+= 	-I./include -W -Wall -ansi -pedantic -Wextra

SRCS	= 	main.c	\
		ia.c	\
		utils.c	\
		map.c

OBJS	= 	$(SRCS:.c=.o)

NAME	= 	allum1

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
