##
## Makefile for Navy in /home/tran_-/Documents/github/EPITECH/tek1/PSU/Navy
## 
## Made by Guillaume TRAN
## Login   <tran_-@epitech.net>
## 
## Started on  Tue Feb  9 02:37:52 2016 Guillaume TRAN
## Last update Tue Feb  9 02:37:54 2016 Guillaume TRAN
##

CC	= 	gcc

RM	= 	rm -rf

LDFLAGS	= 	-L lib -lmy

CFLAGS	+= 	-I./include

SRCS	= 	my_navy.c 		\
		display.c		\
		my_parser.c		\
		place_boat.c		\
		start_game.c		\
		my_signal.c		\
		checking.c		\
		checking_two.c		\
		check_connection.c

OBJS	= 	$(SRCS:.c=.o)

NAME	= 	navy

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
