/*
** get_next_line.h for get_next_line.h in /home/tran_-/Documents/rendu/CPE_2015_getnextline
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Jan  4 12:46:55 2016 Guillaume TRAN
** Last update Fri Apr 29 00:22:56 2016 Guillaume TRAN
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (5)
# endif /* !READ_SIZE */

# include <stdlib.h>
# include <unistd.h>

static int	get_char(const int, char *);
static char	*my_realloc(char *, int);

#endif /* !GET_NEXT_LINE_H_ */
