/*
** main.c for Allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1
**
** Made by tran_-
** Login   <tran_-@epitech.net>
**
** Started on  Mon Feb  8 12:20:48 2016 tran_-
** Last update Sun Feb 21 22:52:50 2016 Guillaume TRAN
*/

#include "allum1.h"

int	game(t_allum *allum)
{
  int	line;
  int	match;
  int   check;

  while (42)
    {
      my_putstr("\nYour turn:\n");
      check = 0;
      while (check != 1)
	{
	  while (check_line(&line, allum) != 1);
	  if (check_match(&line, &match, allum) == 1)
	    check = 1;
	}
      remove_allum(allum, line, match, 0);
      display_map(allum);
      if ((check_win(allum, 0)) == 0)
	return (0);
      if ((ia_turn(allum)) == 0)
	return (0);
    }
  return (1);
}

int		main(int ac, char **av)
{
  t_allum	allum;

  ac = ac;
  av = av;
  allum.width = 7;
  allum.height = 4;
  allum.map = my_initialize_map(allum.width, allum.height);
  my_fill_map(&allum);
  display_map(&allum);
  game(&allum);
  return (0);
}
