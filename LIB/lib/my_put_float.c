/*
** my_put_float.c for my_put_float in /home/tran/Documents/rendu/LIB/lib
**
** Made by Guillaume TRAN
** Login   <tran@epitech.net>
**
** Started on  Thu Apr 28 23:23:57 2016 Guillaume TRAN
** Last update Fri Apr 29 01:11:34 2016 Guillaume TRAN
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static char	*my_init_float(double nb)
{
  double	div;
  int		i;
  char		*str;

  i = 0;
  div = 1.0;
  while ((nb / div) > 10)
    {
      div *= 10;
      i++;
    }
  if ((str = malloc(sizeof(*str) * i + 1)) == NULL)
    return (NULL);
  return (str);
}

static void	my_put_float_next(int precision, char *str, int i, double nb)
{
  my_revstr(str);
  str[i++] = '.';
  nb *= 10;
  while (precision-- > 0)
    {
      str[i++] = '0' + ((unsigned long)nb % 10);
      nb *= 10;
    }
}

char		*my_put_float(double nb, int precision)
{
  char		*str;
  double	tmp;
  int		i;

  str = my_init_float(nb);
  i = 0;
  if (nb < 0)
    {
      my_putstr("-");
      nb *= -1;
    }
  tmp = nb;
  while (tmp > 0)
    {
      str[i++] = '0' + ((unsigned long)tmp % 10);
      tmp = tmp / 10 - 1;
    }
  my_put_float_next(precision, str, i, nb);
  return (str);
}

int	flag_f(va_list args)
{
  char	*str;

  str = my_put_float(va_arg(args, double), 2);
  my_putstr(str);
  return (my_strlen(str));
}
