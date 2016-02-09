/*
** flags_printf.c for flags_printf in /home/tran_-/Documents/rendu/PSU_2015_my_printf/lib/my
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Nov  9 14:17:53 2015 Guillaume TRAN
** Last update Thu Nov 26 15:11:35 2015 Guillaume TRAN
*/

#include "my.h"

int    flag_c(va_list args)
{
  char  c;

  c = (char)va_arg(args, int);
  my_putchar(c);
  return (1);
}

int    flag_d(va_list args)
{
  int	count;

  count = my_putnbr_basev1(va_arg(args, int), "0123456789");
  return (count);
}

int    flag_s(va_list args)
{
  char	*str;

  str = va_arg(args, char *);
  my_putstr(str);
  return (my_strlen(str));
}

int    flag_o(va_list args)
{
  char	*str;

  str = my_putnbr_base(va_arg(args,int), "01234567");
  my_putstr(str);
  return (my_strlen(str));
}

int    flag_x(va_list args)
{
  char	*str;

  str = my_putnbr_base(va_arg(args,int), "0123456789abcdef");
  my_putstr(str);
  return (my_strlen(str));
}
