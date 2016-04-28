/*
** my_getnbr.c for my_get_nbr in /home/tran/Documents/rendu/LIB/lib
**
** Made by Guillaume TRAN
** Login   <tran@epitech.net>
**
** Started on  Fri Apr 29 00:51:09 2016 Guillaume TRAN
** Last update Fri Apr 29 01:08:29 2016 Guillaume TRAN
*/

#include <unistd.h>
#include "my.h"

double		my_atof(char *str)
{
  double	res;
  int		count;
  int		i;

  count = 0;
  i = 0;
  res = 0.0;
  while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    res = res * 10.0 + (str[i++] - '0');
  if (str[i++] == '.')
    {
      while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
	  res = res * 10.0 + (str[i++] - '0');
	  count++;
	}
    }
  while (count-- > 0)
    res /= 10;
  return (res);
}

static int	check_nbr(char *nbr)
{
  int		i;

  i = 0;
  while (nbr[i])
    {
      if (nbr[i] < '0' || nbr[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int	my_getnbr(char *nbr)
{
  int	n;
  int	i;
  int	res;

  n = 1;
  if (check_nbr(nbr) == -1)
    return (-1);
  res = 0;
  i = my_strlen(nbr) - 1;
  while (i >= 0)
    {
      res += n * (nbr[i] - 48);
      n = n * 10;
      i--;
    }
  return (res);
}
