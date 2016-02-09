/*
** my_parser.c for parser in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Dec 14 19:47:21 2015 Guillaume TRAN
** Last update Sat Dec 19 16:00:00 2015 Guillaume TRAN
*/

#include <unistd.h>
#include "my.h"
#include "navy.h"

void	my_parser(char boat[32], char **pos)
{
  int	i;
  int	k;
  int	j;

  j = 0;
  i = 0;
  k = 0;
  while (boat[j] != '\0')
    {
      pos[i][k] = boat[j];
      k++;
      j++;
      if (boat[j] == '\n')
	{
	  i++;
	  j++;
	  k = 0;
	}
      if (boat[j] == ':')
	j++;
    }
}

int	my_get_boat(int map, char **pos)
{
  char  buffer[1];
  int	i;
  char	boat[32];

  i = 0;
  while (i < 32)
    {
      if ((read(map, buffer, 1)) == 0)
	return (1);
      boat[i] = buffer[0];
      i++;
    }
  boat[i] = '\0';
  my_parser(boat, pos);
}
