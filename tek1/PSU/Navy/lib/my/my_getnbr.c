/*
** my_getnbr.c for my_getnbr in /home/tran_-/Documents/rendu/PSU_2015_navy/lib/my
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Dec 18 23:24:26 2015 Guillaume TRAN
** Last update Fri Dec 18 23:24:28 2015 Guillaume TRAN
*/

#include "my.h"

int     my_getnbr(char *nbr)
{
  int   n;
  int   i;
  int   res;

  n = 1;
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
