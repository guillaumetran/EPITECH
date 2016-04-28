/*
** get_next_line.c for gnl in /home/tran/Documents/rendu/LIB/lib
**
** Made by Guillaume TRAN
** Login   <tran@epitech.net>
**
** Started on  Fri Apr 29 00:11:37 2016 Guillaume TRAN
** Last update Fri Apr 29 00:14:21 2016 Guillaume TRAN
*/

#include "get_next_line.h"

static char    *my_realloc(char *old, int size)
{
  char  *new;
  int   i;

  if ((new = malloc(sizeof(*new) * size)) == NULL)
    return (NULL);
  i = -1;
  while (old[++i])
    new[i] = old[i];
  i++;
  new[i] = '\0';
  free(old);
  return (new);
}

static int	get_char(const int fd, char *c)
{
  static int	i = 0;
  static char	buff[READ_SIZE];
  static int	end = READ_SIZE;

  if (i == 0 || i >= end)
    {
      i = 0;
      if ((end = read(fd, buff, READ_SIZE)) <= 0)
	return (0);
    }
  if (end == 0)
    {
      *c = '\0';
      i = -1;
    }
  else
    if (buff[i] == '\n')
      *c = '\0';
    else
      *c = buff[i];
  i++;
  return (end);
}

char	*get_next_line(const int fd)
{
  char	*line;
  int	i;

  i = 0;
  if ((line = malloc((READ_SIZE + 1) * sizeof(*line))) == NULL)
    return (NULL);
  if (get_char(fd, &line[i]) == 0)
    return (NULL);
  while (line[i] != '\0')
    {
      if (i % READ_SIZE == 0)
	{
	  if ((line = my_realloc(line, i + READ_SIZE + 1)) == NULL)
	    return (NULL);
	}
      get_char(fd, &line[++i]);
    }
  line[i] = '\0';
  return (line);
}
