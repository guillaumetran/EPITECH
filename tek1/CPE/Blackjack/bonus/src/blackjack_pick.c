/*
** blackjack_pick.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Fri Mar 18 09:26:56 2016 Guillaume TRAN
** Last update Sat Mar 26 20:51:01 2016 Pierre Ladenburger
*/

#include "blackjack.h"

char	get_card(char *cards)
{
  int   card;

  card = (rand() % 13);
  return (cards[card]);
}

int     get_sum(char card)
{
  if (card <= '9' && card > '1')
    return (card - '0' - 1);
  else if (card == '1')
    return (0);
  else if (card == 'X')
    return (9);
  else if (card == 'J')
    return (10);
  else if (card == 'Q')
    return (11);
  else if (card == 'K')
    return (12);
}

int	check_card(char *pick, char card, int i)
{
  int	k;
  int	count;

  count = 0;
  k = 0;
  while (k < i)
    {
      if (pick[k++] == card)
	count++;
    }
  if (count == 4)
    return (0);
  return (1);
}

void	get_pick(t_bj *game)
{
  int	i;
  char	card;

  i = 0;
  while (i < game->card)
    {
      card = get_card("123456789XJQK");
      if (check_card(game->pick, card, i) == 1)
	game->pick[i++] = card;
    }
  game->pick[i] = 0;
}
