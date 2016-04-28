/*
** flags2_printf.c for flags2_printf in /home/tran_-/Documents/rendu/PSU_2015_my_printf/lib/my
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Nov  9 14:21:13 2015 Guillaume TRAN
** Last update Thu Apr 28 23:04:54 2016 Guillaume TRAN
*/

#include "my.h"

int	flag_X(va_list args)
{
  char	*str;

  str = my_putnbr_base(va_arg(args,int), "0123456789ABCDEF");
  my_putstr(str);
  return (my_strlen(str));
}

int	flag_b(va_list args)
{
  char	*str;

  str = my_putnbr_base(va_arg(args,int), "01");
  my_putstr(str);
  return (my_strlen(str));
}

int		flag_p(va_list args)
{
  char		*str;
  unsigned long	p;

  p = (unsigned long)va_arg(args, void *);
  my_putstr("0x");
  str = my_putnbr_base(p, "0123456789abcdef");
  my_putstr(str);
  return (my_strlen(str) + 2);
}

int	flag_smaj(va_list args)
{
  char	*str;
  int	count[1];
  char	*nbr;

  str = va_arg(args, char *);
  count[0] = 0;
  while (str[count[0]] != '\0')
    {
      count[1] = str[count[0]];
      if (count[1] < 32 || count[1] >= 127)
	{
	  my_putchar('\\');
	  nbr = my_putnbr_base(count[1], "01234567");
	  if (my_strlen(nbr) < 2)
	    my_putstr("00");
	  else if (my_strlen(nbr) <= 2)
	    my_putchar('0');
	  my_putstr(nbr);
	}
      else
	my_putchar(str[count[0]]);
      count[0]++;
    }
  return (my_strlen(str));
}

int		flag_u(va_list args)
{
  char		*str;
  unsigned long	p;

  p = (unsigned long)va_arg(args, int);
  str = my_putnbr_base(p, "0123456789");
  my_putstr(str);
  return (my_strlen(str));
}
