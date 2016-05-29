/*
** blackjack_result.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Mon Mar 28 19:42:25 2016 Guillaume TRAN
** Last update Mon Mar 28 23:04:16 2016 Guillaume TRAN
*/

#include "blackjack.h"

void	my_result(t_bj *game, int player)
{
  t_bunny_position	pos;
  t_bunny_pixelarray	*res;

  get_txt_pos(game, &pos, player);
  pos.x -= 40;
  pos.y += 60;
  if (player != 5)
    {
      if (game->sum[5] == 21 && my_strhands(game->hands[5]) == 2)
	my_blit(game->pix, game->loose, pos);
      else if (game->sum[player] > 21)
	my_blit(game->pix, game->out, pos);
      else if (game->sum[player] == 21 && my_strhands(game->hands[player]) == 2)
	my_blit(game->pix, game->bj, pos);
      else if (game->sum[player] == game->sum[5])
	my_blit(game->pix, game->tie, pos);
      else if (game->sum[player] <= 21 && game->sum[5] > 21)
	my_blit(game->pix, game->gg, pos);
      else if (game->sum[player] > game->sum[5])
	my_blit(game->pix, game->gg, pos);
      else
	my_blit(game->pix, game->loose, pos);
    }
  else if (player == 5)
    {
      if (game->sum[player] == 21 && my_strhands(game->hands[player]) == 2)
	my_blit(game->pix, game->bj, pos);
      if (game->sum[player] > 21)
	my_blit(game->pix, game->out, pos);
    }
}
