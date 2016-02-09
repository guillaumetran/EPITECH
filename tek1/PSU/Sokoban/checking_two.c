/*
** checking_two.c for sokoban in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Jan  8 19:48:36 2016 Guillaume TRAN
** Last update Sun Jan 17 15:41:49 2016 Guillaume TRAN
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

void    display_map(char **map, int height)
{
  int   i;

  i = 0;
  while (i < height)
    {
      mvprintw(i, 0, map[i]);
      i++;
    }
}

void    start_ncurses(t_info *sokoban)
{
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  display_map(sokoban->map, sokoban->height);
  curs_set(0);
}

void	game_part_one(t_info *sokoban)
{
  move_player(sokoban->map, sokoban->pos_player, sokoban->key);
  replace_goal(sokoban->goal, sokoban->map, sokoban->o);
  my_fill_box(sokoban->box, sokoban->map, sokoban->width, sokoban->height);
  display_map(sokoban->map, sokoban->height);
}
