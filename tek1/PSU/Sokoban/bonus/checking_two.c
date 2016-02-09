/*
** checking_two.c for sokoban in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Jan  8 19:48:36 2016 Guillaume TRAN
** Last update Wed Jan 13 20:39:17 2016 Guillaume TRAN
*/

#include "sokoban.h"

int     check_box(int **box, int **goal, char **map, int x)
{
  int   i;

  i = 0;
  while (i < x)
    {
      if ((is_placed(box[i][0], box[i][1], goal, x)) == 1)
	{
	  if ((is_blocked(box[i][0], box[i][1], map)) == 1)
	    return (1);
	}
      i++;
    }
  return (0);
}

int     check_map(char **map, int width, int height)
{
  int   i;
  int   j;

  i = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  if ((i == 0 || j == 0 || i == height-1
	       || j == width-1) && map[i][j] != '#')
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	check_isok(int x, int y, int **goal, int o)
{
  int	i;

  i = 0;
  while (i < o)
    {
      if (goal[i][0] == x && goal[i][1] == y)
	return (1);
      i++;
    }
  return (0);
}

void    display_map(char **map, int width, int height)
{
  int   i;

  i = 0;
  while (i < height)
    {
      mvprintw(LINES / 2 + i - height / 2, COLS / 2 - width / 2, map[i]);
      i++;
    }
}
