/*
** my_getnbr.c for my_getnbr in /home/tran_-/Documents/rendu/CPE_2015_BSQ/lib/my
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Tue Dec 22 16:44:30 2015 Guillaume TRAN
** Last update Mon Dec 28 13:18:38 2015 Guillaume TRAN
*/

#include <unistd.h>
#include "my.h"

int	check_nbr(char *nbr)
{
  int	i;

  i = 0;
  while (nbr[i])
    {
      if (nbr[i] < '0' || nbr[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int     my_getnbr(char *nbr)
{
  int   n;
  int   i;
  int   res;

  n = 1;
  if (check_nbr(nbr) == -1)
    return (-1);
  res = 0;
  i = my_strlen(nbr) - 1;
  while (i >= 0)
    {
      res = res + (n * (nbr[i] - 48));
      n = n * 10;
      i--;
    }
  return (res);
}
