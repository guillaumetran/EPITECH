/*
** my_strcmp.c for my_strcmp in /home/tran/Documents/rendu/LIB/lib
**
** Made by Guillaume TRAN
** Login   <tran@epitech.net>
**
** Started on  Fri Apr 29 00:50:53 2016 Guillaume TRAN
** Last update Fri Apr 29 00:50:54 2016 Guillaume TRAN
*/

#include "my.h"

int	my_strcmp(char *str, char *strcmp)
{
  int	i;

  i = 0;
  if (my_strlen(str) != my_strlen(strcmp))
    return (0);
  while (str[i] == strcmp[i] && str[i] && strcmp[i])
    i++;
  if (my_strlen(str) != i)
    return (0);
  return (1);
}
