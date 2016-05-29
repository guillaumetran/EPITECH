/*
** my_strcat.c for my_strcat in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sun Jan 24 10:45:04 2016 Pierre Ladenburger
** Last update Tue Feb 16 09:35:35 2016 Pierre Ladenburger
*/

#include <stdlib.h>
#include "lib.h"

char	*my_strcat(char *start, char *end)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (start == NULL || end == NULL)
    return (NULL);
  if ((str = malloc(sizeof(*str) *
		    (my_strlen(start) + my_strlen(end) + 2))) == NULL)
    return (NULL);
  while (start[i])
    str[j++] = start[i++];
  i = 0;
  while (end[i])
    str[j++] = end[i++];
  str[j] = '\0';
  return (str);
}

char	*my_strcat_two(char *start, char *end, char sep)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (start == NULL || end == NULL)
    return (NULL);
  if ((str = malloc(sizeof(*str) *
		    (my_strlen(start) + my_strlen(end) + 3))) == NULL)
    return (NULL);
  while (start[i])
    str[j++] = start[i++];
  i = 0;
  str[j] = sep;
  j++;
  while (end[i])
    str[j++] = end[i++];
  str[j] = '\0';
  return (str);
}
