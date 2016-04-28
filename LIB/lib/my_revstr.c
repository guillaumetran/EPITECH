/*
** my_revstr.c for my_revstr.c in /home/tran/Documents/rendu/LIB/lib
**
** Made by Guillaume TRAN
** Login   <tran@epitech.net>
**
** Started on  Thu Apr 28 23:45:34 2016 Guillaume TRAN
** Last update Fri Apr 29 00:17:23 2016 Guillaume TRAN
*/

#include "my.h"

void	my_revstr(char *str)
{
  int	i;
  int	size;
  char	c;

  size = my_strlen(str);
  i = 0;
  while (i < size / 2)
    {
      c = *(str + i);
      *(str + i) = *(str + size - i - 1);
      *(str + size - i - 1) = c;
      i++;
    }
}
