/*
** my_strlen.c for my_strlen in /home/tran_-/Documents/rendu/PSU_2015_my_printf_bootstrap
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Nov  4 11:44:48 2015 Guillaume TRAN
** Last update Wed Nov  4 19:36:54 2015 Guillaume TRAN
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
