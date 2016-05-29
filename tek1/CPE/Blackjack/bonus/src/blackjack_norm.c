/*
** blackjack_norm.c for blackjack_norm in /home/lpierre/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Ladenburger Pierre
** Login   <lpierre@localhost.localdomain>
**
** Started on  Sun Mar 27 20:41:33 2016 Ladenburger Pierre
** Last update Mon Mar 28 23:51:55 2016 Guillaume TRAN
*/

#include "blackjack.h"

int	get_card_value(char card)
{
  if (card <= '9' && card > '1')
    return (card - '0');
  else if (card == '1')
    return (11);
  else
    return (10);
}

int	count_as(char *hands)
{
  int	i;
  int	as;

  i = 0;
  as = 0;
  while (hands[i] != '\0')
    {
      if (hands[i] == '1')
	as++;
      i++;
    }
  return (as);
}
