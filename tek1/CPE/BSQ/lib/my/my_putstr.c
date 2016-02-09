/*
** my_putstr.c for my_putstr in /home/tran_-/Documents/rendu/PSU_2015_my_printf_bootstrap
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Nov  4 16:06:50 2015 Guillaume TRAN
** Last update Thu Nov 12 11:26:15 2015 Guillaume TRAN
*/

#include <stdarg.h>
#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
