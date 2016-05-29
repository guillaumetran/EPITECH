/*
** my_strcpy.c for my_strcpy in /home/ladenb_p/rendu/minishell1/lib/my
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@pc-ladenb_p>
**
** Started on  Sun Jan 24 10:28:48 2016 Pierre Ladenburger
** Last update Wed Mar 23 18:42:50 2016 Guillaume TRAN
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

char	*my_strcp(char *str)
{
  char	*copy;
  int	i;

  if ((copy = malloc(sizeof(*copy) * my_strlen(str))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      copy[i] = str[i];
      i++;
    }
  copy[i] = 0;
  return (copy);
}

char	*my_strcpy(char *src, char *dest)
{
  int	i;

  i = 0;
  if (src == NULL || dest == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
