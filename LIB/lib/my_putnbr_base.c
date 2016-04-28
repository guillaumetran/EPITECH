/*
** my_putnbr_base.c for my_putnbr_base in /home/tran_-/Documents/rendu/PSU_2015_my_printf/lib/my
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Oct  21 17:19:48 2015 Guillaume TRAN
** Last update Thu Apr 28 23:33:22 2016 Guillaume TRAN
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int			my_init_base(unsigned long nb, char *base)
{
  unsigned long		div;
  int			i;
  unsigned long		size_base;

  div = 1;
  i = 0;
  size_base = my_strlen(base);
  while ((nb / div) >= size_base)
    {
      div *= size_base;
      i++;
    }
  return (i);
}

char			*my_putnbr_base(unsigned long nb, char *base)
{
  unsigned long		res;
  unsigned long		div;
  unsigned long		size_base;
  int			i;
  char			*str;
  int			k;

  k = my_init_base(nb, base);
  if ((str = malloc(sizeof(*str) * k + 1)) == NULL)
      return (NULL);
  i = 0;
  size_base = my_strlen(base);
  div = 1;
  while ((nb / div) >= size_base)
    div *= size_base;
  while (div > 0)
    {
      res = (nb / div) % size_base;
      str[i] = base[res];
      div /= size_base;
      i++;
    }
  return (str);
}
