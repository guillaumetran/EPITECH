/*
** utils.c for allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Feb 19 21:35:08 2016 Guillaume TRAN
** Last update Sun Feb 21 00:38:29 2016 Guillaume TRAN
*/

#include "allum1.h"

void	remove_allum(t_allum *allum, int line, int match, int player)
{
  int	i;
  int	count;

  line--;
  i = allum->width;
  count = 0;
  if (player == 0)
    my_putstr("Player removed ");
  else if (player == 1)
    my_putstr("AI removed ");
  my_putchar(match + '0');
  my_putstr(" match(es) from line ");
  my_putchar(line + '1');
  my_putchar('\n');
  while (count < match)
    {
      if (i < 0)
	exit(1);
      if (allum->map[line][i] == '|')
	{
	  allum->map[line][i] = ' ';
	  count++;
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

int	check_line(int *line, t_allum *allum)
{
  char	buffer[200];

  my_putstr("Line: ");
  read(0, buffer, 200);
  *line = buffer[0] - '0';
  if (*line < 0 || *line > 9)
    my_putstr("Error: invalid input (positive number expected)\n");
  else if ((*line == 0 || *line > allum->height || buffer[1] != '\n'))
    my_putstr("Error: this line is out of range\n");
  else
    return (1);
  return (0);
}

int	check_match(int *line, int *match, t_allum *allum)
{
  char	buffer[2];

  my_putstr("Matches: ");
  read(0, buffer, 200);
  *match = buffer[0] - '0';
  if (*match < 0 || *match > 9)
    my_putstr("Error: invalid input (positive number expected)\n");
  else if ((*match > count_allum(allum, *line - 1)) || buffer[1] != '\n')
    my_putstr("Error: not enough matches on this line\n");
  else if (*match == 0)
    my_putstr("Error: you have to remove at least one match\n");
  else
    return (1);
  return (0);
}
