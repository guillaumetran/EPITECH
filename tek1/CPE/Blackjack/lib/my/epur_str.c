/*
** epur_str.c for epur_str in /home/ladenb_p/Rendu/Projets/PSU/PSU_2015_minishell1/minishell/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@ladenb_p>
**
** Started on  Mon Feb  1 16:51:04 2016 Pierre Ladenburger
** Last update Tue Feb  2 20:19:43 2016 Pierre Ladenburger
*/

#include <stdlib.h>
#include "lib.h"

char	*epur_str(char *str)
{
  int	i;
  int	j;
  char	*end;

  if ((end = malloc(sizeof(*end) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while ((str[i] == ' ' || str[i] == '\t') && i++);
	  i--;
	  (str[i + 1] != '\0') ? end[j++] = ' ' : 0;
	}
      else
	end[j++] = str[i];
      i++;
    }
  end[j] = '\0';
  free(str);
  return (end);
}
