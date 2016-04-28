##
## Makefile for Makefile in /home/tran/Documents/rendu/LIB
## 
## Made by Guillaume TRAN
## Login   <tran@epitech.net>
## 
## Started on  Thu Apr 28 22:09:25 2016 Guillaume TRAN
## Last update Fri Apr 29 01:45:13 2016 Guillaume TRAN
##

DEBUG	=

ifeq		($(DEBUG),yes)

	CFLAGS	+=	-I./include -W -Wall -ansi -pedantic -Wextra -g

else

	CFLAGS	+= 	-I./include -W -Wall -ansi -pedantic -Wextra

endif

CC	=	gcc

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"

GREEN	=	"\033[0;32m"

TEAL	=	"\033[1;36m"

RED	=	"\033[0;31m"

RM	=	rm -rf

LDFLAGS	=	-L lib -lmy

NAME	= 	Binary

SRCS	= 	main.c

OBJS	= 	$(SRCS:.c=.o)

ifeq		($(DEBUG),yes)

all:		title $(NAME) title-debug

else

all:		title $(NAME) title-nodebug

endif

title:
		@$(ECHO) $(RED)$(NAME)$(DEFAULT) $(CFLAGS) $(LD_FLAGS)

title-nodebug:
		@$(ECHO) $(TEAL)COMPILATION IN RELEASE MODE. USE \"DEBUG=yes\" FOR DEBUG MODE$(DEFAULT)

title-debug:
		@$(ECHO) $(RED)COMPILATION IN DEBUG MODE$(DEFAULT)

$(NAME)	:	$(OBJS)
		$(MAKE) -C lib all
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) && \
		$(ECHO) $(TEAL) "["$(GREEN)"CC"$(TEAL)"]" $(GREEN) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[XX]" $(GREEN) $(NAME)

clean	:
		$(RM) `find -name "*~"`
		$(RM) `find -name "*#"`
		$(RM) $(OBJS)
		$(MAKE) -C lib clean

fclean	:
		$(RM) `find -name "*~"`
		$(RM) `find -name "*#"`
		$(RM) $(OBJS)
		$(RM) $(NAME)
		$(MAKE) -C lib fclean

re	: 	fclean all

.PHONY: all clean fclean
