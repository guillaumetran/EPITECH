/*
** my_strcmp.c for my_strcmp in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sun Jan 24 11:03:58 2016 Pierre Ladenburger
** Last update Wed Mar 23 17:36:09 2016 Pierre Ladenburger
*/

#include <unistd.h>
#include "lib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (-1);
  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] == s2[i])
        i++;
      else if (s1[i] < s2[i])
        return (-1);
      else if (s1[i] > s2[i])
        return (1);
    }
  if (s1[i] < s2[i])
    return (-1);
  else if (s1[i] > s2[i])
    return (1);
  return (0);
}

int	str_match(const char *text, const char *str)
{
  if (*str == '\0' && *text == '\0')
    return (1);
  if (*str != *text)
    return (0);
  return (str_match(text + 1, str + 1));
}
