/*
** map.c for map in /home/tran_-/Documents/rendu/CPE_2015_BSQ
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Dec 21 17:09:00 2015 Guillaume TRAN
** Last update Mon Dec 28 13:41:29 2015 Guillaume TRAN
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	check_map(int **map, int length, int width)
{
  int	i;
  int	j;

  i = 0;
  while (i < length)
    {
      j = 0;
      while (j < width)
	{
	  if (map[i][j] != '.' && map[i][j] != 'o')
	      return (-1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	**my_initialize_map(int width, int length)
{
  int   i;
  int  **grid;

  i = 0;
  if ((grid = malloc(sizeof(*grid) * length)) == NULL)
    return (NULL);
  while (i <= length)
    {
      if ((grid[i] = malloc(sizeof(*grid) * width)) == NULL)
	return (NULL);
      i++;
    }
  return (grid);
}

int	my_fill_map(int **map, char *filename, int width, int length)
{
  int	count[3];
  char	*buffer;

  if ((buffer = malloc(sizeof(*buffer) * (length * width))) == NULL)
    return (1);
  if ((count[2] = open(filename, O_RDONLY)) == -1)
    return (1);
  while ((read(count[2], buffer, 1)) && buffer[0] != '\n');
  count[0] = -1;
  read(count[2], buffer, 1);
  while (++count[0] < length)
    {
      count[1] = -1;
      while ((++count[1] < width) && (buffer[0] != '\0'))
	{
	  if (buffer[0] == '\n' || buffer[0] == '\0')
	    return (1);
	  map[count[0]][count[1]] = buffer[0];
	  read(count[2], buffer, 1);
	}
      read(count[2], buffer, 1);
    }
  return (0);
}

void	display_map(int **map, int length, int width)
{
  int	i;
  int	j;

  i = 0;
  while (i < length)
    {
      j = 0;
      while (j < width)
	{
	  my_putchar(map[i][j]);
	  j++;
	}
      my_putchar('\n');
      i++;
    }
}
