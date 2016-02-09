/*
** checking.c for cheking.c in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Dec 18 16:43:23 2015 Guillaume TRAN
** Last update Sat Dec 19 20:17:57 2015 Guillaume TRAN
*/

#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"
#include "navy.h"

int     check_loose(char **grid, char **gridenemy)
{
  int   i;
  int   k;

  i = -1;
  while (++i < 8)
    {
      k = -1;
      while (++k < 8)
	{
	  if (grid[i][k] != '.' && grid[i][k] != 'x' && grid[i][k] != 'o')
	    {
	      usleep(500);
	      kill(navy.pid_enemy, SIGUSR2);
	      return (0);
	    }
	}
    }
  usleep(500);
  kill(navy.pid_enemy, SIGUSR1);
  my_printf("\nmy navy:");
  my_display(grid);
  my_printf("\nenemy navy:");
  my_display(gridenemy);
  my_printf("\nEnemy won\n");
  return (1);
}

void     check_result(char **grid, int *coord)
{
  int   x;
  int   y;

  x = coord[1];
  y = coord[0];
  if (grid[x][y] != '.' && grid[x][y] != 'x' && grid[x][y] != 'o')
    {
      my_printf("\nresult: %c%d:hit\n", coord[0] + 65, coord[1] + 1);
      grid[x][y] = 'x';
      usleep(500);
      kill(navy.pid_enemy, SIGUSR1);
    }
  else
    {
      my_printf("\nresult: %c%d:missed\n", coord[0] + 65, coord[1] + 1);
      grid[x][y] = 'o';
      usleep(500);
      kill(navy.pid_enemy, SIGUSR2);
    }
}

void    hit(int sig)
{
  navy.finish = 1;
}

void    not(int sig)
{
  navy.finish = 0;
}

void    hitornot(char **gridenemy, int *coord)
{
  navy.finish = 0;
  signal(SIGUSR1, hit);
  signal(SIGUSR2, not);
  pause();
  if (navy.finish == 1)
    {
      my_printf("\nresult: %c%d:hit\n", coord[0] + 65, coord[1] + 1);
      gridenemy[coord[1]][coord[0]] = 'x';
    }
  else
    {
      my_printf("\nresult: %c%d:missed\n", coord[0] + 65, coord[1] + 1);
      gridenemy[coord[1]][coord[0]] = 'o';
    }
}
