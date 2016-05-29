/*
** cards.c for Blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Sat Mar  5 19:00:32 2016 Guillaume TRAN
** Last update Mon Mar 28 23:54:21 2016 Guillaume TRAN
*/

#include "blackjack.h"

char	get_card(char *cards)
{
  int	card;

  card = (rand() % 13);
  return (cards[card]);
}

int	get_sum(char card)
{
  if (card <= '9' && card > '1')
    return (card - '0');
  else if (card == '1')
    return (11);
  else
    return (10);
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

void	distribute_cards(t_blackjack *bj)
{
  int	player;
  int	turn;

  turn = -1;
  while (++turn < 2)
    {
      player = -1;
      while (++player < bj->players)
	{
	  if (!(player == 2 && turn == 1))
	    pick_card(bj, player);
	}
    }
}

void	pick_card(t_blackjack *bj, int player)
{
  int	j;
  int	as;

  j = my_strhands(bj->hands[player]);
  bj->hands[player][j] = bj->pick[bj->nb_pick++];
  bj->sum[player] += get_sum(bj->hands[player][j]);
  if (bj->sum[player] > 21 && (as = count_as(bj->hands[player])) > 0)
    {
      if (as > bj->as[player])
	{
	  bj->sum[player] -= 10;
	  bj->as[player]++;
	}
    }
  if (j >= 2 || (player == 2 && j >= 1))
    {
      my_putstr(bj->names[player]);
      my_putstr(" got a new card: ");
      if (bj->hands[player][j] == 'X')
	my_putstr("10");
      else
	my_putchar(bj->hands[player][j]);
      my_putstr(".\n");
    }
}
