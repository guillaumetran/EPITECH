##
## Makefile for BSQ in /home/tran_-/Documents/github/EPITECH/tek1/CPE/BSQ
## 
## Made by Guillaume TRAN
## Login   <tran_-@epitech.net>
## 
## Started on  Tue Feb  9 02:31:44 2016 Guillaume TRAN
## Last update Tue Feb  9 02:31:47 2016 Guillaume TRAN
##

CC	= 	gcc -g

RM	= 	rm -rf

LDFLAGS	= 	-L lib -lmy

CFLAGS	+= 	-I./include

SRCS	= 	my_bsq.c	\
		map.c		\
		my_algo.c

OBJS	= 	$(SRCS:.c=.o)

NAME	= 	bsq

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
