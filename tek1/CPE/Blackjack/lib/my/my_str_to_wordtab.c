/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sun Jan 24 10:26:19 2016 Pierre Ladenburger
** Last update Sun Feb 14 12:02:52 2016 Pierre Ladenburger
*/

#include <stdlib.h>
#include "lib.h"

char	**my_str_to_wordtab(char *str, char sep)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  i = 0;
  k = 0;
  if ((tab = malloc(sizeof(*tab) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str && str[k])
    {
      j = 0;
      if ((tab[i] = malloc(sizeof(*tab[i]) * (my_strlen(str) + 1))) == NULL)
	return (NULL);
      while (str[k] != sep && str[k] != 0)
        tab[i][j++] = str[k++];
      tab[i][j] = 0;
      if (str[k] != 0)
        k++;
      i++;
    }
  str[k] = '\0';
  tab[i] = NULL;
  return (tab);
}

char	**my_str_to_wordtab_two(char *str, char sep, char sepa)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  i = 0;
  k = 0;
  if ((tab = malloc(sizeof(*tab) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str && str[k])
    {
      j = 0;
      if ((tab[i] = malloc(sizeof(*tab[i]) * (my_strlen(str) + 1))) == NULL)
	return (NULL);
      while (str[k] != sep && str[k] != sepa && str[k] != 0)
        tab[i][j++] = str[k++];
      tab[i][j] = 0;
      if (str[k] != 0)
        k++;
      i++;
    }
  str[k] = '\0';
  tab[i] = NULL;
  return (tab);
}
