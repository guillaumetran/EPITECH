/*
** my_strdup.c for my_strdup in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sun Jan 24 11:07:02 2016 Pierre Ladenburger
** Last update Mon Feb  1 21:07:24 2016 Pierre Ladenburger
*/

#include <stdlib.h>
#include "lib.h"

char	*my_strdup(char *str)
{
  char	*save;

  if (str == NULL)
    return (NULL);
  if ((save = malloc(sizeof(*save) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  if ((my_strcpy(str, save)) == NULL)
    return (NULL);
  return (save);
}
