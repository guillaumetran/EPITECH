/*
** my_revstr.c for my_revstr in /home/ladenb_p/Rendu/Projets/CPE/CPE_2015_Allum1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@ladenb_p>
**
** Started on  Wed Feb 17 09:58:45 2016 Pierre Ladenburger
** Last update Sat Feb 20 12:04:27 2016 Pierre Ladenburger
*/

#include "lib.h"

void	my_revstr(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  i--;
  while (i >= 0)
    {
      my_putchar(str[i]);
      i--;
    }
}
