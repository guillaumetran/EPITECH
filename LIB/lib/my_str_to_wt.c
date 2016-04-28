/*
** fcnt.c for my_str_to_wt.c in /home/tran/Documents/rendu/LIB/lib
**
** Made by Guillaume TRAN
** Login   <tran@epitech.net>
**
** Started on  Fri Apr 29 00:10:17 2016 Guillaume TRAN
** Last update Fri Apr 29 00:10:34 2016 Guillaume TRAN
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int     *get_max(char *str, int max[1], char c)
{
  int   count;
  int   i;

  max[0] = 0;
  max[1] = 1;
  count = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	{
	  max[1]++;
	  count = 0;
	}
      i++;
      count++;
      if (max[0] < count)
	max[0] = count;
    }
  return (max);
}

static void    fill_tab(char **tab, char *str, char c)
{
  int   j;
  int   k;
  int   i;

  j = 0;
  k = 0;
  i = 0;
  while (i < my_strlen(str))
    {
      if (str[i] == c)
	{
	  tab[j++][k++] = '\0';
	  i++;
	  k = 0;
	}
      tab[j][k++] = str[i++];
    }
  tab[j][k] = '\0';
}

char    **my_str_to_wordtab(char *str, char c)
{
  int   max[1];
  int   i;
  char  **tab;

  get_max(str, max, c);
  i = 0;
  if ((tab = malloc(sizeof(*tab) * (1 + max[1]))) == NULL)
    return (NULL);
  while (i < max[1])
    {
      if ((tab[i] = malloc(sizeof(*tab) * max[0])) == NULL)
	return (NULL);
      i++;
    }
  fill_tab(tab, str, c);
  tab[max[1]] = NULL;
  return (tab);
}
