/*
** map.c for sokoban in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Jan  6 01:16:49 2016 Guillaume TRAN
** Last update Mon Jan 11 19:06:33 2016 Guillaume TRAN
*/

#include "my.h"
#include "sokoban.h"

int	my_fill_map(char **map, char *filename, int width, int height)
{
  char	buffer[3];
  int	counter[4];

  if ((counter[0] = open(filename, O_RDONLY)) == -1)
    return (1);
  counter[1] = 0;
  while (counter[1] < height)
    {
      counter[2] = 0;
      counter[3] = 0;
      while (counter[2] < width && read(counter[0], buffer, 1) > 0)
	{
	  if (buffer[0] == '\n')
	    counter[3]++;
	  else if (buffer[0] == ' ' || buffer[0] == 'X' || buffer[0] == 'O'
		   || buffer[0] == 'P' || buffer[0] == '#')
	    map[counter[1]][counter[2]++] = buffer[0];
	  if (counter[3] == 2)
	    return (1);
	}
      map[counter[1]][counter[2]] = '\0';
      counter[1]++;
    }
  return (0);
}

char     **my_initialize_map(int width, int height)
{
  int   i;
  char  **map;

  i = 0;
  if ((map = malloc(sizeof(*map) * (height + 1) )) == NULL)
    return (NULL);
  while (i <= height)
    {
      if ((map[i] = malloc(sizeof(*map) * (width + 1))) == NULL)
	return (NULL);
      i++;
    }
  return (map);
}

int	**my_initialize_goal(int width, int height)
{
  int   i;
  int  **goal;

  i = 0;
  if ((goal = malloc(sizeof(*goal) * (height + 1) )) == NULL)
    return (NULL);
  while (i <= height)
    {
      if ((goal[i] = malloc(sizeof(*goal) * (width + 1))) == NULL)
	return (NULL);
      i++;
    }
  return (goal);
}

int	my_fill_box(int **box, char **map, int width, int height)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  if (map[i][j] == 'X')
	    {
	      box[k][0] = i;
	      box[k][1] = j;
	      k++;
	    }
	  j++;
	}
      i++;
    }
  return (k);
}

int	my_fill_goal(int **goal, char **map, int width, int height)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  if (map[i][j] == 'O')
	    {
	      goal[k][0] = i;
	      goal[k][1] = j;
	      k++;
	    }
	  j++;
	}
      i++;
    }
  return (k);
}
