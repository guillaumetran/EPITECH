/*
** my_putchar.c for my_putchar in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sun Jan 24 10:24:27 2016 Pierre Ladenburger
** Last update Mon Feb  1 21:01:54 2016 Pierre Ladenburger
*/

#include <unistd.h>
#include "lib.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
