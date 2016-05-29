/*
** my_putstr.c for my_putstr in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sat Jan 23 18:23:34 2016 Pierre Ladenburger
** Last update Mon Feb  1 21:05:51 2016 Pierre Ladenburger
*/

#include <unistd.h>
#include "lib.h"

void	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
}
