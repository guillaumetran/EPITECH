/*
** ia.c for allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Feb 19 21:29:58 2016 Guillaume TRAN
** Last update Sun Feb 21 22:49:54 2016 Guillaume TRAN
*/

#include "allum1.h"

int	xorsum(t_allum *allum)
{
  int	i;
  int	j;
  int	xor;
  int	match;

  i = 0;
  while (i < allum->height)
    {
      j = 0;
      match = 0;
      while (j < allum->width)
	{
	  if (allum->map[i][j] == '|')
	    match++;
	  j++;
	}
      if (i > 0)
	xor = xor ^ match;
      else
	xor = match;
      i++;
    }
  return (xor);
}

int	find_best_move(t_allum *allum, int xor)
{
  int	i;
  int	j;
  int	match;
  int	res;

  i = 0;
  while (i < allum->height)
    {
      j = 0;
      match = 0;
      while (j < allum->width)
	{
	  if (allum->map[i][j] == '|')
	    match++;
	  j++;
	}
      i++;
      res = match ^ xor;
      if (res < match)
	{
	  remove_allum(allum, i, match - res);
	  return (0);
	}
    }
  return (-1);
}

void	ia_move(t_allum *allum, int **lines)
{
  int	line;
  int	xor;

  xor = xorsum(allum);
  if ((line = count_line(allum, lines)) == 1)
    remove_allum(allum, lines[0][0] + 1, lines[0][1] - 1);
  else if ((line == 2) && (lines[0][1] == 1 || lines[1][1] == 1))
    {
      if (lines[0][1] == 1)
	remove_allum(allum, lines[1][0] + 1, lines[1][1]);
      else if (lines[1][1] == 1)
	remove_allum(allum, lines[0][0] + 1, lines[0][1]);
    }
  else if ((line == 3) && ((lines[0][1] == 1 && lines[1][1] == 1)
			   || (lines[0][1] == 1 && lines[2][1] == 1)
			   || (lines[1][1] == 1 && lines[2][1] == 1)))
    {
      if (lines[0][1] != 1)
	remove_allum(allum, lines[0][0] + 1, lines[0][1] - 1);
      else if (lines[1][1] != 1)
	remove_allum(allum, lines[1][0] + 1, lines[1][1] - 1);
      else if (lines[2][1] != 1)
	remove_allum(allum, lines[2][0] + 1, lines[2][1] - 1);
    }
  find_best_move(allum, xor);
}

void	ia_turn(t_allum *allum)
{
  int	**lines;
  int	i;
  int	k;

  k = 0;
  attron(COLOR_PAIR(7));
  mvprintw(LINES/2 - 6, COLS/2 - 3, "IA turn");
  while (k < 12)
    {
      mvprintw(LINES/2 - 5, COLS/2 + k - 5, ".");
      refresh();
      usleep(90000);
      k++;
    }
  i = 0;
  if ((lines = malloc(sizeof(*lines) * allum->height)) == NULL)
    exit (0);
  while (i < allum->height)
    {
      if ((lines[i] = malloc(sizeof(*lines) * allum->width)) == NULL)
	exit(0);
      i++;
    }
  lines[0][0] = 12;
  ia_move(allum, lines);
}

int	check_win(t_allum *allum, int id)
{
  int	i;
  int	j;

  i = 0;
  while (i < allum->height)
    {
      j = 0;
      while (j < allum->width)
	{
	  if (allum->map[i][j] != ' ')
	    return (1);
	  j++;
	}
      i++;
    }
  attron(COLOR_PAIR(6));
  if (id == 0)
    mvprintw(LINES/2, COLS/2 - 7, "You lost, too bad..");
  else
    mvprintw(LINES/2 + 10, COLS/2 - 25,
	     "I lost.. snif.. but I’ll get you next time!!");
  return (0);
}
