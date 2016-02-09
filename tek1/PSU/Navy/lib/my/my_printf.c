/*
** my_printf.c for my_printf in /home/tran_-/Documents/rendu/PSU_2015_my_printf
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Nov  4 23:07:23 2015 Guillaume TRAN
** Last update Thu Dec 10 12:25:38 2015 Guillaume TRAN
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	call_function(int id, va_list args)
{
  int	(*fct[11])(va_list args);
  int	count;

  fct[0] = &flag_c;
  fct[1] = &flag_s;
  fct[2] = &flag_d;
  fct[3] = &flag_d;
  fct[4] = &flag_o;
  fct[5] = &flag_x;
  fct[6] = &flag_X;
  fct[7] = &flag_b;
  fct[8] = &flag_p;
  fct[9] = &flag_smaj;
  fct[10] = &flag_u;
  count = fct[id](args);
  return (count);
}

int	get_id(int i, char *format)
{
  int	k;
  char	*flags;

  flags = "csdioxXbpSu";
  k = 0;
  while (flags[k] != '\0' && format[i] != flags[k - 1])
    {
      if (format[i + 1] == flags[k])
	return (k);
      k++;
    }
  return (-2);
}

int	get_type(char *format, va_list args)
{
  int	count[2];

  count[0] = 0;
  count[1] = 0;
  while (format[count[1]] != '\0')
    {
      count[2] = -1;
      if (format[count[1]] == '%')
	{
	  count[2] = get_id(count[1], format);
	  if (count[2] >= 0)
	    {
	      count[0] += call_function(count[2], args);
	      count[1]++;
	    }
	  count[1]++;
	}
      else
	{
	  my_putchar(format[count[1]]);
	  count[0]++;
	  count[1]++;
	}
    }
  return (count[0]);
}

int	my_printf(char *format, ...)
{
  va_list	args;
  int		count;

  if (format == NULL)
    return (1);
  va_start(args, format);
  count = get_type(format, args);
  va_end(args);
  return (count);
}
