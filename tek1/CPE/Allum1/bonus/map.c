/*
** map.c for Allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1
**
** Made by tran_-
** Login   <tran_-@epitech.net>
**
** Started on  Mon Feb  8 13:46:46 2016 tran_-
** Last update Sun Feb 21 22:48:17 2016 Guillaume TRAN
*/

#include "allum1.h"

void	pick_color(t_allum *allum, int i, int j)
{
  if (allum->status == 1 && (j < allum->mselector)
    && allum->selector == i)
    attron(COLOR_PAIR(6));
  else if (allum->selector == i)
    attron(COLOR_PAIR(7));
  else if (allum->map[i][j] == '|')
    attron(COLOR_PAIR(11));
  else
    attron(COLOR_PAIR(3));
}

void	display_map(t_allum *allum)
{
  int	i;
  int	j;

  i = 0;
  while (i < allum->height)
    {
      j = 0;
      while (j < allum->width)
	{
	  pick_color(allum, i, j);
	  mvprintw(LINES/2 - allum->width/2 + i, COLS/2
		   - allum->height/2 + j, "%c", allum->map[i][j]);
	  j++;
	}
      i++;
    }
}

void	my_fill_map(t_allum *allum)
{
  int   i;
  int   j;
  int   k;

  i = 0;
  while (i < allum->height)
    {
      j = 0;
      k = 0;
      while (j < allum->width)
	{
	  while (k++ < (i * 2 + 1))
	    allum->map[i][j++] = '|';
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
