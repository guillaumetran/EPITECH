/*
** my_put_nbr.c for my_put_nbr in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sun Jan 24 10:43:24 2016 Pierre Ladenburger
** Last update Mon Feb  1 21:06:47 2016 Pierre Ladenburger
*/

#include "lib.h"

int	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  while (nb / i >= 10)
    i = i * 10;
  while (i > 0)
    {
      my_putchar(nb / i % 10 + '0');
      i = i / 10;
    }
  return (0);
}
