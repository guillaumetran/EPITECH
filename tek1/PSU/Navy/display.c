/*
** display.c for display in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Thu Dec 10 20:32:53 2015 Guillaume TRAN
** Last update Fri Dec 18 23:30:32 2015 Guillaume TRAN
*/

#include <unistd.h>
#include <stdlib.h>
#include "navy.h"
#include "my.h"

char    **my_fill_grid(char **grid)
{
  int   i;
  int   k;
  int   n;

  i = 0;
  n = 0;
  while (i < 8)
    {
      k = 0;
      while (k < 8)
	{
	  grid[i][k] = '.';
	  n++;
	  k++;
	}
      i++;
    }
  return (grid);
}

char    **my_initialize_grid()
{
  int   i;
  char  **grid;

  i = 0;
  if ((grid = malloc(sizeof(*grid) * 8)) == NULL)
    return (NULL);
  while (i < 8)
    {
      if ((grid[i] = malloc(sizeof(*grid) * 8)) == NULL)
	return (NULL);
      i++;
    }
  return (grid);
}

void	display_line(int number, char **grid)
{
  int   i;

  i = 0;
  while (i < 8)
    {
      my_printf("%c", grid[number][i]);
      if (i + 1 <= 8)
	my_putchar(' ');
      i++;
    }
}

void    my_display(char **grid)
{
  int   i;

  i = 0;
  my_printf("\n |A B C D E F G H\n");
  my_printf("-+---------------\n");
  while (i < 8)
    {
      my_printf("%d|", i + 1);
      display_line(i, grid);
      my_printf("\n");
      i++;
    }
}
