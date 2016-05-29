/*
** blackjack_loop.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Wed Mar 16 17:32:39 2016 Guillaume TRAN
** Last update Mon Mar 28 22:40:45 2016 Guillaume TRAN
*/

#include "blackjack.h"

void			my_blit(t_bunny_pixelarray *out,
				t_bunny_pixelarray *in,
				t_bunny_position pos_2)
{
  t_color		*in_2;
  t_color		*array;
  unsigned int		color;
  int			w;
  t_bunny_position	pos;

  array = out->pixels;
  in_2 = in->pixels;
  pos.y = 0;
  while (pos.y < (in->clipable.clip_height))
    {
      pos.x = 0;
      while (pos.x < in->clipable.clip_width)
	{
	  w = ((pos.x + in->clipable.clip_x_position) +
	       (pos.y * in->clipable.clip_width));
	  color = in_2[w].full;
	  if (color != 0)
	    array[(pos.x + pos_2.x) +
		  ((pos.y + pos_2.y) * out->clipable.clip_width)].full = color;
	  pos.x++;
	}
      pos.y++;
    }
}

void			print_score(t_bj *game)
{
  my_txt(game, game->sum[0], 0);
  my_txt(game, game->sum[1], 1);
  my_txt(game, game->sum[2], 2);
  my_txt(game, game->sum[3], 3);
  my_txt(game, game->sum[4], 4);
  my_txt(game, game->sum[5], 5);
}

void			print_res(t_bj *game)
{
  my_result(game, 0);
  my_result(game, 1);
  my_result(game, 2);
  my_result(game, 3);
  my_result(game, 4);
  my_result(game, 5);
}

t_bunny_response	refresh(void *data)
{
  t_bj			*game;
  t_bunny_position	pos;

  game = (t_bj *)data;
  bunny_blit(&game->win->buffer, &game->pix->clipable, &pos);
  pos.x = 0;
  pos.y = 0;
  if (game->player <= 5 && game->ia_play != 0 && game->frame % 30 == 0)
    {
      if (game->sum[game->player] <= 16)
	pick_card(game, game->player);
      else
	{
	  game->player++;
	  game->turn = 2;
	}
    }
  if (game->player == 6)
    {
      print_res(game);
      count_money(game);
    }
  bunny_blit(&game->win->buffer, &game->pix->clipable, &pos);
  if (game->player <= 6)
    {
      print_score(game);
      print_money(game);
    }
  if (game->player == 0)
    my_button(game);
  bunny_display(game->win);
  game->frame++;
  return (GO_ON);
}

void		blackjack_loop(t_bj *game)
{
  bunny_set_key_response((t_bunny_key) &blackjack_callback);
  bunny_set_loop_main_function((t_bunny_loop) &refresh);
  bunny_set_click_response((t_bunny_click) &blackjack_click);
  bunny_loop(game->win, 40, game);
}
