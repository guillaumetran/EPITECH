/*
** fcnt.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Feb 29 17:31:23 2016 Guillaume TRAN
** Last update Thu Mar 24 15:37:05 2016 Guillaume TRAN
*/

#include "blackjack.h"

int	my_strhands(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '0' && str[i] != '\0');
  return (i);
}

int	*initialize_sum(int players)
{
  int	*sum;
  int	i;

  if ((sum = malloc(sizeof(*sum) * (players + 1))) == NULL)
    return (NULL);
  sum[players] = 0;
  i = 0;
  while (i < players)
    sum[i++] = 0;
  return (sum);
}

char	*initialize_pick(int cards)
{
  char	*pick;
  int	i;

  if ((pick = malloc(sizeof(*pick) * (cards + 1))) == NULL)
    return (NULL);
  pick[cards] = 0;
  i = 0;
  while (i < cards)
    pick[i++] = 0;
  return (pick);
}

char	**initialize_name(int players, int length)
{
  char	**names;
  int	i;
  int	j;

  if ((names = malloc(sizeof(*names) * (players + 1))) == NULL)
    return (NULL);
  names[players] = 0;
  i = 0;
  while (i < players)
    {
      if ((names[i] = malloc(sizeof(*names) * (length + 1))) == NULL)
	return (NULL);
      j = -1;
      while (++j < length)
	names[i][j] = '0';
      names[i][length] = 0;
      i++;
    }
    names[players] = 0;
  return (names);
}
