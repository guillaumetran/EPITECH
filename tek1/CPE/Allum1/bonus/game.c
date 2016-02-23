/*
** game.c for allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1/bonus
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Sun Feb 21 22:31:52 2016 Guillaume TRAN
** Last update Sun Feb 21 22:41:10 2016 Guillaume TRAN
*/

#include "allum1.h"

void	part_one(t_allum *allum, int key)
{
  clear();
  start_game("Allum1");
  mvprintw(LINES/2 - 6, COLS/2 - 4, "Your turn");
  if (key == '\n')
    allum->status++;
  if (key == KEY_UP && allum->selector > 0)
    {
      allum->selector--;
      allum->status = 0;
      allum->mselector = 0;
    }
  else if (key == KEY_DOWN && allum->selector < allum->height - 1)
    {
      allum->selector++;
      allum->status = 0;
      allum->mselector = 0;
    }
  else if (key == KEY_LEFT && allum->mselector > 0 && allum->status == 1)
    allum->mselector--;
  else if (key == KEY_RIGHT && allum->mselector <
	   count_allum(allum, allum->selector)
	   && allum->status == 1)
    allum->mselector++;
}

int	part_two(t_allum *allum)
{
  if (allum->status == 2 && allum->mselector > 0)
    {
      remove_allum(allum, allum->selector + 1, allum->mselector);
      allum->status = 0;
      clear();
      start_game("Allum1");
      display_map(allum);
      if (check_win(allum, 0) == 0)
	{
	  refresh();
	  sleep(2);
	  return (1);
	}
      ia_turn(allum);
      clear();
    }
  start_game("Allum1");
  display_map(allum);
  return (0);
}
