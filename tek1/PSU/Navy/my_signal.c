/*
** my_signal.c for my_signal.c in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Dec 18 15:52:24 2015 Guillaume TRAN
** Last update Sat Dec 19 20:42:17 2015 Guillaume TRAN
*/

#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"
#include "navy.h"

void	check_input_coord(char str[3], int *coord)
{
  int	check;

  check = 0;
  while (check != 1)
    {
      read(0, str, 200);
      convert_to_coord(str, coord);
      if ((coord[0] < 0 || coord[0] > 7) || (coord[1] < 0 || coord[1] > 7)
	  || str[2] != '\n')
	my_printf("\nwrong position\n\nattack: ");
      else
	check = 1;
    }
}

void    send_coord(int *coord)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  usleep(500);
  while (i++ < coord[0])
    {
      kill(navy.pid_enemy, SIGUSR1);
      usleep(500);
    }
  usleep(500);
  kill(navy.pid_enemy, SIGUSR2);
  while (j++ < coord[1])
    {
      usleep(500);
      kill(navy.pid_enemy, SIGUSR1);
    }
  usleep(500);
  kill(navy.pid_enemy, SIGUSR2);
}

void     function_ok(int sig)
{
  navy.counter = navy.counter + 1;
  signal(SIGUSR1, function_ok);
}

void     function_done(int sig)
{
  navy.finish = 1;
}

int     *receive_coord(int *coord)
{
  navy.counter = 0;
  navy.finish = 0;
  while (navy.finish != 1)
    {
      signal(SIGUSR1, function_ok);
      signal(SIGUSR2, function_done);
      pause();
    }
  coord[0] = navy.counter;
  navy.counter = 0;
  navy.finish = 0;
  while (navy.finish != 1)
    {
      signal(SIGUSR1, function_ok);
      signal(SIGUSR2, function_done);
      pause();
    }
  coord[1] = navy.counter;
  return (coord);
}
