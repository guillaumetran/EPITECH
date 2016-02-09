/*
** enemy_start.c for enemy_start in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Dec 18 15:41:02 2015 Guillaume TRAN
** Last update Sat Dec 19 20:59:47 2015 Guillaume TRAN
*/

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "navy.h"

void     start_navy(char **pos)
{
  my_printf("my PID: %d\n", getpid());
  my_printf("\nwaiting for enemy...\n");
  enemy_connection(pos);
}

void     start_navy_enemy(char **pos)
{
  my_printf("my PID: %d\n", getpid());
  kill(navy.pid_enemy, SIGUSR1);
  my_printf("\nsuccessfully connected to enemy\n");
  connected(pos);
}

int	connected(char **pos)
{
  char  **grid;
  char  **gridenemy;
  int   *coord;

  if ((coord = malloc(sizeof(*coord) * 2)) == NULL)
    return (1);
  grid = my_initialize_grid();
  my_fill_grid(grid);
  gridenemy = my_initialize_grid();
  my_fill_grid(gridenemy);
  usleep(1000);
  if ((place_boat(pos, grid)) == 1)
    {
      kill(navy.pid_enemy, SIGUSR1);
      return (1);
    }
  kill(navy.pid_enemy, SIGUSR2);
  signal(SIGUSR2, enemy_ok);
  signal(SIGUSR1, enemy_lost);
  pause();
  if (navy.finish == 1)
    return (1);
  check_win(grid, gridenemy);
  enemy_go(grid, gridenemy, coord);
  free(grid);
}

void	hdl(int sig, siginfo_t *siginfo, void *context)
{
  navy.pid_enemy = siginfo->si_pid;
  my_printf("\nennemy connected\n");
}

int    enemy_connection(char **pos)
{
  struct sigaction      act;
  char  **grid;
  char  **gridenemy;

  memset(&act, '\0', sizeof(act));
  act.sa_sigaction = &hdl;
  act.sa_flags = SA_SIGINFO;
  if (sigaction(SIGUSR1, &act, NULL) < 0)
      return (1);
  pause();
  grid = my_initialize_grid();
  my_fill_grid(grid);
  gridenemy = my_initialize_grid();
  my_fill_grid(gridenemy);
  signal(SIGUSR2, enemy_ok);
  signal(SIGUSR1, enemy_lost);
  pause();
  if ((player_one_go(grid, gridenemy, pos)) == 1)
    return (1);
  free(grid);
  free(gridenemy);
  return (0);
}
