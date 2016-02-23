/*
** map.c for Allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1
**
** Made by tran_-
** Login   <tran_-@epitech.net>
**
** Started on  Mon Feb  8 13:46:46 2016 tran_-
** Last update Sun Feb 21 22:53:31 2016 Guillaume TRAN
*/

#include "allum1.h"

void	display_map(t_allum *allum)
{
  int	i;

  i = 0;
  while (i++ < allum->width + 2)
    my_putchar('*');
  my_putchar('\n');
  i = -1;
  while (++i < allum->height)
    {
      my_putchar('*');
      my_putstr(allum->map[i]);
      my_putstr("*\n");
    }
  i = 0;
  while (i++ < allum->width + 2)
    my_putchar('*');
  my_putchar('\n');
}

void	my_fill_map(t_allum *allum)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  while (i < allum->height)
    {
      j = 0;
      k = 0;
      while (j < allum->width)
	{
	  if (j + i == allum->width / 2)
	    {
	      while (k++ < (i * 2 + 1))
		allum->map[i][j++] = '|';
	    }
	  allum->map[i][j] = ' ';
	  j++;
	}
      allum->map[i][j] = '\0';
      i++;
    }
  allum->map[i - 1][j - 1] = '\0';
}

char	**my_initialize_map(int width, int height)
{
  int	i;
  char	**map;

  i = 0;
  if ((map = malloc(sizeof(*map) * (height + 1))) == NULL)
    return (NULL);
  while (i <= height)
    {
      if ((map[i] = malloc(sizeof(*map) * (width + 1))) == NULL)
	return (NULL);
      i++;
    }
  return (map);
}
