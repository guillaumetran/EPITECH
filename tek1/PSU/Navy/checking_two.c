/*
** checking_two.c for checking two in /home/tran_-/Documents/rendu/PSU_2015_navy
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Sat Dec 19 02:25:15 2015 Guillaume TRAN
** Last update Sat Dec 19 20:13:03 2015 Guillaume TRAN
*/

#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"
#include "navy.h"

void    youwin(int sig)
{
  navy.win = 1;
}

void    still_continue(int sig)
{
  navy.win = 0;
}

int     check_win(char **grid, char **gridenemy)
{
  navy.win = 0;
  signal(SIGUSR1, youwin);
  signal(SIGUSR2, still_continue);
  pause();
  if (navy.win == 1)
    {
      my_printf("\nmy navy:");
      my_display(grid);
      my_printf("\nenemy navy:");
      my_display(gridenemy);
      my_printf("\nI won\n");
      return (1);
    }
  return (0);
}
