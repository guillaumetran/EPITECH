/*
** checking.c for sokoban in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Thu Jan  7 16:37:02 2016 Guillaume TRAN
** Last update Fri Jan  8 19:48:01 2016 Guillaume TRAN
*/

#include "my.h"
#include "sokoban.h"

int     check_win(int **goal, char **map, int o)
{
  int   i;
  int   count;

  i = 0;
  count = 0;
  while (i < o)
    {
      if (map[goal[i][0]][goal[i][1]] == 'X')
	count++;
      i++;
    }
  if (count == o)
    return (1);
  return (0);
}

void    replace_goal(int **goal, char **map, int o)
{
  int   i;

  i = 0;
  while (i < o)
    {
      if (map[goal[i][0]][goal[i][1]] == ' ')
	map[goal[i][0]][goal[i][1]] = 'O';
      i++;
    }
}

int    find_player(char **map, int width, int height, int coord[2])
{
  int   i;
  int   j;
  int	count;

  i = 0;
  count = 0;
  coord[0] = -1;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  if (map[i][j] == 'P')
	    {
	      coord[0] = i;
	      coord[1] = j;
	      count++;
	    }
	  j++;
	}
      i++;
    }
  if (coord[0] != -1 && count == 1)
    return (0);
  return (1);
}

int     is_placed(int y, int x, int **goal, int o)
{
  int   i;

  i = 0;
  while (i < o)
    {
      if (goal[i][0] == y && goal[i][1] == x)
	return (0);
      i++;
    }
  return (1);
}

int     is_blocked(int y, int x, char **map)
{
  if ((map[y-1][x] == '#' || map[y-1][x] == 'X')
      && (map[y][x-1] == '#' || map[y][x-1] == 'X'))
    return (1);
  else if ((map[y-1][x] == '#' || map[y-1][x] == 'X')
	   && (map[y][x+1] == '#' || map[y][x+1] == 'X'))
    return (1);
  else if ((map[y+1][x] == '#' || map[y+1][x] == 'X')
	   && (map[y][x-1] == '#' || map[y][x-1] == 'X'))
    return (1);
  else if ((map[y+1][x] == '#' || map[y+1][x] == 'X')
	   && (map[y][x+1] == '#' || map[y][x+1] == 'X'))
    return (1);
  return (0);
}
