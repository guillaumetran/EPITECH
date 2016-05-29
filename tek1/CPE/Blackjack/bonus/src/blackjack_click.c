/*
** blackjack_click.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Mar 16 17:28:03 2016 Guillaume TRAN
** Last update Mon Mar 28 22:14:21 2016 Guillaume TRAN
*/

#include "blackjack.h"

void				click(t_bj *game, t_bunny_position *pos)
{
  if (game->player == 0 && pos->y >= 640
      && pos->y < 768 && pos->x >= 540 && pos->x < 668)
    {
      pick_card(game, game->player);
      if (game->sum[game->player] >= 21)
	{
	  game->player++;
	  game->ia_play = 1;
	  game->turn = 2;
	}
    }
  if (game->player == 0 && pos->y >= 640
      && pos->y < 768 && pos->x >= 708 && pos->x < 836)
    {
      game->player++;
      game->ia_play = 1;
      game->turn = 2;
    }
}

t_bunny_response		blackjack_click(t_bunny_event_state sta,
						t_bunny_mouse_button but,
						void *data)
{
  t_bj				*game;
  t_bunny_position		*pos;

  if (sta == GO_UP)
    return (GO_ON);
  game = (t_bj *)data;
  pos = (t_bunny_position *)bunny_get_mouse_position();
  if (sta == GO_DOWN)
    click(game, pos);
  return (GO_ON);
}
