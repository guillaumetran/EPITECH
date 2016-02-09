/*
** check_connection.c for check_connection in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Sat Dec 19 18:52:20 2015 Guillaume TRAN
** Last update Mon Dec 21 23:40:41 2015 Guillaume TRAN
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "my.h"
#include "navy.h"

void	enemy_ok(int sig)
{
  navy.finish = 0;
}

void	enemy_lost(int sig)
{
  navy.finish = 1;
}

int     game_enemy(char **grid, char **gridenemy)
{
  char  str[3];
  int   *coord;

  if ((coord = malloc(sizeof(*coord) * 2)) == NULL)
    return (1);
  while (check_loose(grid, gridenemy) != 1)
    {
      my_printf("\nattack : ");
      check_input_coord(str, coord);
      send_coord(coord);
      hitornot(gridenemy, coord);
      if (check_win(grid, gridenemy) == 1)
	return (1);
      my_printf("\nmy navy:");
      my_display(grid);
      my_printf("\nenemy navy:");
      my_display(gridenemy);
      my_printf("\nwaiting for enemy's attack...\n");
      receive_coord(coord);
      check_result(grid, coord);
    }
  free(coord);
  return (0);
}

void	enemy_go(char **grid, char **gridenemy, int *coord)
{
  my_printf("\nmy navy:");
  my_display(grid);
  my_printf("\nenemy navy:");
  my_display(gridenemy);
  my_printf("\nwaiting for enemy's attack...\n");
  receive_coord(coord);
  check_result(grid, coord);
  game_enemy(grid, gridenemy);
}

int	player_one_go(char **grid, char **gridenemy, char **pos)
{
  if (navy.finish == 1)
    return (1);
  if (place_boat(pos, grid) == 1)
    {
      usleep(500);
      kill(navy.pid_enemy, SIGUSR1);
      return (1);
    }
  usleep(500);
  kill(navy.pid_enemy, SIGUSR2);
  game(grid, gridenemy);
  return (0);
}
