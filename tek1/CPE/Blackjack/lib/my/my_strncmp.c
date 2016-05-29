/*
** my_strncmp.c for my_strncmp in /home/ladenb_p/rendu/Projets/PSU_2015_minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Mon Feb  8 09:26:08 2016 Pierre Ladenburger
** Last update Mon Feb  8 09:34:31 2016 Pierre Ladenburger
*/

#include <unistd.h>
#include "lib.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while ((s1[i] || s2[i]) && i < n)
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i++;
    }
  if ((s1[i] < s2[i]) && i < n)
    return (-1);
  if ((s1[i] > s2[i]) && i < n)
    return (1);
  return (0);
}
