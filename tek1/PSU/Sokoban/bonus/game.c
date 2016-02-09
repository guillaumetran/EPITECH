/*
** game.c for sokoban in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban/bonus
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Sun Jan 17 13:48:49 2016 Guillaume TRAN
** Last update Sun Jan 17 16:02:30 2016 Guillaume TRAN
*/

#include "sokoban.h"

int	game_part_one(t_info *sokoban, int *i, int *restart)
{
  int	n;

  sokoban->key = wgetch(stdscr);
  if (sokoban->key == ' ')
    {
      *restart = *restart + 1;
      clear();
      return (1);
    }
  else if (sokoban->key == 'q')
    {
      n = open_menu();
      if (n == 2)
	*i = *i + 1;
      else if (n == 1)
	{
	  *restart = *restart + 1;
	  clear();
	  return (1);
	}
    }
  clear();
  return (0);
}

int	game_part_two(t_info *sokoban, int *movement, int *restart)
{
  move_player(sokoban->map, sokoban->pos_player, sokoban->key);
  *movement = *movement + 1;
  replace_goal(sokoban->goal, sokoban->map, sokoban->o);
  my_fill_box(sokoban->box, sokoban->map, sokoban->width, sokoban->height);
  if (check_win(sokoban->goal, sokoban->map, sokoban->o) == 1)
    {
      sokoban->map[sokoban->height/2][sokoban->width-1] = 'F';
      if (sokoban->pos_player[0] == sokoban->height/2
	  && sokoban->pos_player[1] == sokoban->width-1)
	{
	  *restart = 0;
	  clear();
	  return (2);
	}
    }
  else
    sokoban->map[sokoban->height/2][sokoban->width-1] = '#';
  return (0);
}
