/*
** my_sokoban.c for my_sokoban in /home/tran_-/Documents/rendu/PSU_2015_my_sokoban
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Jan  4 10:32:28 2016 Guillaume TRAN
** Last update Sun Jan 17 16:34:59 2016 Guillaume TRAN
*/

#include "my.h"
#include "sokoban.h"

int     get_height(int map)
{
  char  buffer[2];
  int   i;

  i = 1;
  while ((read(map, buffer, 1)) && buffer[0] != '\0')
    {
      if (buffer[0] == '\n')
	i++;
    }
  return (i + 1);
}

int     get_width(int map)
{
  char  buffer[2];
  int   i;

  i = 0;
  while ((read(map, buffer, 1)) && buffer[0] != '\n')
    i++;
  return (i);
}

int	game(t_info *sokoban)
{
  start_ncurses(sokoban);
  while ((check_win(sokoban->goal, sokoban->map, sokoban->o)) != 1)
    {
      if ((sokoban->key = wgetch(stdscr)) < 0)
	{
	  endwin();
	  return (1);
	}
      if (sokoban->key == ' ')
	return (2);
      if (LINES < sokoban->height || COLS < sokoban->width)
	{
	  endwin();
	  return (1);
	}
      game_part_one(sokoban);
    }
  endwin();
  return (0);
}

int	my_sokoban(t_info sokoban, char *filename)
{
  sokoban.map = my_initialize_map(sokoban.width, sokoban.height);
  if ((my_fill_map(sokoban.map, filename, sokoban.width, sokoban.height)) == 1)
    return (1);
  if ((check_map(sokoban.map, sokoban.width, sokoban.height)) == 1)
    return (1);
  sokoban.goal = my_initialize_goal(2, (sokoban.height * sokoban.width));
  sokoban.box = my_initialize_goal(2, (sokoban.height * sokoban.width));
  sokoban.o = my_fill_goal(sokoban.goal, sokoban.map,
			   sokoban.width, sokoban.height);
  sokoban.x = my_fill_box(sokoban.box, sokoban.map,
			  sokoban.width, sokoban.height);
  if (sokoban.x != sokoban.o)
    return (1);
  if ((find_player(sokoban.map, sokoban.width,
		   sokoban.height, sokoban.pos_player)) == 1)
    return (1);
  return (game(&sokoban));
}

int	main(int ac, char **av)
{
  t_info	sokoban;
  int		fd;
  int		end;

  if (ac != 2)
    return (1);
  end = 2;
  while (end == 2)
    {
      if ((fd = open(av[1], O_RDONLY)) == -1)
	return (1);
      sokoban.width = get_width(fd);
      sokoban.height = get_height(fd);
      end = my_sokoban(sokoban, av[1]);
    }
  return (end);
}
