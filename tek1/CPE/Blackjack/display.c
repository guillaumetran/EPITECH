/*
** display.c for Blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Tue Mar  1 17:35:20 2016 Guillaume TRAN
** Last update Sun Mar 27 20:32:25 2016 Ladenburger Pierre
*/

#include "blackjack.h"

void	winner_loop(t_blackjack *bj, int *winner, int player, int dealer)
{
  if (player == bj->players - 1 && dealer == 1)
    {
      if (*winner > 0)
	my_putstr(" and ");
      my_putstr("Dealer");
    }
  else if ((player != bj->players - 1) &&
	   ((bj->sum[player] <= 21 && bj->sum[bj->players - 1] > 21) ||
	    (bj->sum[player] <= 21 && bj->sum[bj->players - 1]
	     <= bj->sum[player])))
    {
      if (*winner > 0)
	my_putstr(" and ");
      if (bj->sum[player] == bj->sum[bj->players - 1])
	dealer = 1;
      my_putstr(bj->names[player]);
      (*winner)++;
    }
}

void	winner_is(t_blackjack *bj, int winner, int player, int dealer)
{
  while (++player < bj->players)
    winner_loop(bj, &winner, player, dealer);
  if (winner == 0 && bj->sum[bj->players - 1] <= 21)
    my_putstr("Dealer");
  if (bj->sum[0] > 21 && bj->sum[1] > 21 && bj->sum[2] > 21)
    {
      my_putstr("Nobody win !\n");
      return ;
    }
  my_putstr(" win !\n");
}

void	display_msg(t_blackjack *bj, int player)
{
  if (bj->sum[player] < 21)
    {
      my_putstr("Turn ended with ");
      my_printf("%d points.\n", bj->sum[player]);
    }
  else if (bj->sum[player] == 21)
    my_putstr("Blackjack !!!\n");
  else
    {
      my_putstr("Bursting ! Out with ");
      my_printf("%d points.\n", bj->sum[player]);
    }
}

void	get_names(t_blackjack *bj, char *one, char *two, char *three)
{
  bj->names[0] = my_strcpy(one, bj->names[0]);
  bj->names[1] = my_strcpy(two, bj->names[1]);
  bj->names[2] = my_strcpy(three, bj->names[2]);
}

void	display_game(t_blackjack *bj, int id)
{
  int	player;

  player = -1;
  my_putstr("*************\n");
  while (++player < bj->players)
    {
      (player == id) ? my_putchar('>') : 0;
      my_printf("%s:", bj->names[player]);
      my_puthands(bj->hands[player]);
      if (player < id)
	{
	  my_putstr(" - ");
	  if (bj->sum[player] == 21 && my_strhands(bj->hands[player]) == 2)
	    my_putstr("BLACKJACK");
	  else if (bj->sum[player] <= 21)
	    {
	      my_putchar(bj->sum[player] / 10 + '0');
	      my_putchar(bj->sum[player] % 10 + '0');
	    }
	  else
	    my_putstr("OUT");
	}
      my_putchar('\n');
    }
  my_putstr("*************\n\n");
}
