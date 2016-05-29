/*
** main.c for Allum1 in /home/tran_-/Documents/rendu/CPE_2015_Allum1
**
** Made by tran_-
** Login   <tran_-@epitech.net>
**
** Started on  Mon Feb  8 12:20:48 2016 tran_-
** Last update Sat Mar 26 19:22:58 2016 Pierre Ladenburger
*/

#include "blackjack.h"

void	get_pick(t_blackjack *bj)
{
  int	i;
  char	card;

  i = 0;
  while (i < bj->cards)
    {
      card = get_card("123456789XJQK");
      if (check_card(bj->pick, card, i) == 1)
	bj->pick[i++] = card;
    }
  bj->pick[i] = 0;
}

void	ia_turn(t_blackjack *bj, int player)
{
  display_game(bj, player);
  while (bj->sum[player] <= 16)
    {
      my_printf("(%s) Action: hit\n", bj->names[player]);
      pick_card(bj, player);
      if (bj->sum[player] <= 21)
	display_game(bj, player);
    }
  if (bj->sum[player] > 16 && bj->sum[player] <= 21)
      my_printf("(%s) Action: stand\n", bj->names[player]);
}

int	player_turn(t_blackjack *bj, int player)
{
  char	*action;

  display_game(bj, player);
  my_printf("(%s) Action: ", bj->names[player]);
  if ((action = get_next_line(0)) == NULL)
    return (-1);
  while (str_match(action, "stand") == 0)
    {
      if (my_strcmp(action, "hit") == 0)
	pick_card(bj, player);
      else
	my_putstr("Invalid action. Use 'hit' or 'stand'\n");
      if (bj->sum[player] > 21)
	return (0);
      display_game(bj, player);
      my_printf("(%s) Action: ", bj->names[player]);
      if ((action = get_next_line(0)) == NULL)
	return (-1);
    }
  return (0);
}

int	blackjack(t_blackjack *bj)
{
  int	player;

  get_pick(bj);
  player = 0;
  distribute_cards(bj);
  while (player < bj->players)
    {
      if (player == 0)
	{
	  if ((player_turn(bj, player)) == -1)
	    return (-1);
	}
      else
	ia_turn(bj, player);
      display_msg(bj, player);
      player++;
    }
  display_game(bj, player);
  winner_is(bj, 0, -1, 0);
  return (0);
}

int		main(void)
{
  t_blackjack	bj;

  srand(time(NULL));
  bj.ia = 1;
  bj.players = bj.ia + 2;
  bj.names = initialize_name(bj.players, 15);
  get_names(&bj, "You", "Ben", "Dealer");
  bj.hands = initialize_name(bj.players, 20);
  bj.cards = 52;
  bj.nb_pick = 0;
  bj.pick = initialize_pick(bj.cards);
  bj.sum = initialize_sum(bj.players);
  bj.as = initialize_sum(bj.players);
  if ((blackjack(&bj)) == -1)
    return (-1);
  return (0);
}
