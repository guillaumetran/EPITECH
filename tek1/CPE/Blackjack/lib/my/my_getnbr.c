/*
** my_getnbr.c for my_getnbr in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sun Jan 24 10:33:22 2016 Pierre Ladenburger
** Last update Sun Feb 14 23:58:58 2016 Pierre Ladenburger
*/

#include <unistd.h>
#include "lib.h"

char	*check_str(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] < '0' || str[i] > '9')
        return (NULL);
      i++;
    }
  return (str);
}

int	powten(int pow)
{
  int	ret;

  ret = 1;
  while (pow > 0)
    {
      ret = ret * 10;
      pow = pow - 1;
    }
  return (ret);
}

void	get_sign(char *str, int *pos, int *sign)
{
  *pos = 0;
  *sign = 1;
  while (str[*pos] && (str[*pos] == '-' || str[*pos] == '+'))
    {
      if (str[*pos] == '-')
        *sign = -(*sign);
      *pos = *pos + 1;
    }
}

int	my_getnbr(char *str)
{
  int	pos;
  int	sign;
  int	ret;
  int	i;
  long	lret;

  ret = 0;
  lret = 0;
  if ((check_str(str)) == NULL)
    return (-1);
  get_sign(str, &pos, &sign);
  i = pos - 1;
  while (str[pos] && str[pos] >= '0' && str[pos] <= '9')
    pos = pos + 1;
  pos = pos - 1;
  while (++i <= pos && str[i])
    {
      lret = lret + ((str[i] - '0') * powten(pos - i));
      ret = ret + ((str[i] - '0') * powten(pos - i));
    }
  if (lret == 2147483648 && sign == -1)
    return (-2147483648);
  if (lret != ret)
    return (0);
  return (ret * sign);
}
