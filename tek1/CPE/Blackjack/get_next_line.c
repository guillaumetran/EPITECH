/*
** get_next_line.c for gnl in /home/tran_-/Documents/rendu/CPE_2015_getnextline
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Thu Mar  3 16:28:00 2016 Guillaume TRAN
** Last update Sat Mar 26 20:01:33 2016 Pierre Ladenburger
*/

#include "get_next_line.h"

char	*my_realloc(char *old, int size)
{
  char	*new;
  int	i;

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

int		get_char(const int fd, char *c)
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
	  if ((line = realloc(line, i + READ_SIZE + 1)) == NULL)
	    return (NULL);
	}
      get_char(fd, &line[++i]);
    }
  line[i] = '\0';
  return (line);
}
