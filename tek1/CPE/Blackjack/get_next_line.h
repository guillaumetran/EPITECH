/*
** get_next_line.h for get_next_line.h in /home/tran_-/Documents/rendu/CPE_2015_getnextline
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Jan  4 12:46:55 2016 Guillaume TRAN
** Last update Sat Mar  5 13:07:30 2016 Guillaume TRAN
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
#  define READ_SIZE (14)
# endif /* !READ_SIZE */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(const int fd);
int	get_char(const int fd, char *c);
char	*my_realloc(char *old, int size);

#endif /* !GET_NEXT_LINE_H_ */
