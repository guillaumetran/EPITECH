/*
** my_navy.c for my_navy in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Thu Dec 10 16:51:17 2015 Guillaume TRAN
** Last update Sat Dec 19 20:54:31 2015 Guillaume TRAN
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "navy.h"
#include "my.h"

int	*convert_to_coord(char *str, int *coord)
{
  coord[0] = str[0] - 65;
  coord[1] = str[1] - 49;
  return (coord);
}

int	game(char **grid, char **gridenemy)
{
  char	str[3];
  int	*coord;

  if ((coord = malloc(sizeof(*coord) * 2)) == NULL)
      return (1);
  while (check_loose(grid, gridenemy) != 1)
    {
      my_printf("\nmy navy:");
      my_display(grid);
      my_printf("\nenemy navy:");
      my_display(gridenemy);
      my_printf("\nattack : ");
      check_input_coord(str, coord);
      send_coord(coord);
      hitornot(gridenemy, coord);
      if (check_win(grid, gridenemy) == 1)
	return (1);
      my_printf("\nwaiting for enemy's attack...\n");
      receive_coord(coord);
      check_result(grid, coord);
    }
  free(coord);
  return (0);
}

int	main(int ac, char **av)
{
  int	map;
  char	**pos;

  if (ac == 2)
    {
      pos = my_initialize_grid();
      if ((map = open(av[1], O_RDONLY)) == -1)
	return (1);
      if ((my_get_boat(map, pos)) == 1)
	return (1);
      start_navy(pos);
    }
  else if (ac == 3)
    {
      pos = my_initialize_grid();
      if ((map = open(av[2], O_RDONLY)) == -1)
	return (1);
      if ((my_get_boat(map, pos)) == 1)
	return (1);
      navy.pid_enemy = my_getnbr(av[1]);
      start_navy_enemy(pos);
    }
  else
    return (1);
  free(pos);
}
