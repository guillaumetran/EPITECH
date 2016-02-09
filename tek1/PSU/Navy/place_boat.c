/*
** place_boat.c for place_boat in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Dec 18 15:33:28 2015 Guillaume TRAN
** Last update Sat Dec 19 20:48:52 2015 Guillaume TRAN
*/

#include <stdlib.h>
#include "my.h"
#include "navy.h"

int	case_one(int *coord, char **grid, char c)
{
  int	tmp;
  int	i;
  int	check;

  check = 0;
  if (coord[1] < coord[3])
    {
      tmp = coord[3];
      i = coord[1];
    }
  else
    {
      tmp = coord[1];
      i = coord[3];
    }
  while (i++ <= tmp)
    {
      if (grid[i - 1][coord[0]] == '.')
	grid[i-1][coord[0]] = c;
      else
	return (1);
      check++;
    }
  if (check != c - 48)
    return (1);
}

int	case_two(int *coord, char **grid, char c)
{
  int	tmp;
  int	i;
  int	check;

  check = 0;
  if (coord[0] < coord[2])
    {
      tmp = coord[2];
      i = coord[0];
    }
  else
    {
      tmp = coord[0];
      i = coord[2];
    }
  while (i++ <= tmp)
    {
      if (grid[coord[1]][i - 1] == '.')
	grid[coord[1]][i-1] = c;
      else
	return (1);
      check++;
    }
  if (check != c - 48)
    return (1);
}

int	put_boat(int *coord, char **grid, char c)
{
  if (coord[0] == coord[2])
    {
      if ((case_one(coord, grid, c)) == 1)
	return (1);
    }
  else if (coord[1] == coord[3])
    {
      if ((case_two(coord, grid, c)) == 1)
	return (1);
    }
  else if (coord[0] != coord[2] && coord[1] != coord[3])
    return (1);
  return (0);
}

int	check_pos(char **pos)
{
  int	i;
  int	j;
  int	k;

  j = 0;
  while (j < 4)
    {
      k = j + 1;
      i = 0;
      while (i < 3)
	{
	  if (k >= 3)
	    k = 0;
	  if (pos[j][0] == pos[k][0])
	    return (1);
	  i++;
	}
      j++;
    }
  return (0);
}

int	place_boat(char **pos, char **grid)
{
  int	*coord;
  int	i;

  i = 0;
  if ((coord = malloc(sizeof(*coord) * 4)) == NULL)
      return (1);
  if ((check_pos(pos)) == 1)
    return (1);
  while (i < 4)
    {
      coord[0] = pos[i][1] - 65;
      coord[1] = pos[i][2] - 49;
      coord[2] = pos[i][3] - 65;
      coord[3] = pos[i][4] - 49;
      if ((put_boat(coord, grid, pos[i][0])) == 1)
	return (1);
      i++;
    }
  free(coord);
  return (0);
}
