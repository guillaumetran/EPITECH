/*
** blackjack_callback.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Mar 16 17:26:50 2016 Guillaume TRAN
** Last update Mon Mar 28 22:45:41 2016 Guillaume TRAN
*/

#include "blackjack.h"

t_bunny_response	blackjack_callback(t_bunny_event_state state,
					   t_bunny_keysym sym,
					   void *data)
{
  t_bj			*game;
  t_bunny_position	pos;

  game = (t_bj *)data;
  game = game;
  pos.x = 0;
  pos.y = 0;
  if (sym == BKS_SPACE && game->player == 6)
    {
      my_blit(game->pix, game->table, pos);
      bunny_blit(&game->win->buffer, &game->pix->clipable, &pos);
      bunny_display(game->win);
      print_money(game);
      blackjack_initialize(game);
      get_pick(game);
      distribute_cards(game);
    }
  if (sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
