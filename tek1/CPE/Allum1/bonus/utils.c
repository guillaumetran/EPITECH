/*
** utils.c for allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Feb 19 21:35:08 2016 Guillaume TRAN
** Last update Sun Feb 21 21:57:20 2016 Guillaume TRAN
*/

#include "allum1.h"

void	remove_allum(t_allum *allum, int line, int match)
{
  int	i;
  int	count;

  line--;
  i = allum->width;
  count = 0;
  while (count < match)
    {
      if (allum->map[line][i] == '|')
	{
	  count++;
	  allum->map[line][i] = ' ';
	}
      i--;
    }
}

int	count_allum(t_allum *allum, int line)
{
  int	i;
  int	match;

  i = 0;
  match = 0;
  while (i < allum->width)
    {
      if (allum->map[line][i] == '|')
	match++;
      i++;
    }
  return (match);
}

int	count_line(t_allum *allum, int **lines)
{
  int	i;
  int	j;
  int	line;
  int	check;

  line = 0;
  i = 0;
  while (i < allum->height)
    {
      j = 0;
      check = 0;
      while (j < allum->width)
	{
	  if (check == 0 && allum->map[i][j] == '|')
	    {
	      lines[line][0] = i;
	      lines[line][1] = count_allum(allum, i);
	      line++;
	      check = 1;
	    }
	  j++;
	}
      i++;
    }
  return (line);
}
