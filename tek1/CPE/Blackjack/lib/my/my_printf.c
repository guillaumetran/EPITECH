/*
** my_printf.c for my_printf in /home/ladenb_p/rendu/Projets/Printf/PSU_2015_my_printf
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Wed Nov  4 16:41:48 2015 Pierre Ladenburger
** Last update Sat Mar 26 18:48:50 2016 Pierre Ladenburger
*/

#include <unistd.h>
#include <stdarg.h>
#include "lib.h"

int	flag_fct(const char *format, int i, va_list ap)
{
  if (format[i] == 's')
    my_putstr(va_arg(ap, char *));
  else if (format[i] == 'd' || format[i] == 'i')
    my_put_nbr(va_arg(ap, int));
  else if (format[i] == 'c')
    my_putchar(va_arg(ap, int));
  return (0);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;

  if (format == NULL)
    return (-1);
  va_start(ap, format);
  i = 0;
  while (format[i])
    {
      if (format[i] == '%')
      	{
	  i++;
	  if (format[i + 1] != '%')
	    flag_fct(format, i, ap);
	}
      else
	my_putchar(format[i]);
      i++;
    }
  va_end(ap);
  return (0);
}
