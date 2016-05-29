##
## Makefile for Blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus
## 
## Made by Guillaume TRAN
## Login   <tran_-@epitech.net>
## 
## Started on  Wed Mar 16 16:48:00 2016 Guillaume TRAN
## Last update Mon Mar 28 22:32:07 2016 Guillaume TRAN
##

CC=	gcc

SRC=	$(CHEMIN)/main.c		\
	$(CHEMIN)/blackjack_callback.c	\
	$(CHEMIN)/blackjack_click.c	\
	$(CHEMIN)/blackjack_start.c	\
	$(CHEMIN)/blackjack_button.c	\
	$(CHEMIN)/blackjack_pick.c	\
	$(CHEMIN)/blackjack_norm.c	\
	$(CHEMIN)/blackjack_money.c	\
	$(CHEMIN)/blackjack_result.c	\
	$(CHEMIN)/sprites.c		\
	$(CHEMIN)/text.c		\
	$(CHEMIN)/cards.c		\
	$(CHEMIN)/fcnt.c		\
	$(CHEMIN)/blackjack_loop.c

CHEMIN=	./src

OBJS=	$(SRC:.c=.o)

NAME=	blackjack

CFLAGS+= -W -ansi -pedantic

CFLAGS+= -I./include -I/home/${USER}/.froot/include

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L /home/${USER}/.froot/lib -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm -rdynamic -ldl

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
