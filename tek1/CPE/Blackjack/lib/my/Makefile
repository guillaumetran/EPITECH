##
## Makefile for Makefile in /home/ladenb_p/rendu/Projets/Printf/PSU_2015_my_printf/lib/my
## 
## Made by Pierre Ladenburger
## Login   <ladenb_p@epitech.net>
## 
## Started on  Tue Nov 10 14:24:35 2015 Pierre Ladenburger
## Last update Fri Mar 18 09:48:27 2016 Pierre Ladenburger
##

ARRC	= ar rc

CFLAGS	+= -Wextra -Wall
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.

RANLIB	= ranlib

RM	= rm -f

NAME	= libmy.a

SRCS	= my_printf.c		\
	  my_putchar.c		\
	  my_put_nbr.c		\
	  my_putstr.c		\
	  my_strlen.c		\
	  epur_str.c		\
	  my_strcmp.c		\
	  my_revstr.c		\
	  my_strcpy.c		\
	  my_strncmp.c		\
	  my_getnbr.c		\
	  my_puterror.c		\
	  my_strcat.c		\
	  my_strdup.c		\
	  my_str_to_wordtab.c

OBJ	= $(SRCS:.c=.o)

$(NAME):	$(OBJ)
	$(ARRC) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
