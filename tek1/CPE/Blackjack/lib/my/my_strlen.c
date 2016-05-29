/*
** my_strlen.c for my_strlen in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sat Jan 23 18:22:09 2016 Pierre Ladenburger
** Last update Mon Feb  1 21:04:56 2016 Pierre Ladenburger
*/

#include <unistd.h>
#include "lib.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i]);
  return (i);
}
