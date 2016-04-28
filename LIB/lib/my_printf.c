/*
** my_printf.c for my_printf in /home/tran_-/Documents/rendu/PSU_2015_my_printf
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Nov  4 23:07:23 2015 Guillaume TRAN
** Last update Thu Apr 28 23:54:25 2016 Guillaume TRAN
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	call_function(int id, va_list args)
{
  int	(*fct[12])(va_list args);
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
  fct[11] = &flag_f;
  count = fct[id](args);
  return (count);
}

int	get_id(int i, char *format, char *flags)
{
  int	k;

  k = 0;
  while (flags[k] != '\0' && format[i] != flags[k - 1])
    {
      if (format[i + 1] == flags[k])
	return (k);
      k++;
    }
  return (-2);
}

void	get_type_next(char *format, int count[1])
{
  my_putchar(format[count[1]]);
  count[0]++;
  count[1]++;
}

int	get_type(char *format, va_list args)
{
  int	id;
  int	count[1];

  count[0] = 0;
  count[1] = 0;
  while (format[count[1]] != '\0')
    {
      id = -1;
      if (format[count[1]] == '%')
	{
	  id = get_id(count[1], format, "csdioxXbpSuf");
	  if (id >= 0)
	    {
	      count[0] += call_function(id, args);
	      count[1]++;
	    }
	  count[1]++;
	}
      else
	get_type_next(format, count);
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
