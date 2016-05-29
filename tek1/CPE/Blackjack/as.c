/*
** as.c for as in /home/ladenb_p/Rendu/Projets/CPE/CPE_2015_Blackjack
**
** Made by Pierre Ladenburger
** Login   <ladenb_p@ladenb_p>
**
** Started on  Sat Mar 26 19:57:29 2016 Pierre Ladenburger
** Last update Sat Mar 26 19:59:44 2016 Pierre Ladenburger
*/

#include "blackjack.h"

int	count_as(char *hands)
{
  int	i;
  int	as;

  i = -1;
  as = 0;
  while (hands[++i] != '\0' && hands[i] != '\0')
    {
      if (hands[i] == '1')
	as++;
    }
  return (as);
}
