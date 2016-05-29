/*
** cards.c for blackjack in /home/tran_-/Documents/rendu/CPE_2015_Blackjack/bonus/src
**
** Made by Guillaume TRAN
** Login   <tran_-@epitech.net>
**
** Started on  Thu Mar 17 22:57:21 2016 Guillaume TRAN
** Last update Mon Mar 28 23:51:46 2016 Guillaume TRAN
*/

#include "blackjack.h"

void		load_card(t_bunny_pixelarray *out,
			  t_bunny_pixelarray *in,
		          int number, int type)
{
  t_bunny_position	pos;
  t_bunny_position	pos_2;
  t_color		*font;
  t_color		*array;
  int			w;
  unsigned int		color;

  array = out->pixels;
  font = in->pixels;
  pos.y = 0;
  pos_2.y = type * 98;
  while (pos.y < out->clipable.clip_height && !(pos.x = 0))
    {
      pos_2.x = number * 73;
      while (pos.x < out->clipable.clip_width)
	{
	  w = ((pos_2.x + in->clipable.clip_x_position) +
	       (pos_2.y * in->clipable.clip_width));
	  color = font[w].full;
	  if (font[w].argb[3] > 10)
	    array[pos.x + (pos.y * out->clipable.clip_width)].full = color;
	  pos.x++ + pos_2.x++;
	}
      pos.y++ + pos_2.y++;
    }
}

void			distribute_cards(t_bj *game)
{
  int			player;
  int			turn;
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  turn = -1;
  while (++turn < 2)
    {
      player = -1;
      game->player = 0;
      while (++player < game->players)
	{
	  game->turn = turn;
	  usleep(300000);
	  if (!(player == game->players - 1 && turn == 1))
	    pick_card(game, player);
	  bunny_blit(&game->win->buffer, &game->pix->clipable, &pos);
	  bunny_display(game->win);
	  game->player++;
	}
    }
  game->player = 0;
  game->turn = 2;
}

void	get_pos_two(t_bj *game, int player, t_bunny_position *pos)
{
  if (player == 0)
    {
      pos->x = 1000 + (game->turn * 30);
      pos->y = 280;
    }
  if (player == 1)
    {
      pos->x = 750 + (game->turn * 30);
      pos->y  = 350;
    }
}

void	get_pos(t_bj *game, int player, t_bunny_position *pos)
{
  get_pos_two(game, player, pos);
  if (player == 2)
    {
      pos->x = 500 + (game->turn * 30);
      pos->y = 400;
    }
  if (player == 3)
    {
      pos->x = 280 + (game->turn * 30);
      pos->y = 350;
    }
  if (player == 4)
    {
      pos->x = 20 + (game->turn * 30);
      pos->y = 280;
    }
  if (player == 5)
    {
      if (game->turn == 0)
	pos->x = 500 + (game->turn * 30);
      else
	pos->x = 470 + (game->turn * 30);
      pos->y = 120;
    }
}

void			pick_card(t_bj *game, int player)
{
  t_bunny_position	pos;
  t_bunny_pixelarray	*card;
  int			nb;
  int			j;
  int			as;
  int			type;

  j = my_strhands(game->hands[player]);
  game->hands[player][j] = game->pick[game->nb_pick];
  game->sum[player] += get_card_value(game->hands[player][j]);
  nb = get_sum(game->pick[game->nb_pick++]);
  if (game->sum[player] > 21 && (as = count_as(game->hands[player])) > 0)
    {
      if (as > game->as[player])
	{
	  game->sum[player] -= 10;
	  game->as[player]++;
	}
    }
  type = (rand() % 4);
  card = bunny_new_pixelarray(73, 98);
  get_pos(game, player, &pos);
  if (player <= 5)
    {
      load_card(card, game->cards, nb, type);
      my_blit(game->pix, card, pos);
    }
  game->turn++;
  bunny_sound_play(&game->sound->sound);
}
